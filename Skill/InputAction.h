#pragma once


#include "windows.h"
#include <string>

using namespace std;



typedef struct InputAction {

	//��ʼ������
	void init(const char* gameName);

	// �������
	int lClickDown(int time);

	//�����Ҽ�
	int rClickDown(int time);

	//�����м�
	int mClickDown(int time);

	//�������
	int lClickUp();

	//�����Ҽ�
	int rClickUp();

	//�����м�
	int mClickUp();

	//�ƶ����
	int moveTo(int x, int y);

	// ��ԭ����������ϵ����ƶ����
	int moveToChange(int x, int y);

	// ����м�
	int mOnClick();

	// ������
	int lOnClick();

	// ����Ҽ�
	int rOnClick();

	// ���¼���
	int keyDown(short key, int time);

	// ��������
	int keyUp(short key);

	// ����һ��
	int keyPress(short key);

}_InputAction;
