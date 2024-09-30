#pragma once
#include "Windows.h"
#include "OrderManager.h"
#include <string>


//这里存放msg的返回值

//or000 popOrder
typedef struct MsgPopOrder {
	OrderManager* msgOrderManager = nullptr;
	string order;
}_MsgPopOrder;


//or001 sendOrderStatus
typedef struct MsgSendOrderStatus {
	OrderManager* msgOrderManager = nullptr;
	string orderId;
	int orderStatus;
	int result;
}_MsgSendOrderStatus;

//or002 init
typedef struct MsgOrderController {
	OrderManager* msgOrderManager = nullptr;

}_MsgOrderController;

//or003 httpPost
typedef struct MsgHttpPost {
	OrderManager* msgOrderManager = nullptr;
	string ip;
	string port;
	string http;
	string data;
	int result;
}_MsgHttpPost;