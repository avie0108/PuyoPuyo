#include "ScreenDrawer.h"
#include "Rotation.h"

ScreenDrawer::ScreenDrawer()
{
}


ScreenDrawer::~ScreenDrawer()
{
}

wchar_t* ScreenDrawer::DrawScreen(Field* field, GameController* controller)
{
	wchar_t* res = new wchar_t[screen.size()];
	string score = controller->getScoreAsString();
	pair<byte, byte> pos = controller->getPosition();
	pair<char, char>* NextUp = controller->getNextUp();
	int y = 1, x = -1;
	for (int i = 0; i < screen.size(); i++)
	{
		switch (screen[i])
		{
			case '\n':
				y++;
				x = -1;
				res[i] = '\0';
				continue;
			case 'a':
				res[i] = NextUp->first;
				break;
			case 'b':
				res[i] = NextUp->second;
				break;
			case 'c':
				res[i] = (NextUp + 1)->first;
				break;
			case 'd':
				res[i] = (NextUp + 1)->second;
				break;
			case 'p':
				switch (controller->getRotation())
				{
					case Up:
						if (y + 1 == controller->getPosition().second && x == controller->getPosition().first)
							res[i] = controller->getCurrentPuyo().first;
						else if(y + 1 == controller->getPosition().second - 1 && x == controller->getPosition().first)
							res[i] = controller->getCurrentPuyo().second;
						else
							res[i] = field->getValueAt(x, y);
						break;
					case Left:
						if (y + 1 == controller->getPosition().second && x == controller->getPosition().first)
							res[i] = controller->getCurrentPuyo().first;
						else if (y + 1 == controller->getPosition().second && x == controller->getPosition().first - 1)
							res[i] = controller->getCurrentPuyo().second;
						else
							res[i] = field->getValueAt(x, y);
						break;
					case Right:
						if (y + 1 == controller->getPosition().second && x == controller->getPosition().first)
							res[i] = controller->getCurrentPuyo().first;
						else if (y + 1 == controller->getPosition().second && x == controller->getPosition().first + 1)
							res[i] = controller->getCurrentPuyo().second;
						else
							res[i] = field->getValueAt(x, y);
						break;
					case Down:
						if (y + 1 == controller->getPosition().second && x == controller->getPosition().first)
							res[i] = controller->getCurrentPuyo().first;
						else if (y + 1 == controller->getPosition().second + 1 && x == controller->getPosition().first)
							res[i] = controller->getCurrentPuyo().second;
						else
							res[i] = field->getValueAt(x, y);
						break;
				}
				break;
			case '0':
				res[i] = score[x+1];
				break;
			default:
				res[i] = screen[i];
				break;
		}
		x++;
	}
	return res;
}

const string ScreenDrawer::screen = 
 (string)"-----------" + '\n' +
 (string)"|pppppp||a|" + '\n' +
 (string)"|pppppp||b|" + '\n' +
 (string)"|pppppp||-|" + '\n' +
 (string)"|pppppp||c|" + '\n' +
 (string)"|pppppp||d|" + '\n' +
 (string)"|pppppp||-|" + '\n' +
 (string)"|pppppp|   " + '\n' +
 (string)"|pppppp|   " + '\n' +
 (string)"|pppppp|   " + '\n' +
 (string)"|pppppp|   " + '\n' +
 (string)"|pppppp|   " + '\n' +
 (string)"|pppppp|   " + '\n' +
 (string)"--------   " + '\n' +
 (string)"SCORE:     " + '\n' +
 (string)"00000000000" + '\0';