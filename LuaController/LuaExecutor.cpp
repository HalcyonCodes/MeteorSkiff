

#include "pch.h"
#include "Windows.h"

extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

}

#include "LuaExecutor.h"
#include <string>

//调用过程：luaInit -> luaAddAllFunc -> luaRegistFuncs -> luaLoadScripts(加载外部lua的buff) -> luaExecuteBuff

void LuaExecutor::luaInit() {
	this->L = luaL_newstate();
	return;
}


void LuaExecutor::luaRegistFuncs() {
	for (int i = 0; i <= this -> regCount - 1; i++) {
		lua_pushcfunction(L, luaReg[i].func);
		lua_setglobal(L, luaReg[i].name);
		//dbgPrint("name:%s", luaReg[i].name);
	}
	return;
}

void LuaExecutor::luaAddAFunc(const char* name, lua_CFunction func) {
	this -> regCount++;
	luaReg[regCount - 1].name = name;
	luaReg[regCount - 1].func = func;
	return;
}

void LuaExecutor::luaLoadScripts(char*& actionManagerBuff) {
	this->scriptBuff = actionManagerBuff;
	luaL_loadbufferx(this->L, this->scriptBuff, strlen(this->scriptBuff), "ActionBot", NULL);
	return;
}

void LuaExecutor::luaExecuteBuff() {
	typedef int (*LuaPCall)(lua_State*, int, int, int, lua_KContext, lua_KFunction);
	//LuaPCall luaPCall = (LuaPCall)(staticNewModule + (QWORD)lua_pcallk - staticHModule);
	LuaPCall luaPCall = (LuaPCall)lua_pcallk;
	int i = (*luaPCall)(this->L, 0, 0, 0, 0, NULL);
	return;
}
