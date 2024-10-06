#include "pch.h"
#include "framework.h"
#include "MsgInterface.h" //定义了message的接口

#include <WinUser.h>
#include "GetHwndByPID.h"
#include "SetWindowHook.h"
#include "BotSkills.h"

//====ins001 inputInit====
void msgInputInit(const char* windowName) {
	MsgInput msgInterface;
	msgInterface.windowName = new char[strlen(windowName) + 1];
	strcpy_s(msgInterface.windowName, strlen(windowName) + 1, windowName);
	LRESULT result = SendMessageA(botHwnd, botMsgCode, in001, (LPARAM)&msgInterface);
	delete[] msgInterface.windowName;
	return;
}

//====ins002  lClickDown====
int msgLClickDown(int time) {
	MsgInput msgInterface;
	msgInterface.time = time;
	LRESULT result = SendMessageA(botHwnd, botMsgCode, in002, (LPARAM)&msgInterface);
	return msgInterface.result;
}


//====ins003 rClickDown====
int msgRClickDown(int time) {
	MsgInput msgInterface;
	msgInterface.time = time;
	LRESULT result = SendMessageA(botHwnd, botMsgCode, in003, (LPARAM)&msgInterface);
	return msgInterface.result;
}

//====ins004 mClickDown====
int msgMClickDown(int time) {
	MsgInput msgInterface;
	msgInterface.time = time;
	LRESULT result = SendMessageA(botHwnd, botMsgCode, in004, (LPARAM)&msgInterface);
	return msgInterface.result;
}


//====ins005 lClickUp====
int msgLClickUp() {
	MsgInput msgInterface;
	LRESULT result = SendMessageA(botHwnd, botMsgCode, in005, (LPARAM)&msgInterface);
	return msgInterface.result;
}

//====ins006 rClickUp====
int msgRClickUp() {
	MsgInput msgInterface;
	LRESULT result = SendMessageA(botHwnd, botMsgCode, in006, (LPARAM)&msgInterface);
	return msgInterface.result;
}

//====ins007 mClickUp====
int msgMClickUp() {
	MsgInput msgInterface;
	LRESULT result = SendMessageA(botHwnd, botMsgCode, in007, (LPARAM)&msgInterface);
	return msgInterface.result;
}

//====ins008 moveTo====
int msgMoveTo(int x, int y) {
	MsgInput msgInterface;
	msgInterface.mouseX = x;
	msgInterface.mouseY = y;
	LRESULT result = SendMessageA(botHwnd, botMsgCode, in008, (LPARAM)&msgInterface);
	return msgInterface.result;
}


//====ins009 moveToChange====
int msgMoveToChange(int x, int y) {
	MsgInput msgInterface;
	msgInterface.mouseX = x;
	msgInterface.mouseY = y;
	LRESULT result = SendMessageA(botHwnd, botMsgCode, in009, (LPARAM)&msgInterface);
	return msgInterface.result;
}


//====ins010 mOnClick====
int msgMOnClick() {
	MsgInput msgInterface;
	LRESULT result = SendMessageA(botHwnd, botMsgCode, in010, (LPARAM)&msgInterface);
	return msgInterface.result;
}

//====ins011 lOnClick====
int msgLOnClick() {
	MsgInput msgInterface;
	LRESULT result = SendMessageA(botHwnd, botMsgCode, in011, (LPARAM)&msgInterface);
	return msgInterface.result;
}

//====ins012 rOnClick====
int msgROnClick() {
	MsgInput msgInterface;
	LRESULT result = SendMessageA(botHwnd, botMsgCode, in012, (LPARAM)&msgInterface);
	return msgInterface.result;
}

//====ins013 keyDown====
int msgKeyDown(short key, int time) {
	MsgInput msgInterface;
	msgInterface.key = key;
	msgInterface.time = time;
	LRESULT result = SendMessageA(botHwnd, botMsgCode, in013, (LPARAM)&msgInterface);
	return msgInterface.result;
}

//====ins014 keyUp====
int msgKeyUp(short key) {
	MsgInput msgInterface;
	msgInterface.key = key;
	LRESULT result = SendMessageA(botHwnd, botMsgCode, in014, (LPARAM)&msgInterface);
	return msgInterface.result;
}

//====ins015 keyPress====
int msgKeyPress(short key) {
	MsgInput msgInterface;
	msgInterface.key = key;
	LRESULT result = SendMessageA(botHwnd, botMsgCode, in015, (LPARAM)&msgInterface);
	return msgInterface.result;
}

//====ins016 sendString
void msgSendString(string inputString) {
	MsgInput msgInterface;
	msgInterface.sendString = (char*)inputString.c_str();
	LRESULT result = SendMessageA(botHwnd, botMsgCode, in016, (LPARAM)&msgInterface);
	return;
}

//====ins017
void msgSendStringToClipboard(string inputString) {
	MsgInput msgInterface;
	msgInterface.sendString = (char*)inputString.c_str();
	LRESULT result = SendMessageA(botHwnd, botMsgCode, in017, (LPARAM)&msgInterface);
	return;
}


//====ins018
string msgReadStringFromClipboard() {
	MsgInput msgInterface;
	LRESULT result = SendMessageA(botHwnd, botMsgCode, in017, (LPARAM)&msgInterface);
	return msgInterface.resultString;
}
