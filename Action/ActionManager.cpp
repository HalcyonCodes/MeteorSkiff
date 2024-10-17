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

#include "GBKToUTF8.h"


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
        dbgPrint("�����޷���Ŀ¼���ҵ��ļ���%s", path.c_str());
        return -1;
    }

    int count = 0;
    do {
        if (!(findFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)) {
            std::string fileName = findFileData.cFileName;
            // ȥ���ļ���չ��
            size_t dotPos = fileName.find_last_of(".");
            if (dotPos != std::string::npos) {
                fileName = fileName.substr(0, dotPos);
            }

            fileNames.push_back(fileName);

            std::string fullPath = path + "\\" + findFileData.cFileName;
            //dbgPrint("·����%s", fullPath.c_str());
  
            std::string content;
            std::ifstream file(fullPath);
            
            if (!file.is_open()) {
               // dbgPrint("�����޷����ļ���%s", fullPath.c_str());
                continue;
            }

            std::string line;
            //std::string temp;
            while (std::getline(file, line)) {
                line = line + "\0"; //������Ҫע���lua�ļ����ΪANSI����,��Ȼ���Ļ�����
                //temp = String::Utf8ToAnsi(line);
                //temp = String::AnsiToUtf8(line);
                content += line;
                content += '\n';
            }
           
            content = content + "\0";

            //dbgPrint("gbkTest��%s", content.c_str());
            file.close();

            char* bufTemp = new char[content.length() + 2];
            strcpy_s(bufTemp, content.length() + 1, content.c_str());
            bufTemp[content.length() + 2] = '\0';
            this->scripts[fileName] = bufTemp;
            //dbgPrint("aaasr:%s", this->scripts[fileName]);
            count++;
        }
    } while (FindNextFileA(hFind, &findFileData) != 0);

    FindClose(hFind);

    return count;
}

char* ActionManager::getScript(const char* json) {

    //��ȡ"script"�ֶ��µĽű�����
    Document doc;
    doc.Parse(json);
    if (doc.HasParseError()) {
        //dbgPrint("Para Parse Error");
        this->script = nullptr;
    }
    string name = doc["script"].GetString();
    size_t dotPos = name.find_last_of(".");
    
        // ��ȡ�ӿ�ʼ����֮ǰ���ַ���������ֵ�� scriptName
    string newName = name.substr(0, dotPos);
    
    //dbgPrint("sssss : %s", newName.c_str());

    char* result = scripts[newName];

    return result;
}

char* ActionManager::getScriptPara(const char* json) {
    Document doc;

    doc.Parse(json);
    if (doc.HasParseError()) {
       // dbgPrint("Para Parse Error");
        return nullptr;
    }
    std::list<const char*> keyList;
    std::string luaCommond = "para = {} \n";
    
    //lua�ű�������ʽ�� para["��������"] = ������ֵ
  if (doc.IsObject()) {
    // ��� "orderParas" �Ƿ���ڲ�����һ������
    if (doc.HasMember("orderParas") && doc["orderParas"].IsArray()) {
        const auto& orderParas = doc["orderParas"].GetArray();

        //dbgPrint("Order Paras Array Size: %zu\n", orderParas.Size());

        // ���� "orderParas" ����
        for (const auto& para : orderParas) {
            if (para.IsObject()) {
                for (const auto& kv : para.GetObject()) {
					std::string nextRow;
					if (kv.value.IsInt()) {
						nextRow = "para[\"" + std::string(kv.name.GetString()) + "\"] = " + std::to_string(kv.value.GetInt()) + ";";
					}
					if (kv.value.IsString()) {
						nextRow = "para[\"" + std::string(kv.name.GetString()) + "\"] = \"" + std::string(kv.value.GetString()) + "\";";
					}
					if (kv.value.IsDouble()) {
						nextRow = "para[\"" + std::string(kv.name.GetString()) + "\"] = " + std::to_string(kv.value.GetDouble()) + ";";
					}
					if (kv.value.IsBool()) {
						nextRow = "para[\"" + std::string(kv.name.GetString()) + "\"] = " + std::to_string(kv.value.GetBool()) + ";";
					}

                    luaCommond += nextRow;
                    luaCommond += "\n";
                }
            }
        }
    }
}
    size_t len = luaCommond.length();
    char* charPtr = new char[len + 1];

    strcpy_s(charPtr, len + 1, luaCommond.c_str());
    charPtr[len] = '\0';
    dbgPrint("para : %s", charPtr);
    return charPtr;

}

void ActionManager::buildScript(const char* json) {

    if (this->script != nullptr) {
        delete[] this->script;
        this->script = nullptr;
    }

    char* scriptPara = this->getScriptPara(json);
    char* sourceScript = this->getScript(json);
    char* resultScript = new char[strlen(scriptPara) + strlen(sourceScript) + 1];
    memset(resultScript, 0x00, sizeof(*resultScript));
    strcat_s(resultScript, strlen(scriptPara) + strlen(sourceScript) + 1, scriptPara);
    strcat_s(resultScript, strlen(scriptPara) + strlen(sourceScript) + 1, sourceScript);
    //dbgPrint("script: %s", resultScript);
    delete[] scriptPara;
    //delete[] sourceScript;
    this->script = resultScript;
    return;
  
}


