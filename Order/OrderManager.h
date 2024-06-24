#pragma once

#include <list>
#include <string>
#include "OrderManager.h"

using namespace std;



typedef struct OrderManager {
	
	//--
	const char* testChar = "testChar";
	//--
	list<const char*> orders; //所有订单
	char* serverIp; //服务器ip地址
	char* port; //服务器端口
	char* botAccount; //机器人账户
	char* botPwd; //机器人密码
	char* serverResult; //服务器返回json字符串
	char* jwt; //服务器发放的令牌
	char* httpResultBody; //http请求后存放body的字符串
	void init(); //读取配置文件，获取ip和端口
	void addServerOrders(); //把json字符串解析成订单压入订单栈
	string popServerOrder();  //从栈顶返回一个订单，并且从orders中删除那个被弹出的订单
	void pullServerOrders(); //向服务器请求订单
	void login(); //向服务器发送登录请求，获取jwt令牌
	int sendOrderStatus(const char* orderId, const char* status); //另一个线程完成订单后,向服务器发送订单完成状态，通知服务器删除订单

}_OrderManager;

extern OrderManager* orderManager;



/* json 格式：
{
  "orders":[
    {
        "stackIndex": 0,
        "orderId":"12345",
        "orderName":"orderName",
        "createTime":"2024/4/30 6:45",
        "orderParas":{"paraName1": "paraValue", "paraName2": "paraValue"},
        "script":"scriptName",
        "status":"wait"
    }
]
}

*/

