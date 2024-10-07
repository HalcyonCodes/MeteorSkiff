#include "pch.h"
#include "OrderController.h"


#include <Windows.h>
#include <stdio.h>
#include <iostream>

extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

}
#include "DbgPrint.h"



//or008 loadBmp
int luaLHttpPost(lua_State* L) {
    // 从Lua栈中获取参数
    const char* ip = luaL_tolstring(L, 1, nullptr);
    const char* port = luaL_tolstring(L, 2, nullptr);
    const char* http = luaL_tolstring(L, 3, nullptr);
    const char* data = luaL_tolstring(L, 4, nullptr);
    
    
    int result = msgHttpPost(orderManager, ip, port, http, data);
    // 将结果压入Lua栈
    lua_pushnumber(L, result);
    // 返回结果的数量（即压入栈的数量）
    return 1;
}

//or009 CurlGet
int luaLCurlGet(lua_State* L) {
    // 获取 Lua 栈上的参数
    const char* ip = luaL_tolstring(L, 1, nullptr);
    const char* port = luaL_tolstring(L, 2, nullptr);
    const char* http = luaL_tolstring(L, 3, nullptr);

    // 执行 HTTP GET 请求
    httplib::Result result = msgCurlGet(orderManager, ip, port, http);

    // 创建一个新的 Lua 表
    lua_newtable(L); // 表在栈顶

    // 设置状态码
    lua_pushinteger(L, 1); // 键
    lua_pushinteger(L, result->status); // 值
    lua_settable(L, -3); // 将键值对存入表中

    // 设置响应体
    lua_pushinteger(L, 2); // 键
    lua_pushstring(L, result->body.c_str()); // 值
    lua_settable(L, -3); // 将键值对存入表中

    // 返回结果表
    return 1;
}













