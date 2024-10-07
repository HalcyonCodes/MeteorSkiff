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
    // ��Luaջ�л�ȡ����
    const char* ip = luaL_tolstring(L, 1, nullptr);
    const char* port = luaL_tolstring(L, 2, nullptr);
    const char* http = luaL_tolstring(L, 3, nullptr);
    const char* data = luaL_tolstring(L, 4, nullptr);
    
    
    int result = msgHttpPost(orderManager, ip, port, http, data);
    // �����ѹ��Luaջ
    lua_pushnumber(L, result);
    // ���ؽ������������ѹ��ջ��������
    return 1;
}

//or009 CurlGet
int luaLCurlGet(lua_State* L) {
    // ��ȡ Lua ջ�ϵĲ���
    const char* ip = luaL_tolstring(L, 1, nullptr);
    const char* port = luaL_tolstring(L, 2, nullptr);
    const char* http = luaL_tolstring(L, 3, nullptr);

    // ִ�� HTTP GET ����
    httplib::Result result = msgCurlGet(orderManager, ip, port, http);

    // ����һ���µ� Lua ��
    lua_newtable(L); // ����ջ��

    // ����״̬��
    lua_pushinteger(L, 1); // ��
    lua_pushinteger(L, result->status); // ֵ
    lua_settable(L, -3); // ����ֵ�Դ������

    // ������Ӧ��
    lua_pushinteger(L, 2); // ��
    lua_pushstring(L, result->body.c_str()); // ֵ
    lua_settable(L, -3); // ����ֵ�Դ������

    // ���ؽ����
    return 1;
}













