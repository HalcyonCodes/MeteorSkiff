#pragma once


#include "Windows.h"
#include "LuaExecutor.h"
#include "OrderManager.h"
#include "ActionManager.h"

typedef struct MeteorSkiffBot {
	OrderManager* orderManager; //order����������ȡ���񶩵�
	ActionManager* actionManager; //����lua�ű�
	LuaExecutor* luaExecutor; //ִ��lua�����ִ����
	void botInit(OrderManager* orderManager);  //��ʼ��������
	int botRun(); //�����˿�ʼ����


}_MeteorSkiffBot;
