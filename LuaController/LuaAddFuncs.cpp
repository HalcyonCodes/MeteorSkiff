#include "pch.h"
#include "LuaExecutor.h"
#include "FindPicLuaFuncs.h"


void LuaExecutor::luaAddAllFunc() {
    //====调用路径：lua -> msg -> skill
    
    //====Test模块====
    LuaExecutor::luaAddAFunc("luaLTest", luaLTest);

    //====DbgPrint模块====
    LuaExecutor::luaAddAFunc("dbgPrint", luaLDbgPrint);

    //====FindPic模块====
    // LBM001
    LuaExecutor::luaAddAFunc("loadBmp", luaLLoadBmp);

    // LBM002
    LuaExecutor::luaAddAFunc("loadBmpSub", luaLLoadBmpSub);

    // LBM003
    LuaExecutor::luaAddAFunc("loadBmpList", luaLLoadBmpList);

    // LBM005
    LuaExecutor::luaAddAFunc("findPAPicA", luaLFindPAPicA);

    // LBM006
    LuaExecutor::luaAddAFunc("findDAPicA", luaLFindDAPicA);

    // LBM007
    LuaExecutor::luaAddAFunc("findSAPicA", luaLFindSAPicA);

    // LBM008
    LuaExecutor::luaAddAFunc("findPAPicN", luaLFindPAPicN);

    // LBM009
    LuaExecutor::luaAddAFunc("findDAPicN", luaLFindDAPicN);

    // LBM010
    LuaExecutor::luaAddAFunc("findSAPicN", luaLFindSAPicN);

    // LBM011
    LuaExecutor::luaAddAFunc("findLNPicA", luaLFindLNPicA);

    // LBM012
    LuaExecutor::luaAddAFunc("findLNPicN", luaLFindLNPicN);

}