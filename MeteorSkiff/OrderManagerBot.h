#pragma once



#include "Windows.h"
#include "LuaExecutor.h"
#include "OrderManager.h"
#include "ActionManager.h"

typedef struct OrderManagerBot {
	OrderManager* orderManager; //order����������ȡ���񶩵�
	void botInit(OrderManager* orderManager);  //��ʼ��������
	int botRun(); //�����˿�ʼ����
}_MeteorSkiffBot;