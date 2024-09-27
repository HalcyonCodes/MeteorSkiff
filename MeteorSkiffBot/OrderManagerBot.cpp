

#include "pch.h"
#include "Windows.h"
#include "LuaExecutor.h"
#include "OrderManager.h"
#include "ActionManager.h"
#include "OrderController.h"
#include "OrderManagerBot.h"



void OrderManagerBot::botInit() {
	//1.��ʼ��
	msgOrderManagerInit(orderManager);
	msgOrderManagerLogin(orderManager);
	msgTerminalInit(orderManager);

}

int OrderManagerBot::botRun() {

	while (true) {
		//1.ÿ��һ��ʱ�䷢��һ��http����
		msgOrderManagerPullServerOrders(orderManager);

		//2.������
		msgOrderManagerAddServerOrders(orderManager);

		//3.����250����
		Sleep(250); //�ӳ�250����BOO
	}
	return 0;
}

