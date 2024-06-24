#pragma once
#include <map>
#include <string>
#include <list>

using namespace std;

//������������ű������Ҽ��ؽű������ַ����ڴ�

typedef struct ActionManager {


	char* script = nullptr; //���չ���Ľű��ַ���

	std::map<std::string, char*> scripts;  //������л����Ľű��ļ�

	int loadAllScript(); //����LuaScripts�ļ�����������ļ�

	char* getScript(const char* json); //��ȡ�ڴ���script�ļ�

	char* getScriptPara(const char* json); //ͨ��json��������lua�ű��Ĳ���

	void buildScript(const char* json); //ͨ��json����lua�ű�

}_ActionManager;




