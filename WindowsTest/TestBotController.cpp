

#include "setWindowHook.h"
#include "FindPicController.h"
#include "GetScreenController.h"
#include "DbgPrint.h"
#include "GetHwndByPID.h"
#include "MsgInterface.h"
#include "BotSkills.h"
#include "TestBotController.h"

HWND hwndHidden;

#pragma comment(lib,"user32.lib")


//====控制机器人的线程====
void testBotController() {

	//====ges001 findWindow====
	//HWND hwnd = msgFindWindow("Chrome_WidgetWin_1", "广发操盘手");
	//dbgPrint("HWND:%d", hwnd);

	//====bmp001 loadBmp====
	msgLoadBmp("C:\\Users\\reddock\\Desktop\\BMPTEST\\testFincPic1.bmp|C:\\Users\\reddock\\Desktop\\BMPTEST\\testFincPic2.bmp");

	//====bmp002 loadBmpSub====
	msgLoadBmpSub("C:\\Users\\reddock\\Desktop\\BMPTEST\\testFincPic1.bmp|C:\\Users\\reddock\\Desktop\\BMPTEST\\testFincPic2.bmp");

	//====bmp003 loadBmpList====
	msgLoadBmpList("C:\\Users\\reddock\\Desktop\\BMPTEST\\testFincPic1.bmp|C:\\Users\\reddock\\Desktop\\BMPTEST\\testFincPic2.bmp");

	//====bmp004 freeBmp====
	//msgFreeBmp();

	//====bmp005 findPAPicA====
	/*while (true)
	{
	  int* r = msgFindPAPicA(nullptr, 0, 0, 1920, 1024, "C:\\Users\\reddock\\Desktop\\BMPTEST\\testFincPic1.bmp", 52);
	  if (r != nullptr) {
		  dbgPrint("====x:%d====", r[0]);
		  dbgPrint("====y:%d====", r[1]);
	  }
	}*/

	//====bmp006 findDAPicA====
	/*while (true) {
		int* r = msgFindDAPicA(nullptr, 0, 0, 1920, 1024, "testFincPic1", 32);
		if (r != nullptr) {
			dbgPrint("====x:%d====", r[0]);
			dbgPrint("====y:%d====", r[1]);
		}
	}*/

	//====bmp007 findSAPicA====
	/*while (true) {
		int* r = msgFindSAPicA(nullptr, 0, 0, 1920, 1024, "testFincPic1", 32);
		if (r != nullptr) {
			dbgPrint("====x:%d====", r[0]);
			dbgPrint("====y:%d====", r[1]);
		}
	}*/

	//====bmp008 findPAPicN====
	/*while (true) {
		int** r = msgFindPAPicN(nullptr, 0, 0, 1024, 1920, "C:\\Users\\reddock\\Desktop\\BMPTEST\\testFincPic1.bmp", 32);
		dbgPrint("===x1: %d===", r[0][0]);
		dbgPrint("===y1: %d===", r[0][1]);
		dbgPrint("===x2: %d===", r[1][0]);
		dbgPrint("===y2: %d===", r[1][1]);
		int i = 0;
		while (true) {
			int q = r[i][0];
			delete[] r[i];
			i++;
			if (q == -1) {
				break;
			}
		};
		delete[] r;
	}*/
	

	//====bmp009 findDAPicN====
	//int** msgFindDAPicN(HWND hwnd, int left, int top, int right, int bottom, const char* name, int similar);
	/*while (true) {
		int** r = msgFindDAPicN(nullptr, 0, 0, 1024, 1920, "testFincPic1", 32);
		dbgPrint("===x1: %d===", r[0][0]);
		dbgPrint("===y1: %d===", r[0][1]);
		dbgPrint("===x2: %d===", r[1][0]);
		dbgPrint("===y2: %d===", r[1][1]);
		int i = 0;
		while (true) {
			int q = r[i][0];
			delete[] r[i];
			i++;
			if (q == -1) {
				break;
			}
		};
		delete[] r;
	}*/

	//====bmp010 findSAPicN====
	//int** msgFindSAPicN(HWND hwnd, int left, int top, int right, int bottom, const char* name, int similar);
	/*while (true) {
		int** r = msgFindSAPicN(nullptr, 0, 0, 1920, 1024, "testFincPic1", 32);
		dbgPrint("===x1: %d===", r[0][0]);
		dbgPrint("===y1: %d===", r[0][1]);
		dbgPrint("===x2: %d===", r[1][0]);
		dbgPrint("===y2: %d===", r[1][1]);
		int i = 0;
		while (true) {
			int q = r[i][0];
			delete[] r[i];
			i++;
			if (q == -1) {
				break;
			}
		};
		delete[] r;
	}*/

	//====bmp011 findLNPicA====
	//int* msgFindLNPicA(HWND hwnd, int left, int top, int right, int bottom, int similar);
	/*while (true) {
		int* r = msgFindLNPicA(nullptr, 0, 0, 1924, 1024, 32);
		dbgPrint("====x: %d====", r[0]);
		dbgPrint("====y: %d====", r[1]);
		dbgPrint("====index: %d====", r[2]);
		delete[] r;
	}*/

	//====bmp012 findLNPicN====
	//int** msgFindLNPicN(HWND hwnd, int left, int top, int right, int bottom, int similar);
	/*while (true) {
		int** r = msgFindLNPicN(nullptr, 0, 0, 1024, 1920, 32);
		dbgPrint("x: %d", r[0][0]);
		dbgPrint("y: %d", r[0][1]);
		dbgPrint("index: %d", r[0][2]);
		dbgPrint("\n");
		dbgPrint("x: %d", r[1][0]);
		dbgPrint("y: %d", r[1][1]);
		dbgPrint("index: %d", r[1][2]);
		dbgPrint("\n");
		dbgPrint("x: %d", r[2][0]);
		dbgPrint("y: %d", r[2][1]);
		dbgPrint("index: %d", r[2][2]);
		dbgPrint("\n");
		dbgPrint("x: %d", r[3][0]);
		dbgPrint("y: %d", r[3][1]);
		dbgPrint("index: %d", r[3][2]);
		dbgPrint("\n");
		int i = 0;
		while (true) {
			int q = r[i][0];
			delete[] r[i];
			i++;
			if (q == -1) {
				break;
			}
		};
		delete[] r;

	}*/
    //====msg测试通过：2024/5/9====

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	int a;

}

