#include "pch.h"
#include "Windows.h"


#include "OrderSkill.h"

#include "rapidjson/document.h"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"
#include <OrderManager.h>
#include <INIReader.h>
#include <DbgPrint.h>

#include "httplib.h"


int OrderSkill::createOrder(int channleLevel, int serviceID, string targetID, vector<int>& resouorceID,
    const std::vector<int>& intVal, const std::vector<string>& stringVal, const std::vector<double>& doubleVal) {


    //��ʼ��
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



    // ����һ���ĵ�����
    rapidjson::Document doc;
    doc.SetObject();

    // ����һ��Writer����׼�����л�
    rapidjson::StringBuffer strBuf;
    rapidjson::Writer<rapidjson::StringBuffer> writer(strBuf);

    // ��ʼ���л�
    writer.StartObject();

    // ��� "orderChannelLevel" �ֶ�
    writer.Key("orderChannelLevel");
    writer.Int(channleLevel);

    // ��� "orders" ����
    writer.Key("orders");
    writer.StartArray();

    // ���һ����������
    writer.StartObject();

    // ��� "orderID" �ֶ�
    writer.Key("orderID");
    writer.String("3fa85f64-5717-4562-b3fc-2c963f66afa6");

    // ��� "orderService" ����
    writer.Key("orderService");
    writer.StartObject();
    writer.Key("orderServiceID");
    writer.Int(serviceID);
    writer.EndObject(); // ���� "orderService" ����

    // ��� "sourceTerminalID" �� "targetTerminalID" �ֶ�
    writer.Key("sourceTerminalID");
   // writer.String(terminalID);  //���������õ�
    writer.String("abcdefg"); //���Ի����õ�
    writer.Key("targetTerminalID");
    writer.String(targetID.c_str());

    // ��� "orderServiceResources" ����
    writer.Key("orderServiceResources");
    writer.StartArray();

    int index = 0;
    for (int q : resouorceID) {
        writer.StartObject();

        // ��� "orderServiceResource" ����
        writer.Key("orderServiceResource");
        writer.StartObject();
        writer.Key("orderServiceResourceID");
        writer.Int(q);
        writer.EndObject();

        writer.Key("resourceIntValue");
        writer.Int(intVal[index]);
        writer.Key("resourceStringValue");
        writer.String(stringVal[index].c_str());
        writer.Key("resourceDoubleValue");
        writer.Double(doubleVal[index]);

        // ������Դ����
        writer.EndObject();

        index++;
    }

    // ���� "orderServiceResources" ����
    writer.EndArray();

    // ������������
    writer.EndObject();

    // ���� "orders" ����
    writer.EndArray();

    // ���������ĵ�����
    writer.EndObject();

    // ������л���� JSON �ַ���
    //strBuf.GetString();
    
    string http = string(charServerIp);
    string port = string(charServerPort);



    httplib::Client client(http + ":" + port);
    client.set_default_headers({
        {"Authorization", JWT}
        });

    httplib::Headers headers;

    if (JWT != nullptr) {
        std::string authorizationHeader = "Bearer " + std::string(JWT);
        //std::string authorization_header = std::string(this->jwt);
        // ����Ĭ�ϵ�����ͷ��������JWT����
        //client.set_default_headers({
        //	{"Authorization", authorization_header}
        //});
        headers = {
        {"Authorization", authorizationHeader}
        };
    }

    //====������ַ====
    httplib::Result res = client.Post("/api/v1/Order/CreateOrder", headers, strBuf.GetString(), "application/json");
    return res->status;


}