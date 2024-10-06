
#include "pch.h"

#include "InputActionController.h"

#include <Windows.h>
#include <stdio.h>
#include <iostream>

extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

}
#include "DbgPrint.h"
#include <string>
using namespace std;



//LIN001 inputInit
int luaLInputInit(lua_State* L) {
    // 从Lua栈中获取参数
    const char* windowName = luaL_tolstring(L, 1, nullptr);
    msgInputInit(windowName);
    return 0;
}

//LIN002 lClickDonw
int luaLLeftClickDown(lua_State* L) {
    // 从Lua栈中获取参数
    int time = lua_tointeger(L, 1);
    int result = msgLClickDown(time);
    // 将结果压入Lua栈
    lua_pushnumber(L, result);
    // 返回结果的数量（即压入栈的数量）
    return 1;
}

//LIN003 rClickDown
int luaLRightClickDown(lua_State* L) {
    // 从Lua栈中获取参数
    int time = lua_tointeger(L, 1);
    int result = msgRClickDown(time);
    // 将结果压入Lua栈
    lua_pushnumber(L, result);
    // 返回结果的数量（即压入栈的数量）
    return 1;
}

//LIN004 mClickDown
int luaLMidClickDown(lua_State* L) {
    // 从Lua栈中获取参数
    int time = lua_tointeger(L, 1);
    int result = msgMClickDown(time);
    // 将结果压入Lua栈
    lua_pushnumber(L, result);
    // 返回结果的数量（即压入栈的数量）
    return 1;
}

//LIN005 lClickUp
int luaLLeftClickUp(lua_State* L) {
    // 从Lua栈中获取参数
    int result = msgLClickUp();
    // 将结果压入Lua栈
    lua_pushnumber(L, result);
    // 返回结果的数量（即压入栈的数量）
    return 1;
}


//LIN006 rClickUp
int luaLRightClickUp(lua_State* L) {
    // 从Lua栈中获取参数
    int result = msgRClickUp();
    // 将结果压入Lua栈
    lua_pushnumber(L, result);
    // 返回结果的数量（即压入栈的数量）
    return 1;
}


//LIN007 mClickUp
int luaLMidClickUp(lua_State* L) {
    // 从Lua栈中获取参数
    int result = msgMClickUp();
    // 将结果压入Lua栈
    lua_pushnumber(L, result);
    // 返回结果的数量（即压入栈的数量）
    return 1;
}

//LIN008 moveTo
int luaLMoveTo(lua_State* L) {
    //从Lua栈中获取参数
    int x = lua_tointeger(L, 1);
    int y = lua_tointeger(L, 2);
    //调用
    int result = msgMoveTo(x, y);
    // 将结果压入Lua栈
    lua_pushnumber(L, result);
    // 返回结果的数量（即压入栈的数量）
    return 1;
}


//LIN009 moveToChange
int luaLMoveToChange(lua_State* L) {
    //从Lua栈中获取参数
    int x = lua_tointeger(L, 1);
    int y = lua_tointeger(L, 2);
    //调用
    int result = msgMoveToChange(x, y);
    // 将结果压入Lua栈
    lua_pushnumber(L, result);
    // 返回结果的数量（即压入栈的数量）
    return 1;
}

//LIN010 mOnClick
int luaLMidOnClick(lua_State* L) {
    //从Lua栈中获取参数
    //调用
    int result = msgMOnClick();
    // 将结果压入Lua栈
    lua_pushnumber(L, result);
    // 返回结果的数量（即压入栈的数量）
    return 1;
}

//LIN011 lOnClick
int luaLLeftOnClick(lua_State* L) {
    //从Lua栈中获取参数
    //调用
    int result = msgLOnClick();
    // 将结果压入Lua栈
    lua_pushnumber(L, result);
    // 返回结果的数量（即压入栈的数量）
    return 1;
}

//LIN012 rOnClick
int luaLRightOnClick(lua_State* L) {
    //从Lua栈中获取参数
    //调用
    int result = msgROnClick();
    // 将结果压入Lua栈
    lua_pushnumber(L, result);
    // 返回结果的数量（即压入栈的数量）
    return 1;
}

//LIN013 keyDown
int luaLKeyDown(lua_State* L) {
    //从Lua栈中获取参数
    short key = lua_tointeger(L, 1);
    int time = lua_tointeger(L, 2);
    //调用
    int result = msgKeyDown(key, time);
    // 将结果压入Lua栈
    lua_pushnumber(L, result);
    // 返回结果的数量（即压入栈的数量）
    return 1;
}

//LIN014 keyUp
int luaLKeyUp(lua_State* L) {
    //从Lua栈中获取参数
    short key = lua_tointeger(L, 1);
    //调用
    int result = msgKeyUp(key);
    // 将结果压入Lua栈
    lua_pushnumber(L, result);
    // 返回结果的数量（即压入栈的数量）
    return 1;
}


//LIN015 keyPress
int luaLKeyPress(lua_State* L) {
    //从Lua栈中获取参数
    short key = lua_tointeger(L, 1);
    //调用
    int result = msgKeyPress(key);
    // 将结果压入Lua栈
    lua_pushnumber(L, result);
    // 返回结果的数量（即压入栈的数量）
    return 1;
}

//LIN016 sendString
int luaLSendString(lua_State* L) {
    // 从Lua栈中获取参数
    string inputString = lua_tostring (L, 1);
    msgSendString(inputString);
    // 将结果压入Lua栈
    // 返回结果的数量（即压入栈的数量）
    return 0;
}


//LIN017 sendStringToClipboard
int luaLSendStringToClipboard(lua_State* L) {
    // 从Lua栈中获取参数
    string inputString = lua_tostring(L, 1);
    msgSendStringToClipboard(inputString);
    return 0;
}

//LIN018 ReadStringFromClipboard
int luaLReadStringFromClipboard(lua_State* L) {
    string result = msgReadStringFromClipboard();
    lua_pushstring(L, result.c_str());
    return 1;
}





