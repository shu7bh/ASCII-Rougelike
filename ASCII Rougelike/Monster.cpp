#include "Monster.h"
#include "Game.h"
#include <random>
#include <ctime>

using namespace std;

extern Game G;

default_random_engine Mov(time(0));

Monster::Monster()
{
	set_pos();

	set_dir();
}

void Monster::set_pos()
{
	while (true)
	{
		_r(row, col, lev);
		if (G.pos[G.cur_lev][row][col] == G.f_space)
		{
			shape = G.pos[G.cur_lev][row][col] = G._mon_[lev].get_shape();
			break;
		}
	}
#define INIT(x) G._mon_[lev].x

	name = INIT(get_name());
	health = INIT(get_heal());
	attack = INIT(get_att());
	speed = INIT(get_speed());
	bul_att = INIT(Bul_.att);
	bul_speed = INIT(Bul_.speed);
	bul_shape = INIT(Bul_.shape);
	xp = INIT(get_Xp());
}

void Monster::set_dir()
{
#define S_DIR(x) dir = G.Dir.x

	uniform_int_distribution <int> M_(0, 4);


	switch (M_(Mov))
	{
	case 0:		S_DIR(down);		break;
	case 1:		S_DIR(up);		break;
	case 2:		S_DIR(lft);		break;
	case 3:		S_DIR(ryt);		break;
	default:							break;
	}
}

#define RANDOM uniform_int_distribution <int> 

void Monster::_r(int & r, int & c, int & l)
{
	RANDOM row(1, G.row - 2);
	RANDOM col(1, G.column - 2);
	RANDOM lev(0, G.mon_lev - 1);

	r = row(Mov), c = col(Mov), l = lev(Mov);
}

bool Monster::move()
{
#define DIR(dir_) dir == G.Dir.dir_
#define SET f_space(row, col)
#define UD(x, y) update(row + x, col + y) // UPDATE FUNCTION

	for (int i = 0; i < speed; i++)
		while (true)
		{
			if (!random_())
				return false;

			if (DIR(up) && UD(-1, 0))
				SET;
			else if (DIR(down) && UD(+1, 0))
				SET;
			else if (DIR(lft) && UD(0, -1))
				SET;
			else if (DIR(ryt) && UD(0, 1))
				SET;
			else
				continue;
			break;
		}
	return true;
}

bool Monster::random_()
{
#define S_DIR(x) dir = G.Dir.x

	RANDOM M_(0, 77);

	int n = M_(Mov);

	if (n < 60);
	else if (n < 70)		return false;
	else if (n < 72)		S_DIR(up);
	else if (n < 74)		S_DIR(down);
	else if (n < 76)		S_DIR(lft);
	else					S_DIR(ryt);
	return true;
}

bool Monster::update(int i, int j)
{
	if (G.pos[G.cur_lev][i][j] == G.f_space)
	{
		G.pos[G.cur_lev][i][j] = shape;
		tr = i, tc = j;
		return true;
	}
	return false;
}

void Monster::f_space(int i, int j)
{
	G.pos[G.cur_lev][i][j] = G.f_space;
	row = tr, col = tc;
}

bool Monster::check()
{
#define P_CHK(x, y) G.pos[G.cur_lev][row + x][col + y] == G.P_.shape

	if (P_CHK(1, 0) || P_CHK(-1, 0) || P_CHK(0, 1) || P_CHK(0, -1))
		G.P_.health -= attack;

	if (G.P_.health < 0)
		return false;
	else
		return true;
}