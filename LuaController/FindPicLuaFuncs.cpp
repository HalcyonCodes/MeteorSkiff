
#include "pch.h"
#include "findPicController.h"
#include "GetScreenController.h"

#include <Windows.h>
#include <stdio.h>
#include <iostream>

extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

}
#include "DbgPrint.h"

//TES001 TEST
int luaLTest(lua_State* L) {
    dbgPrint("LuaLTest");
    return 1;
}

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

//LGS001 findWindow
int luaLFindWindow(lua_State* L) {
    // ��Luaջ�л�ȡ����
    const char* className = luaL_tolstring(L, 1, nullptr);
    const char* windowName = luaL_tolstring(L, 2, nullptr);
    HWND result = msgFindWindow(className, windowName);
    // �����ѹ��Luaջ
    lua_pushnumber(L, int(result));
    // ���ؽ������������ѹ��ջ��������
    return 1;
}

//LBM001 LoadBmp
int luaLLoadBmp(lua_State* L) {
    // ��Luaջ�л�ȡ����
    const char* path = luaL_tolstring(L, 1, nullptr);
    int result = msgLoadBmp(path);
    // �����ѹ��Luaջ
    lua_pushnumber(L, result);
    // ���ؽ������������ѹ��ջ��������
    return 1;
}

//LBM002 loadBmpSub
int luaLLoadBmpSub(lua_State* L) {
    const char* path = luaL_tolstring(L, 1, nullptr);
    int result = msgLoadBmpSub(path);
    lua_pushnumber(L, result);
    return 1;
}

//LBM003 loadBmpList
int luaLLoadBmpList(lua_State* L) {
    const char* path = luaL_tolstring(L, 1, nullptr);
    int result = msgLoadBmpList(path);
    lua_pushnumber(L, result);
    return 1;
}

//LBM004 freeBmp
int luaLFreeBmp(lua_State* L) {
    int result = msgFreeBmp();
    lua_pushnumber(L, result);
    return 1;
}

//LBM005 findPAPicA
int luaLFindPAPicA(lua_State* L) {
    HWND hwnd = (HWND)lua_tointeger(L, 1); //HWND
    int left = lua_tointeger(L, 2); //left
    int top = lua_tointeger(L, 3); //top
    int right = lua_tointeger(L, 4); //right
    int bottom = lua_tointeger(L, 5); //bottom
    const char* path = luaL_tolstring(L, 6, nullptr); //path
    int similar = lua_tointeger(L, 7);
    int* result = msgFindPAPicA(hwnd, left, top, right, bottom, path, similar);
    lua_newtable(L); // ����һ���µ� Lua �����ڴ��

    for (int i = 0; i < 2; ++i) {
        lua_pushinteger(L, i + 1); // ���������� 1 ��ʼ
        lua_pushinteger(L, result[i]); // ������Ԫ��ѹ��ջ��
        lua_settable(L, -3); // ����ֵ�Դ�ŵ�����
    }
    delete[] result;
    return 1;
}

//LBM006 findDAPicA
int luaLFindDAPicA(lua_State* L) {
    HWND hwnd = (HWND)lua_tointeger(L, 1);
    int left = lua_tointeger(L, 2);
    int top = lua_tointeger(L, 3);
    int right = lua_tointeger(L, 4);
    int bottom = lua_tointeger(L, 5);
    const char* name = luaL_tolstring(L, 6, nullptr);
    int similar = lua_tointeger(L, 7);
    int* result = msgFindDAPicA(hwnd, left, top, right, bottom, name, similar);
    lua_newtable(L);

    for (int i = 0; i < 2; ++i) {
        lua_pushinteger(L, i + 1);
        lua_pushinteger(L, result[i]);
        lua_settable(L, -3);
    }
    delete[] result;
    return 1;
}

//LBM007 findSAPicA
int luaLFindSAPicA(lua_State* L) {
    HWND hwnd = (HWND)lua_tointeger(L, 1);
    int left = lua_tointeger(L, 2);
    int top = lua_tointeger(L, 3);
    int right = lua_tointeger(L, 4);
    int bottom = lua_tointeger(L, 5);
    const char* name = luaL_tolstring(L, 6, nullptr);
    int similar = lua_tointeger(L, 7);
    int* result = msgFindSAPicA(hwnd, left, top, right, bottom, name, similar);
    lua_newtable(L);

    for (int i = 0; i < 2; ++i) {
        lua_pushinteger(L, i + 1);
        lua_pushinteger(L, result[i]);
        lua_settable(L, -3);
    }
    delete[] result;
    return 1;
}

