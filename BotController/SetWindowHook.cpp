
#include "pch.h"
#include "DbgPrint.h"
#include <windows.h>
#include "SetWindowHook.h"
#include "BotSkills.h"
#include "framework.h"
#include <winnt.h>

#pragma comment(lib, "kernel32.lib")
#include "tlhelp32.h"
#define QWORD unsigned long long 

HWND botHwnd;

HHOOK tHGame;

DWORD hookBotThread(HWND hwnd) {

	if (tHGame != 0) {
		dbgPrint("已经有钩子");
		return 0;
	}

	botHwnd = hwnd;

	//获取主线程
	/*DWORD dThreadId = 0;
	THREADENTRY32 te32 = { sizeof(te32) };
	HANDLE hThreadSnap = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
	DWORD dProcessId = GetCurrentProcessId();
	if (Thread32First(hThreadSnap, &te32))
	{
		do {
			if (dProcessId == te32.th32OwnerProcessID)
			{
				dThreadId = te32.th32ThreadID;
				break;
			}
		} while (Thread32Next(hThreadSnap, &te32));
	}
	if (dThreadId == 0) {
		dbgPrint("获取主线程失败");
	}*/
	
	//int t = int(dThreadId);
	

	// 获取当前线程ID
	DWORD dThreadId = GetCurrentThreadId();
	//int t = int(dThreadId);

	HHOOK hGame = 0;

    hGame = SetWindowsHookExA(WH_CALLWNDPROC, actionsProc, NULL, GetCurrentThreadId());
	if (hGame != 0) {
		tHGame = hGame;
	}
	else
	{
		return 0;
	}
	dbgPrint("主线程hook完成");
	return 1;
}

DWORD unHookBotThread() {
	UnhookWindowsHookEx(tHGame);
	return 1;
}