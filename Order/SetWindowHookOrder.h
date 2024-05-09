#pragma once

#pragma comment(lib,"user32.lib")
#include "windows.h"

extern HHOOK qHGame;


DWORD hookOrderThread();
DWORD unHookOrderThread();