#pragma once
#include "Windows.h"
#include <vector>
#include <string>

//这里存放msg的返回值

using namespace std;

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
	int resultLength; //result第1维数组的大小
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
	char* sendString = nullptr;
	string resultString;
	short key;
	int time;
	int mouseX;
	int mouseY;
	int result;
}_MsgInput;

//==========
//OR001-
typedef struct MsgOrder {
	int channelLevel;
	int serviceID;
	std::string targetID;
	std::vector<int> resourceID;
	std::vector<int> intVal;
	std::vector<std::string> stringVal;
	std::vector<double> doubleVal;
	int result;
} _MsgOrder;

//=========
//SS001-
typedef struct MsgSystem {
	string clipBoardtext;
	
};


