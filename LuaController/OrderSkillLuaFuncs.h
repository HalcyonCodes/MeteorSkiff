#pragma once


extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}

int luaLCreateOrder(lua_State* L);