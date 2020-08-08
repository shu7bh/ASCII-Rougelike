#include "Shop.h"
#include <string>
#include <vector>
#include <iostream>
#include <conio.h>
#include "Game.h"
#include <string.h>

using namespace std;

extern Game G;

#define FOR(y) for(int i = 0; i < y; i++)
#define P_ printf

Shop::Shop()
{
#define I item.push_back(Item
	I("AUTO", -1, 0, 80, '+', 2));
	I("WAD CUTTER", 5000, 5, 200, '*', 4));
	I("SPLITZER", 2500, 10, 300, '`', 7));
	I("GOLD CASED", 25000, 2, 100, '.', 2));
	I("SWISS MINI", 1000, 50, 700, '~', 15));
	I("SHOT LOAD", 50000, 1, 90, ',', 3));
	I("SEMI AUTO", 4000, 3, 120, 249, 6));
#undef I
	play_bull.push_back(Item("AUTO", -1, 0, 80, '+', 2));
}

void Shop::display()
{
	system("CLS");
	dis_star(29);
	P_("%s", " WELCOME TO THE SHOP ");
	dis_star(29);
	P_("\n\n\n%*s%*s%*s%*s%*s%*s\n", 6, "S.NO", 15,
		"BULLET NAME", 15, "QUANTITY", 12, "DAMAGE", 12, "SPEED", 15, "COST");

	U_L(2, 4);	U_L(4, 11);
	U_L(7, 8);	U_L(6, 6);
	U_L(7, 5);	U_L(11, 4);
	{
		int ct = 0;
		for (int i = 0; i < item.size(); i++)

			if (item[i].get_cost() != 0 && item[i].get_quan() != 0)
			{
				P_("\n%*i", 3, ++ct);
				item[i].display();
			}
	}
	P_("\n\n%*s\t%i", 44, "YOUR XP: ", int(G.XP));
	P_("\n\n%*s", 15, "ENTER S.No: ");
	int sno, quantity;
	cin >> sno;
	P_("\n%*s%*c", 13, "QUANTITY: ", 2, ' ');
	cin >> quantity;

	change(sno, quantity, G.XP);
}

void Shop::my_bullet()
{
	system("CLS");
	dis_star(34);
	P_("%s", " MY BULLETS ");
	dis_star(34);
	P_("\n\n\n%*s%*s%*s%*s%*s%*s\n", 6, "S.NO", 15,
		"BULLET NAME", 15, "QUANTITY", 12, "DAMAGE", 12, "SPEED", 15, "COST");

	U_L(2, 4);
	U_L(4, 11);
	U_L(7, 8);
	U_L(6, 6);
	U_L(7, 5);
	U_L(11, 4);

	P_("\n\n\n");
	for (int i = 0; i < play_bull.size(); i++)
	{
		P_("\n%*i", 3, i + 1);
		play_bull[i].display();
	}

	FOR(1500000000);
}

inline void Shop::dis_star(int n)
{
	for (int i = 0; i < n; i++)
		P_("%c", '*');
}

inline void Shop::U_L(int leave, int n)
{
	P_("%*c", leave, ' ');
	for (int i = 0; i < n; i++)
		P_("~");
}

void Shop::change(int sno, int quantity, double & xp)
{
#define I item[i]
#define P play_bull
	int ct = 0;
	for (int i = 0; i < item.size(); i++)
	{
		if (I.get_quan() && I.get_cost())
			ct++;
		else
			continue;
		if (sno == ct)
		{
			int j;
			for (int j = 0; j < quantity; j++)
			{
				if (I.get_cost() > xp)
					return;

				I.set_quan(I.get_quan() - 1);

				int k;
				for (int k = 0; k < P.size(); k++)
				{
					if (P[k].get_name() == I.get_name())
					{
						P[k].set_quan(1 + P[k].get_quan());
						break;
					}
					if (k == P.size() - 1)
					{
						P.push_back(Item(I.get_name(), 1,
							I.get_cost(), I.get_damage(), I.get_shape(),
							I.get_speed()));
						break;
					}
				}
				xp -= I.get_cost();
			}
		}
	}
}
#undef FOR(x, y)
#undef P_
#undef I