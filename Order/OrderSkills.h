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
#define or001 5555510
#define or002 5555511





extern LRESULT CALLBACK orderProc(int code, WPARAM wParam, LPARAM lParam);