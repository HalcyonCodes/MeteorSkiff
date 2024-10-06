
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
    // ��Luaջ�л�ȡ����
    const char* windowName = luaL_tolstring(L, 1, nullptr);
    msgInputInit(windowName);
    return 0;
}

//LIN002 lClickDonw
int luaLLeftClickDown(lua_State* L) {
    // ��Luaջ�л�ȡ����
    int time = lua_tointeger(L, 1);
    int result = msgLClickDown(time);
    // �����ѹ��Luaջ
    lua_pushnumber(L, result);
    // ���ؽ������������ѹ��ջ��������
    return 1;
}

//LIN003 rClickDown
int luaLRightClickDown(lua_State* L) {
    // ��Luaջ�л�ȡ����
    int time = lua_tointeger(L, 1);
    int result = msgRClickDown(time);
    // �����ѹ��Luaջ
    lua_pushnumber(L, result);
    // ���ؽ������������ѹ��ջ��������
    return 1;
}

//LIN004 mClickDown
int luaLMidClickDown(lua_State* L) {
    // ��Luaջ�л�ȡ����
    int time = lua_tointeger(L, 1);
    int result = msgMClickDown(time);
    // �����ѹ��Luaջ
    lua_pushnumber(L, result);
    // ���ؽ������������ѹ��ջ��������
    return 1;
}

//LIN005 lClickUp
int luaLLeftClickUp(lua_State* L) {
    // ��Luaջ�л�ȡ����
    int result = msgLClickUp();
    // �����ѹ��Luaջ
    lua_pushnumber(L, result);
    // ���ؽ������������ѹ��ջ��������
    return 1;
}


//LIN006 rClickUp
int luaLRightClickUp(lua_State* L) {
    // ��Luaջ�л�ȡ����
    int result = msgRClickUp();
    // �����ѹ��Luaջ
    lua_pushnumber(L, result);
    // ���ؽ������������ѹ��ջ��������
    return 1;
}


//LIN007 mClickUp
int luaLMidClickUp(lua_State* L) {
    // ��Luaջ�л�ȡ����
    int result = msgMClickUp();
    // �����ѹ��Luaջ
    lua_pushnumber(L, result);
    // ���ؽ������������ѹ��ջ��������
    return 1;
}

//LIN008 moveTo
int luaLMoveTo(lua_State* L) {
    //��Luaջ�л�ȡ����
    int x = lua_tointeger(L, 1);
    int y = lua_tointeger(L, 2);
    //����
    int result = msgMoveTo(x, y);
    // �����ѹ��Luaջ
    lua_pushnumber(L, result);
    // ���ؽ������������ѹ��ջ��������
    return 1;
}


//LIN009 moveToChange
int luaLMoveToChange(lua_State* L) {
    //��Luaջ�л�ȡ����
    int x = lua_tointeger(L, 1);
    int y = lua_tointeger(L, 2);
    //����
    int result = msgMoveToChange(x, y);
    // �����ѹ��Luaջ
    lua_pushnumber(L, result);
    // ���ؽ������������ѹ��ջ��������
    return 1;
}

//LIN010 mOnClick
int luaLMidOnClick(lua_State* L) {
    //��Luaջ�л�ȡ����
    //����
    int result = msgMOnClick();
    // �����ѹ��Luaջ
    lua_pushnumber(L, result);
    // ���ؽ������������ѹ��ջ��������
    return 1;
}

//LIN011 lOnClick
int luaLLeftOnClick(lua_State* L) {
    //��Luaջ�л�ȡ����
    //����
    int result = msgLOnClick();
    // �����ѹ��Luaջ
    lua_pushnumber(L, result);
    // ���ؽ������������ѹ��ջ��������
    return 1;
}

//LIN012 rOnClick
int luaLRightOnClick(lua_State* L) {
    //��Luaջ�л�ȡ����
    //����
    int result = msgROnClick();
    // �����ѹ��Luaջ
    lua_pushnumber(L, result);
    // ���ؽ������������ѹ��ջ��������
    return 1;
}

//LIN013 keyDown
int luaLKeyDown(lua_State* L) {
    //��Luaջ�л�ȡ����
    short key = lua_tointeger(L, 1);
    int time = lua_tointeger(L, 2);
    //����
    int result = msgKeyDown(key, time);
    // �����ѹ��Luaջ
    lua_pushnumber(L, result);
    // ���ؽ������������ѹ��ջ��������
    return 1;
}

//LIN014 keyUp
int luaLKeyUp(lua_State* L) {
    //��Luaջ�л�ȡ����
    short key = lua_tointeger(L, 1);
    //����
    int result = msgKeyUp(key);
    // �����ѹ��Luaջ
    lua_pushnumber(L, result);
    // ���ؽ������������ѹ��ջ��������
    return 1;
}


//LIN015 keyPress
int luaLKeyPress(lua_State* L) {
    //��Luaջ�л�ȡ����
    short key = lua_tointeger(L, 1);
    //����
    int result = msgKeyPress(key);
    // �����ѹ��Luaջ
    lua_pushnumber(L, result);
    // ���ؽ������������ѹ��ջ��������
    return 1;
}

//LIN016 sendString
int luaLSendString(lua_State* L) {
    // ��Luaջ�л�ȡ����
    string inputString = lua_tostring (L, 1);
    msgSendString(inputString);
    // �����ѹ��Luaջ
    // ���ؽ������������ѹ��ջ��������
    return 0;
}


//LIN017 sendStringToClipboard
int luaLSendStringToClipboard(lua_State* L) {
    // ��Luaջ�л�ȡ����
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





