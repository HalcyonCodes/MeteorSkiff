
#include "pch.h"

#include <Windows.h>
#include <stdio.h>
#include <iostream>

extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

}
#include "DbgPrint.h"

//TOL001 dbgPring
int luaLDbgPrint(lua_State* L) {
    // 获取参数数量
    int argCount = lua_gettop(L);
    // 确保至少有一个参数（格式化字符串）
    //if (argCount < 1) {
     //   luaL_error(L, "dbgPrint: format string is missing");
     //   return 0;
     //}
    //const char* format = luaL_checkstring(L, 1); // 确保第一个参数是字符串
    // 创建一个缓冲区以存储最终的输出字符串
    char buf[0x1000];
    char* bufPtr = buf;
    // 逐个处理每个参数
    for (int i = 1; i <= argCount; ++i) {
        int type = lua_type(L, i); // 获取当前参数的类型

        switch (type) {
        case LUA_TNUMBER: {
            // 参数是数字
            double number = lua_tonumber(L, i);
            sprintf_s(bufPtr, sizeof(buf) - (bufPtr - buf), "%f", number);
            break;
        }
        case LUA_TSTRING: {
            // 参数是字符串
            const char* str = lua_tolstring(L, i, NULL);
            sprintf_s(bufPtr, sizeof(buf) - (bufPtr - buf), "%s", str);
            break;
        }
        case LUA_TBOOLEAN: {
            // 参数是布尔值
            int boolean = lua_toboolean(L, i);
            sprintf_s(bufPtr, sizeof(buf) - (bufPtr - buf), "%s", boolean ? "true" : "false");
            break;
        }
        default: {
            // 对于不支持的类型，可以追加一个占位符
            sprintf_s(bufPtr, sizeof(buf) - (bufPtr - buf), "(unsupported type)");
            break;
        }
        }

        // 移动指针以指向缓冲区的下一个空位
        bufPtr += strlen(bufPtr);

        // 如果不是最后一个参数，追加分隔符（例如空格）
        if (i < argCount) {
            sprintf_s(bufPtr, sizeof(buf) - (bufPtr - buf), ", ");
            bufPtr += strlen(bufPtr);
        }
    }

    // 构建最终的输出字符串，并使用OutputDebugStringA输出
    char printFilter[0x1012] = "Game:";
    strcat_s(printFilter, sizeof(printFilter), buf);
    OutputDebugStringA(printFilter);

    return 0; // 返回给Lua的返回值数量
}