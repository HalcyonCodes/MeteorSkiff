#pragma once


#include "Windows.h"

#include <vector>
#include <string>

using namespace std;


//====or001 createOrder====
int msgCreateOrder(int channleLevel, int serviceID, string targetID, vector<int>& resouorceID,
	const std::vector<int>& intVal, const std::vector<string>& stringVal, const std::vector<double>& doubleVal);
