#pragma once
#include "Windows.h"


//������msg�ķ���ֵ

//BM000 - BM003
typedef struct MsgLoadPic {
	char* picPath;
	int result;
}_MsgLoadPic;

//BM005 - BM007 | BM011
typedef struct MsgFindPicA {
	HWND hwnd;
	int top;
	int left;
	int right;
	int bottom;
	int similar;
	char* picName;
	char* picPath;
	int* result;

}_MsgFindPicA;


//BM008 - BM010 | BM012
typedef struct MsgFindPicN {
	HWND hwnd;
	int top;
	int left;
	int right;
	int bottom;
	int similar;
	char* picName;
	char* picPath;
	int** result;
	int resultLength; //result��1ά����Ĵ�С
}_MsgFindPicN;

//=========
//GE001 
typedef struct MsgFindWindow {
	HWND hwnd;
	char* className;
	char* windowName;
}_MsgFindWindow;

//==========
//IM001-IM015
typedef struct MsgInput {
	char* windowName = nullptr;
	short key;
	int time;
	int mouseX;
	int mouseY;
	int result;
}_MsgInput;




