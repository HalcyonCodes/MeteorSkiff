

#include "SystemSkillController.h"

#include "pch.h"
#include "framework.h"
#include "MsgInterface.h" //������message�Ľӿ�

#include <WinUser.h>
#include "GetHwndByPID.h"
#include "BotSkills.h"

//SS001 sleep
std::string msgGetClipboardText() {

	MsgSystem msgInterface;
	
	LRESULT result = SendMessageA(getCurrentHwnd(), botMsgCode, ss001, (LPARAM)&msgInterface);
	return msgInterface.clipBoardtext;
}


