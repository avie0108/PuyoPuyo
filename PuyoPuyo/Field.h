#pragma once
#include <Windows.h>
#include <math.h>
#include <string>
#include <iostream>
#include "Rotation.h"

using namespace std;

class Field
{
private:
	int height = 12;
	int width = 6;
	const int deadspot = 14;
	string field;
	void MakeField();

public:
	Field();
	~Field();
	char getValueAt(char x, char y);
	char getValueAt(pair<char,char> pos);
	void SetPuyo(char puyo, char x, char y);
	void SetPuyo(char puyo, pair<char,char> pos);
	bool CanMove(rotation direction, rotation rot, char x, char y);
	bool CanMove(rotation direction, rotation rot, pair<char, char> pos);
	bool ShouldDrop(char x, char y, rotation rot);
	bool ShouldDrop(pair<char, char> pos, rotation rot);
	bool GameOver() { return this->field[this->deadspot] == 'x'; }
	char getLowestPoint(char x);
};

