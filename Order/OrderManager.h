#pragma once

#include <list>
#include <string>
#include "OrderManager.h"

using namespace std;



typedef struct OrderManager {
	
	//--
	const char* testChar = "testChar";
	//--
	list<const char*> orders; //���ж���
	char* serverIp; //������ip��ַ
	char* port; //�������˿�
	char* botAccount; //�������˻�
	char* botPwd; //����������
	char* serverResult; //����������json�ַ���
	char* jwt; //���������ŵ�����
	char* httpResultBody; //http�������body���ַ���
	void init(); //��ȡ�����ļ�����ȡip�Ͷ˿�
	void addServerOrders(); //��json�ַ��������ɶ���ѹ�붩��ջ
	string popServerOrder();  //��ջ������һ�����������Ҵ�orders��ɾ���Ǹ��������Ķ���
	void pullServerOrders(); //����������󶩵�
	void login(); //����������͵�¼���󣬻�ȡjwt����
	int sendOrderStatus(const char* orderId, const char* status); //��һ���߳���ɶ�����,����������Ͷ������״̬��֪ͨ������ɾ������

}_OrderManager;

extern OrderManager* orderManager;



/* json ��ʽ��
{
  "orders":[
    {
        "stackIndex": 0,
        "orderId":"12345",
        "orderName":"orderName",
        "createTime":"2024/4/30 6:45",
        "orderParas":{"paraName1": "paraValue", "paraName2": "paraValue"},
        "script":"scriptName",
        "status":"wait"
    }
]
}

*/

