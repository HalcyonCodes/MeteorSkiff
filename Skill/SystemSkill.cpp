

#include "pch.h"
#include "SystemSkill.h"
#include "InputAction.h"

using namespace std;

#include <windows.h>
#include <iostream>

#include <Windows.h>





std::string SystemSkill::GetClipboardText() {
    if (OpenClipboard(NULL)) {
        HGLOBAL hglbCopy = GetClipboardData(CF_TEXT);
        if (hglbCopy) {
            char* lptstrCopy = static_cast<char*>(GlobalLock(hglbCopy));
            if (lptstrCopy) {
                std::string strText = lptstrCopy;
                GlobalUnlock(hglbCopy);
                return strText;
            }
        }
        CloseClipboard();
    }
    return "";
}
  
