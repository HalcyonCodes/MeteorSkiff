#pragma once



#include "Windows.h"
#include "LuaExecutor.h"
#include "OrderManager.h"
#include "ActionManager.h"

typedef struct OrderManagerBot {
	OrderManager* orderManager; //order管理器，获取任务订单
	void botInit(OrderManager* orderManager);  //初始化机器人
	int botRun(); //机器人开始运行
}_MeteorSkiffBot;