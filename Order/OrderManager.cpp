
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

using namespace std;
using namespace rapidjson;

//std::mutex mtx;

//std::mutex t_mutex;


OrderManager* orderManager = nullptr;

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

	for (const auto& order : httpResultDoc["orders"].GetArray()) {
		const char* httpOrderId = order["orderId"].GetString();

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
			// �����¶����� JSON �ַ���
			rapidjson::StringBuffer strBuf;
			rapidjson::Writer<rapidjson::StringBuffer> writer(strBuf);
			writer.StartObject();

			// orderId
			writer.Key("orderId");
			writer.String(httpOrderId);

			// orderName
			writer.Key("orderName");
			writer.String(order["orderName"].GetString());

			// createTime
			writer.Key("createTime");
			writer.String(order["createTime"].GetString());

			// orderParas
			writer.Key("orderParas");
			writer.StartArray();
			for (const auto& para : order["orderParas"].GetObj()) {
				writer.StartObject();
				writer.Key(para.name.GetString());
				if (para.value.IsInt() == true) {
					writer.Int(para.value.GetInt());
				}
				if (para.value.IsDouble() == true) {
					writer.Double(para.value.GetDouble());
				}
				if (para.value.IsString() == true) {
					writer.String(para.value.GetString());
				}
				if (para.value.IsBool() == true) {
					writer.Bool(para.value.GetBool());
				}
				writer.EndObject();
			}
			writer.EndArray();

			// script
			writer.Key("script");
			writer.String(order["script"].GetString());

			writer.EndObject();

			//����
			string newOrder = strBuf.GetString();
			char* newOrderChar = new char[newOrder.length() + 1];
			strcpy_s(newOrderChar, newOrder.length() + 1, newOrder.c_str());
			this->orders.push_back(newOrderChar);

		}
	}
	return;
}

void OrderManager::pullServerOrders() {
	//�ͷ��ڴ�
	if (this->httpResultBody != nullptr) {
		delete[] this->httpResultBody;
		this->httpResultBody = nullptr;
	}

	//��ȡ���ж�������������ַ http://ip:port/orders
	string http = string(this->serverIp);
	string port = string(this->port);

	httplib::Client client(http + ":" + port);

	if (this->jwt == nullptr) {
		this->login();
	}

	if (this->jwt != nullptr) {
		client.set_default_headers({
		{"Authorization", this->jwt} // ����Ĭ�ϵ�����ͷ�������� JWT ����
			});
	}

	//====������ַ====
	//auto res = client.Get("/orders");

	//====���Ե�ַ====
    //====/mock/00b44ac4-9575-4322-bcc8-583a9fcac8ce/orders====
	httplib::Result res = client.Get("/mock/00b44ac4-9575-4322-bcc8-583a9fcac8ce/orders");
	//==================
	if (res) {

	}
	else {
		//û����Ӧ
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
		//����
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

	// ��� orders �б��Ƿ�Ϊ��
	if (!this->orders.empty()) {

		// ��ȡָ���һ��������ָ��
		const char* order = this->orders.front();


		//ȡ��������ͬʱ����������Ͷ���״̬��Ϣ, ���ᶩ����

		string status;
		Document doc;
		doc.Parse(order);
		string orderId = doc["orderId"].GetString();
		status = "working";
		this->sendOrderStatus(orderId.c_str(), status.c_str());

		// ���б����Ƴ���һ������
		orders.pop_front();
		
		//std::string result(order);

		string result = string(order);

		delete[] order;

		// ���� std::string ����
		return result;
	}
	else {
		// ����б�Ϊ�գ����ؿ��ַ���
		return "";
	}
}

int OrderManager::sendOrderStatus(const char* orderId, const char* status) {

	string http = string(this->serverIp);
	string port = string(this->port);

	httplib::Client client(http + ":" + port);
	client.set_default_headers({
		{"Authorization", this->jwt}
		});
	// ���� POST ����� JSON ����
	std::string postJson =
		"{\"orderId\" : \"" +
		string(orderId) +
		"\" , " +
		"\"status\" : \"" +
		string(status) +
		"\"}";
	client.set_default_headers({
	 {"Authorization", this->jwt} // ����Ĭ�ϵ�����ͷ�������� JWT ����
	});

	//auto res = client.Post("/setOrderStatus", postJson, "application/json");
	auto res = client.Post("/mock/00b44ac4-9575-4322-bcc8-583a9fcac8ce/setOrderStatus", postJson, "application/json");

	return res->status;
}


void OrderManager::init() {

	//���������ļ�
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

	//��ȡ�����ļ�
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

	//���ù����ڴ�ͨ��

	return;
}


void OrderManager::login() {

	//ɾ��ָ��
	if (this->jwt != nullptr) {
		delete[] this->jwt;
		this->jwt = nullptr;
	}

	//��¼����ȡ��ȡ����
	string http = string(this->serverIp);
	string port = string(this->port); 
	httplib::Client client(http + ":" + port);

	// ���� POST ����� JSON ����
	std::string postJson =
		"{\"botAccount\" : " +
		string(this->botAccount) +
		"," +
		"\"password\": \"" +
		string(this->botPwd) +
		"\"" +
		"}";
	//��ȡjwt����,��������ַ http://ip:port/login
	//auto res = client.Post("/login", postJson, "application/json");

	//====���Ե�ַ====
	//====/mock/00b44ac4-9575-4322-bcc8-583a9fcac8ce/login====
	auto res = client.Post("/mock/00b44ac4-9575-4322-bcc8-583a9fcac8ce/login", postJson, "application/json");
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

	// �����Ӧ״̬��
	if (res && res->status == 200) {
		Document doc;
		doc.Parse(res->body.c_str());
		string token = doc["token"].GetString() ;
		token = token + "\0";
		this->jwt = new char[strlen(token.c_str()) + 4];
		//int q = token.length() + 2;
		strcpy_s(this->jwt, strlen(token.c_str()) + 1, token.c_str());
	}
	return;
}
