#pragma once



#include "Windows.h"
#include "LuaExecutor.h"
#include "OrderManager.h"
#include "ActionManager.h"

typedef struct OrderManagerBot {
	void botInit();  //��ʼ��������
	int botRun(); //�����˿�ʼ����
}_OrderManagerBot;