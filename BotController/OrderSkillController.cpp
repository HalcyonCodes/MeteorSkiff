#include "pch.h"
#include "framework.h"
#include "MsgInterface.h" //定义了message的接口

#include <WinUser.h>
#include "GetHwndByPID.h"
#include "SetWindowHook.h"
#include "BotSkills.h"

#include "Windows.h"
#include <string>

#include <vector>
#include <string>
using namespace std;

//====or001 createOrder====
int msgCreateOrder(int channleLevel, int serviceID, string targetID, vector<int>& resouorceID,
	const std::vector<int>& intVal, const std::vector<string>& stringVal, const std::vector<double>& doubleVal){


    MsgOrder msgInterface;
	msgInterface.targetID = targetID;
	msgInterface.channelLevel = channleLevel;
	msgInterface.resourceID = resouorceID;
	msgInterface.serviceID = serviceID;
	msgInterface.intVal = intVal;
	msgInterface.stringVal = stringVal;
	msgInterface.doubleVal = doubleVal;
	LRESULT result = SendMessageA(botHwnd, botMsgCode, or001, (LPARAM)&msgInterface);
	return msgInterface.result;
}