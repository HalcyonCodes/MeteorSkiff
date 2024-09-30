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



//LBM001 loadBmp
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














