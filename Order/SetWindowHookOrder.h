#pragma once

#pragma comment(lib,"user32.lib")
#include "windows.h"

extern HHOOK qHGame;

extern HWND orderManagerHwnd;

DWORD hookOrderThread(HWND hwnd);
DWORD unHookOrderThread();