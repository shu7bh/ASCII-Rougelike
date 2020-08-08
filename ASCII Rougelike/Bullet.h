#pragma once	// BULLET CLASS DECLARATIONS
#include "Game.h"
#include "Monster.h"
#include <vector>
#include "Item.h"
#include <string>

extern Game G;

using namespace std;

class Bullet : private Item	// INHERITS ITEM MEMBERS TO
{											//  EXECUTE DIFF TYPES OF BULLETS
	int row, col, tr, tc;	// POS OF THE MONSTER
	char dir;	// DIR OF THE MONSTER
	int ct = 0;
	bool update(int, int, vector <Monster> &);
	void f_space(int, int);

public:

	Bullet(string name, int dam, char shape, int speed, char dir,
		int quan = 0, int cost_ = 0) : Item(name, quan, cost_, dam, shape, speed), dir(dir)
	{	// FIRST OVERLOADED CONSTRUCTOR
#define SET(x) x = G.P_.x

		SET(row), SET(col);
	}
#define I(x) int x

	Bullet(string name, I(dam), I(speed), I(row), I(col), char dir,
		char shape) : Item(name, 0, 0, dam, shape, speed), row(row), col(col), dir(dir) {}
		// 2ND OVERLOADED CONSTRUCTOR
	

	bool move(vector <Monster> &);	//	THE MOVE FUNCTION
};