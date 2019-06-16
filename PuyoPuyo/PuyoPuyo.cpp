#include <Windows.h>
#include <math.h>
#include <iostream>
#include <string>
#include <map>
#include <time.h>
#include <vector>
#include "Field.h"
#include "ScreenDrawer.h"
#include "GameController.h"
#include "InputHandler.h"

using namespace std;

Field field = Field();
FrameController frameController = FrameController();
InputHandler inputHandler = InputHandler();
GameController gameController = GameController(&field, &frameController);
ScreenDrawer drawer = ScreenDrawer();

int main()
{
	srand(time(NULL));
	HANDLE Console = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
	SetConsoleActiveScreenBuffer(Console);
	DWORD bytesWritten;
	while (true)
	{
		short input = inputHandler.GetInput();
		gameController.UseInput(input);
		WriteConsoleOutputCharacter(Console, drawer.DrawScreen(&field, &gameController), 12 * 16 , { 0,0 }, &bytesWritten);
		gameController.PrepareForNextFrame();
		frameController.NextFrame(input);
	}
}