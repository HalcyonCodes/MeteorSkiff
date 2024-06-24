#pragma once



#include "Windows.h"
#include "LuaExecutor.h"
#include "OrderManager.h"
#include "ActionManager.h"

typedef struct OrderManagerBot {
	void botInit();  //初始化机器人
	int botRun(); //机器人开始运行
}_OrderManagerBot;