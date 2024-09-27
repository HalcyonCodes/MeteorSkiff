
#include "pch.h"


#include <Windows.h>
#include <stdio.h>
#include <iostream>
#include "OrderSkillController.h"

extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"


}
#include "DbgPrint.h"
#include <vector>



//LOR001 createOrder
int luaLCreateOrder(lua_State* L) {
    // ��Lua��ջ�л�ȡ����
    int channelLevel = luaL_checkinteger(L, 1);
    int serviceID = luaL_checkinteger(L, 2);
    std::string targetID = luaL_checkstring(L, 3);

    // ��ȡresourceID
    std::vector<int> resourceID;
    if (lua_istable(L, 4)) {
        lua_pushnil(L);  // ��nil�����ջ����ʼ����table
        while (lua_next(L, 4) != 0) {
            // key��ջ����value��key����
            int id = luaL_checkinteger(L, -1);
            resourceID.push_back(id);
            lua_pop(L, 1);  // �Ƴ�value������key���Ա��´ε���
        }
    }

    // ��ȡintVal
    std::vector<int> intVal;
    lua_getfield(L, 1, "intVal");  // ����intVal�ǵڶ�������
    if (lua_istable(L, -1)) {
        lua_pushnil(L);
        while (lua_next(L, -2) != 0) {
            int val = luaL_checkinteger(L, -1);
            intVal.push_back(val);
            lua_pop(L, 1);
        }
    }
    lua_pop(L, 1);  // �Ƴ�intVal table

    // ��ȡstringVal
    std::vector<std::string> stringVal;
    lua_getfield(L, 1, "stringVal");  // ����stringVal�ǵ���������
    if (lua_istable(L, -1)) {
        lua_pushnil(L);
        while (lua_next(L, -2) != 0) {
            const char* str = luaL_checkstring(L, -1);
            stringVal.push_back(str);
            lua_pop(L, 1);
        }
    }
    lua_pop(L, 1);  // �Ƴ�stringVal table

    // ��ȡdoubleVal
    std::vector<double> doubleVal;
    lua_getfield(L, 1, "doubleVal");  // ����doubleVal�ǵ��ĸ�����
    if (lua_istable(L, -1)) {
        lua_pushnil(L);
        while (lua_next(L, -2) != 0) {
            double val = luaL_checknumber(L, -1);
            doubleVal.push_back(val);
            lua_pop(L, 1);
        }
    }
    lua_pop(L, 1);  // �Ƴ�doubleVal table

    // ����C++����
    int result = msgCreateOrder(channelLevel, serviceID, targetID, resourceID, intVal, stringVal, doubleVal);

    // ���ؽ��
    lua_pushinteger(L, result);
    return 1;  // ����һ������
}