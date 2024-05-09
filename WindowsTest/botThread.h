#pragma once

#include "Windows.h"


DWORD WINAPI testBotThread(LPVOID lpParam);


extern LRESULT CALLBACK qWndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

