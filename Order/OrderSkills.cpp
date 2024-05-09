
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
				//������Ӹ��ֻ����˶���
			case msgOrderTest1: {
				//----------------����----------------------
				dbgPrint("��ʼ����");
			}

							  //====�������������====
							  //====or 001 popServerOrder===
			case or001: {
				//bm001
				//----1.�������----
				MsgPopOrder* msgInterface = static_cast<MsgPopOrder*>((void*)(lpArg->lParam));
				//memset(msgInterface->name, 0x00, 512);
				//dbgPrint("addr-1:%p", msgInterface);
				//----2.����----
				string order = msgInterface->orderManager->popServerOrder();
				//----3.����----
				msgInterface->order = order;
				break;
			}
					  //====or 002 sendOrderStatus====
			case or002: {
				//bm001
				//----1.�������----
				MsgSendOrderStatus* msgInterface = static_cast<MsgSendOrderStatus*>((void*)(lpArg->lParam));
				//memset(msgInterface->name, 0x00, 512);
				//dbgPrint("addr-1:%p", msgInterface);
				//----2.����----
				const char* orderId = msgInterface->orderId.c_str();
				const char* orderStatus = msgInterface->orderStatus.c_str();
				int result = msgInterface->orderManager->sendOrderStatus(orderId, orderStatus);
				//----3.����----
				msgInterface->result = result;
				break;
			}


					  return 1;
			}
		}
		return CallNextHookEx(qHGame, code, wParam, lParam);
	}
}







