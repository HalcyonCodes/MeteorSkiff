#include "pch.h"
#using "../Dll/BlessFindPic.dll"
#include <string>

using namespace std;
#include <msclr/marshal_cppstd.h>

#include <Windows.h>

#include <vcclr.h>


//这里把.NET的加入就可以在C++使用托管类
#using <System.Drawing.dll>

using namespace System::Drawing;
using namespace System::Drawing::Imaging;

using namespace System;
using namespace msclr::interop;




System::Drawing::Bitmap^ getWindow(HWND hWnd) {
	BlessFindPic::GetScreen^ getScreen = gcnew BlessFindPic::GetScreen();
    IntPtr parHwnd = static_cast<IntPtr>(hWnd);

	System::Drawing::Bitmap^ hBitmap = getScreen -> getWindow(parHwnd);

    // 将System::Drawing::Bitmap对象转换为HBITMAP
	/*BitmapData^ bitmapData = hBitmap->LockBits(
		System::Drawing::Rectangle(0, 0, hBitmap->Width, hBitmap->Height),
		ImageLockMode::ReadOnly,
		hBitmap->PixelFormat);
	BITMAPINFO bmi;
	ZeroMemory(&bmi, sizeof(BITMAPINFO));
	bmi.bmiHeader.biSize = sizeof(BITMAPINFO);
	bmi.bmiHeader.biWidth = sizeof(BITMAPINFOHEADER);
	bmi.bmiHeader.biHeight = -hBitmap->Height;
	bmi.bmiHeader.biPlanes = 1;
	bmi.bmiHeader.biBitCount = 24;
	bmi.bmiHeader.biCompression = BI_RGB;
	IntPtr qBitMap = IntPtr(
		CreateDIBSection(NULL, &bmi, DIB_RGB_COLORS, NULL, NULL, 0)
	);
	cli::array<Byte>^ pixels = gcnew cli::array<Byte>(bitmapData->Stride * hBitmap->Height);
	System::Runtime::InteropServices::Marshal::Copy(
		bitmapData->Scan0,
		pixels,
		0,
		bitmapData->Stride * hBitmap->Height);
	hBitmap->UnlockBits(bitmapData);
	HBITMAP hResult = static_cast<HBITMAP>(qBitMap.ToPointer());*/
	return hBitmap;

}

void saveBitMap(System::Drawing::Bitmap^ b, string fileName, string path) {

	BlessFindPic::GetScreen^ getScreen = gcnew BlessFindPic::GetScreen();
	String^ parFileName = marshal_as<String^>(fileName);
	String^ parPath = marshal_as<String^>(path);
	getScreen->saveBitMap(b, parFileName, parPath);
}

HWND findWindow(string className, string gameName) {
	BlessFindPic::GetScreen^ getScreen = gcnew BlessFindPic::GetScreen();
	System::String^ parClassName = msclr::interop::marshal_as<System::String^>(className);
	System::String^ parGameName = msclr::interop::marshal_as<System::String^>(gameName);
	System::IntPtr hwnd = getScreen->findWindow(parClassName, parGameName);
	HWND result = nullptr;
	if (hwnd != IntPtr::Zero) {
		result = static_cast<HWND>(hwnd.ToPointer());
	}
	return result;
}

void saveBitMapByOffset(System::Drawing::Bitmap^ b, int left, int top, int right, int bottom, string fileName, string path) {
	BlessFindPic::GetScreen^ getScreen = gcnew BlessFindPic::GetScreen();
	System::String^ parFileName = msclr::interop::marshal_as<System::String^>(fileName);
	System::String^ parPathName = msclr::interop::marshal_as<System::String^>(path);
	getScreen->saveBitMapByOffset(b, left, top, right, bottom, parFileName, parPathName);
}

System::Drawing::Bitmap^ getDeskTop() {
	BlessFindPic::GetScreen^ getScreen = gcnew BlessFindPic::GetScreen();
	return getScreen->getDeskTop();
}









