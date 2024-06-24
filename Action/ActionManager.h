#pragma once
#include <map>
#include <string>
#include <list>

using namespace std;

//这里用来管理脚本，并且加载脚本代码字符到内存

typedef struct ActionManager {


	char* script = nullptr; //最终构造的脚本字符串

	std::map<std::string, char*> scripts;  //存放所有基本的脚本文件

	int loadAllScript(); //加载LuaScripts文件夹里的所有文件

	char* getScript(const char* json); //获取内存里script文件

	char* getScriptPara(const char* json); //通过json构造输入lua脚本的参数

	void buildScript(const char* json); //通过json构造lua脚本

}_ActionManager;




