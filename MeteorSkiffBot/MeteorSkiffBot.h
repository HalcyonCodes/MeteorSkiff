#pragma once


#include "Windows.h"
#include "LuaExecutor.h"
#include "OrderManager.h"
#include "ActionManager.h"

typedef struct MeteorSkiffBot {
	//OrderManager* orderManager = nullptr; //order管理器，获取任务订单
	ActionManager* actionManager = nullptr; //管理lua脚本
	LuaExecutor* luaExecutor = nullptr; //执行lua代码的执行器
	void botInit();  //初始化机器人
	int botRun(); //机器人开始运行

}_MeteorSkiffBot;
