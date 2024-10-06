#include "pch.h"

#include "SystemSkillController.h"

#include <Windows.h>
#include <stdio.h>
#include <iostream>

extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

}
#include "DbgPrint.h"



//LSS001 GetClipboardText
int luaLGetClipboardText(lua_State* L) {

    string result = msgGetClipboardText();
    lua_pushstring(L, result.c_str());
    return 1;
}



