#pragma once


#include "windows.h"
#include <string>
#include "OrderManager.h"


using namespace std;

//====or000 megOrderTest====
string msgOrderTest(OrderManager* orderManager);

//====or001 msgPopServerOrder====
string msgPopServerOrder(OrderManager* orderManager);

//====or002 msgSendOrderStatus====
void msgSendOrderStatus(OrderManager* orderManager, string orderId, string orderStatus);

//====or003 msgOrderManagerInit====
void msgOrderManagerInit(OrderManager* orderManager);

//====or004 msgAddServerOrders====
void msgOrderManagerAddServerOrders(OrderManager* orderManager);

//====or005 msgPullServerOrders====
void msgOrderManagerPullServerOrders(OrderManager* orderManager);

//====or006 msgOrderManagerLogin====
void msgOrderManagerLogin(OrderManager* orderManager);
	
