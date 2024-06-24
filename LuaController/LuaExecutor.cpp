 

#include "pch.h"
#include "Windows.h"

extern "C" {
#include "lua.h"
#include "lauxlib.h"
#include "lualib.h"

}


#include "LuaExecutor.h"
#include <string>
#include "DbgPrint.h"

//调用过程：luaInit -> luaAddAllFunc -> luaRegistFuncs -> luaLoadScripts(加载外部lua的buff) -> luaExecuteBuff

void LuaExecutor::luaInit() {
	//this->L = luaL_newstate();
	luaL_openlibs(this->L);
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

void LuaExecutor::luaLoadScripts(char* actionManagerBuff) {
	//this->scriptBuff = actionManagerBuff;
	//dbgPrint("Buff:%s", this->scriptBuff);
	int i = luaL_loadbuffer(this->L, actionManagerBuff, strlen(actionManagerBuff), "ActionBot", NULL);
	//int q = lua_pcall(L, 0, LUA_MULTRET, 0);
	//if (this->scriptBuff != nullptr) {
	//	delete[] this->scriptBuff;
	//	this->scriptBuff = nullptr;
	//}
	return;
}

void LuaExecutor::luaExecuteBuff() {
	typedef int (*LuaPCall)(lua_State*, int, int, int, lua_KContext, lua_KFunction);
	//LuaPCall luaPCall = (LuaPCall)(staticNewModule + (QWORD)lua_pcallk - staticHModule);
	LuaPCall luaPCall = (LuaPCall)lua_pcallk;
	int i = (*luaPCall)(this->L, 0, 0, 0, 0, NULL);
	//int i = lua_pcallk(this->L, 0, 0, 0, 0, NULL);
	return;
}

void LuaExecutor::luaExit() {
	lua_close(L);
}
