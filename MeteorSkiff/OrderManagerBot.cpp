


#include "Windows.h"
#include "LuaExecutor.h"
#include "OrderManager.h"
#include "ActionManager.h"

typedef struct OrderManagerBot {
	OrderManager* orderManager; //order����������ȡ���񶩵�
	void botInit(OrderManager* orderManager);  //��ʼ��������
	int botRun(); //�����˿�ʼ����
}_MeteorSkiffBot;


void OrderManagerBot::botInit(OrderManager* orderManager) {
	this->orderManager = orderManager;
}

int OrderManagerBot::botRun() {

	while (true) {
		//1.ÿ��һ��ʱ�䷢��һ��http����
		this->orderManager->pullServerOrders();

		//2.������
		this->orderManager->addServerOrders();

		//3.����250����
		Sleep(250); //�ӳ�250����BOO
	}
}

