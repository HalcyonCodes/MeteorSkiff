#pragma once


#include "windows.h"
#include <string>

#include <vector>
#include <string>
using namespace std;



typedef struct OrderSkill{
	//���������������
	int createOrder(int channleLevel, int serviceID, string targetID, vector<int>& resouorceID, 
	const std::vector<int>& intVal, const std::vector<string>& stringVal, const std::vector<double>& doubleVal);
	
	

}_OrderSkill;
