

#include "Windows.h"
#include "SetWindowHook.h"
#include "botThread.h"

//===�����������߳�====
DWORD WINAPI testBotThread(LPVOID lpParam)
{
	// ʵ�������ͨ������NULL��ʹ�õ�ǰʵ��
	HINSTANCE hInstance = (HINSTANCE)lpParam;

	// ע�ᴰ����
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = 0;
	wcex.lpfnWndProc = qWndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance; // ���Ӧ�ó���ʵ�����
	wcex.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = "MyThreadWindowClass";
	wcex.hIconSm = LoadIcon(NULL, IDI_APPLICATION);

	if (!RegisterClassEx(&wcex))
	{
		// �������
	}

	HWND hwnd = CreateWindow(
		"MyThreadWindowClass",
		"My Thread Window",
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
		NULL, NULL, hInstance, NULL);


	hookBotThread(hwnd);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}

	return 0;

}



LRESULT CALLBACK qWndProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
	}
	return DefWindowProc(hwnd, message, wParam, lParam);;
}


