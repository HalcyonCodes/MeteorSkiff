
#include "pch.h"
#include "Windows.h"
#include "OrderManager.h"
#include <string>
#include "INIReader.h"
#include "DbgPrint.h"
#include "httplib.h"
#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"
#include "SetWindowHookOrder.h"
#include "GetHwndByPID.h"


#include <winsock2.h>
#include <iphlpapi.h>
#include <iostream>

#pragma comment(lib, "iphlpapi.lib")
#pragma comment(lib, "Ws2_32.lib")


using namespace std;
using namespace rapidjson;

//std::mutex mtx;

//std::mutex t_mutex;


OrderManager* orderManager = nullptr;
char* terminalID = nullptr;
char* JWT = nullptr;

void OrderManager::addServerOrders() {
	Document orderDoc;
	Document httpResultDoc;

	if (this->httpResultBody == nullptr) {
		return;
	}

	httpResultDoc.Parse(this->httpResultBody);

	list<const char*> orderIds;

	for (const auto& t : this->orders) {
		orderDoc.Parse(t);

		orderIds.push_back(orderDoc["orderId"].GetString());
	}

	const rapidjson::Value& orders = httpResultDoc["order"];

	//const char* test = orders["orderID"].GetString();

	//for (const auto& order : httpResultDoc["orders"].GetArray()) {
	
		const char* httpOrderId = orders["orderID"].GetString();

		bool isHas = false;
		for (const auto& t : orderIds) {
			//dbgPrint("t1:%s", t);
			//dbgPrint("t2:%s", httpOrderId);
			isHas = (strcmp(t, httpOrderId) == 0);
			if (isHas == true) {
				break;
			}
		}

		if (isHas == true) {
			
		}
		else {
			// 构建新订单的 JSON 字符串
			rapidjson::StringBuffer strBuf;
			rapidjson::Writer<rapidjson::StringBuffer> writer(strBuf);
			writer.StartObject();

			// orderId
			writer.Key("orderId");
			writer.String(httpOrderId);

			// orderName
			writer.Key("orderServiceName");
			writer.String(orders["orderService"]["orderServiceName"].GetString());

			// createTime
			writer.Key("createTime");
			writer.String(orders["createdTime"].GetString());

			// orderParas
			writer.Key("orderParas");
			writer.StartArray();
			for (const auto& para : orders["orderServiceResources"].GetArray()) {
				
				

				writer.StartObject();

				const char* baseKey = para["orderServiceResource"]["orderServiceResourceName"].GetString();
				writer.Key((string(baseKey) + "IntVal").c_str());
				writer.Int(para["resourceIntValue"].GetInt());
				writer.Key((string(baseKey) + "DoubleVal").c_str());
				writer.Double(para["resourceDoubleValue"].GetDouble());
				
				writer.Key((string(baseKey) + "StringVal").c_str());
				writer.String(para["resourceStringValue"].GetString());
				
				writer.EndObject();
			}
			writer.EndArray();

			// script
			writer.Key("script");
			writer.String(orders["orderService"]["orderServiceWorkScript"]["orderServiceScriptName"].GetString());

			writer.EndObject();

			//保存
			string newOrder = strBuf.GetString();
			char* newOrderChar = new char[newOrder.length() + 1];
			strcpy_s(newOrderChar, newOrder.length() + 1, newOrder.c_str());
			this->orders.push_back(newOrderChar);

			//设置服务器端订单为等待
			this->sendOrderStatus(httpOrderId, 0);
		}
	//}
	return;
}

void OrderManager::pullServerOrders() {
	//释放内存
	if (this->httpResultBody != nullptr) {
		delete[] this->httpResultBody;
		this->httpResultBody = nullptr;
	}

	//获取所有订单，服务器地址 http://ip:port/orders
	string http = string(this->serverIp);
	string port = string(this->port);

	httplib::Client client(http + ":" + port);

	if (this->jwt == nullptr) {
		this->login();
	}
	httplib::Headers headers;

	if (this->jwt != nullptr) {
		std::string authorizationHeader = "Bearer " + std::string(this->jwt);
		//std::string authorization_header = std::string(this->jwt);
		// 设置默认的请求头部，包含JWT令牌
		//client.set_default_headers({
		//	{"Authorization", authorization_header}
		//});
		headers = {
		{"Authorization", authorizationHeader},
		};
	}

	

	
	//====生产地址====
	

	httplib::Result res = client.Get("/api/v1/Order/GetOrder", headers);
	//httplib::Result res = client.Post("/api/v1/Account/PostTest", headers);
	
	
	//====测试地址====
    //====/mock/00b44ac4-9575-4322-bcc8-583a9fcac8ce/orders====
	//httplib::Result res = client.Get("/mock/00b44ac4-9575-4322-bcc8-583a9fcac8ce/orders");
	//==================
	if (res) {

	}
	else {
		//没有响应
		if (this->httpResultBody != nullptr) {
			delete[] this->httpResultBody;
			this->httpResultBody = nullptr;
		}
		return;
	}
	
	if (res->status == 401) {
		this->login();
		return;
	}
	if (res->status == 200) {
		//拷贝
		size_t bodyLenght = res->body.length();
		this->httpResultBody = new char[bodyLenght + 1];
		strcpy_s(this->httpResultBody, bodyLenght + 1, res->body.c_str());
		
		return;
	}
	return;

}


