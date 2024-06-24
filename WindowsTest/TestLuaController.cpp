

#include "Windows.h"
#include "ActionManager.h"
#include "OrderManager.h"
#include "LuaExecutor.h"
#include "DbgPrint.h"

void testLuaController() {

	//====��ʼ��====
	//this->orderManager = orderManager;

	ActionManager* actionManager = new ActionManager();
	LuaExecutor* luaExecutor = new LuaExecutor();

	//actionManager��ʼ��
	actionManager->loadAllScript(); //��������lua�ļ�

	//luaExecutor��ʼ��
	luaExecutor->luaInit(); //����lua����
	luaExecutor->luaAddAllFunc();  //�������lua�����Ա�ע��
	luaExecutor->luaRegistFuncs();  //ע������lua����
	//===========

	const char* scriptJson = "{\"script\":\"test\"}"; //����ָ��lua�ļ����Ƶ�json��ʽ�ַ���

	char* luaScript = actionManager->getScript(scriptJson);

	luaExecutor->luaLoadScripts(luaScript);

	//5.��ʼ����
	try
	{
		luaExecutor->luaExecuteBuff();
	}
	catch (...)
	{
		dbgPrint("lua�ű����ִ���");

	}
}