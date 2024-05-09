
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


using namespace std;
using namespace rapidjson;

std::mutex mtx;

void OrderManager::addServerOrders() {
	std::lock_guard<std::mutex> lock(mtx);

	Document orderDoc;
	Document httpResultDoc;
	httpResultDoc.Parse(this->httpResultBody);

	list<const char*> orderIds;

	for (const auto& t : this->orders) {
		orderDoc.Parse(t);
		orderIds.push_back(orderDoc["orderId"].GetString());
	}

	for (const auto& order : httpResultDoc["orders"].GetArray()) {
		const char* httpOrderId = order["orderId"].GetString();

		// ��� orderId �Ƿ��Ѿ������
		if (std::find(orderIds.begin(), orderIds.end(), httpOrderId) == orderIds.end()) {
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
				writer.String(para.value.GetString());
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
			this->orders.push_back(strBuf.GetString());
		}
		return;
	}
}

void OrderManager::pullServerOrders() {
	//�ͷ��ڴ�
	if (this->httpResultBody != nullptr) {
		delete[] this->httpResultBody;
		this->httpResultBody = nullptr;
	}

	//��ȡ���ж�������������ַ http://ip:port/orders
	string http = "http://" + string(this->serverIp);

	httplib::Client client(http, std::atoi(this->port));

	client.set_default_headers({
		{"Authorization", this->jwt} // ����Ĭ�ϵ�����ͷ�������� JWT ����
		});

	auto res = client.Get("/orders");

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
	// ��� orders �б��Ƿ�Ϊ��
	if (!this->orders.empty()) {
		// ��ȡָ���һ��������ָ��
		const char* order = this->orders.front();
		// ���б����Ƴ���һ������
		orders.pop_front();
		// ʹ�� char* ���� std::string ����std::string ���ӹ��ڴ����
		std::string result(order);
		// ���� std::string ����
		return result;
	}
	else {
		// ����б�Ϊ�գ����ؿ��ַ���
		return std::string();
	}
}

int OrderManager::sendOrderStatus(const char* orderId, const char* status) {

	string http = "http://" + string(this->serverIp);
	httplib::Client client(http, std::atoi(this->port));
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
	auto res = client.Post("/setOrderStatus", postJson, "application/json");
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
	INIReader reader("config.ini");
	if (reader.ParseError() < 0) {
		dbgPrint("Error: Unable to load config.ini");
		return;
	}
	string serverIp = reader.Get("server", "ip", "127.0.0.1");
	string serverPort = reader.Get("server", "port", "80");
	string userName = reader.Get("user", "name", "guest");
	string password = reader.Get("user", "password", "");

	const char* charServerIp = serverIp.c_str();
	const char* charServerPort = serverIp.c_str();
	const char* charServerUserName = serverIp.c_str();
	const char* charPassword = serverIp.c_str();

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
	string http = "http://" + string(this->serverIp);
	httplib::Client client(http, std::atoi(this->port));

	// ���� POST ����� JSON ����
	std::string postJson =
		"{\"botAccount\": \"" +
		string(this->botAccount) +
		"\"," +
		"\"password\": \"" +
		string(this->botPwd) +
		"\"" +
		"}";
	//��ȡjwt����,��������ַ http://ip:port/jwt
	auto res = client.Post("/jwt", postJson, "application/json");
	// �����Ӧ״̬��
	if (res && res->status == 200) {
		Document doc;
		doc.Parse(res->body.c_str());

		this->jwt = new char[strlen(doc["token"].GetString()) + 1];
		strcpy_s(this->jwt, strlen(doc["token"].GetString() + 1), doc["token"].GetString());
	}
	return;
}
