

#include "pch.h"
#include "SystemSkill.h"
#include "InputAction.h"

using namespace std;


#include <Windows.h>


void SystemSkill::setClipBoardText(string text) {

	if (OpenClipboard(nullptr)) {
		EmptyClipboard();
		HGLOBAL clipbuffer = GlobalAlloc(GMEM_DDESHARE, text.size() + 1);
		char* buffer = static_cast<char*>(GlobalLock(clipbuffer));
		memcpy(buffer, text.c_str(), text.size() + 1);
		GlobalUnlock(clipbuffer);
		SetClipboardData(CF_TEXT, clipbuffer);
		CloseClipboard();
	}
}

string SystemSkill::GetClipBoardText() {
    if (!IsClipboardFormatAvailable(CF_UNICODETEXT)) {
        return ""; // ���а���û���ı�����
    }

    if (!OpenClipboard(nullptr)) {
        return ""; // �޷��򿪼��а�
    }

    HANDLE hClipboardData = GetClipboardData(CF_UNICODETEXT);
    if (hClipboardData == nullptr) {
        CloseClipboard();
        return ""; // ���а���û������
    }

    // �����ڴ沢��ȡ���а�����
    wchar_t* pwchData = static_cast<wchar_t*>(GlobalLock(hClipboardData));
    if (pwchData == nullptr) {
        CloseClipboard();
        return ""; // �޷������ڴ�
    }

    // �����ַ�ת��Ϊ��׼�ַ���
    std::wstring wstr(pwchData);
    std::string str(wstr.begin(), wstr.end());

    GlobalUnlock(hClipboardData);
    CloseClipboard();

    return str;
}

void SystemSkill::pasteClipBoardText() {
    InputAction* inputAction = new InputAction();

    inputAction->keyDown(17, 0); //ctrl
    inputAction->keyPress(86); //v
    inputAction->keyUp(17);
    delete inputAction;
    return;
}
