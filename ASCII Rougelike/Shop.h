#pragma once
#include <vector>
#include "Item.h"
#include "Game.h"

using namespace std;

class Shop
{
	vector < Item > item;
	inline void dis_star(int);
	inline void U_L(int, int);
	void change(int, int, double &);
public:
	vector < Item >	play_bull;
	Shop();
	void display();
	void my_bullet();
};