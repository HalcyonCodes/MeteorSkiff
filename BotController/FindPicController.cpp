
//这里是向线程发送message消息的函数

#include "pch.h"
#include "framework.h"
#include "MsgInterface.h" //定义了message的接口

#include <WinUser.h>
#include "GetHwndByPID.h"
#include "BotSkills.h"
#include "SetWindowHook.h"
#include "DbgPrint.h"

//====bmp001 loadBmp====
int msgLoadBmp(const char* paths) {
	MsgLoadPic msgInterface; //存放返回值，这里没有new，所以不需要释放内存
	msgInterface.picPath = new char[strlen(paths) + 1];
	strcpy_s(msgInterface.picPath, strlen(paths) + 1, paths);
	LRESULT result = SendMessageA(botHwnd, botMsgCode, bm001, (LPARAM)&msgInterface);
	delete[] msgInterface.picPath;
	return 0;
}

//====bmp002 loadBmpSub====
int msgLoadBmpSub(const char* paths) {
	MsgLoadPic msgInterface;
	msgInterface.picPath = new char[strlen(paths) + 1];
	strcpy_s(msgInterface.picPath, strlen(paths) + 1, paths);
	LRESULT result = SendMessageA(botHwnd, botMsgCode, bm002, (LPARAM)&msgInterface);
	delete[] msgInterface.picPath;
	return 0;
}

//====bmp003 loadBmpList====
int msgLoadBmpList(const char* paths) {
	MsgLoadPic msgInterface;
	msgInterface.picPath = new char[strlen(paths) + 1];
	strcpy_s(msgInterface.picPath, strlen(paths) + 1, paths);
	LRESULT result = SendMessageA(botHwnd, botMsgCode, bm003, (LPARAM)&msgInterface);
	delete[] msgInterface.picPath;
	return 0;
}

//====bmp004 freeBmp====
int msgFreeBmp() {
	MsgLoadPic msgInterface;
	LRESULT result = SendMessageA(botHwnd, botMsgCode, bm004, (LPARAM)&msgInterface);
	return 0;
}


//====bmp005 findPAPicA====
int* msgFindPAPicA(HWND hwnd, int left, int top, int right, int bottom, const char* path, int similar) {
	MsgFindPicA msgInterface;
	msgInterface.picPath = new char[strlen(path) + 1];
	strcpy_s(msgInterface.picPath, strlen(path) + 1, path);
	msgInterface.left = left;
	msgInterface.top = top;
	msgInterface.right = right;
	msgInterface.bottom = bottom;
	msgInterface.similar = similar;
	HWND h = getCurrentHwnd();
	LRESULT result = SendMessageA(botHwnd, botMsgCode, bm005, (LPARAM)&msgInterface);
	delete[] msgInterface.picPath;
	return msgInterface.result;
}

//====bmp006 findDAPicA====
int* msgFindDAPicA(HWND hwnd, int left, int top, int right, int bottom, const char* name, int similar) {
	MsgFindPicA msgInterface;
	msgInterface.picName = new char[strlen(name) + 1];
	strcpy_s(msgInterface.picName, strlen(name) + 1, name);
	msgInterface.left = left;
	msgInterface.top = top;
	msgInterface.right = right;
	msgInterface.bottom = bottom;
	msgInterface.similar = similar;
	LRESULT result = SendMessageA(botHwnd, botMsgCode, bm006, (LPARAM)&msgInterface);
	delete[] msgInterface.picName;
	return msgInterface.result;
}

//====bmp007 findSAPicA====
int* msgFindSAPicA(HWND hwnd, int left, int top, int right, int bottom, const char* name, int similar) {
	MsgFindPicA msgInterface;
	msgInterface.picName = new char[strlen(name) + 1];
	strcpy_s(msgInterface.picName, strlen(name) + 1, name);
	msgInterface.left = left;
	msgInterface.top = top;
	msgInterface.right = right;
	msgInterface.bottom = bottom;
	msgInterface.similar = similar;
	LRESULT result = SendMessageA(botHwnd, botMsgCode, bm007, (LPARAM)&msgInterface);
	delete[] msgInterface.picName;
	return msgInterface.result;
}

//====bmp008 findPAPicN====
int** msgFindPAPicN(HWND hwnd, int left, int top, int right, int bottom, const char* path, int similar) {
	MsgFindPicN msgInterface; 
	msgInterface.picPath = new char[strlen(path) + 1];
	strcpy_s(msgInterface.picPath, strlen(path) + 1, path);
	msgInterface.left = left;
	msgInterface.top = top;
	msgInterface.right = right;
	msgInterface.bottom = bottom;
	msgInterface.similar = similar;
	LRESULT result = SendMessageA(botHwnd, botMsgCode, bm008, (LPARAM)&msgInterface);
	delete[] msgInterface.picPath;
	return msgInterface.result;
}

//====bmp009 findDAPicN====
int** msgFindDAPicN(HWND hwnd, int left, int top, int right, int bottom, const char* name, int similar){
	MsgFindPicN msgInterface;
	msgInterface.picName = new char[strlen(name) + 1];
	strcpy_s(msgInterface.picName, strlen(name) + 1, name);
	msgInterface.left = left;
	msgInterface.top = top;
	msgInterface.right = right;
	msgInterface.bottom = bottom;
	msgInterface.similar = similar;
	LRESULT result = SendMessageA(botHwnd, botMsgCode, bm009, (LPARAM)&msgInterface);
	delete[] msgInterface.picName;
	return msgInterface.result;
}

//====bmp010 findSAPicN====
int** msgFindSAPicN(HWND hwnd, int left, int top, int right, int bottom, const char* name, int similar) {
	MsgFindPicN msgInterface;
	msgInterface.picName = new char[strlen(name) + 1];
	strcpy_s(msgInterface.picName, strlen(name) + 1, name);
	msgInterface.left = left;
	msgInterface.top = top;
	msgInterface.right = right;
	msgInterface.bottom = bottom;
	msgInterface.similar = similar;
	LRESULT result = SendMessageA(botHwnd, botMsgCode, bm010, (LPARAM)&msgInterface);
	delete[] msgInterface.picName;
	return msgInterface.result;
}

//====bmp011 findLNPicA====
int* msgFindLNPicA(HWND hwnd, int left, int top, int right, int bottom, int similar) {
	MsgFindPicA msgInterface;
	msgInterface.left = left;
	msgInterface.top = top;
	msgInterface.right = right;
	msgInterface.bottom = bottom;
	msgInterface.similar = similar;
	LRESULT result = SendMessageA(botHwnd, botMsgCode, bm011, (LPARAM)&msgInterface);
	return msgInterface.result;
}

//====bmp012 findLNPicN====
int** msgFindLNPicN(HWND hwnd, int left, int top, int right, int bottom, int similar) {
	MsgFindPicN msgInterface;
	msgInterface.left = left;
	msgInterface.top = top;
	msgInterface.right = right;
	msgInterface.bottom = bottom;
	msgInterface.similar = similar;
	LRESULT result = SendMessageA(botHwnd, botMsgCode, bm012, (LPARAM)&msgInterface);
	return msgInterface.result;
}