//LBM008 findPAPicN
int luaLFindPAPicN(lua_State* L) {
    HWND hwnd = (HWND)lua_tointeger(L, 1);
    int left = lua_tointeger(L, 2);
    int top = lua_tointeger(L, 3);
    int right = lua_tointeger(L, 4);
    int bottom = lua_tointeger(L, 5);
    const char* path = luaL_tolstring(L, 6, nullptr);
    int similar = lua_tointeger(L, 7);
    int** result = msgFindPAPicN(hwnd, left, top, right, bottom, path, similar);
    lua_newtable(L);

    int length = 0;
    while (true) {
        int q = result[length][0];
        length++;
        if (q == -1) {
            break;
        }
    };


    for (int i = 0; i < length; ++i) {
        lua_pushinteger(L, i + 1);
        lua_newtable(L);
        for (int j = 0; j < 2; ++j) {
            lua_pushinteger(L, j + 1);
            lua_pushinteger(L, result[i][j]);
            lua_settable(L, -3);
        }
        lua_settable(L, -3);
    }

    for (int i = 0; i < length; ++i) {
        delete[] result[i];
    }
    delete[] result;

    return 1;
}

//LBM009 findDAPicN
int luaLFindDAPicN(lua_State* L) {
    HWND hwnd = (HWND)lua_tointeger(L, 1);
    int left = lua_tointeger(L, 2);
    int top = lua_tointeger(L, 3);
    int right = lua_tointeger(L, 4);
    int bottom = lua_tointeger(L, 5);
    const char* name = luaL_tolstring(L, 6, nullptr);
    int similar = lua_tointeger(L, 7);
    int** result = msgFindDAPicN(hwnd, left, top, right, bottom, name, similar);
    lua_newtable(L);

    int length = 0;
    while (true) {
        int q = result[length][0];
        length++;
        if (q == -1) {
            break;
        }
    };

    for (int i = 0; i < length; ++i) {
        lua_pushinteger(L, i + 1);
        lua_newtable(L);
        for (int j = 0; j < 2; ++j) {
            lua_pushinteger(L, j + 1);
            lua_pushinteger(L, result[i][j]);
            lua_settable(L, -3);
        }
        lua_settable(L, -3);
    }

    for (int i = 0; i < length; ++i) {
        delete[] result[i];
    }
    delete[] result;

    return 1;
}

//LBM010 findSAPicN
int luaLFindSAPicN(lua_State* L) {
    HWND hwnd = (HWND)lua_tointeger(L, 1);
    int left = lua_tointeger(L, 2);
    int top = lua_tointeger(L, 3);
    int right = lua_tointeger(L, 4);
    int bottom = lua_tointeger(L, 5);
    const char* name = luaL_tolstring(L, 6, nullptr);
    int similar = lua_tointeger(L, 7);
    int** result = msgFindSAPicN(hwnd, left, top, right, bottom, name, similar);
    lua_newtable(L);

    int length = 0;
    while (true) {
        int q = result[length][0];
        length++;
        if (q == -1) {
            break;
        }
    };

    for (int i = 0; i < length; ++i) {
        lua_pushinteger(L, i + 1);
        lua_newtable(L);
        for (int j = 0; j < 2; ++j) {
            lua_pushinteger(L, j + 1);
            lua_pushinteger(L, result[i][j]);
            lua_settable(L, -3);
        }
        lua_settable(L, -3);
    }

    for (int i = 0; i < length; ++i) {
        delete[] result[i];
    }
    delete[] result;

    return 1;
}

//LBM011 findLNPicA
int luaLFindLNPicA(lua_State* L) {
    HWND hwnd = (HWND)lua_tointeger(L, 1);
    int left = lua_tointeger(L, 2);
    int top = lua_tointeger(L, 3);
    int right = lua_tointeger(L, 4);
    int bottom = lua_tointeger(L, 5);
    int similar = lua_tointeger(L, 6);
    int* result = msgFindLNPicA(hwnd, left, top, right, bottom, similar);
    lua_newtable(L);

    for (int i = 0; i < 3; ++i) {
        lua_pushinteger(L, i + 1);
        lua_pushinteger(L, result[i]);
        lua_settable(L, -3);
    }

    return 1;
}

//LBM012 findLNPicN
int luaLFindLNPicN(lua_State* L) {
    HWND hwnd = (HWND)lua_tointeger(L, 1);
    int left = lua_tointeger(L, 2);
    int top = lua_tointeger(L, 3);
    int right = lua_tointeger(L, 4);
    int bottom = lua_tointeger(L, 5);
    int similar = lua_tointeger(L, 6);
    int** result = msgFindLNPicN(hwnd, left, top, right, bottom, similar);
    lua_newtable(L);

    int length = 0;
    while (true) {
        int q = result[length][0];
        length++;
        if (q == -1) {
            break;
        }
    };

    for (int i = 0; i < length; ++i) {
        lua_pushinteger(L, i + 1);
        lua_newtable(L);
        for (int j = 0; j < 3; ++j) {
            lua_pushinteger(L, j + 1);
            lua_pushinteger(L, result[i][j]);
            lua_settable(L, -3);
        }
        lua_settable(L, -3);
    }

    for (int i = 0; i < length; ++i) {
        delete[] result[i];
    }
    delete[] result;

    return 1;
}