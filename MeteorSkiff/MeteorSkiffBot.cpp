


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

void MeteorSkiffBot::botInit(OrderManager* orderManager) {
	this->orderManager = orderManager;
	this->actionManager = new ActionManager();
	this->luaExecutor = new LuaExecutor();
	
	//actionManager初始化
	actionManager->loadAllScript(); //加载所有lua文件

	//luaExecutor初始化
	luaExecutor->luaInit(); //创建lua环境
	luaExecutor->luaAddAllFunc();  //添加所有lua函数以便注册
	luaExecutor->luaRegistFuncs();  //注册所有lua函数

}

int MeteorSkiffBot::botRun() {

	//1.检查OrderManager里有没有订单
	string targetOrder = popServerOrder(orderManager); //通过sendmessage方法向order线程发送hook消息
	
	if (targetOrder.length() == 0) {
		return -1; //-1表示没有订单
	}

	Document doc;
	doc.Parse(targetOrder.c_str());
	string orderId = doc["orderId"].GetString();

	//2.更新订单状态(暂时忽略)

	//3.构造脚本
	this->actionManager->buildScript(targetOrder.c_str());

	//4.lua执行器加载脚本
	char* luaScript = this->actionManager->script;
	this->luaExecutor->luaLoadScripts(luaScript);

	//5.开始调用
	try
	{
		this->luaExecutor->luaExecuteBuff();
	}
	catch (...)
	{
		dbgPrint("lua脚本出现错误");
		return -2; //-2表示lua脚本有问题
	}

	//6.发送脚本完成状态
	string status = "complete";
	sendOrderStatus(this->orderManager, orderId, status);


	return 0;
}




