#pragma once
#include <Windows.h>
#include <string>
#include "Field.h"
#include "InputHandler.h"
#include "Rotation.h"
#include "FrameController.h"

class GameController
{
	Field* field;
	FrameController* frameController;
	unsigned long long Score = 0;
	pair<char, char> Position = { 2 ,0 };
	pair<char, char> CurrentPuyo;
	pair<char, char> NextUp[2];
	rotation Rotation = Up;
	void NextPuyo();
	void Drop();
public:
	GameController(Field* field, FrameController* frameController);
	~GameController();
	void UseInput(short input);
	void PrepareForNextFrame();
	pair<char, char> getPosition() { return Position; }
	pair<char, char> getCurrentPuyo() { return CurrentPuyo; }
	pair<char, char>* getNextUp() { return NextUp; }
	rotation getRotation() { return Rotation; }
	unsigned long long getScore() { return Score; }
	string getScoreAsString();
};