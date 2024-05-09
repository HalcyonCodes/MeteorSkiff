#pragma once

extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"
}

//���ù��̣�luaInit -> luaAddAllFunc -> luaRegistFuncs -> luaLoadScripts(�����ⲿlua��buff) -> luaExecuteBuff

typedef struct LuaExecutor {
	lua_State* L;
	luaL_Reg luaReg[150]; //���150������
	int regCount = 0; //ע���˶��ٸ����� 
	char* scriptBuff; //���ⲿָ����lua�ű���buff
	void luaInit();//��ʼ��
	void luaAddAFunc(const char* name, lua_CFunction func);
	void luaAddAllFunc(); //��������C++����
	void luaRegistFuncs(); //ע��lua����
	void luaLoadScripts(char*& actionManagerBuff); //װ��Ҫִ�е�lua�ű���buff����
	void luaExecuteBuff(); //ͨ��scriptBuffִ��lua����
}_LuaExecutor;
