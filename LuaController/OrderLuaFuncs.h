#pragma once



extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}



//LOr001 
int luaLHttpPost(lua_State* L);

//LOR002 
int luaLCurlGet(lua_State* L);

//LOR003
int luaLCurlPost(lua_State* L);
