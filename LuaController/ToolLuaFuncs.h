#pragma once

//存放被封装的FindPic的lua函数


extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}


int luaLDbgPrint(lua_State* L);