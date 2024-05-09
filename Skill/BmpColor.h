#pragma once



#include "windows.h"
#include <string>
using namespace std;



typedef struct BmpColor {
	int result;
	int* resultA; //1维返回值数组
	int** resultN; //2维返回值数组
	int resultNLengthA; //resultN的第1维长度,第二维度长度固定是2
	


	//加载图片，把图片放进hashTable里
	int loadBmp(string paths);

	//清空后再加载图片到内存
	int loadBmpSub(string paths);

	//清空后再加载图片到内存列表
	int loadBmpList(string paths);

	//清空hashTable
	void freeBmp();

	//从文件路径加载的图片中按路径名称找1个图1个位置(需要delect指针)
	int* findPAPicA(HWND hWnd, int left, int top, int right, int bottom, string path, int similar);

	//从loadBmp加载的图片中按图片名称找1个图1个位置(需要delect指针)
	int* findDAPicA(HWND hWnd, int left, int top, int right, int bottom, string picName, int similar);

	//从loadBmpSub加载的图片中按图片名称找1个图1个位置(需要delect指针)
	int* findSAPicA(HWND hWnd, int left, int top, int right, int bottom, string picName, int similar);

	//从文件路径加载的图片中按路径名称找1个图多个位置(需要delect指针)：
	//r[index][0]为x坐标; r[index][1]为y坐标
	//如果读取到的值为-1，则代表数组结束
	int** findPAPicN(HWND hWnd, int left, int top, int right, int bottom, string path, int similar);

	//从loadBmp加载的图片中按图片名称找1个图多个位置
	int** findDAPicN(HWND hWnd, int left, int top, int right, int bottom, string picName, int similar);

	//从loadBmpSub加载的图片中按图片名称找1个图多个位置
	int** findSAPicN(HWND hWnd, int left, int top, int right, int bottom, string picName, int similar);

	// 从loadBmp加载的图片中找多个图中的第1个找到的图的1个位置
	int* findLNPicA(HWND hWnd, int left, int top, int right, int bottom, int similar);

	// 从loadBmpList加载的图片中找多个图多个位置
	int** findLNPicN(HWND hWnd, int left, int top, int right, int bottom, int similar);
}_BmpColor;

