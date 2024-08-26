

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
	
	//actionManager��ʼ��
	int r = actionManager->loadAllScript(); //��������lua�ļ�

	//luaExecutor��ʼ��
	//luaExecutor->luaInit(); //����lua����
	//luaExecutor->luaAddAllFunc();  //�������lua�����Ա�ע��
	//luaExecutor->luaRegistFuncs();  //ע������lua����

}

int MeteorSkiffBot::botRun() {

	//������ѭ��
	while (true)
	{
		//string test = msgOrderTest(orderManager);
		
		//1.���OrderManager����û�ж���
		string targetOrder = msgPopServerOrder(orderManager); //ͨ��sendmessage������order�̷߳���hook��Ϣ
	    
		
		if (targetOrder.length() == 0) {
			//û�ж���ʱ������
		}
		else
		{
			//0.��ʼ��luaִ����
			this->luaExecutor = new LuaExecutor();
			//luaExecutor��ʼ��
            luaExecutor->luaInit(); //����lua����
            luaExecutor->luaAddAllFunc();  //�������lua�����Ա�ע��
            luaExecutor->luaRegistFuncs();  //ע������lua����


			//1.����ű�
			this->actionManager->buildScript(targetOrder.c_str());

			//2.luaִ�������ؽű�
			//char* luaScript = this->actionManager->script;
			this->luaExecutor->luaLoadScripts(this->actionManager->script); //luaL_loadbuffer�������ڴ�й©����
			if (this->actionManager->script != nullptr) {
				delete[] this->actionManager->script;
				this->actionManager->script = nullptr;
			}

			//3.��ʼ����
			try
			{
				this->luaExecutor->luaExecuteBuff();
			}
			catch (...)
			{
				dbgPrint("lua�ű����ִ���");
				return -2; //-2��ʾlua�ű�������
			}


			//4.���ͽű����״̬

			int status;
			Document doc;
			doc.Parse(targetOrder.c_str());
			string orderId = doc["orderId"].GetString();
			status = 1;
			msgSendOrderStatus(orderManager, orderId, status);

			//7.����luaִ����
			luaExecutor->luaExit();
			delete  this->luaExecutor;
			this->luaExecutor = nullptr;
		
		}
	

	}

	return 0;
}




