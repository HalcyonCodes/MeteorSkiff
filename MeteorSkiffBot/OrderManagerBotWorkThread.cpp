
#include "pch.h"
#include "Windows.h"
#include "SetWindowHook.h"
#include "SetWindowHookOrder.h"
#include "OrderManager.h"
#include "OrderManagerBotWorkThread.h"
#include <mutex>
#include "OrderManagerBot.h"

//std::mutex h_mutex;

//===机器人所在线程====
DWORD WINAPI orderManagerBotWorkThread(LPVOID lpParam)
{
	//std::lock_guard<std::mutex> lock(h_mutex);
	// 实例句柄，通常传入NULL以使用当前实例
	HINSTANCE hInstance = (HINSTANCE)lpParam;

	// 注册窗口类
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = 0;
	wcex.lpfnWndProc = orderManagerBotWorkThreadWndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance; 
	wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = "OrderManagerWorkThreadClass";
	wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&wcex))
	{
		// 处理错误
	}

	//创建一个没有窗口的窗口
	HWND hwnd = CreateWindow(
		"OrderManagerWorkThreadClass",
		"OrderManagerWorkThread",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL, hInstance, NULL);


	//====hookOrderManager====
	orderManager = new OrderManager(); //在线程里实例化对象
	hookOrderThread(hwnd);

	//OrderManagerBot bot;
	//bot.botInit();
	//bot.botRun();

	//========

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;

}



LRESULT CALLBACK  orderManagerBotWorkThreadWndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return DefWindowProc(hwnd, message, wParam, lParam);;
}


