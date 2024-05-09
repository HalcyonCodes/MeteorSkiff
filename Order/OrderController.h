#pragma once


#include "windows.h"
#include <string>
#include "OrderManager.h"


using namespace std;

//====or001 popServerOrder====
string popServerOrder(OrderManager* orderManager);

//====or002 sendOrderStatus====
void sendOrderStatus(OrderManager* orderManager, string orderId, string orderStatus);
	
