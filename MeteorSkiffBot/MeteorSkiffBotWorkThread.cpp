#include "pch.h"
#include "Windows.h"
#include "SetWindowHook.h"
#include "OrderManager.h"
#include "MeteorSkiffBotWorkThread.h"

//===机器人所在线程====
DWORD WINAPI meteorSkiffBotWorkThread(LPVOID lpParam)
{
	// 实例句柄，通常传入NULL以使用当前实例
	HINSTANCE hInstance = (HINSTANCE)lpParam;

	// 注册窗口类
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = 0;
	wcex.lpfnWndProc = meteorSkiffBotWorkThreadWndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = "MeteorSkiffBotWorkThreadClass";
	wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&wcex))
	{
		// 处理错误
	}

	//创建一个没有窗口的窗口
	HWND hwnd = CreateWindow(
		"MeteorSkiffBotWorkThreadClass",
		"MeteorSkiffBotWorkThread",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL, hInstance, NULL);


	//====hookBot====
	hookBotThread(hwnd);


	//========

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;

}

LRESULT CALLBACK meteorSkiffBotWorkThreadWndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return DefWindowProc(hwnd, message, wParam, lParam);;
}


