#pragma once



#include "windows.h"
#include <string>
#include <msclr/marshal_cppstd.h>
#using <System.Drawing.dll>

//找到窗口
HWND findWindow(string className, string gameName);

// 获取窗口截图，图像周围有边框，和按键精灵截图工具的图像边框大小一致
System::Drawing::Bitmap^ getWindow(HWND hWnd);

//全局截图
System::Drawing::Bitmap^ getDeskTop();

//保存截图
void saveBitMap(System::Drawing::Bitmap^ b, string fileName, string path);


// 输入坐标保存截图中的一小块截图，用于开发用
void saveBitMapByOffset(System::Drawing::Bitmap^ b, int left, int top, int right, int bottom, string fileName, string path);





