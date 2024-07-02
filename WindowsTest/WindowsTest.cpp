// WindowsTest.cpp : 定义应用程序的入口点。
//

#include "framework.h"
#include "WindowsTest.h"
#include <thread>
#include "TestBotController.h"
#include "SetWindowHook.h"
#include "FindPicController.h"
#include "DbgPrint.h"

#include "TestBotController.h"
#include "GetHwndByPID.h"
#include "BotThread.h"
#include "TestLuaController.h"
#include "TestOrderManager.h"
#include "SetWindowHookOrder.h"

#define MAX_LOADSTRING 100


// 全局变量:
HINSTANCE hInst;                                // 当前实例
WCHAR szTitle[MAX_LOADSTRING];                  // 标题栏文本
WCHAR szWindowClass[MAX_LOADSTRING];            // 主窗口类名

// 此代码模块中包含的函数的前向声明:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK    About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 在此处放置代码。

    // 初始化全局字符串
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_WINDOWSTEST, szWindowClass, MAX_LOADSTRING);
   
    MyRegisterClass(hInstance);

    // 执行应用程序初始化:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }
    //====TEST代码位置====
    // 在这里初始化并启动线程
    
    //====bot所在线程====
    HANDLE hThread = CreateThread(NULL, 0, testBotThread, NULL, 0, NULL);
    if (hThread == NULL)
    {
        // 处理错误
    }

    //这里需要等待线程hook完成才能启动sendmessage线程
   while (botHwnd == nullptr)
   {

    }
    //while (orderMangerHwnd == nullptr)
    //{

    //}

    //=========测试msgController的线程==========
    LPTHREAD_START_ROUTINE botThread2 = (LPTHREAD_START_ROUTINE)testBotController;
    HANDLE hThread2 = CreateThread(NULL, 0, botThread2, NULL, CREATE_SUSPENDED, NULL);
    if (hThread2 == NULL)
    {

    }

    // Set the thread to run in the background
    SetThreadPriority(hThread2, THREAD_PRIORITY_BELOW_NORMAL);

    // Start the thread
    ResumeThread(hThread2);

    //========测试luaController的线程========
    /*LPTHREAD_START_ROUTINE luaTestThread = (LPTHREAD_START_ROUTINE)testLuaController;
    HANDLE hThread2 = CreateThread(NULL, 0, luaTestThread, NULL, CREATE_SUSPENDED, NULL);
    if (hThread2 == NULL)
    {

    }

    SetThreadPriority(hThread2, THREAD_PRIORITY_BELOW_NORMAL);


    ResumeThread(hThread2);
    */

    //========测试OrderManager的线程========
    //LPTHREAD_START_ROUTINE orderTestThread = (LPTHREAD_START_ROUTINE)testOrderManager;
    //HANDLE hThread3 = CreateThread(NULL, 0, orderTestThread, NULL, CREATE_SUSPENDED, NULL);
    //if (hThread3 == NULL)
    //{

    //}

    //SetThreadPriority(hThread3, THREAD_PRIORITY_BELOW_NORMAL);


    //ResumeThread(hThread3);



    //====
    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_WINDOWSTEST));

    MSG msg;

    // 主消息循环:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int) msg.wParam;
}



//
//  函数: MyRegisterClass()
//
//  目标: 注册窗口类。
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_WINDOWSTEST));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = MAKEINTRESOURCEW(IDC_WINDOWSTEST);
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

//
//   函数: InitInstance(HINSTANCE, int)
//
//   目标: 保存实例句柄并创建主窗口
//
//   注释:
//
//        在此函数中，我们在全局变量中保存实例句柄并
//        创建和显示主程序窗口。
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 将实例句柄存储在全局变量中

   HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  函数: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  目标: 处理主窗口的消息。
//
//  WM_COMMAND  - 处理应用程序菜单
//  WM_PAINT    - 绘制主窗口
//  WM_DESTROY  - 发送退出消息并返回
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
 
    switch (message)
    {
   // case WM_USER + 1: // 假设这是自定义消息的编号
    //{ // 发送消息到线程，让线程调用指定的函数
       // PostMessage(hWnd, WM_USER + 4, 0, 0);
       // break;
    //}
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // 分析菜单选择:
            switch (wmId)
            {
            case IDM_ABOUT:
                DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
                break;
            case IDM_EXIT:
                DestroyWindow(hWnd);
                break;
            default:
                return DefWindowProc(hWnd, message, wParam, lParam);
            }
        }
        break;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hWnd, &ps);
            // TODO: 在此处添加使用 hdc 的任何绘图代码...
            EndPaint(hWnd, &ps);
        }
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
        //CallNextHookEx(NULL, message, wParam, lParam);
    }
    return 0;
    //CallNextHookEx(tHGame, message, wParam, lParam);
}

// “关于”框的消息处理程序。
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;

    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}
