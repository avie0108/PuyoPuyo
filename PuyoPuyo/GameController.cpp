#include "GameController.h"
#include <time.h>

GameController::GameController(Field* field, FrameController* frameController)
{
	srand(time(NULL));
	this->field = field;
	this->frameController = frameController;
	CurrentPuyo = { COLORS[rand() % 4], COLORS[rand() % 4] };
	NextUp[0] = { COLORS[rand() % 4], COLORS[rand() % 4] };
	NextUp[1] = { COLORS[rand() % 4], COLORS[rand() % 4] };
}


GameController::~GameController()
{
	
}



void GameController::UseInput(short input)
{
	int das = frameController->getFrameRate() / 6;
	if (input & LEFT && ((frameController->getFramesKeyHold(LEFT) == 0) ||
		(frameController->getFramesKeyHold(LEFT) >= das * 2 && frameController->getFramesKeyHold(LEFT) % das == 0)))
		if (field->CanMove(Left, Rotation, Position))
			Position.first--;
	if (input & RIGHT && ((frameController->getFramesKeyHold(RIGHT) == 0) ||
		(frameController->getFramesKeyHold(RIGHT) >= das * 2 && frameController->getFramesKeyHold(RIGHT) % das == 0)))
		if (field->CanMove(Right, Rotation, Position))
			Position.first++;
	if (input & DROP && ((frameController->getFramesKeyHold(DROP) == 0) ||
		(frameController->getFramesKeyHold(DROP) >= das * 2 && frameController->getFramesKeyHold(DROP) % das == 0)))
		Drop();
	if (input & ROTL && ((frameController->getFramesKeyHold(ROTL) == 0) ||
		(frameController->getFramesKeyHold(ROTL) >= das * 2 && frameController->getFramesKeyHold(ROTL) % das == 0)))
		switch (Rotation)
		{
			case Up:
				Rotation = Left;
				if (Position.first == 0 || (field->getValueAt(Position.first - 1, Position.second) != '.' && field->getValueAt(Position.first - 1, Position.second) != 'x'))
					Position.first++;
				break;
			case Left:
				Rotation = Down;
				if (Position.second == 13 || (field->getValueAt(Position.first, Position.second + 1) != '.' && field->getValueAt(Position.first, Position.second + 1) != 'x'))
					Position.second--;
				break;
			case Right:
				Rotation = Up;
				break;
			case Down:
				Rotation = Right;
				if (Position.first == 5 || (field->getValueAt(Position.first + 1, Position.second) != '.' && field->getValueAt(Position.first + 1, Position.second) != 'x'))
					Position.second--;
				break;
			default:
				break;
		}
	if (input & ROTR && ((frameController->getFramesKeyHold(ROTR) == 0) ||
		(frameController->getFramesKeyHold(ROTR) >= das * 2 && frameController->getFramesKeyHold(ROTR) % das == 0)))
		switch (Rotation)
		{
			case Up:
				Rotation = Right;
				if (Position.first == 5 || (field->getValueAt(Position.first + 1, Position.second) != '.' && field->getValueAt(Position.first + 1, Position.second) != 'x'))
					Position.first--;
				break;
			case Left:
				Rotation = Up;
				break;
			case Right:
				Rotation = Down;
				if (Position.second == 13 || (field->getValueAt(Position.first, Position.second + 1) != '.' && field->getValueAt(Position.first, Position.second + 1) != 'x'))
					Position.second --;
				break;
			case Down:
				Rotation = Left;
				if (Position.first == 0 || (field->getValueAt(Position.first - 1, Position.second) != '.' && field->getValueAt(Position.first - 1, Position.second) != 'x'))
					Position.first++;
				break;
			default:
				break;
		}
}

void GameController::NextPuyo()
{
	CurrentPuyo = NextUp[0];
	NextUp[0] = NextUp[1];
	NextUp[1] = { COLORS[rand() % 4], COLORS[rand() % 4] };
}

void GameController::PrepareForNextFrame()
{
	char mod = this->frameController->getFramesKeyHold(DOWN) == 0 ? this->frameController->getFrameRate(): this->frameController->getFrameRate() / 16;
	if (this->frameController->getFramesPassed() % mod == 0)
	{
		if (field->ShouldDrop(Position, Rotation))
		{
			Drop();
			return;
		}
		this->Position.second++;
	}
}

string GameController::getScoreAsString()
{
	char res[50];
	sprintf_s(res, "%011i", this->Score);
	return res;
}

void GameController::Drop()
{
	char y;
	switch (Rotation)
	{
		case Up:
			y = this->field->getLowestPoint(Position.first);
			this->field->SetPuyo(CurrentPuyo.first, Position.first, y);
			this->field->SetPuyo(CurrentPuyo.second, Position.first, y - 6);
			break;
		case Left:
			y = this->field->getLowestPoint(Position.first);
			this->field->SetPuyo(CurrentPuyo.first, Position.first, y);
			y = this->field->getLowestPoint(Position.first - 1);
			this->field->SetPuyo(CurrentPuyo.second, Position.first - 1, y);
			break;
		case Right:
			y = this->field->getLowestPoint(Position.first);
			this->field->SetPuyo(CurrentPuyo.first, Position.first, y);
			y = this->field->getLowestPoint(Position.first + 1);
			this->field->SetPuyo(CurrentPuyo.second, Position.first + 1, y);
			break;
		case Down:
			y = this->field->getLowestPoint(Position.first);
			this->field->SetPuyo(CurrentPuyo.second, Position.first, y);
			this->field->SetPuyo(CurrentPuyo.first, Position.first, y - 6);
			break;
	}
	Position = { 2, 0 };
	NextPuyo();
}