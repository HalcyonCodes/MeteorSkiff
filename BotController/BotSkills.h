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
#define in002 31
#define in003 32
#define in004 33
#define in005 34
#define in006 35
#define in007 36
#define in008 37
#define in009 38
#define in010 39
#define in011 40
#define in012 41
#define in013 42
#define in014 43
#define in015 44

//----3,订单模块----
#define or001 200
#define or002 201

//----4.系统模块----
#define ss001 300
#define ss002 301
#define ss003 302



//----钩子函数----
extern LRESULT CALLBACK actionsProc(int code, WPARAM wParam, LPARAM lParam);



