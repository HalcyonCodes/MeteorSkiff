


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
	
	//actionManager��ʼ��
	actionManager->loadAllScript(); //��������lua�ļ�

	//luaExecutor��ʼ��
	luaExecutor->luaInit(); //����lua����
	luaExecutor->luaAddAllFunc();  //�������lua�����Ա�ע��
	luaExecutor->luaRegistFuncs();  //ע������lua����

}

int MeteorSkiffBot::botRun() {

	//1.���OrderManager����û�ж���
	string targetOrder = popServerOrder(orderManager); //ͨ��sendmessage������order�̷߳���hook��Ϣ
	
	if (targetOrder.length() == 0) {
		return -1; //-1��ʾû�ж���
	}

	Document doc;
	doc.Parse(targetOrder.c_str());
	string orderId = doc["orderId"].GetString();

	//2.���¶���״̬(��ʱ����)

	//3.����ű�
	this->actionManager->buildScript(targetOrder.c_str());

	//4.luaִ�������ؽű�
	char* luaScript = this->actionManager->script;
	this->luaExecutor->luaLoadScripts(luaScript);

	//5.��ʼ����
	try
	{
		this->luaExecutor->luaExecuteBuff();
	}
	catch (...)
	{
		dbgPrint("lua�ű����ִ���");
		return -2; //-2��ʾlua�ű�������
	}

	//6.���ͽű����״̬
	string status = "complete";
	sendOrderStatus(this->orderManager, orderId, status);


	return 0;
}




