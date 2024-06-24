#include "pch.h"


#include "DbgPrint.h"
#include <windows.h>

#include "SetWindowHookOrder.h"
//#include "BotSkills.h"

#include "framework.h"

#include <winnt.h>
#pragma comment(lib, "kernel32.lib")
#include "tlhelp32.h"
#include "OrderSkills.h"

#define QWORD unsigned long long 

//#pragma comment(lib,"user32.lib")

HHOOK qHGame;

HWND orderManagerHwnd;

DWORD hookOrderThread(HWND hwnd) {

	if (qHGame != 0) {
		dbgPrint("�Ѿ��й���");
		return 0;
	}
	orderManagerHwnd = hwnd;

	// ��ȡ��ǰ�߳�ID
	DWORD dThreadId = GetCurrentThreadId();

	HHOOK hGame = 0;

	hGame = SetWindowsHookExA(WH_CALLWNDPROC, orderProc, NULL, dThreadId);
	if (hGame != 0) {
		qHGame = hGame;
	}
	else
	{
		return 0;
	}
	dbgPrint("���߳�hook���");
	return 1;
}

DWORD unHookOrderThread() {
	UnhookWindowsHookEx(qHGame);
	return 1;
}