#include "Item.h"
#include <string>

Item::Item(std::string name_, int quantity_, int cost_, int damage_,
	char shape_, int speed_)
{
	name = name_, quantity = quantity_, cost = cost_, damage = damage_, shape = shape_,
		speed = speed_;
}

string Item::get_name()
{
	return name;
}

int Item::get_cost()
{
	return cost;
}

int Item::get_quan()
{
	return quantity;
}

int Item::get_damage()
{
	return damage;
}

char Item::get_shape()
{
	return shape;
}

int Item::get_speed()
{
	return speed;
}

void Item::set_quan(int quan)
{
	quantity = quan;
}

void Item::display()
{
	if (quantity < 0 && cost == 0)
		printf("%*s%*s%*i%*i%*s\n", 18, name.c_str(), 15,
			"UNLIMITED", 10, damage, 12, speed, 17, "FREE");
	else
		printf("%*s%*s%*i%*i%*i%*i\n", 18, name.c_str(), 6, " x ", 6,
			quantity, 13, damage, 12, speed, 15, cost);
}