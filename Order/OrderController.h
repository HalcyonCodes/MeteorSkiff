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
void msgSendOrderStatus(OrderManager* orderManager, string orderId, int orderStatus);

//====or003 msgOrderManagerInit====
void msgOrderManagerInit(OrderManager* orderManager);

//====or004 msgAddServerOrders====
void msgOrderManagerAddServerOrders(OrderManager* orderManager);

//====or005 msgPullServerOrders====
void msgOrderManagerPullServerOrders(OrderManager* orderManager);

//====or006 msgOrderManagerLogin====
void msgOrderManagerLogin(OrderManager* orderManager);

//====or007 msgTerminalInit====
void msgTerminalInit(OrderManager* orderManager);

//====or008 =====
int msgHttpPost(OrderManager* orderManager, string ip, string port, string http, string data);

//====or009 ====
httplib::Result msgCurlGet(OrderManager* orderManager, string ip, string port, string http);