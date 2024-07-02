#pragma once

#include "pch.h"


#using "../Dll/BlessFindPic.dll"


#include <string>


using namespace std;
#include <msclr/marshal_cppstd.h>
using namespace System;
using namespace msclr::interop;

#include "BmpColor.h"


int BmpColor::loadBmp(string paths) {
	BlessFindPic::BmpColor^ bmpColor = gcnew BlessFindPic::BmpColor();
	String^ parPaths = marshal_as<System::String^>(paths);
	Int32 result = bmpColor->loadBmp(parPaths);
	delete bmpColor;
	bmpColor = nullptr;
	this -> result = result;
	return this -> result;
}


int BmpColor::loadBmpSub(string paths) {
	BlessFindPic::BmpColor^ bmpColor = gcnew BlessFindPic::BmpColor();
	String^ parPaths = marshal_as<System::String^>(paths);
	Int32 result = bmpColor->loadBmpSub(parPaths); 
	this->result = result;
	delete bmpColor;
	bmpColor = nullptr;
	return this->result;
}

int BmpColor::loadBmpList(string paths) {
	BlessFindPic::BmpColor^ bmpColor = gcnew BlessFindPic::BmpColor();
	String^ parPaths = marshal_as<System::String^>(paths);
	Int32 result = bmpColor->loadBmpList(parPaths);
	this->result = result;
	delete bmpColor;
	bmpColor = nullptr;
	return this->result;
}

void BmpColor::freeBmp() {
	BlessFindPic::BmpColor^ bmpColor = gcnew BlessFindPic::BmpColor();
	bmpColor -> freeBmp();
	delete bmpColor;
	bmpColor = nullptr;

}

int* BmpColor::findPAPicA(HWND hWnd, int left, int top, int right, int bottom, string path, int similar) {
	BlessFindPic::BmpColor^ bmpColor = gcnew BlessFindPic::BmpColor();
	IntPtr parHwnd = IntPtr(nullptr);
	if (hWnd != nullptr) {
		IntPtr parHwnd = static_cast<IntPtr>(hWnd);
	}
	
	String^ parPath = marshal_as<String^>(path);
	cli::array<Int32>^ resultArray = bmpColor -> findPAPicA(parHwnd, left, top, right, bottom, parPath,
		similar);
	int length = resultArray->Length ;
	this -> resultA = new int[length];
	for (int i = 0; i < length; i++) {
		this->resultA[i] = resultArray[i];
	}

	delete bmpColor;
	bmpColor = nullptr;
	return this->resultA;
}


int* BmpColor::findDAPicA(HWND hWnd, int left, int top, int right, int bottom, string picName, int similar) {
	BlessFindPic::BmpColor^ bmpColor = gcnew BlessFindPic::BmpColor();
	IntPtr parHwnd = IntPtr(nullptr);
	if (hWnd != nullptr) {
		IntPtr parHwnd = static_cast<IntPtr>(hWnd);
	}
	String^ parPath = marshal_as<String^>(picName);
	cli::array<Int32>^ resultArray = bmpColor->findDAPicA(parHwnd, left, top, right, bottom, parPath, similar);
	int length = resultArray->Length;
	this -> resultA = new int[length];
	for (int i = 0; i < length; i++) {
		this -> resultA[i] = resultArray[i];
	}
	delete bmpColor;
	bmpColor = nullptr;
	return this->resultA;
}

int* BmpColor::findSAPicA(HWND hWnd, int left, int top, int right, int bottom, string path, int similar) {
	BlessFindPic::BmpColor^ bmpColor = gcnew BlessFindPic::BmpColor();
	IntPtr parHwnd = IntPtr(nullptr);
	if (hWnd != nullptr) {
		IntPtr parHwnd = static_cast<IntPtr>(hWnd);
	}
	String^ parPath = marshal_as<String^>(path);
	cli::array<Int32>^ resultArray = bmpColor->findSAPicA(parHwnd, left, top, right, bottom, parPath, similar);
	int length = resultArray->Length;
	this->resultA = new int[length];
	for (int i = 0; i < length; i++) {
		this->resultA[i] = resultArray[i];
	}
	delete bmpColor;
	bmpColor = nullptr;
	return this->resultA;
}


int** BmpColor::findPAPicN(HWND hWnd, int left, int top, int right, int bottom, string path, int similar) {
	BlessFindPic::BmpColor^ bmpColor = gcnew BlessFindPic::BmpColor();
	IntPtr parHwnd = IntPtr(nullptr);
	if (hWnd != nullptr) {
		IntPtr parHwnd = static_cast<IntPtr>(hWnd);
	}
	String^ parPath = marshal_as<String^>(path);
	cli::array<Int32, 2>^ resultArray = bmpColor->findPAPicN(parHwnd, left, top, right, bottom, parPath, similar);

	int cols = resultArray->Length / 2; // 第二维是坐标对的数量由于第2维只有2个所以总数量除以2得到第一维数量
	cols++;
	this->resultNLengthA = cols;
	this -> resultN = new int* [cols];
	for (int i = 0; i < cols; i++) {
		this -> resultN[i] = new int[2]; // 每个坐标对包含x和y两个坐标
	}
	for (int i = 0; i < cols - 1; i++) {
		this -> resultN[i][0] = resultArray[0, i]; // x坐标
		this -> resultN[i][1] = resultArray[1, i]; // y坐标
	}
	this -> resultN[cols - 1][0] = -1;
	this -> resultN[cols - 1][1] = -1;

	delete bmpColor;
	bmpColor = nullptr;

	return this -> resultN;
}


