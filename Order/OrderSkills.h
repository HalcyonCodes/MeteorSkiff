#pragma once
#include "Windows.h"

//这里定义msg消息


//====定义一个消息====
#define orderMsgCode WM_USER + 1235
//进程间通信调试用消息
//#define acceptMsgCode WM_USER + 4321
//====定义回调函数====


//====定义功能模块====
//所有数字前面加上55555
//测试 0
#define msgOrderTest1 555550  //测试


//----Order处理函数----
#define or000 5555509
#define or001 5555510
#define or002 5555511
#define or003 5555512
#define or004 5555513
#define or005 5555514
#define or006 5555515
#define or007 5555516
#define or008 5555517





extern LRESULT CALLBACK orderProc(int code, WPARAM wParam, LPARAM lParam);

