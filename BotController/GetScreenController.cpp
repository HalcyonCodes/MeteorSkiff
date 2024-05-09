//这里是向线程发送message消息的函数

#include "pch.h"
#include "framework.h"
#include "MsgInterface.h" //定义了message的接口

#include <WinUser.h>
#include "GetHwndByPID.h"
#include "BotSkills.h"

//====ges001 findWindow====
HWND msgFindWindow(const char* className, const char* windowName) {
	MsgFindWindow msgInterface;
	msgInterface.className = new char[strlen(className) + 1];
	msgInterface.windowName = new char[strlen(windowName) + 1];
	strcpy_s(msgInterface.className, strlen(className) + 1, className);
	strcpy_s(msgInterface.windowName, strlen(windowName) + 1, windowName);
	HWND t = getCurrentHwnd();
	int q = int(t);
	LRESULT result = SendMessageA(getCurrentHwnd(), botMsgCode, ge001, (LPARAM)&msgInterface);
	delete[] msgInterface.className;
	delete[] msgInterface.windowName;
	return msgInterface.hwnd;
}


