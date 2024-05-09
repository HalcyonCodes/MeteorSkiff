#pragma once
#include "pch.h"
#pragma comment(lib,"user32.lib")
#include "windows.h"

//这里定义msg消息

//====定义一个消息====
#define botMsgCode WM_USER + 1234
//进程间通信调试用消息
#define acceptMsgCode WM_USER + 4321
//====定义回调函数====

//====定义功能模块====
//测试 0
#define msgTest1 0  //测试
#define msgTest2 1  //测试2
#define msgTest3 3  //测试3



//----0.识图模块----
#define bm001 10
#define bm002 11
#define bm003 12
#define bm004 13
#define bm005 14
#define bm006 15
#define bm007 16
#define bm008 17
#define bm009 18
#define bm010 19
#define bm011 110
#define bm012 111
#define bm013 112
#define bm014 113
#define bm015 114
#define bm016 115 
#define bm017 116
#define bm018 117
#define bm019 118

//----1.截图模块----
#define ge001 20

//----2.模拟键鼠输入模块----
#define in001 30


//----钩子函数----
extern LRESULT CALLBACK actionsProc(int code, WPARAM wParam, LPARAM lParam);



