#pragma once


#include "Windows.h"
#include <string>

using namespace std;

//====ss001 setClipBoardText
void msgSetClipBoardText(string text);

//====ss002 GetClipBoardText
string msgGetClipBoardText();

//====ss003 pasteClipBoardText
void msgPasteClipBoardText();
