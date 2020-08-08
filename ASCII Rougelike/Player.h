#pragma once
#include "Game.h"

using namespace std;

class Player
{
	bool update(int, int);
	void f_space(int, int);

	void _r(int &, int &);
	int row, col, tr, tc;
	int speed;

public:
	Player();
	void move();
};