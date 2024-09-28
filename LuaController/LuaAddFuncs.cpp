#include "pch.h"
#include "LuaExecutor.h"
#include "FindPicLuaFuncs.h"
#include "ToolLuaFuncs.h"
#include "InputLuaFuncs.h"



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

    // LBM013
    LuaExecutor::luaAddAFunc("freeBmp", luaLFreeBmp);

    //====InputAction模块====
    // LIN001
    LuaExecutor::luaAddAFunc("inputInit", luaLInputInit);

    // LIN002
    LuaExecutor::luaAddAFunc("lClickDown", luaLLeftClickDown);

    // LIN003
    LuaExecutor::luaAddAFunc("rClickDown", luaLRightClickDown);
    
    // LIN004
    LuaExecutor::luaAddAFunc("mClickDown", luaLMidClickDown);
    
    // LIN005
    LuaExecutor::luaAddAFunc("lClickUp", luaLLeftClickUp);
    
    // LIN006
    LuaExecutor::luaAddAFunc("rClickUp", luaLRightClickUp);
    
    // LIN007
    LuaExecutor::luaAddAFunc("mClickUp", luaLMidClickUp);
    
    // LIN008
    LuaExecutor::luaAddAFunc("moveTo", luaLMoveTo);
    
    // LIN009
    LuaExecutor::luaAddAFunc("moveToChange", luaLMoveToChange);
    
    // LIN010
    LuaExecutor::luaAddAFunc("mOnClick", luaLMidOnClick);
    
    // LIN011
    LuaExecutor::luaAddAFunc("lOnClick", luaLLeftOnClick);
    
    // LIN012
    LuaExecutor::luaAddAFunc("rOnClick", luaLRightOnClick);
    
    // LIN013
    LuaExecutor::luaAddAFunc("keyDown", luaLKeyDown);
    
    // LIN014
    LuaExecutor::luaAddAFunc("keyUp", luaLKeyUp);

    // LOR001
    //LuaExecutor::luaAddAFunc("createOrder", luaLCreateOrder);


}