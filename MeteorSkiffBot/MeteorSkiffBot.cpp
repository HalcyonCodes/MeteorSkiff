

#include "pch.h"
#include "Windows.h"
#include "MeteorSkiffBot.h"
#include "ActionManager.h"
#include "OrderManager.h"
#include "LuaExecutor.h"

#include "rapidjson/document.h"
#include "rapidjson/error/en.h"
#include "DbgPrint.h"
#include "OrderController.h"




using namespace rapidjson;

void MeteorSkiffBot::botInit() {
	this->actionManager = new ActionManager();
	//this->luaExecutor = new LuaExecutor();
	
	//actionManager初始化
	int r = actionManager->loadAllScript(); //加载所有lua文件

	//luaExecutor初始化
	//luaExecutor->luaInit(); //创建lua环境
	//luaExecutor->luaAddAllFunc();  //添加所有lua函数以便注册
	//luaExecutor->luaRegistFuncs();  //注册所有lua函数

}

int MeteorSkiffBot::botRun() {

	//机器人循环
	while (true)
	{
		//string test = msgOrderTest(orderManager);
		
		//1.检查OrderManager里有没有订单
		string targetOrder = msgPopServerOrder(orderManager); //通过sendmessage方法向order线程发送hook消息
	    
		
		if (targetOrder.length() == 0) {
			//没有订单时不工作
		}
		else
		{
			//0.初始化lua执行器
			this->luaExecutor = new LuaExecutor();
			//luaExecutor初始化
            luaExecutor->luaInit(); //创建lua环境
            luaExecutor->luaAddAllFunc();  //添加所有lua函数以便注册
            luaExecutor->luaRegistFuncs();  //注册所有lua函数


			//1.构造脚本
			this->actionManager->buildScript(targetOrder.c_str());

			//2.lua执行器加载脚本
			//char* luaScript = this->actionManager->script;
			this->luaExecutor->luaLoadScripts(this->actionManager->script); //luaL_loadbuffer函数有内存泄漏问题
			if (this->actionManager->script != nullptr) {
				delete[] this->actionManager->script;
				this->actionManager->script = nullptr;
			}

			//3.开始调用
			try
			{
				this->luaExecutor->luaExecuteBuff();
			}
			catch (...)
			{
				dbgPrint("lua脚本出现错误");
				return -2; //-2表示lua脚本有问题
			}


			//4.发送脚本完成状态

			int status;
			Document doc;
			doc.Parse(targetOrder.c_str());
			string orderId = doc["orderId"].GetString();
			status = 1;
			msgSendOrderStatus(orderManager, orderId, status);

			//7.清理lua执行器
			luaExecutor->luaExit();
			delete  this->luaExecutor;
			this->luaExecutor = nullptr;
		
		}
	

	}

	return 0;
}




