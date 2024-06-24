#include "pch.h"
#include "Windows.h"
#include "OrderManagerBot.h"


DWORD WINAPI orderManagerCtrlThread(LPVOID lpParam)
{	OrderManagerBot bot;
	bot.botInit();
	bot.botRun();
	return 0;
}