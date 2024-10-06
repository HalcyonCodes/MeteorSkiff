#pragma once

//存放被封装的Input的lua函数


#include "Windows.h"
#include <String>

using namespace std;

//====ins001 inputInit====
void msgInputInit(const char* windowName);

//====ins002  lClickDown====
int msgLClickDown(int time);

//====ins003 rClickDown====
int msgRClickDown(int time);

//====ins004 mClickDown====
int msgMClickDown(int time);

//====ins005 lClickUp====
int msgLClickUp();

//====ins006 lClickUp====
int msgRClickUp();

//====ins007 mClickUp====
int msgMClickUp();

//====ins008 moveTo====
int msgMoveTo(int x, int y);

//====ins009 moveToChange====
int msgMoveToChange(int x, int y);

//====ins010 mOnClick====
int msgMOnClick();

//====ins011 lOnClick====
int msgLOnClick();

//====ins012 rOnClick====
int msgROnClick();

//====ins013 keyDown====
int msgKeyDown(short key, int time);

//====ins014 keyUp====
int msgKeyUp(short key);

//====ins015 keyPress====
int msgKeyPress(short key);

//====ins016 sendString====
void msgSendString(string inputString);

//====ins017 sendStringToClipboard
void msgSendStringToClipboard(string string);

//====ins018 readStringFromClipboard
string msgReadStringFromClipboard();

