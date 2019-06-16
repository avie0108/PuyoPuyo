#pragma once
#include <Windows.h>
#include <map>
#include <string>
#include <iostream>
#include "Field.h"
#include "GameController.h"

using namespace std;

class ScreenDrawer
{
	static const string screen;
public:
	ScreenDrawer();
	~ScreenDrawer();
	wchar_t* DrawScreen(Field* field, GameController* controller);
};

