#pragma once
//存放被封装的FindPic的lua函数


extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}

//luaLTest
int luaLTest(lua_State* L);
//LBM001 LoadBmp
int luaLLoadBmp(lua_State* L);
//LBM002 loadBmpSub
int luaLLoadBmpSub(lua_State* L);
//LBM003 loadBmpList
int luaLLoadBmpList(lua_State* L);
//LBM004 freeBmp
int luaLFreeBmp(lua_State* L);
//LBM005 findPAPicA
int luaLFindPAPicA(lua_State* L);
//LBM006 findDAPicA
int luaLFindDAPicA(lua_State* L);
//LBM007 findSAPicA
int luaLFindSAPicA(lua_State* L);
//LBM008 findPAPicN
int luaLFindPAPicN(lua_State* L);
//LBM009 findDAPicN
int luaLFindDAPicN(lua_State* L);
//LBM010 findSAPicN
int luaLFindSAPicN(lua_State* L);
//LBM011 findLNPicA
int luaLFindLNPicA(lua_State* L);
//LBM012 findLNPicN
int luaLFindLNPicN(lua_State* L);