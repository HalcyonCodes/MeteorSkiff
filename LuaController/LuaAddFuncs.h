#pragma once
#include "LuaExecutor.h"
#include "FindPicLuaFuncs.h"

//添加所有C++函数

void LuaExecutor::luaAddAllFunc() {
    //====调用路径：lua -> msg -> skill
    //====FindPic模块====
    // LBM001
    LuaExecutor::luaAddAFunc("luaLLoadBmp", luaLLoadBmp);

    // LBM002
    LuaExecutor::luaAddAFunc("luaLLoadBmpSub", luaLLoadBmpSub);

    // LBM003
    LuaExecutor::luaAddAFunc("luaLLoadBmpList", luaLLoadBmpList);

    // LBM005
    LuaExecutor::luaAddAFunc("luaLFindPAPicA", luaLFindPAPicA);

    // LBM006
    LuaExecutor::luaAddAFunc("luaLFindDAPicA", luaLFindDAPicA);

    // LBM007
    LuaExecutor::luaAddAFunc("luaLFindSAPicA", luaLFindSAPicA);

    // LBM008
    LuaExecutor::luaAddAFunc("luaLFindPAPicN", luaLFindPAPicN);

    // LBM009
    LuaExecutor::luaAddAFunc("luaLFindDAPicN", luaLFindDAPicN);

    // LBM010
    LuaExecutor::luaAddAFunc("luaLFindSAPicN", luaLFindSAPicN);

    // LBM011
    LuaExecutor::luaAddAFunc("luaLFindLNPicA", luaLFindLNPicA);

    // LBM012
    LuaExecutor::luaAddAFunc("luaLFindLNPicN", luaLFindLNPicN);

}
