#pragma once
#include "Windows.h"

//���ﶨ��msg��Ϣ


//====����һ����Ϣ====
#define orderMsgCode WM_USER + 1235
//���̼�ͨ�ŵ�������Ϣ
//#define acceptMsgCode WM_USER + 4321
//====����ص�����====


//====���幦��ģ��====
//��������ǰ�����55555
//���� 0
#define msgOrderTest1 555550  //����


//----Order������----
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

