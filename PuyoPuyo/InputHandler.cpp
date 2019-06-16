#include "InputHandler.h"



InputHandler::InputHandler()
{
}


InputHandler::~InputHandler()
{
}

short InputHandler::GetInput()
{
	int res = 0;
	if (GetKeyState(VK_LEFT) == -127)
		res |= LEFT;
	if (GetKeyState(VK_RIGHT) == -127)
		res |= RIGHT;
	if (GetKeyState(VK_DOWN) == -127)
		res |= DOWN;
	if (GetKeyState('Z') == -127)
		res |= ROTL;
	if (GetKeyState('X') == -127)
		res |= ROTR;
	if (GetKeyState(VK_SPACE) == -127)
		res |= DROP;
	return res;
}