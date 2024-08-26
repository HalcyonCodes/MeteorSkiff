
#include "pch.h"
#include "framework.h"

#include "OrderMsgInterface.h" //定义了message的接口

#include <WinUser.h>
#include "GetHwndByPID.h"
#include "OrderSkills.h"
#include "OrderManager.h"
#include <string>
#include "SetWindowHookOrder.h"
#include <mutex>

using namespace std;


//====or000 msgOrderTest====
string msgOrderTest(OrderManager* pOrderManager) {
	//MsgLoadPic msgInterface;
	MsgPopOrder msgInterface;
	msgInterface.msgOrderManager = pOrderManager;
	LRESULT result = SendMessageA(orderManagerHwnd, orderMsgCode, or000, (LPARAM)&msgInterface);
	return msgInterface.order;
}

//====or001 popServerOrder====
string msgPopServerOrder(OrderManager* pOrderManager) {
	//MsgLoadPic msgInterface;
	MsgPopOrder msgInterface;
	msgInterface.msgOrderManager = pOrderManager;
	LRESULT result = SendMessageA(orderManagerHwnd, orderMsgCode, or001, (LPARAM)&msgInterface);
	return msgInterface.order;
}

//====or002 sendOrderStatus====
void msgSendOrderStatus(OrderManager* pOrderManager, string orderId, int orderStatus) {
	//MsgLoadPic msgInterface;
	MsgSendOrderStatus  msgInterface;
	msgInterface.msgOrderManager = pOrderManager;
	msgInterface.orderId = orderId;
	msgInterface.orderStatus = orderStatus;
	LRESULT result = SendMessageA(orderManagerHwnd, orderMsgCode, or002, (LPARAM)&msgInterface);
	return ;
}

//====or003 msgOrderManagerInit====
void msgOrderManagerInit(OrderManager* pOrderManager){
	MsgOrderController msgInterface;
	msgInterface.msgOrderManager = pOrderManager;
	LRESULT result = SendMessageA(orderManagerHwnd, orderMsgCode, or003, (LPARAM)&msgInterface);
	return;
}

//====or004 msgAddServerOrders====
void msgOrderManagerAddServerOrders(OrderManager* pOrderManager) {
	MsgOrderController msgInterface;
	msgInterface.msgOrderManager = pOrderManager;
	LRESULT result = SendMessageA(orderManagerHwnd, orderMsgCode, or004, (LPARAM)&msgInterface); //post
	return;
}

//====or005 msgPullServerOrders====
void msgOrderManagerPullServerOrders(OrderManager* pOrderManager) {
	MsgOrderController msgInterface;
	msgInterface.msgOrderManager = pOrderManager;
	LRESULT result = SendMessageA(orderManagerHwnd, orderMsgCode, or005, (LPARAM)&msgInterface); //post
	return;
}

//====or006 msgOrderManagerLogin====
void msgOrderManagerLogin(OrderManager* pOrderManager) {
	MsgOrderController msgInterface;
	msgInterface.msgOrderManager = pOrderManager;
	LRESULT result = SendMessageA(orderManagerHwnd, orderMsgCode, or006, (LPARAM)&msgInterface);
	return;
}
