
#include <Windows.h>
#include "Skill.h"
#include <OrderSkill.h>

using namespace std;
#using <System.Drawing.dll>
using namespace System::Drawing;
using namespace System::Drawing::Imaging;




void testSkill() {

    BmpColor bmpColor;

    //GetScreen 001
    //HWND hWnd =  findWindow("Notepad", "testNot - Notepad");
    // HWND hWnd = findWindow("Chrome_WidgetWin_1", "广发操盘手");
    //printf("hwnd is %d", hWnd);


    //GetScreen 002;
    //System::Drawing::Bitmap^ b = getWindow(hWnd);

    //GetScreen 003;
    //System::Drawing::Bitmap^ b =  getDeskTop();

    //GetScreen 004
    //saveBitMap(b, "testBmp", "C:\\Users\\reddock\\Desktop\\BMPTEST\\");

    //GetScreen 005
    //saveBitMapByOffset( b, 50, 100, 100, 200, "testBmp2", "C:\\Users\\reddock\\Desktop\\BMPTEST\\");

    //===========================

    //BmpColor 001
    //bmpColor.loadBmp("C:\\Users\\reddock\\Desktop\\BMPTEST\\testFincPic1.bmp|C:\\Users\\reddock\\Desktop\\BMPTEST\\testFincPic2.bmp");

    //BmpColor 002
    //bmpColor.loadBmpSub("C:\\Users\\reddock\\Desktop\\BMPTEST\\testFincPic1.bmp|C:\\Users\\reddock\\Desktop\\BMPTEST\\testFincPic2.bmp");

    //BmpColor 003
    //bmpColor.loadBmpList("C:\\Users\\reddock\\Desktop\\BMPTEST\\testFincPic1.bmp|C:\\Users\\reddock\\Desktop\\BMPTEST\\testFincPic2.bmp");

    //BmpColor 004
    //freeBmp();

    //BmpColor 005
    //int* r = bmpColor.findPAPicA(nullptr, 0, 0, 1024, 1920, "C:\\Users\\reddock\\Desktop\\BMPTEST\\testFincPic1.bmp", 32);
    //printf("x: %d", r[0]);
    //printf("y: %d", r[1]);
    //delete(r);

    //BmpColor 006
    //int* r = findDAPicA(nullptr, 0, 0, 1024, 1920, "testFincPic1", 32);
    //printf("x: %d", r[0]);
    //printf("y: %d", r[1]);
    //delete(r);

    //BmpColor 007
   // int* r = bmpColor.findSAPicA(nullptr, 0, 0, 1024, 1920, "testFincPic1", 32);
    //printf("x: %d", r[0]);
    //printf("y: %d", r[1]);
    //delete(r);

    //BmpColor 008
    /*
    while (true) {
        int** r = findPAPicN(nullptr, 0, 0, 1024, 1920, "C:\\Users\\reddock\\Desktop\\BMPTEST\\testFincPic1.bmp", 32);
        printf("x: %d", r[0][0]);
        printf("y: %d", r[0][1]);
        printf("\n");
        printf("x: %d", r[1][0]);
        printf("y: %d", r[1][1]);
        printf("\n");
        int i = 0;
        while (true) {
            int q = r[i][0];
            delete[] r[i];
            i++;
            if (q == -1) {
                break;
            }
        };
        delete[] r;
    }*/

    //BmpColor 009
    /*
    while (true) {
        int** r = findDAPicN(nullptr, 0, 0, 1024, 1920, "testFincPic1", 32);
        printf("x: %d", r[0][0]);
        printf("y: %d", r[0][1]);
        printf("\n");
        printf("x: %d", r[1][0]);
        printf("y: %d", r[1][1]);
        printf("\n");
        int i = 0;
        while (true) {
            int q = r[i][0];
            delete[] r[i];
            i++;
            if (q == -1) {
                break;
            }
        };
        delete[] r;
    }*/

    //BmpColor 010 从loadBmpSub加载的图片中按图片名称找1个图多个位置
    /*while (true) {
        int** r = findSAPicN(nullptr, 0, 0, 1024, 1920, "testFincPic1", 32);
        printf("x: %d", r[0][0]);
        printf("y: %d", r[0][1]);
        printf("\n");
        printf("x: %d", r[1][0]);
        printf("y: %d", r[1][1]);
        printf("\n");
        int i = 0;
        while (true) {
            int q = r[i][0];
            delete[] r[i];
            i++;
            if (q == -1) {
                break;
            }
        };
        delete[] r;
    }*/

    //BmpColor 011
    //int* findLNPicA(HWND hWnd, int left, int top, int right, int bottom, int similar);
    /*while (true) {
        int* r = findLNPicA(nullptr, 0, 0, 1024, 1920, 32);
        printf("x: %d", r[0]);
        printf("\n");
        printf("y: %d", r[1]);
        printf("\n");
        printf("index: %d", r[2]);
        printf("\n");
        delete[] r;
    }*/
     

    //BmpColor 012
    /*while (true) {
        int** r = findLNPicN(nullptr, 0, 0, 1024, 1920, 32);
        printf("x: %d", r[0][0]);
        printf("y: %d", r[0][1]);
        printf("index: %d", r[0][2]);
        printf("\n");
        printf("x: %d", r[1][0]);
        printf("y: %d", r[1][1]);
        printf("index: %d", r[1][2]);
        printf("\n");
        printf("x: %d", r[2][0]);
        printf("y: %d", r[2][1]);
        printf("index: %d", r[2][2]);
        printf("\n");
        printf("x: %d", r[3][0]);
        printf("y: %d", r[3][1]);
        printf("index: %d", r[3][2]);
        printf("\n");
        int i = 0;
        while (true) {
            int q = r[i][0];
            delete[] r[i];
            i++;
            if (q == -1) {
                break;
            }
        };
        delete[] r;
    }*/


     //====InputAction====
     InputAction inputAction;

     //InpuitAction 001
     //inputAction.init("按键抓抓辅助工具2014.05.16868");

     //InputAction 002
     //inputAction.lClickDown(0);

     //InputAction 003
     //inputAction.rClickDown(0);
     
     //InputAction 004
     //inputAction.mClickDown(0);

     //InputAction 005
     //inputAction.lClickUp();

     //InputAction 006
     //inputAction.rClickUp();

     //InputAction 007
     //inputAction.mClickUp();

     //InputAction 008
     //inputAction.moveTo(0, 0);

     //InputAction 009
     //inputAction.moveToChange(100, 100);

     //InputAction 010
     //inputAction.mOnClick();

     //InputAciton 011
     //inputAction.lOnClick();

     //InputAction 012
     //inputAction.rOnClick();

     //InputAction 013
     //inputAction.keyDown(65, 0);
     //Sleep(1000);

     //InputAction 014
     //inputAction.keyUp(65);

     //InputAction 015
     //inputAction.keyPress(65);
     //======================================
     /*OrderSkill orderSkill;
     
     //OrderSkill 001
     int channelLevel = 1;
     int serviceID = 1001;
     std::string targetID = "Target123";

     std::vector<int> resourceID = { 101, 102, 103 }; // 资源 ID 列表
     std::vector<int> intVal = { 1, 2, 3 }; // 整数值列表
     std::vector<std::string> stringVal = { "one", "two", "three" }; // 字符串值列表
     std::vector<double> doubleVal = { 1.1, 2.2, 3.3 }; // 双精度浮点数值列表

     // 调用 createOrder 方法
     int result = orderSkill.createOrder(channelLevel, serviceID, targetID, resourceID, intVal, stringVal, doubleVal);
     */
     //==============================================
     //SystemSkill systemSkill;

     //SystemSkill 001
     //systemSkill.setClipBoardText("1012345");

     //SystemSkill 002
     //string text = systemSkill.GetClipBoardText();
     //int a;

     //SystemSkill 003
     //systemSkill.pasteClipBoardText();


}
