#pragma once
#include "Windows.h"
#include "OrderManager.h"
#include <string>


//������msg�ķ���ֵ

//or000 popOrder
typedef struct MsgPopOrder {
	OrderManager* orderManager;
	string order;
}_MsgPopOrder;


//or001 sendOrderStatus
typedef struct MsgSendOrderStatus {
	OrderManager* orderManager;
	string orderId;
	string orderStatus;
	int result;
}_MsgSendOrderStatus;



