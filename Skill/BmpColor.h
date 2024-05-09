#pragma once



#include "windows.h"
#include <string>
using namespace std;



typedef struct BmpColor {
	int result;
	int* resultA; //1ά����ֵ����
	int** resultN; //2ά����ֵ����
	int resultNLengthA; //resultN�ĵ�1ά����,�ڶ�ά�ȳ��ȹ̶���2
	


	//����ͼƬ����ͼƬ�Ž�hashTable��
	int loadBmp(string paths);

	//��պ��ټ���ͼƬ���ڴ�
	int loadBmpSub(string paths);

	//��պ��ټ���ͼƬ���ڴ��б�
	int loadBmpList(string paths);

	//���hashTable
	void freeBmp();

	//���ļ�·�����ص�ͼƬ�а�·��������1��ͼ1��λ��(��Ҫdelectָ��)
	int* findPAPicA(HWND hWnd, int left, int top, int right, int bottom, string path, int similar);

	//��loadBmp���ص�ͼƬ�а�ͼƬ������1��ͼ1��λ��(��Ҫdelectָ��)
	int* findDAPicA(HWND hWnd, int left, int top, int right, int bottom, string picName, int similar);

	//��loadBmpSub���ص�ͼƬ�а�ͼƬ������1��ͼ1��λ��(��Ҫdelectָ��)
	int* findSAPicA(HWND hWnd, int left, int top, int right, int bottom, string picName, int similar);

	//���ļ�·�����ص�ͼƬ�а�·��������1��ͼ���λ��(��Ҫdelectָ��)��
	//r[index][0]Ϊx����; r[index][1]Ϊy����
	//�����ȡ����ֵΪ-1��������������
	int** findPAPicN(HWND hWnd, int left, int top, int right, int bottom, string path, int similar);

	//��loadBmp���ص�ͼƬ�а�ͼƬ������1��ͼ���λ��
	int** findDAPicN(HWND hWnd, int left, int top, int right, int bottom, string picName, int similar);

	//��loadBmpSub���ص�ͼƬ�а�ͼƬ������1��ͼ���λ��
	int** findSAPicN(HWND hWnd, int left, int top, int right, int bottom, string picName, int similar);

	// ��loadBmp���ص�ͼƬ���Ҷ��ͼ�еĵ�1���ҵ���ͼ��1��λ��
	int* findLNPicA(HWND hWnd, int left, int top, int right, int bottom, int similar);

	// ��loadBmpList���ص�ͼƬ���Ҷ��ͼ���λ��
	int** findLNPicN(HWND hWnd, int left, int top, int right, int bottom, int similar);
}_BmpColor;

