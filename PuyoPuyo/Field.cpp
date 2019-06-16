#include "Field.h"

#define yeet throw

Field::Field()
{
	this->MakeField();
}


Field::~Field()
{
}


char Field::getValueAt(pair<char, char> pos)
{
	return getValueAt(pos.first, pos.second);
}

char Field::getValueAt(char x, char y)
{
		return this->field[y * this->width + x];
}

void Field::SetPuyo(char puyo, pair<char, char> pos)
{
	SetPuyo(puyo, pos.first, pos.second);
}

void Field::SetPuyo(char puyo, char x, char y)
{
	this->field[y * 6 + x] = puyo;
}

bool Field::CanMove(rotation direction, rotation rot, char x, char y)
{
	return CanMove(direction, rot, { x,y });
}

bool Field::CanMove(rotation direction, rotation rot, pair<char, char> pos)
{
	switch (direction)
	{
		case Left:
			if (rot == Left)
			{
				if (pos.first == 1)
					return false;
				char c = getValueAt(pos.first - 2, pos.second);
				return c == '.' || c == 'x';
			}
			else if (rot == Down)
			{
				if (pos.first == 0)
					return false;
				char c = getValueAt(pos.first - 1, pos.second);
				char c2 = getValueAt(pos.first - 1, pos.second + 1);
				return (c == '.' || c == 'x') && (c2 == '.' || c2 == 'x');
			}
			else
			{
				if (pos.first == 0)
					return false;
				char c = getValueAt(pos.first - 1, pos.second);
				return c == '.' || c == 'x';
			}
		case Right:
			if (rot == Right)
			{
				if (pos.first == 4)
					return false;
				char c = getValueAt(pos.first + 2, pos.second);
				return c == '.' || c == 'x';
			}
			else if (rot == Down)
			{
				if (pos.first == 5)
					return false;
				char c = getValueAt(pos.first + 1, pos.second);
				char c2 = getValueAt(pos.first + 1, pos.second + 1);
				return (c == '.' || c == 'x') && (c2 == '.' || c2 == 'x');
			}
			else
			{
				if (pos.first == 5)
					return false;
				char c = getValueAt(pos.first + 1, pos.second);
				return c == '.' || c == 'x';
			}
		default:
			yeet new invalid_argument(direction + " is not a valid direction");
	}
}

bool Field::ShouldDrop(char x, char y, rotation rot)
{
	return ShouldDrop({ x,y }, rot);
}

bool Field::ShouldDrop(pair<char, char> pos, rotation rot)
{
	if ((pos.second + 1) * 6 + pos.first > field.length())
		return true;
	switch (rot)
	{
		case Up:
			return (getValueAt(pos.first, pos.second + 1) != '.' && getValueAt(pos.first, pos.second + 1) != 'x');
		case Left:
			return (getValueAt(pos.first, pos.second + 1) != '.' && getValueAt(pos.first, pos.second + 1) != 'x' ||
				getValueAt(pos.first - 1, pos.second + 1) != '.' && getValueAt(pos.first - 1, pos.second + 1) != 'x');
		case Right:
			return (getValueAt(pos.first, pos.second + 1) != '.' && getValueAt(pos.first, pos.second + 1) != 'x' ||
					getValueAt(pos.first + 1, pos.second + 1) != '.' && getValueAt(pos.first + 1, pos.second + 1) != 'x');
		case Down:
			return (pos.second + 2) * 6 + pos.first > field.length() || 
				(getValueAt(pos.first, pos.second + 2) != '.' && getValueAt(pos.first, pos.second + 2) != 'x');
		default:
			break;
	}
}

char Field::getLowestPoint(char x)
{
	for (; x < this->field.size() && (this->field[x] == '.' || this->field[x] == 'x'); x += 6) { }
	return x - 6;
}

void Field::MakeField()
{
	this->field  = "......";
	this->field += "......";
	this->field += "..x...";
	this->field += "......";
	this->field += "......";
	this->field += "......";
	this->field += "......";
	this->field += "......";
	this->field += "......";
	this->field += "......";
	this->field += "......";
	this->field += "......";
	this->field += "......";
	this->field += "......";
}