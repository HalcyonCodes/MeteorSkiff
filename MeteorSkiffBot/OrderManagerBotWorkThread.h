#pragma once


#pragma once

#include "Windows.h"


DWORD WINAPI orderManagerBotWorkThread(LPVOID lpParam);


extern LRESULT CALLBACK  orderManagerBotWorkThreadWndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

