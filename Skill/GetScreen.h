#pragma once



#include "windows.h"
#include <string>
#include <msclr/marshal_cppstd.h>
#using <System.Drawing.dll>

//�ҵ�����
HWND findWindow(string className, string gameName);

// ��ȡ���ڽ�ͼ��ͼ����Χ�б߿򣬺Ͱ��������ͼ���ߵ�ͼ��߿��Сһ��
System::Drawing::Bitmap^ getWindow(HWND hWnd);

//ȫ�ֽ�ͼ
System::Drawing::Bitmap^ getDeskTop();

//�����ͼ
void saveBitMap(System::Drawing::Bitmap^ b, string fileName, string path);


// �������걣���ͼ�е�һС���ͼ�����ڿ�����
void saveBitMapByOffset(System::Drawing::Bitmap^ b, int left, int top, int right, int bottom, string fileName, string path);





