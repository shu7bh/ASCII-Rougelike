// WELCOME TO ASCII ROUGELIKE
// 
// SPECIAL THANKS TO DEVANG FOR MOTIVATING ME TO DESIGN THE GAME
//
// HOPE YOU ENJOY THE GAME :)

#include <iostream>
#include "Game.h"
#include "Basic.h"
#include <conio.h>

using namespace std;

#define SPACE printf("\n\n\n\n\n\n\n\n\t\t\t");

int main()
{
	hide_cursor();

	SPACE;

	printf("WELCOME TO ASCII ROUGELIKE");
	for (int i = 100000; i--;)
		if (_kbhit())
		{
			_getch();
			break;
		}
	char op;
	do
	{
		while (true)
			if (run())
				break;
		char *temp = new char[50];
		// THE GAME RUNS AND RETURNS TRUE IF THE PLAYER HAS LOST THE GAME
		system("CLS");
		SPACE;
		if (_kbhit())
			cin.getline(temp, 50);

		delete[] temp;

		cout << "DO YOU WANT TO START A NEW GAME(Y / N)";// ASKING THE USER WHETHER TO
		cout << "\n\n";// (S)HE WANTS TO PLAY AGAIN
		printf("\t\t\t");
		cin >> op;
	} while (op != 'N' && op != 'n');

	system("CLS");
	SPACE;
	printf("PRESS ANY KEY TO EXIT");
	_getch();
	return 0;
}

Game::Game()// INITIALIZE THE CLASS GAME
{
#define M _mon_.push_back(Monster_
	input_ct = 0;

	M("Infantry", 'I', 300, 40, 100, 1, 10, 2));

	M("Brigadier", 'B', 500, 50, 120, 1, 12, 3));

	// TO INITIALIZE DIFF TYPES OF  MONSTERS

	M("Admiral", 'A', 500, 90, 125, 1, 5, 6));

	// NAME, SHAPE, HEALTH, DAMAGE, SCORE INCREASED, SPEED, BUL_DAM, BUL, SPEED

	M("Major", 'M', 1000, 20, 200, 1, 20, 3));

	M("Sergeant", 'S', 700, 80, 250, 1, 25, 4));

	M("Lieutenant", 'L', 1200, 100, 400, 1, 40, 3));

	mon_lev = _mon_.size();//NO OF LEVELS ARE NO. OF DIFF TYPE OF MONSTERS

	mon_ct = 3;	// NO OF MONSTERS AT A TIME TO BE ALIVE
				// DIFF FOR EVERY LEVEL

	bullet_ct = 0;// NO BULLET WILL BE IN THE STARTING
	XP = 2000;	// INITIAL XP FOR LEVEL 1
}