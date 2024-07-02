
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
    // ��ȡ��������
    int argCount = lua_gettop(L);
    // ȷ��������һ����������ʽ���ַ�����
    //if (argCount < 1) {
     //   luaL_error(L, "dbgPrint: format string is missing");
     //   return 0;
     //}
    //const char* format = luaL_checkstring(L, 1); // ȷ����һ���������ַ���
    // ����һ���������Դ洢���յ�����ַ���
    char buf[0x1000];
    char* bufPtr = buf;
    // �������ÿ������
    for (int i = 1; i <= argCount; ++i) {
        int type = lua_type(L, i); // ��ȡ��ǰ����������

        switch (type) {
        case LUA_TNUMBER: {
            // ����������
            double number = lua_tonumber(L, i);
            sprintf_s(bufPtr, sizeof(buf) - (bufPtr - buf), "%f", number);
            break;
        }
        case LUA_TSTRING: {
            // �������ַ���
            const char* str = lua_tolstring(L, i, NULL);
            sprintf_s(bufPtr, sizeof(buf) - (bufPtr - buf), "%s", str);
            break;
        }
        case LUA_TBOOLEAN: {
            // �����ǲ���ֵ
            int boolean = lua_toboolean(L, i);
            sprintf_s(bufPtr, sizeof(buf) - (bufPtr - buf), "%s", boolean ? "true" : "false");
            break;
        }
        default: {
            // ���ڲ�֧�ֵ����ͣ�����׷��һ��ռλ��
            sprintf_s(bufPtr, sizeof(buf) - (bufPtr - buf), "(unsupported type)");
            break;
        }
        }

        // �ƶ�ָ����ָ�򻺳�������һ����λ
        bufPtr += strlen(bufPtr);

        // ����������һ��������׷�ӷָ���������ո�
        if (i < argCount) {
            sprintf_s(bufPtr, sizeof(buf) - (bufPtr - buf), ", ");
            bufPtr += strlen(bufPtr);
        }
    }

    // �������յ�����ַ�������ʹ��OutputDebugStringA���
    char printFilter[0x1012] = "Game:";
    strcat_s(printFilter, sizeof(printFilter), buf);
    OutputDebugStringA(printFilter);

    return 0; // ���ظ�Lua�ķ���ֵ����
}