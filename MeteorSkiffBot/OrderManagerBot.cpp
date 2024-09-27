

#include "pch.h"
#include "Windows.h"
#include "LuaExecutor.h"
#include "OrderManager.h"
#include "ActionManager.h"
#include "OrderController.h"
#include "OrderManagerBot.h"



void OrderManagerBot::botInit() {
	//1.初始化
	msgOrderManagerInit(orderManager);
	msgOrderManagerLogin(orderManager);
	msgTerminalInit(orderManager);

}

int OrderManagerBot::botRun() {

	while (true) {
		//1.每隔一段时间发起一次http请求
		msgOrderManagerPullServerOrders(orderManager);

		//2.整理订单
		msgOrderManagerAddServerOrders(orderManager);

		//3.休眠250毫秒
		Sleep(250); //延迟250毫秒BOO
	}
	return 0;
}

