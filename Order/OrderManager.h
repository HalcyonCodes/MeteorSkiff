#pragma once

#include <list>
#include <string>
#include "OrderManager.h"

using namespace std;



typedef struct OrderManager {
	
	//--
	const char* testChar = "testChar";
	//--
	list<const char*> orders;
	char* serverIp; //������ip��ַ
	char* port; //�������˿�
	char* botAccount; //�������˻�
	char* botPwd; //����������
	char* serverResult; //����������json�ַ���
	char* jwt; //���������ŵ�����
	char* httpResultBody; //http�������body���ַ���
    char* terminalID; //��ȡ�ն˵�id
    char* terminalIP; //�ն�ip
	void init(); //��ȡ�����ļ�����ȡip�Ͷ˿�
	void addServerOrders(); //��json�ַ��������ɶ���ѹ�붩��ջ
	string popServerOrder();  //��ջ������һ�����������Ҵ�orders��ɾ���Ǹ��������Ķ���

	void pullServerOrders(); //����������󶩵�
	void login(); //����������͵�¼���󣬻�ȡjwt����
	int sendOrderStatus(const char* orderId, int status); //��һ���߳���ɶ�����,����������Ͷ������״̬��֪ͨ������ɾ������
    int terminalInit(); //��ʼ���ն�
    int httpPost(string ip, string port, string http, string data); //����post����
    
}_OrderManager;

extern OrderManager* orderManager;
extern char* terminalID;
extern char* JWT;

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

/*
{
  "code": "string", // ���磺"200"
  "message": "string", // ���磺"�����ɹ�"
  "orderChannels": [
    {
      "orderChannelID": "GUID", // ���磺"12345678-abcd-1234-abcd-1234567890ab"
      "orderChannelLevel": 1,
      "orders": [
        {
          "orderID": "GUID", // ���磺"87654321-dcba-4321-dcba-9876543210fe"
          "orderService": {
            // ����ʡ���� OrderServiceViewModel �ľ�������
          },
          "createdTime": "date-time", // ���磺"2024-08-21T12:00:00Z"
          "sourceTerminalID": "GUID",
          "targetTerminalID": "GUID",
          "status": 1, // ö��ֵ�����磺1 ��Ӧ working
          "orderServiceResources": [
            {
              "orderServiceResourceClasssID": "GUID",
              "createdTime": "date-time",
              "orderServiceResource": {
                // ����ʡ���� OrderServiceResourceViewModel �ľ�������
              },
              "resourceIntValue": 123,
              "resourceStringValue": "string",
              "resourceDoubleValue": 123.45
            }
            // �����и��� OrderServiceResourceClassesViewModel ����
          ]
        }
        // �����и��� OrderViewModel ����
      ]
    }
    // �����и��� OrderChannelViewModel ����
  ]
}
*/

/*
{
  "orderChannelLevel": 1,
  "order": [
    {
      "orderID": "3fa85f64-5717-4562-b3fc-2c963f66afa6",
      "orderService": {
        "orderServiceID": 1001
      },
      "sourceTerminalID": "abcdefg",
      "targetTerminalID": "Target123",
      "orderServiceResources": [
        {
          
          "resourceIntValue": 1,
          "resourceStringValue": "one",
          "resourceDoubleValue": 1.1
        },
        {
         
          "resourceIntValue": 2,
          "resourceStringValue": "two",
          "resourceDoubleValue": 2.2
        },
        {
          "resourceIntValue": 3,
          "resourceStringValue": "three",
          "resourceDoubleValue": 3.3
        }
      ]
    }
  ]
}
*/
