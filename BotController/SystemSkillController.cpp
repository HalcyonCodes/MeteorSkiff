

#include "SystemSkillController.h"

#include "pch.h"
#include "framework.h"
#include "MsgInterface.h" //定义了message的接口

#include <WinUser.h>
#include "GetHwndByPID.h"
#include "BotSkills.h"


void msgSetClipBoardText(string text) {
	MsgSystem msgInterface;
	msgInterface.clipBoardText = text;
	LRESULT result = SendMessageA(getCurrentHwnd(), botMsgCode, ss001, (LPARAM)&msgInterface);
	return;
}

//====ss002 GetClipBoardText
string msgGetClipBoardText() {
	MsgSystem msgInterface;
	LRESULT result = SendMessageA(getCurrentHwnd(), botMsgCode, ss002, (LPARAM)&msgInterface);
	return msgInterface.clipBoardTextResult;
}

//====ss003 pasteClipBoardText
void msgPasteClipBoardText() {
	MsgSystem msgInterface;
	LRESULT result = SendMessageA(getCurrentHwnd(), botMsgCode, ss003, (LPARAM)&msgInterface);
	return;
}
