
#include "Windows.h"
#include "OrderController.h"
#include "OrderManager.h"

void testOrderManager() {

	//1.init
	msgOrderManagerInit(orderManager);

	//2.�����������Ϣ
	for (int i = 0; i < 2; i++) {
		msgOrderManagerPullServerOrders(orderManager);
	}
	
	//3.��Ӷ���

	msgOrderManagerAddServerOrders(orderManager);
	
	//4.��������
	while (true)
	{
		string t = msgPopServerOrder(orderManager);
	}
	
}