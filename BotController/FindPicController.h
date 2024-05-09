#pragma once
#include "Windows.h"



//====bmp001 loadBmp====
int msgLoadBmp(const char* paths);

//====bmp002 loadBmpSub====
int msgLoadBmpSub(const char* paths);

//====bmp003 loadBmpList====
int msgLoadBmpList(const char* paths);

//====bmp004 freeBmp====
int msgFreeBmp();

//====bmp005 findPAPicA====
int* msgFindPAPicA(HWND hwnd, int left, int top, int right, int bottom, const char* path, int similar);

//====bmp006 findDAPicA====
int* msgFindDAPicA(HWND hwnd, int left, int top, int right, int bottom, const char* name, int similar);

//====bmp007 findSAPicA====
int* msgFindSAPicA(HWND hwnd, int left, int top, int right, int bottom, const char* name, int similar);

//====bmp008 findPAPicN====
int** msgFindPAPicN(HWND hwnd, int left, int top, int right, int bottom, const char* path, int similar);

//====bmp009 findDAPicN====
int** msgFindDAPicN(HWND hwnd, int left, int top, int right, int bottom, const char* name, int similar);

//====bmp010 findSAPicN====
int** msgFindSAPicN(HWND hwnd, int left, int top, int right, int bottom, const char* name, int similar);

//====bmp011 findLNPicA====
int* msgFindLNPicA(HWND hwnd, int left, int top, int right, int bottom, int similar);

//====bmp012 findLNPicN====
int** msgFindLNPicN(HWND hwnd, int left, int top, int right, int bottom, int similar);










