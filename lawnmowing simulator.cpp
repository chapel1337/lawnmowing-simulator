#include <iostream>
#include <vector>
#include <conio.h>
#include <windows.h>

using std::cout; using std::cin; using std::string; using std::vector;

/*
* written by chapel1337
* made on 11/12/2022
* really crappy lawn mowing simulator
* finally implemented key movement for options
* tried to make flipped V letter for the lawn mower when it's pointing up, 
* but it was unicode (chars don't support unicode characters)
*/

vector<vector<char>> map1
{
	{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', },
	{ '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', },
	{ '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', },
	{ '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', },
	{ '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', },
	{ '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', },
};
vector<vector<char>> map2
{
	{ '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', },
	{ ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', },
	{ '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', },
	{ ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', },
	{ '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', },
	{ ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', },
	{ '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', },
};
vector<vector<char>> map3
{
	{ ' ', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', '#', ' ', },
	{ ' ', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', '#', ' ', },
	{ ' ', '#', '#', '#', '#', ' ', ' ', ' ', '#', '#', '#', '#', '#', ' ', ' ', ' ', '#', '#', '#', '#', ' ', },
	{ ' ', '#', '#', '#', '#', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#', '#', '#', '#', ' ', },
	{ ' ', '#', '#', '#', '#', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#', '#', '#', '#', ' ', },
	{ ' ', '#', '#', '#', '#', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#', '#', '#', '#', ' ', },
	{ ' ', '#', '#', '#', '#', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#', '#', '#', '#', ' ', },
	{ ' ', '#', '#', '#', '#', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#', '#', '#', '#', ' ', },
	{ ' ', '#', '#', '#', '#', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', '#', '#', '#', '#', ' ', },
	{ ' ', '#', '#', '#', '#', ' ', ' ', ' ', '#', '#', '#', '#', '#', ' ', ' ', ' ', '#', '#', '#', '#', ' ', },
	{ ' ', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', '#', ' ', },
	{ ' ', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', '#', ' ', },
};
vector<vector<char>> map4
{
	{ ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', },
	{ ' ', ' ', '#', '#', '#', '#', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', ' ', ' ', '#', '#', '#', '#', '#', ' ', ' ', },
	{ ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', },
	{ ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', },
	{ ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', },
	{ ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', },
	{ ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', },
	{ ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', },
	{ ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', },
	{ ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', },
	{ ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', },
	{ ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', },
	{ ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', },
	{ ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', },
	{ ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', },
	{ ' ', ' ', '#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', ' ', ' ', },
	{ ' ', ' ', '#', '#', '#', '#', ' ', ' ', ' ', ' ', '#', '#', '#', ' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', ' ', ' ', },
	{ ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', '#', ' ', },
};

int currentMapNumber{};

vector<vector<vector<char>>> mapsList{ map1, map2, map3, map4 };
vector<vector<char>> currentMap{ mapsList[currentMapNumber] };
vector<int> grassAmounts{ 70, 99, 118, 121, };

int mapY{ static_cast<int>(currentMap.size()) };
int mapX{ static_cast<int>(currentMap[0].size()) };

int playerY{ mapY - 1 };
int playerX{ mapX - 1 };

int grassMowed{};
int grassLeft{ grassAmounts[currentMapNumber] };

void clear()
{
	system("cls");
}

void setTextColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

void resetTextColor()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void menu(int position);
void start();

void youWin(int position, bool refresh)
{
	clear();

	if (!refresh)
	{
		setTextColor(10);
		cout << "you win!\n\n";
		resetTextColor();

		cin.get();
		cin.ignore();

		clear();

		mapsList.clear();
		mapsList.push_back(map1);
		mapsList.push_back(map2);
		mapsList.push_back(map3);
		mapsList.push_back(map4);

		currentMapNumber = 0;
		currentMap = mapsList[0];

		mapY = currentMap.size();
		mapX = currentMap[0].size();
		playerY = mapY - 1;
		playerX = mapX - 1;

		grassMowed = 0;
		grassLeft = grassAmounts[currentMapNumber];
	}

	cout << "  would you like to play again?\n\n";
	
	if (position == 1)
	{
		cout << "  > yes <\n";
	}
	else
	{
		cout << "  yes\n";
	}

	if (position == 2)
	{
		cout << "  > no <\n";
	}
	else
	{
		cout << "  no\n";
	}
	
	int input{ _getch() };

	if (input == 'W' && position != 1 || input == 'w' && position != 1)
	{
		youWin(position - 1, true);
	}
	else if (input == 'S' && position != 2 || input == 's' && position != 2)
	{
		youWin(position + 1, true);
	}
	else if (input == 13)
	{
		switch (position)
		{
		case 1:
			start();
			break;

		case 2:
			menu(1);
			break;
		}
	}
	else
	{
		youWin(position, true);
	}
}

void changeLevel(int mapNumber)
{
	if (mapNumber == 4)
	{
		youWin(1, false);
	}
	else
	{
		currentMap = mapsList[mapNumber];
		currentMapNumber = mapNumber;

		grassMowed = 0;
		grassLeft = grassAmounts[mapNumber];

		mapY = currentMap.size();
		mapX = currentMap[0].size();
		playerY = mapY - 1;
		playerX = mapX - 1;

		start();
	}
}

void positionPlayer(char direction)
{
	if (grassMowed == grassAmounts[currentMapNumber])
	{
		changeLevel(currentMapNumber + 1);
	}

	currentMap = mapsList[currentMapNumber];

	if (direction == 'w')
	{
		currentMap[playerY][playerX] = '^';
	}
	else if (direction == 's')
	{
		currentMap[playerY][playerX] = 'v';
	}
	else if (direction == 'a')
	{
		currentMap[playerY][playerX] = '<';
	}
	else if (direction == 'd')
	{
		currentMap[playerY][playerX] = '>';
	}
}

void displayStatistics()
{
	cout << "player x: " << playerX << '\n';
	cout << "player y: " << playerY << "\n\n";

	cout << "map x: " << mapX << '\n';
	cout << "map y: " << mapY << "\n\n";

	cout << "grass mowed: " << grassMowed << '\n';
	cout << "grass left: " << grassLeft << "\n\n";
}

void refresh()
{
	clear();
	displayStatistics();

	for (int i{ 0 }; i < currentMap.size(); ++i)
	{
		for (int o{ 0 }; o < currentMap[i].size(); ++o)
		{
			if (currentMap[i][o] == '#')
			{
				setTextColor(2);
				cout << currentMap[i][o];
				resetTextColor();
			}
			else if (currentMap[i][o] == currentMap[playerY][playerX])
			{
				setTextColor(4);
				cout << currentMap[i][o];
				resetTextColor();
			}
			else
			{
				cout << currentMap[i][o];
			}
		}

		cout << '\n';
	}
}

void movePlayer(char direction)
{
	if (direction == 'w' && playerY != 0)
	{
		if (mapsList[currentMapNumber][playerY - 1][playerX] == '#')
		{
			mapsList[currentMapNumber][playerY - 1][playerX] = ' ';

			grassMowed++;
			grassLeft--;
		}

		playerY--;
		positionPlayer('w');
	}
	else if (direction == 's' && playerY != mapY - 1)
	{
		if (mapsList[currentMapNumber][playerY + 1][playerX] == '#')
		{
			mapsList[currentMapNumber][playerY + 1][playerX] = ' ';

			grassMowed++;
			grassLeft--;
		}

		playerY++;
		positionPlayer('s');
	}
	else if (direction == 'a' && playerX != 0)
	{
		if (mapsList[currentMapNumber][playerY][playerX - 1] == '#')
		{
			mapsList[currentMapNumber][playerY][playerX - 1] = ' ';

			++grassMowed;
			--grassLeft;
		}

		--playerX;
		positionPlayer('a');
	}
	else if (direction == 'd' && playerX != mapX - 1)
	{
		if (mapsList[currentMapNumber][playerY][playerX + 1] == '#')
		{
			mapsList[currentMapNumber][playerY][playerX + 1] = ' ';

			grassMowed++;
			grassLeft--;
		}

		playerX++;
		positionPlayer('d');
	}

	refresh();
}

void getInput()
{
	int input{ _getch() };

	switch(input)
	{
	case 'W':
	case 'w':
		movePlayer('w');
		break;

	case 'S':
	case 's':
		movePlayer('s');
		break;

	case 'A':
	case 'a':
		movePlayer('a');
		break;

	case 'D':
	case 'd':
		movePlayer('d');
		break;
	}

	getInput();
}

void start()
{
	positionPlayer('w');
	refresh();
	getInput();
}

void selectLevel(int position)
{
	clear();

	cout << "  select level\n\n";

	if (position == 1)
	{
		cout << "  > level 1 <\n";
	}
	else
	{
		cout << "  level 1\n";
	}
	if (position == 2)
	{
		cout << "  > level 2 <\n";
	}
	else
	{
		cout << "  level 2\n";
	}
	if (position == 3)
	{
		cout << "  > level 3 <\n";
	}
	else
	{
		cout << "  level 3\n";
	}
	if (position == 4)
	{
		cout << "  > level 4 <\n";
	}
	else
	{
		cout << "  level 4\n";
	}
	if (position == 5)
	{
		cout << "  > back <\n";
	}
	else
	{
		cout << "  back\n";
	}

	int input{ _getch() };

	if (input == 'W' && position != 1 || input == 'w' && position != 1)
	{
		selectLevel(position - 1);
	}
	else if (input == 'S' && position != 5 || input == 's' && position != 5)
	{
		selectLevel(position + 1);
	}
	else if (input == 13)
	{
		switch (position)
		{
		case 1:
			currentMapNumber = 0;
			break;

		case 2:
			currentMapNumber = 1;
			break;

		case 3:
			currentMapNumber = 2;
			break;

		case 4:
			currentMapNumber = 3;
			break;

		case 5:
			menu(1);
			break;
		}

		currentMap = mapsList[currentMapNumber];
		mapY = currentMap.size();
		mapX = currentMap[0].size();
		playerY = mapY - 1;
		playerX = mapX - 1;

		start();
	}
	else
	{
		selectLevel(position);
	}
}

void quit()
{
	clear();

	for (int i{ 3 }; i > 0; --i)
	{
		cout << "okay, exiting in " << i;

		Sleep(1000);
		clear();
	}

	Beep(200, 325);
	exit(1);
}

void menu(int position)
{
	clear();

	cout << "  menu\n\n";

	if (position == 1)
	{
		cout << "  > start <\n";
	}
	else
	{
		cout << "  start\n";
	}

	if (position == 2)
	{
		cout << "  > select level <\n";
	}
	else
	{
		cout << "  select level\n";
	}

	if (position == 3)
	{
		cout << "  > quit <\n";
	}
	else
	{
		cout << "  quit\n";
	}

	int input{ _getch() };

	if (input == 'W' && position != 1 || input == 'w' && position != 1)
	{
		menu(position - 1);
	}
	else if (input == 'S' && position != 3 || input == 's' && position != 3)
	{
		menu(position + 1);
	}
	else if (input == 13) // why is enter called "carriage return" on this ascii table??
	{
		switch (position)
		{
		case 1:
			start();
			break;

		case 2:
			selectLevel(1);
			break;

		case 3:
			quit();
			break;
		}
	}
	else
	{
		menu(position);
	}
}

int main()
{
	setTextColor(6);
	cout << "written by chapel1337\n";
	cout << "made on 11/12/2022\n";
	resetTextColor();

	Sleep(2000);
	Beep(200, 325);

	menu(1);
}