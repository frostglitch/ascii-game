#include <string>
#include <iostream>
#include <thread> //Sleep
#include <chrono> //milliseconds
#include <stdlib.h> //system clear
#include <conio.h> //_getch
#include <random>
using namespace std;
using namespace this_thread;
using namespace chrono;

#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77


void ClearLevel(char level[10][20], char point)
{
	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			level[i][j] = point;
		}
	}
}

void PrintLevel(char level[10][20])
{
	cout << "[][][][][][][][][][][][]\n";

	for (int i = 0; i < 10; i++)
	{
		cout << "[]";
		for (int j = 0; j < 20; j++)
		{
			cout << level[i][j];
		}
		cout << "[]";
		cout << endl;
	}

	cout << "[][][][][][][][][][][][]\n";
}

void PrintScores(int deaths, int scores, int x, int y)
{
	cout << endl;
	cout << "{-] | " << x << ", " << y << " | Score: " << scores << ", Deaths: " << deaths << " [-}";

	if (scores == 5)
	{
		cout << endl << endl << " Y O U    W I N    ! ! !" << endl;
	}
}

void FillWithTraps(char score, char death, char level[10][20])
{
	level[5][5] = score;
	level[7][14] = score;
	level[9][10] = score;
	level[2][4] = score;
	level[4][18] = score;

	level[3][15] = death;
	level[6][5] = death;
	level[9][13] = death;
	level[2][3] = death;
	level[5][16] = death;
}

int main()
{
	char level[10][20];


	char player = '@';
	char point = '+';
	char score = 'o';
	char death = '*';

	int minXpos = 0;
	int maxXpos = 19;
	int xPos = 0;

	int minYpos = 0;
	int maxYpos = 9;
	int yPos = 0;

	int scores = 0;
	int deaths = 0;

	int scoreArray[5] = { 0,0,0,0,0 };

	cout << "Hello!\n";

	sleep_for(seconds(1));

	cout << "You are this: @\n";

	sleep_for(seconds(1));

	cout << "* is bad\n";

	sleep_for(seconds(1));

	cout << "o is good\n";

	sleep_for(seconds(1));

	cout << "Good Luck!\n";

	sleep_for(seconds(1));

	cout << "3   ";

	sleep_for(seconds(1));

	cout << "2   ";

	sleep_for(seconds(1));

	cout << "1   ";

	system("CLS");

	int c = 0;

	while (1)
	{

		FillWithTraps(score, death, level);

		if (scoreArray[0] == 1) level[5][5] = point;
		if (scoreArray[1] == 1) level[7][14] = point;
		if (scoreArray[2] == 1) level[9][10] = point;
		if (scoreArray[3] == 1) level[2][4] = point;
		if (scoreArray[4] == 1) level[4][18] = point;

		level[yPos][xPos] = player;

		PrintLevel(level);
		PrintScores(deaths, scores, xPos, yPos);


#pragma region Input
		c = 0;
		switch ((c = _getch())) {
		case KEY_UP:
			if (yPos > minYpos) yPos--;
			break;
		case KEY_DOWN:
			if (yPos < maxYpos) yPos++;
			break;
		case KEY_LEFT:
			if (xPos > minXpos) xPos--;
			break;
		case KEY_RIGHT:
			if (xPos < maxXpos) xPos++;
			break;
		}
#pragma endregion


		if (xPos == 5 && yPos == 5 && scoreArray[0] == 0)
		{
			scoreArray[0] = 1;
			scores++;
		}
		if (xPos == 14 && yPos == 7 && scoreArray[1] == 0)
		{
			scoreArray[1] = 1;
			scores++;
		}
		if (xPos == 10 && yPos == 9 && scoreArray[2] == 0)
		{
			scoreArray[2] = 1;
			scores++;
		}
		if (xPos == 4 && yPos == 2 && scoreArray[3] == 0)
		{
			scoreArray[3] = 1;
			scores++;
		}
		if (xPos == 18 && yPos == 4 && scoreArray[4] == 0)
		{
			scoreArray[4] = 1;
			scores++;
		}

		if ((xPos == 15 && yPos == 3) || (xPos == 5 && yPos == 6) || (xPos == 13 && yPos == 9) || (xPos == 3 && yPos == 2) || (xPos == 16 && yPos == 5))
		{
			scores = 0;

			for (int i = 0; i < 5; i++) scoreArray[i] = 0;

			deaths++;

			xPos = 0;
			yPos = 0;
		}



		ClearLevel(level, point);
		system("CLS");
	}
}