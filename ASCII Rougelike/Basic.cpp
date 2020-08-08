#include <iostream>
#include <Windows.h>
#include "Game.h"
#include <random>
#include <ctime>
#include "Basic.h"
#include <vector>
#include "Monster.h"

using namespace std;

extern Game G;

void hide_cursor()	// FUNCTION TO HIDE THE CURSOR
{
	HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cci;

	cci.dwSize = 25;
	cci.bVisible = FALSE;
	SetConsoleCursorInfo(output, &cci);
}

void display(Shop & shop, vector <Monster> &M)	// FUNCT TO DIPLAY THE GAME
{
	for (int j = 0; j < G.row; j++)
	{
		cout << "\n\t";
		for (int k = 0; k < G.column; k++)	// PRINTING THE TABLE ROW
			cout << G.pos[G.cur_lev][j][k];
		if (j == G.row / 2 - 8)
			cout << "  LEVEL " << G.cur_lev + 1;	// DISPLAYING THE LEVEL
		else if (j == G.row / 2 - 5)
			cout << "  XP - " << int(G.XP);	// DISPL INT XP, SCORE, OF THE PLAYER
		else if (j == G.row / 2 - 3)
			cout << "  HEALTH - " << int(G.P_.health); // PLAYER HEALTH
		else if (j == G.row / 2 + 4)
			cout << "  " << "BULLET - " << shop.play_bull[G.bullet_ct].get_name(); // THE 
		else if (j == G.row / 2 + 6)						// BULLET NAME
		{
			cout << "  QUANTITY - ";
			if (shop.play_bull[G.bullet_ct].get_quan() < 0)
				cout << "INFINITE";
			else
				cout << shop.play_bull[G.bullet_ct].get_quan();	// BULLET QUANTITY
		}
	}
	printf("\n\n%*s%*s%*s%*s\n\n%*s%*s%*s", 13, "UP: W", 14, "DOWN: S", 14, "LEFT: A", 14,
		"RIGHT: D", 22, "SHOOT: <SPACE>", 33, "CHANGE BULLET: <N, M>", 18, "MAIN MENU : P");
	// GAME DIR
}

void set_level() // SETTING THE LEVEL
{
	for (int row = 0; row < G.row; row++)
		for (int col = 0; col < G.column; col++)
			if (row == 0)
				if (col == 0)
					G.pos[G.cur_lev][row][col] = 201; // ╔
				else if (col == G.column - 1)
					G.pos[G.cur_lev][row][col] = 187; // ╗
				else
					G.pos[G.cur_lev][row][col] = 205; // ═

			else if (row == G.row - 1)
				if (col == 0)
					G.pos[G.cur_lev][row][col] = 200; // ╚
				else if (col == G.column - 1)
					G.pos[G.cur_lev][row][col] = 188; // ╝
				else
					G.pos[G.cur_lev][row][col] = 205; // ═
			else
				G.pos[G.cur_lev][row][col] = 186;	 //  ║

	for (int row = 1; row < G.row - 1; row++)	// SETTING THE INNER SPACES AS FREE SPACE
		for (int col = 1; col < G.column - 1; col++)
			G.pos[G.cur_lev][row][col] = G.f_space;

	default_random_engine wall_(time(0));	// CREATING A RANDOM VARIABLE
	uniform_int_distribution <int> x(1, 18);
	uniform_int_distribution <int> y(1, 48);

	for (int i = 0; i < 100 + G.cur_lev * 10; i++)	// CREATING RANDOMLY PLACED WALLS
		if (G.pos[G.cur_lev][x(wall_)][y(wall_)] == G.f_space)
			G.pos[G.cur_lev][x(wall_)][y(wall_)] = 250;//219, 178, 177, 176
		else
			i--;
}