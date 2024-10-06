#pragma once


extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}


//LSS001 setClipBoardText
int luaLGetClipboardText(lua_State* L);

