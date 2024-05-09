
#include "pch.h"
#include "framework.h"

#include "OrderMsgInterface.h" //定义了message的接口

#include <WinUser.h>
#include "GetHwndByPID.h"
#include "OrderSkills.h"
#include "OrderManager.h"
#include <string>

using namespace std;



//====or001 popServerOrder====
string popServerOrder(OrderManager* orderManager) {
	//MsgLoadPic msgInterface;
	MsgPopOrder msgInterface;
	msgInterface.orderManager = orderManager;
	LRESULT result = SendMessageA(getCurrentHwnd(), orderMsgCode, or001, (LPARAM)&msgInterface);
	return msgInterface.order;
}

//====or002 sendOrderStatus====
void sendOrderStatus(OrderManager* orderManager, string orderId, string orderStatus) {
	//MsgLoadPic msgInterface;
	MsgSendOrderStatus  msgInterface;
	msgInterface.orderManager = orderManager;
	msgInterface.orderId = orderId;
	msgInterface.orderStatus = orderStatus;
	LRESULT result = SendMessageA(getCurrentHwnd(), orderMsgCode, or002, (LPARAM)&msgInterface);
	return ;
}

