#pragma once


#include "Windows.h"
#include "LuaExecutor.h"
#include "OrderManager.h"
#include "ActionManager.h"

typedef struct MeteorSkiffBot {
	//OrderManager* orderManager = nullptr; //order����������ȡ���񶩵�
	ActionManager* actionManager = nullptr; //����lua�ű�
	LuaExecutor* luaExecutor = nullptr; //ִ��lua�����ִ����
	void botInit();  //��ʼ��������
	int botRun(); //�����˿�ʼ����

}_MeteorSkiffBot;