string OrderManager::popServerOrder() {

	//dbgPrint("sss1:%d", orderMangerHwnd);
	//dbgPrint("sss2:%d", getCurrentHwnd());

	// 检查 orders 列表是否为空
	if (!this->orders.empty()) {

		// 获取指向第一个订单的指针
		const char* order = this->orders.front();


		//取出订单的同时向服务器发送订单状态信息, 冻结订单。

		string status;
		Document doc;
		doc.Parse(order);
		//string orderId = doc["orderId"].GetString();
		//status = "working";
		//this->sendOrderStatus(orderId.c_str(), status.c_str());

		// 从列表中移除第一个订单
		orders.pop_front();
		
		//std::string result(order);

		string result = string(order);

		delete[] order;

		// 返回 std::string 对象
		return result;
	}
	else {
		// 如果列表为空，返回空字符串
		return "";
	}
}

int OrderManager::sendOrderStatus(const char* orderId, int status) {

	string http = string(this->serverIp);
	string port = string(this->port);

	httplib::Client client(http + ":" + port);
	client.set_default_headers({
		{"Authorization", this->jwt}
		});
	// 构建 POST 请求的 JSON 数据
	std::string postJson =
		"{\"orderID\" : \"" +
		string(orderId) +
		"\" , " +
		"\"status\" : \"" +
		std::to_string(status) +
		"\"}";

	httplib::Headers headers;

	if (this->jwt != nullptr) {
		std::string authorizationHeader = "Bearer " + std::string(this->jwt);
		//std::string authorization_header = std::string(this->jwt);
		// 设置默认的请求头部，包含JWT令牌
		//client.set_default_headers({
		//	{"Authorization", authorization_header}
		//});
		headers = {
		{"Authorization", authorizationHeader}
		};
	}

	//auto res = client.Post("/setOrderStatus", postJson, "application/json");
	//auto res = client.Post("/mock/00b44ac4-9575-4322-bcc8-583a9fcac8ce/setOrderStatus", postJson, "application/json");
	//====生产地址====
	httplib::Result res = client.Post("/api/v1/Order/UpdateOrderStatus", headers, postJson, "application/json");


	return res->status;
}


void OrderManager::init() {

	//清理配置文件
	if (this->serverIp != nullptr) {
		delete[] this->serverIp;
		this->serverIp = nullptr;
	}
	if (this->port != nullptr) {
		delete[] this->port;
	}
	if (this->botAccount != nullptr) {
		delete[] this->botAccount;
	}
	if (this->botPwd != nullptr) {
		delete[] this->botPwd;
	}

	//读取配置文件
	char currentDirectory[MAX_PATH];
	DWORD length = GetCurrentDirectoryA(MAX_PATH, currentDirectory);
	std::string configPath(currentDirectory);
	configPath += "\\config.ini";

	INIReader reader(configPath);
	if (reader.ParseError() < 0) {
		dbgPrint("Error: Unable to load config.ini");
		return;
	}

	string serverIp = reader.Get("server", "ip", "127.0.0.1");
	string serverPort = reader.Get("server", "port", "80");
	string userName = reader.Get("user", "name", "guest");
	string password = reader.Get("user", "password", "");

	const char* charServerIp = serverIp.c_str();
	const char* charServerPort = serverPort.c_str();
	const char* charServerUserName = userName.c_str();
	const char* charPassword = password.c_str();

	this->serverIp = new char[strlen(charServerIp) + 1];
	this->port = new char[strlen(charServerPort) + 1];
	this->botAccount = new char[strlen(charServerUserName) + 1];
	this->botPwd = new char[strlen(charPassword) + 1];

	strcpy_s(this->serverIp, strlen(charServerIp) + 1, charServerIp);
	strcpy_s(this->port, strlen(charServerPort) + 1, charServerPort);
	strcpy_s(this->botAccount, strlen(charServerUserName) + 1, charServerUserName);
	strcpy_s(this->botPwd, strlen(charPassword) + 1, charPassword);

	//设置共享内存通道
	
	//设置本机ip
	

	return;
}


