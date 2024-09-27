
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
    // 从Lua堆栈中获取参数
    int channelLevel = luaL_checkinteger(L, 1);
    int serviceID = luaL_checkinteger(L, 2);
    std::string targetID = luaL_checkstring(L, 3);

    // 获取resourceID
    std::vector<int> resourceID;
    if (lua_istable(L, 4)) {
        lua_pushnil(L);  // 将nil推入堆栈，开始遍历table
        while (lua_next(L, 4) != 0) {
            // key在栈顶，value在key下面
            int id = luaL_checkinteger(L, -1);
            resourceID.push_back(id);
            lua_pop(L, 1);  // 移除value，保留key，以便下次迭代
        }
    }

    // 获取intVal
    std::vector<int> intVal;
    lua_getfield(L, 1, "intVal");  // 假设intVal是第二个参数
    if (lua_istable(L, -1)) {
        lua_pushnil(L);
        while (lua_next(L, -2) != 0) {
            int val = luaL_checkinteger(L, -1);
            intVal.push_back(val);
            lua_pop(L, 1);
        }
    }
    lua_pop(L, 1);  // 移除intVal table

    // 获取stringVal
    std::vector<std::string> stringVal;
    lua_getfield(L, 1, "stringVal");  // 假设stringVal是第三个参数
    if (lua_istable(L, -1)) {
        lua_pushnil(L);
        while (lua_next(L, -2) != 0) {
            const char* str = luaL_checkstring(L, -1);
            stringVal.push_back(str);
            lua_pop(L, 1);
        }
    }
    lua_pop(L, 1);  // 移除stringVal table

    // 获取doubleVal
    std::vector<double> doubleVal;
    lua_getfield(L, 1, "doubleVal");  // 假设doubleVal是第四个参数
    if (lua_istable(L, -1)) {
        lua_pushnil(L);
        while (lua_next(L, -2) != 0) {
            double val = luaL_checknumber(L, -1);
            doubleVal.push_back(val);
            lua_pop(L, 1);
        }
    }
    lua_pop(L, 1);  // 移除doubleVal table

    // 调用C++函数
    int result = msgCreateOrder(channelLevel, serviceID, targetID, resourceID, intVal, stringVal, doubleVal);

    // 返回结果
    lua_pushinteger(L, result);
    return 1;  // 返回一个整数
}