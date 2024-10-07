
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
#include"httplib.h"
#include <memory>
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

//====or007 msgTerminalInit====
void msgTerminalInit(OrderManager* pOrderManager) {
	MsgOrderController msgInterface;
	msgInterface.msgOrderManager = pOrderManager;
	LRESULT result = SendMessageA(orderManagerHwnd, orderMsgCode, or007, (LPARAM)&msgInterface);
	return;
}

//====or008 msgHttpPost
int msgHttpPost(OrderManager* orderManager, string ip, string port, string http, string data){
	MsgHttpPost msgInterface;
	msgInterface.msgOrderManager = orderManager;
	msgInterface.ip = ip;
	msgInterface.port = port;
	msgInterface.http = http;
	msgInterface.data = data;
	LRESULT result = SendMessageA(orderManagerHwnd, orderMsgCode, or008, (LPARAM)&msgInterface);
	return msgInterface.result;
}

//====or009 curlGet
httplib::Result msgCurlGet(OrderManager* orderManager, string ip, string port, string http) 
{
	auto msgInterfacePtr = std::make_unique<MsgHttpGet>();
	msgInterfacePtr->msgOrderManager = orderManager;
	msgInterfacePtr->ip = ip;
	msgInterfacePtr->port = port;
	msgInterfacePtr->http = http;

	LRESULT result = SendMessageA(orderManagerHwnd, orderMsgCode, or009, reinterpret_cast<LPARAM>(msgInterfacePtr.get()));

	// 使用 std::move 来避免使用拷贝构造函数
	return std::move(msgInterfacePtr->result);
}