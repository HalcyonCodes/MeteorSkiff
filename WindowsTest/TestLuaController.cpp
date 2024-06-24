

#include "Windows.h"
#include "ActionManager.h"
#include "OrderManager.h"
#include "LuaExecutor.h"
#include "DbgPrint.h"

void testLuaController() {

	//====初始化====
	//this->orderManager = orderManager;

	ActionManager* actionManager = new ActionManager();
	LuaExecutor* luaExecutor = new LuaExecutor();

	//actionManager初始化
	actionManager->loadAllScript(); //加载所有lua文件

	//luaExecutor初始化
	luaExecutor->luaInit(); //创建lua环境
	luaExecutor->luaAddAllFunc();  //添加所有lua函数以便注册
	luaExecutor->luaRegistFuncs();  //注册所有lua函数
	//===========

	const char* scriptJson = "{\"script\":\"test\"}"; //用于指定lua文件名称的json格式字符串

	char* luaScript = actionManager->getScript(scriptJson);

	luaExecutor->luaLoadScripts(luaScript);

	//5.开始调用
	try
	{
		luaExecutor->luaExecuteBuff();
	}
	catch (...)
	{
		dbgPrint("lua脚本出现错误");

	}
}