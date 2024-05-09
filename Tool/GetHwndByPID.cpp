#include "pch.h"
#include "Windows.h"


#pragma comment(lib,"DbgHelp.lib")
#pragma comment(lib,"User32.lib")

///< ö�ٴ��ڲ���
typedef struct
{
    HWND hwndWindow; // ���ھ��
    DWORD dwProcessID; // ����ID
}EnumWindowsArg;

///< ö�ٴ��ڻص�����
BOOL CALLBACK enumWindowsProc(HWND hwnd, LPARAM lParam)
{
    EnumWindowsArg* pArg = (EnumWindowsArg*)lParam;
    DWORD dwProcessID = 0;
    // ͨ�����ھ��ȡ�ý���ID
    ::GetWindowThreadProcessId(hwnd, &dwProcessID);
    if (dwProcessID == pArg->dwProcessID)
    {
        pArg->hwndWindow = hwnd;
        // �ҵ��˷���FALSE
        return FALSE;
    }
    // û�ҵ��������ң�����TRUE
    return TRUE;
}

///< ͨ������ID��ȡ���ھ��
HWND getWindowHwndByPID(DWORD dwProcessID)
{
    HWND hwndRet = NULL;
    EnumWindowsArg ewa;
    ewa.dwProcessID = dwProcessID;
    ewa.hwndWindow = NULL;
    EnumWindows(enumWindowsProc, (LPARAM)&ewa);
    if (ewa.hwndWindow)
    {
        hwndRet = ewa.hwndWindow;
    }
    int d = (int)hwndRet;
    return hwndRet;
}

///��ȡ��ǰ���ھ��
HWND getCurrentHwnd() {
    return getWindowHwndByPID(GetCurrentProcessId());
}