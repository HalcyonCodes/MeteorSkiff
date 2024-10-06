#pragma once

//存放被封装的Input的lua函数

extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}



//LIN001 inputInit
int luaLInputInit(lua_State* L);

//LIN002 lClickDonw
int luaLLeftClickDown(lua_State* L);

//LIN003 rClickDown
int luaLRightClickDown(lua_State* L);

//LIN004 mClickDown
int luaLMidClickDown(lua_State* L);

//LIN005 lClickUp
int luaLLeftClickUp(lua_State* L);

//LIN006 rClickUp
int luaLRightClickUp(lua_State* L);

//LIN007 mClickUp
int luaLMidClickUp(lua_State* L);

//LIN008 moveTo
int luaLMoveTo(lua_State* L);

//LIN009 moveToChange
int luaLMoveToChange(lua_State* L);

//LIN010 mOnClick
int luaLMidOnClick(lua_State* L);

//LIN011 lOnClick
int luaLLeftOnClick(lua_State* L);

//LIN012 rOnClick
int luaLRightOnClick(lua_State* L);

//LIN013 keyDown
int luaLKeyDown(lua_State* L);

//LIN014 keyUp
int luaLKeyUp(lua_State* L);

//LIN015 keyPress
int luaLKeyPress(lua_State* L);

//LIN016 sendString
int luaLSendString(lua_State* L);

//LIN017
int luaLSendStringToClipboard(lua_State* L);

//LIN018
int luaLReadStringFromClipboard(lua_State* L);
