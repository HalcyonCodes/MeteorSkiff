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


//----���Ӻ���----
extern LRESULT CALLBACK actionsProc(int code, WPARAM wParam, LPARAM lParam);


