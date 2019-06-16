#pragma once
#define LEFT  0b1
#define RIGHT 0b10
#define DOWN  0b100
#define ROTL  0b1000
#define ROTR  0b10000
#define DROP  0b100000
#include <Windows.h>

class InputHandler
{
public:
	InputHandler();
	~InputHandler();
	short GetInput();
};