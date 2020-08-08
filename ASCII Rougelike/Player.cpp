#include "Player.h"
#include "Game.h"
#include <random>
#include <ctime>

using namespace std;

extern Game G;

#define C_POS G.pos[G.cur_lev][row][col]
#define CHECK(x) C_POS == G.x
#define SET_POS(x) C_POS = G.x

Player::Player()
{
	while (true)
	{
		_r(row, col);

		if (CHECK(f_space))
		{
			G.P_.row = row, G.P_.col = col;
			SET_POS(P_.shape);
			break;
		}
	}
	speed = 1;
}

void Player::_r(int & r, int & c)
{
	default_random_engine Mov_(time(0));

	uniform_int_distribution <int> row(1, G.row - 2);
	uniform_int_distribution <int> col(1, G.column - 2);

	r = row(Mov_), c = col(Mov_);
}

void Player::move()
{
#define CK(x) G.input == G.Dir.x
#define UP(x, y) update(row + x, col + y)
#define SET f_space(row, col)

	if (CK(up) && UP(-1, 0))
		SET;
	else if (CK(down) && UP(1, 0))
		SET;
	else if (CK(ryt) && UP(0, 1))
		SET;
	else if (CK(lft) && UP(0, -1))
		SET;
	return;
}

bool Player::update(int row, int col)
{
	if (CHECK(f_space))
	{
		SET_POS(P_.shape);
		tr = row, tc = col;
		return true;
	}
	return false;
}

void Player::f_space(int i, int j)
{
	SET_POS(f_space);
	row = G.P_.row = tr, col = G.P_.col = tc;
}