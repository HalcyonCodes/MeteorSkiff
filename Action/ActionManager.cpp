#include "pch.h"
#include "Windows.h"
#include "ActionManager.h"
#include <vector>
#include "dbgPrint.h"

#include <string>
#include <iostream>
#include <fstream>

#include "rapidjson/document.h"
#include "rapidjson/error/en.h"
#include <list>

using namespace rapidjson;

int ActionManager::loadAllScript() {
    char dirPathName[MAX_PATH] = {};
    GetModuleFileNameA(GetModuleHandle(NULL), dirPathName, MAX_PATH);
    std::string path = dirPathName;
    path = path.substr(0, path.rfind("\\"));
    path = path + "\\LuaScripts";

    // Use Windows API to list files in the directory
    std::vector<std::string> fileNames;
    WIN32_FIND_DATAA findFileData;
    HANDLE hFind = FindFirstFileA((path + "\\*").c_str(), &findFileData);
    if (hFind == INVALID_HANDLE_VALUE) {
        dbgPrint("错误：无法在目录中找到文件：%s", path.c_str());
        return -1;
    }

    int count = 0;
    do {
        if (!(findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
            std::string fileName = findFileData.cFileName;
            // 去除文件扩展名
            size_t dotPos = fileName.find_last_of(".");
            if (dotPos != std::string::npos) {
                fileName = fileName.substr(0, dotPos);
            }

            fileNames.push_back(fileName);

            std::string fullPath = path + "\\" + findFileData.cFileName;
            dbgPrint("路径：%s", fullPath.c_str());

            std::string content;
            std::ifstream file(fullPath);
            if (!file.is_open()) {
                dbgPrint("错误：无法打开文件：%s", fullPath.c_str());
                continue;
            }

            std::string line;
            while (std::getline(file, line)) {
                dbgPrint("行：%s", line.c_str());
                content += line;
                content += '\n';
            }

            file.close();
            dbgPrint("内容大小：%d", content.size());

            char* bufTemp = new char[content.size() + 1];
            // 根据需要使用bufTemp
            memcpy(bufTemp, content.c_str(), content.size());
            bufTemp[content.size()] = '\0';
            this->scripts[fileName] = bufTemp;
            count++;
        }
    } while (FindNextFileA(hFind, &findFileData) != 0);

    FindClose(hFind);

    return count;
}

char* ActionManager::getScript(const char* json) {
    //获取"script"字段下的脚本名称
    Document doc;
    doc.Parse(json);
    if (doc.HasParseError()) {
        dbgPrint("Para Parse Error");
        this->script = nullptr;
    }

    return scripts[doc["script"].GetString()];
}

char* ActionManager::getScriptPara(const char* json) {
    Document doc;
    doc.Parse(json);
    if (doc.HasParseError()) {
        dbgPrint("Para Parse Error");
        return nullptr;
    }

    std::list<const char*> keyList;

    std::string luaCommond = "para = {} \n";
    

    //lua脚本参数格式： para["参数名称"] = 参数数值
    if (doc.IsObject()) {
        // 遍历所有成员
        for (Value::ConstMemberIterator itr = doc["orderParas"] .MemberBegin(); itr != doc["orderParas"].MemberEnd(); ++itr) {
            std::string nextRow = "";
            nextRow = "para[" + std::string(itr->name.GetString()) + "]" + " = " + itr->value.GetString();
            luaCommond = luaCommond + nextRow;
            luaCommond = luaCommond + "\n";
        }
    }

    size_t len = luaCommond.length();
    char* charPtr = new char[len + 1];
    strcpy_s(charPtr, len + 1, luaCommond.c_str());
    return charPtr;

}

void ActionManager::buildScript(const char* json) {
    if (this->script != nullptr) {
        delete[] this->script;
        this->script = nullptr;
    }

    char* scriptPara = this->getScriptPara(json);
    char* sourceScript = this->getScript(json);
    char* buildScript = new char[strlen(scriptPara) + strlen(sourceScript) + 3];
    strcat_s(buildScript, strlen(scriptPara) + 1, scriptPara);
    strcat_s(buildScript, strlen(sourceScript) + 1, sourceScript);

    delete[] scriptPara;
    delete[] sourceScript;
    this->script = buildScript;
    return;
}


