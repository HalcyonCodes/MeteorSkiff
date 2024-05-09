
#include "pch.h"
#include <wtypes.h>
#include "DbgPrint.h"

#include "SetWindowHookOrder.h"
#include "OrderSkills.h"
#include "OrderMsgInterface.h"
#include <string>

using namespace std;

LRESULT CALLBACK orderProc(int code, WPARAM wParam, LPARAM lParam) {
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
							  //====or 001 popServerOrder===
			case or001: {
				//bm001
				//----1.处理参数----
				MsgPopOrder* msgInterface = static_cast<MsgPopOrder*>((void*)(lpArg->lParam));
				//memset(msgInterface->name, 0x00, 512);
				//dbgPrint("addr-1:%p", msgInterface);
				//----2.调用----
				string order = msgInterface->orderManager->popServerOrder();
				//----3.处理----
				msgInterface->order = order;
				break;
			}
					  //====or 002 sendOrderStatus====
			case or002: {
				//bm001
				//----1.处理参数----
				MsgSendOrderStatus* msgInterface = static_cast<MsgSendOrderStatus*>((void*)(lpArg->lParam));
				//memset(msgInterface->name, 0x00, 512);
				//dbgPrint("addr-1:%p", msgInterface);
				//----2.调用----
				const char* orderId = msgInterface->orderId.c_str();
				const char* orderStatus = msgInterface->orderStatus.c_str();
				int result = msgInterface->orderManager->sendOrderStatus(orderId, orderStatus);
				//----3.处理----
				msgInterface->result = result;
				break;
			}


					  return 1;
			}
		}
		return CallNextHookEx(qHGame, code, wParam, lParam);
	}
}







