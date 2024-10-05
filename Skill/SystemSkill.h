#pragma once
#include "windows.h"
#include <string>


using namespace std;


typedef struct SystemSkill
{
    //SS001
    void setClipBoardText(string text); //ÉèÖÃÕ³Ìù°åÄÚÈİ
    //SS002
    string GetClipBoardText(); //»ñÈ¡Õ³Ìù°åÄÚÈİ
    //SS003
    void pasteClipBoardText(); //Õ³Ìù×Ö·û´®

}_SystemSkill;