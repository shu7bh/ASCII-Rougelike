#pragma once
#include <string>
#include <vector>

using namespace std;

struct Directions	// ALL TYPES OF DIRECTIONS
{
	char up = 'W';
	char down = 'S';
	char ryt = 'D';
	char lft = 'A';
};

class Monster_	// MONSTER CLASS WILL HAVE ALL PROP OF MONSTER
{
	class Bullet_	// NESTED BULLET CLASS IT WILL HAVE THE TYPE OF DAMAGE AND SPEED
	{				// OF THE BULLETS SHOT BY THE MONSTERS
	public:
		char shape;
		int att;
		int speed;
	};

	string name;	// NAME OF THE MONSTER - JUST FOR IDENTIFYING

	char shape;		// THE SYMBOL OF THE MONSTER

	int health, att, Xp, speed;	// THE MONSTERS HEALTH, DAMAGE, XP THE USER WILL RECEIVE
		// WHEN THE MONSTER DIES AND THE SPEED OF THE MONSTER
public:

	Bullet_ Bul_;	// CREATING A BUL OBJECT OF NESTED BULLET CLASS

	Monster_(string name_, char shape_, int health_, int att_, int Xp_, int speed_
		, int _att, int _speed)	// CONSTRUCTOR OF MONSTER CLASS
	{
		name = name_, shape = shape_, health = health_, att = att_, Xp = Xp_;
		speed = speed_;
		Bul_.att = _att, Bul_.shape = 'o', Bul_.speed = _speed;
	}

	string get_name() { return name; };	// GETTER FUNCTIONS SINCE THESE VARIABLES WONT

	char get_shape() { return shape; }	// CHANGE

	int get_heal() { return health; }

	int get_att() { return att; }

	int get_Xp() { return Xp; }

	int get_speed() { return speed; }
};

class Player_	// PLAYER CLASS
{
public:
	float health;	// HEALTH OF PLAYER
	int row, col;	// POS OF PLAYER
	const char shape = '@';	// THE SHAPE OF PLAYER
};

class Game
{
public:

	int mon_lev = 0;

	int input_ct, cur_lev, bullet_ct; // INPUT COUNTER, THE PRESENT LEVEL, BULLET COUNTER

	int mon_ct;	// MONSTER COUNTER

	int bullet_ct_max;	// THE NUMBER OF DIFF TYPES OF BULLETS THE PLAYER HAS

	int max_XP;	// THE NEEDED XP TO ADVANCE TO THE NEXT LEVEL

	double XP;	// THE CURRENT XP OF THE PLAYER WITH WHICH HE CAN BUY DIFF BULLETS

#define MAX_ROW 20	// MAX ROWS POSSIBLE
#define MAX_COL 50	// MAX COL POSSIBLE

	const int row = MAX_ROW, column = MAX_COL;

	char pos[10][MAX_ROW][MAX_COL];

	const char wall[7] = { '╔' , '╗', '═', '╚', '╝', '║', '·' };
	const char f_space = ' ', space_ = ' ', pause = 'P';

	char input, last_in;	// THE INPUT THE USER WILL ENTER // THE LAST USER INPUT

	Player_ P_;	// CREATING AN OBJECT OF CLASS PLAYER_

	Directions Dir;	// CREATING OBJECT OF CLASS DIR

	vector < Monster_ > _mon_;	// CREATING A VECOTOR OF CLASS MONSTER_

	void init()	// FUNCTION THAT WILL CHANGE SOME VARIABLES FOR EACH LEVEL
	{
		P_.health = 4000 - cur_lev * 200;	// THE HEALTH WILL DECREASE BY 200 EVERY LEVEL
		XP = 2000;//+cur_lev * 50;	// THE XP WILL INCREASE BY 50
		mon_ct = 4 + cur_lev;	// THE NO. OF MONSTERS WILL INCREASE BY 1
		max_XP = 4000;// +cur_lev * 100;	// THE MAX XP NEEDED WILL INCREASE BY 100
	}

	Game();	// CONSTRUCTOR
};