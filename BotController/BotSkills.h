#pragma once
#include "pch.h"
#pragma comment(lib,"user32.lib")
#include "windows.h"

//���ﶨ��msg��Ϣ

//====����һ����Ϣ====
#define botMsgCode WM_USER + 1234
//���̼�ͨ�ŵ�������Ϣ
#define acceptMsgCode WM_USER + 4321
//====����ص�����====

//====���幦��ģ��====
//���� 0
#define msgTest1 0  //����
#define msgTest2 1  //����2
#define msgTest3 3  //����3



//----0.ʶͼģ��----
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

//----1.��ͼģ��----
#define ge001 20

//----2.ģ���������ģ��----
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

//----3,����ģ��----
#define or001 200
#define or002 201

//----4.ϵͳģ��----
#define ss001 300
#define ss002 301
#define ss003 302



//----���Ӻ���----
extern LRESULT CALLBACK actionsProc(int code, WPARAM wParam, LPARAM lParam);



