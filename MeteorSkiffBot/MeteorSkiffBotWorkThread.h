#pragma once


#pragma once

#include "Windows.h"


DWORD WINAPI meteorSkiffBotWorkThread(LPVOID lpParam);


extern LRESULT CALLBACK  meteorSkiffBotWorkThreadWndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

