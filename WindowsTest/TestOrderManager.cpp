
#include "Windows.h"
#include "OrderController.h"
#include "OrderManager.h"

void testOrderManager() {

	//1.init
	msgOrderManagerInit(orderManager);

	//2.向服务器拉信息
	for (int i = 0; i < 2; i++) {
		msgOrderManagerPullServerOrders(orderManager);
	}
	
	//3.添加订单

	msgOrderManagerAddServerOrders(orderManager);
	
	//4.弹出订单
	while (true)
	{
		string t = msgPopServerOrder(orderManager);
	}
	
}