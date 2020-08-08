#pragma once	// MONSTER CLASS
#include <string>

class Monster
{
	std::string name;

	char dir;	// THE DIR OF THE MONSTERS

	int health;	// THE HEALTH OF THE MONSTER

	int attack, bul_att;	// DAMAGE OF THE MONSTER AND ITS BULLET

	char shape, bul_shape;

	int row, col, lev, tr, tc;

	int speed, bul_speed;

	bool random_();

	bool update(int i, int j);

	void set_dir();

	void set_pos();

	void _r(int & r, int & c, int & l);

	int xp;

public:

	Monster();

	bool move();

	bool check();

	void f_space(int i, int j);

	std::string get_name() { return name; }

	char get_mon_() { return shape; }

	int get_health() { return health; }

	void set_health(int health_) { health = health_; }

	int row_() { return row; }

	int col_() { return col; }

	char get_dir() { return dir; }

	int get_bul_speed() { return bul_speed; }

	char get_bul_shape() { return bul_shape; }

	int get_bul_att() { return bul_att; }

	int get_xp() { return xp; }
};
