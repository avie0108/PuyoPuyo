#include "FrameController.h"



FrameController::FrameController()
{
}


FrameController::~FrameController()
{
}

void FrameController::NextFrame(short Input)
{
	this->framesPassed++;
	if (Input & LEFT)
		this->framesKeyHold[LEFT]++;
	else
		this->framesKeyHold[LEFT] = 0;
	if (Input & RIGHT)
		this->framesKeyHold[RIGHT]++;
	else
		this->framesKeyHold[RIGHT] = 0;
	if (Input & DOWN)
		this->framesKeyHold[DOWN]++;
	else
		this->framesKeyHold[DOWN] = 0;
	if (Input & DROP)
		this->framesKeyHold[DROP]++;
	else
		this->framesKeyHold[DROP] = 0;
	if (Input & ROTR)
		this->framesKeyHold[ROTR]++;
	else
		this->framesKeyHold[ROTR] = 0;
	if (Input & ROTL)
		this->framesKeyHold[ROTL]++;
	else
		this->framesKeyHold[ROTL] = 0;
	Sleep(1000 / this->FrameRate);
}