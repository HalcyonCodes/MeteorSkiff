#pragma once

#include "pch.h"
#include "Windows.h"


BOOL CALLBACK enumWindowsProc(HWND hwnd, LPARAM lParam);


HWND getWindowHwndByPID(DWORD dwProcessID);

HWND getCurrentHwnd();


