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


    //初始化
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



    // 创建一个文档对象
    rapidjson::Document doc;
    doc.SetObject();

    // 创建一个Writer对象，准备序列化
    rapidjson::StringBuffer strBuf;
    rapidjson::Writer<rapidjson::StringBuffer> writer(strBuf);

    // 开始序列化
    writer.StartObject();

    // 添加 "orderChannelLevel" 字段
    writer.Key("orderChannelLevel");
    writer.Int(channleLevel);

    // 添加 "orders" 数组
    writer.Key("orders");
    writer.StartArray();

    // 添加一个订单对象
    writer.StartObject();

    // 添加 "orderID" 字段
    writer.Key("orderID");
    writer.String("3fa85f64-5717-4562-b3fc-2c963f66afa6");

    // 添加 "orderService" 对象
    writer.Key("orderService");
    writer.StartObject();
    writer.Key("orderServiceID");
    writer.Int(serviceID);
    writer.EndObject(); // 结束 "orderService" 对象

    // 添加 "sourceTerminalID" 和 "targetTerminalID" 字段
    writer.Key("sourceTerminalID");
   // writer.String(terminalID);  //生产环境用的
    writer.String("abcdefg"); //测试环境用的
    writer.Key("targetTerminalID");
    writer.String(targetID.c_str());

    // 添加 "orderServiceResources" 数组
    writer.Key("orderServiceResources");
    writer.StartArray();

    int index = 0;
    for (int q : resouorceID) {
        writer.StartObject();

        // 添加 "orderServiceResource" 对象
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

        // 结束资源对象
        writer.EndObject();

        index++;
    }

    // 结束 "orderServiceResources" 数组
    writer.EndArray();

    // 结束订单对象
    writer.EndObject();

    // 结束 "orders" 数组
    writer.EndArray();

    // 结束整个文档对象
    writer.EndObject();

    // 输出序列化后的 JSON 字符串
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
        // 设置默认的请求头部，包含JWT令牌
        //client.set_default_headers({
        //	{"Authorization", authorization_header}
        //});
        headers = {
        {"Authorization", authorizationHeader}
        };
    }

    //====生产地址====
    httplib::Result res = client.Post("/api/v1/Order/CreateOrder", headers, strBuf.GetString(), "application/json");
    return res->status;


}