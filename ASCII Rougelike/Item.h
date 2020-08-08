#pragma once	// ITEM CLASS
#include <string>

using namespace std;

class Bullet;	// CLASS DECLARATION

class Item
{
protected:
	string name;

	int quantity;

	unsigned int cost;

	unsigned int damage;

	char shape;

	unsigned int speed;

public:

	Item(string, int, int, int, char, int);

	string get_name();

	int get_cost();

	int get_quan();

	int get_damage();

	char get_shape();

	int get_speed();

	void set_quan(int quan);

	void display();
};
