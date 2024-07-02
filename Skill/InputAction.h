#pragma once


#include "windows.h"
#include <string>

using namespace std;



typedef struct InputAction {

	//初始化窗口
	void init(const char* gameName);

	// 按紧左键
	int lClickDown(int time);

	//按紧右键
	int rClickDown(int time);

	//按紧中键
	int mClickDown(int time);

	//弹起左键
	int lClickUp();

	//弹起右键
	int rClickUp();

	//弹起中键
	int mClickUp();

	//移动鼠标
	int moveTo(int x, int y);

	// 在原本鼠标坐标上叠加移动鼠标
	int moveToChange(int x, int y);

	// 点击中键
	int mOnClick();

	// 点击左键
	int lOnClick();

	// 点击右键
	int rOnClick();

	// 按下键盘
	int keyDown(short key, int time);

	// 按键弹起
	int keyUp(short key);

	// 按键一次
	int keyPress(short key);

}_InputAction;
