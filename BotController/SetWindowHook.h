#pragma once

#pragma comment(lib,"user32.lib")
#include "windows.h"

extern  HHOOK tHGame;

extern HWND botHwnd;

DWORD hookBotThread(HWND hwnd);
DWORD unHookBotThread();