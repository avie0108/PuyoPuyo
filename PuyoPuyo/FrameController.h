#pragma once
#include <map>
#include "InputHandler.h"

using namespace std;

class FrameController
{
	unsigned int FrameRate = 144;
	unsigned long framesPassed = 0;
	map<short, unsigned int> framesKeyHold = {
		{LEFT, 0},
		{RIGHT, 0},
		{DOWN, 0},
		{DROP, 0},
		{ROTL, 0},
		{ROTR, 0},
	};
public:
	FrameController();
	~FrameController();
	void NextFrame(short Input);
	unsigned long getFramesPassed() { return this->framesPassed; }
	unsigned int getFrameRate() { return FrameRate; }
	unsigned int getFramesKeyHold(int x) { return this->framesKeyHold[x]; }
};