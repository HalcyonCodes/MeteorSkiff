#pragma once
#include "windows.h"
#include <string>


using namespace std;


typedef struct SystemSkill
{
    //SS001
    void setClipBoardText(string text); //����ճ��������
    //SS002
    string GetClipBoardText(); //��ȡճ��������
    //SS003
    void pasteClipBoardText(); //ճ���ַ���

}_SystemSkill;