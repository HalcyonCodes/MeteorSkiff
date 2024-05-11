#pragma once

#include "windows.h"

extern "C" {

#include "..\\LuaResource\lua.h"
#include "..\\LuaResource\lauxlib.h"
#include "..\\LuaResource\lualib.h"
}


using namespace std;


//调用过程：luaInit -> luaAddAllFunc -> luaRegistFuncs -> luaLoadScripts(加载外部lua的buff) -> luaExecuteBuff

typedef struct LuaExecutor {
	lua_State* L = luaL_newstate();
	luaL_Reg luaReg[150]; //最多150个函数
	int regCount = 0; //注册了多少个函数 
	char* scriptBuff; //由外部指定的lua脚本的buff
	void luaInit();//初始化
	void luaAddAFunc(const char* name, lua_CFunction func);
	void luaAddAllFunc(); //添加所有C++函数
	void luaRegistFuncs(); //注册lua函数
	void luaLoadScripts(char* actionManagerBuff); //装载要执行的lua脚本到buff区里
	void luaExecuteBuff(); //通过scriptBuff执行lua函数
}_LuaExecutor;

