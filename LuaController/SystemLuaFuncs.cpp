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



//LSS001 setClipBoardText
int luaLSetClipBoardText(lua_State* L) {
    // 从Lua栈中获取参数
    const char* text = luaL_tolstring(L, 1, nullptr);
    msgSetClipBoardText(text);
    return 0;
}

//LSS002 getClipBoardText
int luaLGetClipBoardText(lua_State* L) {
    string result = msgGetClipBoardText();
    lua_pushstring(L, result.c_str());
    return 1;
}

//LSS003 pasteClipBoardText
int luaLPasteClipBoardText(lua_State* L) {
    msgPasteClipBoardText();
    return 0;
}

