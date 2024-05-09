// Test.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>

#include <Windows.h>
#include "TestSkill.h"


#include <thread>

int main()
{
    //====test skill====
    testSkill();

    //====test action====
    //std::thread t(testBotController);
    //t.join();

    
    //====test connet====


    std::cout << "Hello World!\n";
}


