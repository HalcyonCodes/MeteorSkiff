


#include "Windows.h"
#include "LuaExecutor.h"
#include "OrderManager.h"
#include "ActionManager.h"

typedef struct OrderManagerBot {
	OrderManager* orderManager; //order管理器，获取任务订单
	void botInit(OrderManager* orderManager);  //初始化机器人
	int botRun(); //机器人开始运行
}_MeteorSkiffBot;


void OrderManagerBot::botInit(OrderManager* orderManager) {
	this->orderManager = orderManager;
}

int OrderManagerBot::botRun() {

	while (true) {
		//1.每隔一段时间发起一次http请求
		this->orderManager->pullServerOrders();

		//2.整理订单
		this->orderManager->addServerOrders();

		//3.休眠250毫秒
		Sleep(250); //延迟250毫秒BOO
	}
}