int** BmpColor::findDAPicN(HWND hWnd, int left, int top, int right, int bottom, string picName, int similar){
	BlessFindPic::BmpColor^ bmpColor = gcnew BlessFindPic::BmpColor();
	IntPtr parHwnd = IntPtr(nullptr);
	if (hWnd != nullptr) {
		IntPtr parHwnd = static_cast<IntPtr>(hWnd);
	}
	String^ parPicName = marshal_as<String^>(picName);
	cli::array<Int32, 2>^ resultArray = bmpColor->findDAPicN(parHwnd, left, top, right, bottom, parPicName, similar);
	int cols = resultArray->Length / 2; // 第二维是坐标对的数量由于第2维只有2个所以总数量除以2得到第一维数量
	cols++;
	this->resultNLengthA = cols;
	this -> resultN = new int* [cols];
	for (int i = 0; i < cols; i++) {
		this -> resultN[i] = new int[2]; // 每个坐标对包含x和y两个坐标
	}
	for (int i = 0; i < cols - 1; i++) {
		this -> resultN[i][0] = resultArray[0, i]; // x坐标
		this -> resultN[i][1] = resultArray[1, i]; // y坐标
	}
	this -> resultN[cols - 1][0] = -1;
	this -> resultN[cols - 1][1] = -1;

	delete bmpColor;
	bmpColor = nullptr;

	return this -> resultN;
}

int* BmpColor::findLNPicA(HWND hWnd, int left, int top, int right, int bottom, int similar) {
	BlessFindPic::BmpColor^ bmpColor = gcnew BlessFindPic::BmpColor();
	IntPtr parHwnd = IntPtr(nullptr);
	if (hWnd != nullptr) {
		IntPtr parHwnd = static_cast<IntPtr>(hWnd);
	}
	cli::array<Int32>^ resultArray = bmpColor->findLNPicA(parHwnd, left, top, right, bottom, similar);
	int length = resultArray -> Length;
	this -> resultA = new int[length];
	for (int i = 0; i < length; i++) {
		this -> resultA[i] = resultArray[i];
	}

	delete bmpColor;
	bmpColor = nullptr;

	return this -> resultA;
}

int** BmpColor::findLNPicN(HWND hWnd, int left, int top, int right, int bottom, int similar) {
	BlessFindPic::BmpColor^ bmpColor = gcnew BlessFindPic::BmpColor();
	IntPtr parHwnd = IntPtr(nullptr);
	if (hWnd != nullptr) {
		IntPtr parHwnd = static_cast<IntPtr>(hWnd);
	}
	cli::array<Int32, 2>^ resultArray = bmpColor -> findLNPicN(parHwnd, left, top, right, bottom, similar);
	int cols = resultArray->Length / 3; // 第二维是坐标对的数量由于第2维只有2个所以总数量除以2得到第一维数量
	cols++;
	this->resultNLengthA = cols;
	this -> resultN = new int* [cols];
	for (int i = 0; i < cols; i++) {
		this -> resultN[i] = new int[3]; // 每个坐标对包含x和y两个坐标
	}
	for (int i = 0; i < cols - 1; i++) {
		this -> resultN[i][0] = resultArray[0, i]; // x坐标
		this -> resultN[i][1] = resultArray[1, i]; // y坐标
		this -> resultN[i][2] = resultArray[2, i]; // 找到的第index个图片
	}
	this -> resultN[cols - 1][0] = -1;
	this -> resultN[cols - 1][1] = -1;
	this -> resultN[cols - 1][2] = -1;

	delete bmpColor;
	bmpColor = nullptr;

	return this -> resultN;
}


//从loadBmpSub加载的图片中按图片名称找1个图多个位置
int** BmpColor::findSAPicN(HWND hWnd, int left, int top, int right, int bottom, string picName, int similar) {
	BlessFindPic::BmpColor^ bmpColor = gcnew BlessFindPic::BmpColor();
	IntPtr parHwnd = IntPtr(nullptr);
	if (hWnd != nullptr) {
		IntPtr parHwnd = static_cast<IntPtr>(hWnd);
	}
	String^ parPicName = marshal_as<String^>(picName);
	cli::array<Int32, 2>^ resultArray = bmpColor->findSAPicN(parHwnd, left, top, right, bottom, parPicName, similar);
	int cols = resultArray->Length / 2; // 第二维是坐标对的数量由于第2维只有2个所以总数量除以2得到第一维数量
	cols++;
	this->resultNLengthA = cols;
	this->resultN = new int* [cols];
	for (int i = 0; i < cols; i++) {
		this -> resultN[i] = new int[2]; // 每个坐标对包含x和y两个坐标
	}
	for (int i = 0; i < cols - 1; i++) {
		this -> resultN[i][0] = resultArray[0, i]; // x坐标
		this -> resultN[i][1] = resultArray[1, i]; // y坐标
	}
	this -> resultN[cols - 1][0] = -1;
	this -> resultN[cols - 1][1] = -1;

	delete bmpColor;
	bmpColor = nullptr;

	return this -> resultN;
}