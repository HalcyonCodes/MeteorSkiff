
#include "pch.h"
#include <wtypes.h>
#include "DbgPrint.h"
#include "MsgInterface.h"
#include "BmpColor.h"
#include "GetScreen.h"
#include "BotSkills.h"
#include "SetWindowHook.h"



LRESULT CALLBACK actionsProc(int code, WPARAM wParam, LPARAM lParam) {
	CWPSTRUCT* lpArg = (CWPSTRUCT*)lParam;
	if (code == HC_ACTION) {
		if (lpArg->message == botMsgCode) {
			switch (lpArg->wParam) {
				//这里添加各种机器人动作
			case msgTest1: {
				//----------------测试----------------------
				dbgPrint("开始测试");
			}

			//====机器人====
			case bm001: {
				//bm001
				//----1.处理参数----
				MsgLoadPic* msgInterface = static_cast<MsgLoadPic*>((void*)(lpArg->lParam));
				//memset(msgInterface->name, 0x00, 512);
				//dbgPrint("addr-1:%p", msgInterface);
				//----2.调用----
				BmpColor* bmpColor = new BmpColor();
				bmpColor->loadBmp(msgInterface->picPath);
				//----3.处理----
				msgInterface->result = bmpColor->result;
				delete(bmpColor);
				break;
			}
			case bm002: {
				//bm002
				//----1.处理参数----
				MsgLoadPic* msgInterface = static_cast<MsgLoadPic*>((void*)(lpArg->lParam));
				//memset(msgInterface->name, 0x00, 512);
				//dbgPrint("addr-1:%p", msgInterface);
				//----2.调用----
				BmpColor* bmpColor = new BmpColor();
				bmpColor->loadBmpSub(msgInterface->picPath);
				//----3.处理----
				msgInterface->result = bmpColor->result;
				delete(bmpColor);
				break;
			}
			case bm003: {
				//bm003
				//----1.处理参数----
				MsgLoadPic* msgInterface = static_cast<MsgLoadPic*>((void*)(lpArg->lParam));
				//memset(msgInterface->name, 0x00, 512);
				//dbgPrint("addr-1:%p", msgInterface);
				//----2.调用----
				BmpColor* bmpColor = new BmpColor();
				bmpColor->loadBmpList(msgInterface->picPath);
				//----3.处理----
				msgInterface->result = bmpColor->result;
				delete(bmpColor);
				break;
			}
			case bm004: {
				//bm004
				//----1.处理参数----
				MsgLoadPic* msgInterface = static_cast<MsgLoadPic*>((void*)(lpArg->lParam));
				//memset(msgInterface->name, 0x00, 512);
				//dbgPrint("addr-1:%p", msgInterface);
				//----2.调用----
				BmpColor* bmpColor = new BmpColor();
				bmpColor->freeBmp();
				//----3.处理----
				delete(bmpColor);
				break;
			}
			case bm005: {
				//bm005
				//----1.处理参数----
				MsgFindPicA* msgInterface = static_cast<MsgFindPicA*>((void*)(lpArg->lParam));
				//memset(msgInterface->name, 0x00, 512);
				//dbgPrint("addr-1:%p", msgInterface);
				//----2.调用----
				BmpColor* bmpColor = new BmpColor();
				bmpColor->findPAPicA(
					msgInterface->hwnd, msgInterface->left, msgInterface->top, msgInterface->right, msgInterface->bottom,
					msgInterface->picPath, msgInterface->similar
				);
				msgInterface->result = new int[2];
				memcpy_s(msgInterface->result, sizeof(bmpColor->resultA), bmpColor->resultA, sizeof(bmpColor->resultA));
				//----3.处理----
				delete[] bmpColor->resultA;
				delete(bmpColor);
				break;
			}
			case bm006: {
				//bm006
				//----1.处理参数----
				MsgFindPicA* msgInterface = static_cast<MsgFindPicA*>((void*)(lpArg->lParam));
				//memset(msgInterface->name, 0x00, 512);
				//dbgPrint("addr-1:%p", msgInterface);
				//----2.调用----
				BmpColor* bmpColor = new BmpColor();
				bmpColor->findDAPicA(
					msgInterface->hwnd, msgInterface->left, msgInterface->top, msgInterface->right, msgInterface->bottom,
					msgInterface->picName, msgInterface->similar
				);
				msgInterface->result = new int[2];
				memcpy_s(msgInterface->result, sizeof(bmpColor->resultA), bmpColor->resultA, sizeof(bmpColor->resultA));
				//----3.处理----
				delete[] bmpColor->resultA;
				delete(bmpColor);
				break;
			}
			case bm007: {
				//bm007
				//----1.处理参数----
				MsgFindPicA* msgInterface = static_cast<MsgFindPicA*>((void*)(lpArg->lParam));
				//memset(msgInterface->name, 0x00, 512);
				//dbgPrint("addr-1:%p", msgInterface);
				//----2.调用----
				BmpColor* bmpColor = new BmpColor();
				bmpColor->findSAPicA(
					msgInterface->hwnd, msgInterface->left, msgInterface->top, msgInterface->right, msgInterface->bottom,
					msgInterface->picName, msgInterface->similar
				);
				msgInterface->result = new int[2];
				memcpy_s(msgInterface->result, sizeof(bmpColor->resultA), bmpColor->resultA, sizeof(bmpColor->resultA));
				//----3.处理----
				delete[] bmpColor->resultA;
				delete(bmpColor);
				break;
			}
			case bm008: {
				//bm008
				//----1.处理参数----
				MsgFindPicN* msgInterface = static_cast<MsgFindPicN*>((void*)(lpArg->lParam));
				//memset(msgInterface->name, 0x00, 512);
				//dbgPrint("addr-1:%p", msgInterface);
				//----2.调用----
				BmpColor* bmpColor = new BmpColor();
				bmpColor->findPAPicN(
					msgInterface->hwnd, msgInterface->left, msgInterface->top, msgInterface->right, msgInterface->bottom,
					msgInterface->picPath, msgInterface->similar
				);
				msgInterface->resultLength = bmpColor->resultNLengthA;
				msgInterface->result = new int* [bmpColor->resultNLengthA];
				for (int i = 0; i < bmpColor->resultNLengthA; i++) {
					msgInterface->result[i] = new int[2];
					msgInterface->result[i][0] = bmpColor->resultN[i][0];
					msgInterface->result[i][1] = bmpColor->resultN[i][1];
				}	
				//----3.处理----
				for (int i = 0; i < bmpColor->resultNLengthA; i++) {
					delete[] bmpColor->resultN[i];
				}
				delete[] bmpColor->resultN;
				delete(bmpColor);
				break;
			}
			case bm009: {
				//bm009
				//----1.处理参数----
				MsgFindPicN* msgInterface = static_cast<MsgFindPicN*>((void*)(lpArg->lParam));
				//memset(msgInterface->name, 0x00, 512);
				//dbgPrint("addr-1:%p", msgInterface);
				//----2.调用----
				BmpColor* bmpColor = new BmpColor();
				bmpColor->findDAPicN(
					msgInterface->hwnd, msgInterface->left, msgInterface->top, msgInterface->right, msgInterface->bottom,
					msgInterface->picName, msgInterface->similar
				);
				msgInterface->resultLength = bmpColor->resultNLengthA;
				msgInterface->result = new int* [bmpColor->resultNLengthA];
				for (int i = 0; i < bmpColor->resultNLengthA; i++) {
					msgInterface->result[i] = new int[2];
					msgInterface->result[i][0] = bmpColor->resultN[i][0];
					msgInterface->result[i][1] = bmpColor->resultN[i][1];
				}

				//memcpy_s(msgInterface->result, sizeof(bmpColor->resultN), bmpColor->resultN, sizeof(bmpColor->resultN));
				//----3.处理----
				for (int i = 0; i < bmpColor->resultNLengthA; i++) {
					delete[] bmpColor->resultN[i];
				}
				delete[] bmpColor->resultN;
				delete(bmpColor);
				break;
			}
			case bm010: {
				//bm010
				//----1.处理参数----
				MsgFindPicN* msgInterface = static_cast<MsgFindPicN*>((void*)(lpArg->lParam));
				//memset(msgInterface->name, 0x00, 512);
				//dbgPrint("addr-1:%p", msgInterface);
				//----2.调用----
				BmpColor* bmpColor = new BmpColor();
				bmpColor->findSAPicN(
					msgInterface->hwnd, msgInterface->left, msgInterface->top, msgInterface->right, msgInterface->bottom,
					msgInterface->picName, msgInterface->similar
				);
				msgInterface->resultLength = bmpColor->resultNLengthA;
				msgInterface->result = new int* [bmpColor->resultNLengthA];
				for (int i = 0; i < bmpColor->resultNLengthA; i++) {
					msgInterface->result[i] = new int[2];
					msgInterface->result[i][0] = bmpColor->resultN[i][0];
					msgInterface->result[i][1] = bmpColor->resultN[i][1];
				}
				//memcpy_s(msgInterface->result, sizeof(bmpColor->resultN), bmpColor->resultN, sizeof(bmpColor->resultN));
				//----3.处理----
				for (int i = 0; i < bmpColor->resultNLengthA; i++) {
					delete[] bmpColor->resultN[i];
				}
				delete[] bmpColor->resultN;
				delete(bmpColor);
				break;
			}
			case bm011: {
				//bm011
				//----1.处理参数----
				MsgFindPicA* msgInterface = static_cast<MsgFindPicA*>((void*)(lpArg->lParam));
				//memset(msgInterface->name, 0x00, 512);
				//dbgPrint("addr-1:%p", msgInterface);
				//----2.调用----
				BmpColor* bmpColor = new BmpColor();
				bmpColor->findLNPicA(
					msgInterface->hwnd, msgInterface->left, msgInterface->top, msgInterface->right, msgInterface->bottom,
					msgInterface->similar
				);
				msgInterface->result = new int[3];
				//memcpy_s(msgInterface->result, sizeof(bmpColor->resultA), bmpColor->resultA, sizeof(bmpColor->resultA));
				msgInterface->result[0] = bmpColor->resultA[0];
				msgInterface->result[1] = bmpColor->resultA[1];
				msgInterface->result[2] = bmpColor->resultA[2];
				//----3.处理----
				delete[] bmpColor->resultA;
				delete(bmpColor);
				break;
			}
			case bm012: {
				//bm012
				//----1.处理参数----
				MsgFindPicN* msgInterface = static_cast<MsgFindPicN*>((void*)(lpArg->lParam));
				//memset(msgInterface->name, 0x00, 512);
				//dbgPrint("addr-1:%p", msgInterface);
				//----2.调用----
				BmpColor* bmpColor = new BmpColor();
				bmpColor->findLNPicN(
					msgInterface->hwnd, msgInterface->left, msgInterface->top, msgInterface->right, msgInterface->bottom,
					msgInterface->similar
				);
				msgInterface->resultLength = bmpColor->resultNLengthA;
		
				msgInterface->result = new int* [bmpColor->resultNLengthA];
				for (int i = 0; i < bmpColor->resultNLengthA; i++) {
					msgInterface->result[i] = new int[3];
					msgInterface->result[i][0] = bmpColor->resultN[i][0];
					msgInterface->result[i][1] = bmpColor->resultN[i][1];
					msgInterface->result[i][2] = bmpColor->resultN[i][2];
				}
				//memcpy_s(msgInterface->result, sizeof(bmpColor->resultN), bmpColor->resultN, sizeof(bmpColor->resultN));
				//----3.处理----
				for (int i = 0; i < bmpColor->resultNLengthA; i++) {
					delete[] bmpColor->resultN[i];
				}
				delete[] bmpColor->resultN;
				delete(bmpColor);
				break;
			}


			}
			return 1;
		}
	}
	return CallNextHookEx(tHGame, code, wParam, lParam);
}

