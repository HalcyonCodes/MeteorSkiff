
#include "pch.h"


#using "../Dll/BlessInput.dll"

#include <string>

using namespace std;
#include <msclr/marshal_cppstd.h>
using namespace System;
using namespace msclr::interop;

#include "InputAction.h"

void InputAction::init(const char* windowName) {

	BlessInput::InputAction^ inputAction = gcnew BlessInput::InputAction();
	String^ name = marshal_as<System::String^>(windowName);
	inputAction->init(name);
	delete inputAction;
	inputAction = nullptr;
	return;
}

int InputAction::lClickDown(int time) {
	BlessInput::InputAction^ inputAction = gcnew BlessInput::InputAction();
	Int32 clickTime = time;
	Int32 result = inputAction->LClickDown(clickTime);
	delete inputAction;
	inputAction = nullptr;
	return result;
}

int InputAction::rClickDown(int time) {
	BlessInput::InputAction^ inputAction = gcnew BlessInput::InputAction();
	Int32 clickTime = time;
	Int32 result = inputAction->RClickDown(clickTime);
	delete inputAction;
	inputAction = nullptr;
	return result;
}

int InputAction::mClickDown(int time) {
	BlessInput::InputAction^ inputAction = gcnew BlessInput::InputAction();
	Int32 clickTime = time;
	Int32 result = inputAction->MClickDown(clickTime);
	delete inputAction;
	inputAction = nullptr;
	return result;
}

int InputAction::lClickUp() {
	BlessInput::InputAction^ inputAction = gcnew BlessInput::InputAction();
	Int32 result = inputAction->LClickUp();
	delete inputAction;
	inputAction = nullptr;
	return result;
}


int InputAction::rClickUp() {
	BlessInput::InputAction^ inputAction = gcnew BlessInput::InputAction();
	Int32 result = inputAction->RClickUp();
	delete inputAction;
	inputAction = nullptr;
	return result;
}

int InputAction::mClickUp() {
	BlessInput::InputAction^ inputAction = gcnew BlessInput::InputAction();
	Int32 result = inputAction->MClickUp();
	delete inputAction;
	inputAction = nullptr;
	return result;
}


int InputAction::moveTo(int x, int y) {
	BlessInput::InputAction^ inputAction = gcnew BlessInput::InputAction();
	Int32 targetX = x;
	Int32 targetY = y;
	Int32 result = inputAction->moveTo(targetX, targetY);
	delete inputAction;
	inputAction = nullptr;
	return result;
}


int InputAction::moveToChange(int x, int y) {
	BlessInput::InputAction^ inputAction = gcnew BlessInput::InputAction();
	Int32 targetX = x;
	Int32 targetY = y;
	Int32 result = inputAction->moveToChange(targetX, targetY);
	delete inputAction;
	inputAction = nullptr;
	return result;
}


int InputAction::mOnClick() {
	BlessInput::InputAction^ inputAction = gcnew BlessInput::InputAction();
	Int32 result = inputAction->MOnClick();
	delete inputAction;
	inputAction = nullptr;
	return result;
}

int InputAction::lOnClick() {
	BlessInput::InputAction^ inputAction = gcnew BlessInput::InputAction();
	Int32 result = inputAction->LOnClick();
	delete inputAction;
	inputAction = nullptr;
	return result;
}

int InputAction::rOnClick() {
	BlessInput::InputAction^ inputAction = gcnew BlessInput::InputAction();
	Int32 result = inputAction->ROnClick();
	delete inputAction;
	inputAction = nullptr;
	return result;
}

int InputAction::keyDown(short key, int time)
{
	BlessInput::InputAction^ inputAction = gcnew BlessInput::InputAction();
	short targetKey = key;
	Int32 targetTime = time;
	Int32 result = inputAction->keyDown(targetKey, targetTime);
	delete inputAction;
	inputAction = nullptr;
	return result;
}


int InputAction::keyUp(short key)
{
	BlessInput::InputAction^ inputAction = gcnew BlessInput::InputAction();
	short targetKey = key;
	Int32 result = inputAction->keyUp(targetKey);
	delete inputAction;
	inputAction = nullptr;
	return result;
}



int InputAction::keyPress(short key)
{
	BlessInput::InputAction^ inputAction = gcnew BlessInput::InputAction();
	short targetKey = key;
	Int32 result = inputAction->keyPress(targetKey);
	delete inputAction;
	inputAction = nullptr;
	return result;
}







