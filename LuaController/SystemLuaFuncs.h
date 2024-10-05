#pragma once


extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}


//LSS001 setClipBoardText
int luaLSetClipBoardText(lua_State* L);

//LSS002 getClipBoardText
int luaLGetClipBoardText(lua_State* L);

//LSS003 pasteClipBoardText
int luaLPasteClipBoardText(lua_State* L);