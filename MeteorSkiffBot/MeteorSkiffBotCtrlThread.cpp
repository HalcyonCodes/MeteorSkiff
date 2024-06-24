

#include "pch.h"
#include "Windows.h"
#include "MeteorSkiffBot.h"

DWORD WINAPI meteorSkiffCtrlThread(LPVOID lpParam){
	MeteorSkiffBot bot;
	bot.botInit();
	bot.botRun();
	return 0;
}
