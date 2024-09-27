
#include "pch.h"
#include <wtypes.h>
#include "DbgPrint.h"

#include "SetWindowHookOrder.h"
#include "OrderSkills.h"
#include "OrderMsgInterface.h"
#include <string>

#include <mutex>


using namespace std;

//std::mutex h_mutex;



LRESULT CALLBACK orderProc(int code, WPARAM wParam, LPARAM lParam) {

	//std::lock_guard<std::mutex> lock(h_mutex);

	CWPSTRUCT* lpArg = (CWPSTRUCT*)lParam;
	if (code == HC_ACTION) {
		if (lpArg->message == orderMsgCode) {
			switch (lpArg->wParam) {
				//这里添加各种机器人动作
			case msgOrderTest1: {
				//----------------测试----------------------
				dbgPrint("开始测试");
			}

			//====订单管理机器人====
			//====or000 OrderTest ===
			case or000: {
				//or001
				//----1.处理参数----
				MsgPopOrder* msgInterface = static_cast<MsgPopOrder*>((void*)(lpArg->lParam));
				//memset(msgInterface->name, 0x00, 512);
				//dbgPrint("addr-1:%p", msgInterface);
				//----2.调用----
				//string order = msgInterface->msgOrderManager->popServerOrder();
				string order = msgInterface->msgOrderManager->testChar;

				//----3.处理----
				msgInterface->order = order;
				break;
			}
			//====or 001 popServerOrder===
			case or001: {
				//or001
				//----1.处理参数----
				MsgPopOrder* msgInterface = static_cast<MsgPopOrder*>((void*)(lpArg->lParam));
				//memset(msgInterface->name, 0x00, 512);
				//dbgPrint("addr-1:%p", msgInterface);
				//----2.调用----
				string order = msgInterface->msgOrderManager->popServerOrder();
				//----3.处理----
				msgInterface->order = order;
				break;
			}
			//====or 002 sendOrderStatus====
			case or002: {
				//or002
				//----1.处理参数----
				MsgSendOrderStatus* msgInterface = static_cast<MsgSendOrderStatus*>((void*)(lpArg->lParam));
				//memset(msgInterface->name, 0x00, 512);
				//dbgPrint("addr-1:%p", msgInterface);
				//----2.调用----
				const char* orderId = msgInterface->orderId.c_str();
				int orderStatus = msgInterface->orderStatus;
				int result = msgInterface->msgOrderManager->sendOrderStatus(orderId, orderStatus);
				//----3.处理----
				msgInterface->result = result;
				break;
			}	
			//====or 003 OrderManagerInit====
			case or003: {
				//or 003
				//----1.处理参数----
				MsgOrderController* msgInterface = static_cast<MsgOrderController*>((void*)(lpArg->lParam));
				//memset(msgInterface->name, 0x00, 512);
				//dbgPrint("addr-1:%p", msgInterface);
				//----2.调用----
				msgInterface->msgOrderManager->init();
				//----3.处理----
				//msgInterface->result = result;
				break;
			}
			//====or 004 OrderMangerAddServerOrders====
			case or004: {
				//or 004
				//----1.处理参数----
				MsgOrderController* msgInterface = static_cast<MsgOrderController*>((void*)(lpArg->lParam));
				//memset(msgInterface->name, 0x00, 512);
				//dbgPrint("addr-1:%p", msgInterface);
				//----2.调用----
				msgInterface->msgOrderManager->addServerOrders();
				//----3.处理----
				//msgInterface->result = result;
				break;
			}
			//====or 005 OrderManagerPullServerOrders====
			case or005: {
				//or 005
			    //----1.处理参数----
				MsgOrderController* msgInterface = static_cast<MsgOrderController*>((void*)(lpArg->lParam));
				//memset(msgInterface->name, 0x00, 512);
				//dbgPrint("addr-1:%p", msgInterface);
				//----2.调用----
				msgInterface->msgOrderManager->pullServerOrders();
				//----3.处理----
				//msgInterface->result = result;
				break;
			}
			//====or 006 OrderManagerLogin====
			case or006: {
				//or 006
				//----1.处理参数----
				MsgOrderController* msgInterface = static_cast<MsgOrderController*>((void*)(lpArg->lParam));
				//memset(msgInterface->name, 0x00, 512);
				//dbgPrint("addr-1:%p", msgInterface);
				//----2.调用----
				msgInterface->msgOrderManager->login();
				//----3.处理----
				//msgInterface->result = result;
				break;
			}
			//====or 007 terminalInit====
			case or007: {
				//or 006
				//----1.处理参数----
				MsgOrderController* msgInterface = static_cast<MsgOrderController*>((void*)(lpArg->lParam));
				//memset(msgInterface->name, 0x00, 512);
				//dbgPrint("addr-1:%p", msgInterface);
				//----2.调用----
				msgInterface->msgOrderManager->terminalInit();
				//----3.处理----
				//msgInterface->result = result;
				break;
			}

			return 1;
			}

		}
		return CallNextHookEx(qHGame, code, wParam, lParam);
	}
}







