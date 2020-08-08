#include "Bullet.h"
#include "Game.h"
#include <iostream>
#include "Monster.h"
#include <vector>

using namespace std;

extern  Game G;	// GAME OBJ TAKING VALUE FROM GAME.CPP

#define POS	G.pos[G.cur_lev][i][j]
#define SET f_space(row, col)
#define DIR(dir_) dir == G.Dir.dir_
#define C_POS(check) POS == check
#define CHECK(x, y)	update(row + x, col + y, mo)

bool Bullet::move(vector <Monster> & mo)	// FUNCTION TO MOVE THE BULLET
{
	for (int i = 0; i < speed; i++)	//THE BULLET WILL MOVE 1 BLOCK AT A TIME UPTO THE SPEED

		if (DIR(up) && CHECK(-1, 0))	// CHECK() WILL CHECK WHETHER ITS
			SET;	// POSSIBLE FOR THE BULLET TO MOVE TO THE DESIGNATED POS

		else if (DIR(down) && CHECK(1, 0))
			SET;	// SET() FUNCTION SETS THE INITIAL POS OF THE BULLET TO 

		else if (DIR(lft) && CHECK(0, -1))	// FREESPACE
			SET;

		else if (DIR(ryt) && CHECK(0, 1))
			SET;
		else	// IF THE BULLET CANNOT MOVE THE BULLET POS WILL CHANGE TO FREESPACE
		{	// AND THEN THE BULLET OBJECT WILL GET DESTROYED
			SET;
			return false;
		}
	return true;	// IF THE BULLET CAN SUCCESSFULLY MOVE
}

bool Bullet::update(int i, int j, vector <Monster> & mo)	// THE BULLET CHECK FUNCTION
{
	if (C_POS(G.f_space))	// IF THE NEXT POS IS SPACE
	{
		POS = shape;	// SETTING THE POS TO THE BULLET SHAPE
		tr = i, tc = j;	// SETTING THE CURRENT MON POS TO TEMP VARIABLES TR AND TC
		return true;	// TR -> ROW // TC -> COL
	}

	//for (int i = 0; i < 7; i++)
	//	if (C_POS(G.wall[i])) // IF THE POS IS A WALL
	//		return false;
	//

	for (int k = 0; k < G.mon_ct; k++)	// TO CHECK IF THE POS CONSISTS OF A MONSTER
		if (shape == mo[k].get_bul_shape())
		{// SHOOTING OR WHETHER THE MON_BULLET IS SHOOTING. THE PLAYER HEALTH WILL REDUCE
			if (C_POS(G.P_.shape))	// ONLY IF THEY ARE MON BULLETS
				G.P_.health -= damage;	// THE  PLAYER HEALTH WILL REDUCE

			return false;
		}

	for (int k = 0; k < G.mon_ct; k++)
		if (i == mo[k].row_() && j == mo[k].col_())	// CHECKING IF THE POS IS OCCUPIED BY
		{
			mo[k].set_health(mo[k].get_health() - damage);
			return false;
		}// A MONSTER AND REDUCING ITS HEALTH

	return false;
}

void Bullet::f_space(int i, int j)	// SETTING THE POS OF THE PREVIOUS POS OCCUPIED BY THE
{								// BULLET TO FREESPACE
	if (C_POS(shape))	// FOR THE FISRT TIME THE PLAYER BULLETS WILL
		POS = G.f_space;	// BE ON THE POS OF THE PLAYER SO THE PLAYER 
								// SHOULDN'T GET DESTROYED
	row = tr, col = tc;	// SETTING THE NEW ROW AND COL FROM THE TEMP VARIABLES
}