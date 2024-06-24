
#include "pch.h"
#include "Windows.h"
#include "SetWindowHook.h"
#include "SetWindowHookOrder.h"
#include "OrderManager.h"
#include "OrderManagerBotWorkThread.h"
#include <mutex>
#include "OrderManagerBot.h"

//std::mutex h_mutex;

//===�����������߳�====
DWORD WINAPI orderManagerBotWorkThread(LPVOID lpParam)
{
	//std::lock_guard<std::mutex> lock(h_mutex);
	// ʵ�������ͨ������NULL��ʹ�õ�ǰʵ��
	HINSTANCE hInstance = (HINSTANCE)lpParam;

	// ע�ᴰ����
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
		// �������
	}

	//����һ��û�д��ڵĴ���
	HWND hwnd = CreateWindow(
		"OrderManagerWorkThreadClass",
		"OrderManagerWorkThread",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL, hInstance, NULL);


	//====hookOrderManager====
	orderManager = new OrderManager(); //���߳���ʵ��������
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