void OrderManager::login() {

	//删除指针
	if (this->jwt != nullptr) {
		delete[] this->jwt;
		this->jwt = nullptr;
	}

	//登录并获取获取令牌
	string http = string(this->serverIp);
	string port = string(this->port); 
	httplib::Client client(http + ":" + port);

	// 构建 POST 请求的 JSON 数据
	std::string postJson =
		"{\"userName\" : " +
		string(this->botAccount) +
		"," +
		"\"password\": \"" +
		string(this->botPwd) +
		"\"" +
		"}";
	//获取jwt令牌,服务器地址 http://ip:port/login
	//auto res = client.Post("/login", postJson, "application/json");

	//====测试地址====
	//====/mock/00b44ac4-9575-4322-bcc8-583a9fcac8ce/login====
	//auto res = client.Post("/mock/00b44ac4-9575-4322-bcc8-583a9fcac8ce/login", postJson, "application/json");
	//==================
	//====生产地址====
	auto res = client.Post("/api/v1/Account/Login", postJson, "application/json");
	//
	//==================
	
	if (res) {

	}
	else
	{
		if (this->jwt != nullptr) {
			delete[] this->jwt;
			this->jwt = nullptr;
		}
		return;
	}

	// 检查响应状态码
	if (res && res->status == 200) {
		Document doc;
		doc.Parse(res->body.c_str());
		string token = doc["Access_token"].GetString() ;
		//token = token + "\0";
		this->jwt = new char[strlen(token.c_str()) + 1];
		memset(this->jwt, 0x00, strlen(token.c_str()) + 1);
		//int q = token.length() + 2;
		strcpy_s(this->jwt, strlen(token.c_str()) + 1, token.c_str());
	}
	JWT = this->jwt;
	return;
}


int OrderManager::terminalInit() {
	string http = string(this->serverIp);
	string port = string(this->port);



	httplib::Client client(http + ":" + port);
	client.set_default_headers({
		{"Authorization", this->jwt}
		});

	httplib::Headers headers;

	if (this->jwt != nullptr) {
		std::string authorizationHeader = "Bearer " + std::string(this->jwt);
		//std::string authorization_header = std::string(this->jwt);
		// 设置默认的请求头部，包含JWT令牌
		//client.set_default_headers({
		//	{"Authorization", authorization_header}
		//});
		headers = {
		{"Authorization", authorizationHeader}
		};
	}
	//
	//

	std::string postJson =
		"{\"terminalName\" : " +
		string(this->botAccount) +
		"," +
		"\"terminalIP\": \"" +
		"????" + "\"" +
		","+
		"\"terminalDesc\": \"a terminal.\""
		"}";
	
	//====生产地址====
	httplib::Result res = client.Post("/api/v1/Termianl/TerminalInit", headers, postJson, "application/json");

	string temp = string(res->body.c_str());

	temp.erase(0, 1); // 去掉第一个字符（即第一个双引号）
	temp.erase(temp.size() - 1);
	this->terminalID = new char[strlen(temp.c_str()) + 1];
	strcpy_s(this->terminalID, strlen(temp.c_str()) + 1, temp.c_str());
	terminalID = this->terminalID;

	return res->status;
}


int OrderManager::httpPost(string ip, string port, string http, string data) {


	httplib::Client client(ip + ":" + port);
	client.set_default_headers({
		{"Authorization", this->jwt}
		});

	httplib::Headers headers;

	if (this->jwt != nullptr) {
		std::string authorizationHeader = "Bearer " + std::string(this->jwt);
		//std::string authorization_header = std::string(this->jwt);
		// 设置默认的请求头部，包含JWT令牌
		//client.set_default_headers({
		//	{"Authorization", authorization_header}
		//});
		headers = {
		{"Authorization", authorizationHeader}
		};
	}
	std::string postJson = data;

	httplib::Result res = client.Post(http, headers, postJson, "application/json");
	return res->status;
}


