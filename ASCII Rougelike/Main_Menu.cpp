#include <iostream>
#include "Game.h"
#include "Basic.h"
#include "Shop.h"
#include <conio.h>

extern Game G;			// THE MAIN MENU OF THE GAME HERE THE PLAYER CAN EITHER GO TO
						//		NEW / CONTINUE / NEW LEVEL
using namespace std;	//		
						//		SHOP
inline void p_stars(int n)
{						//		VIEW PLAYER BULLETS
	for (int i = 0; i < n; i++)
		printf("*");	// TO PRINT STARS
}

void S_(int n = 0, int t = 0)	// TO PRINT SPACES AND TABS
{
	for (int i = 0; i++ < n;)
		printf("\n");
	for (int i = 0; i++ < t;)
		printf("\t");
}

void main_menu(Shop & shop, string new_game)
{
	while (true)
	{
		char op;
		system("CLS");
		p_stars(27);
		cout << " WELCOME TO THE MAIN MENU ";
		p_stars(27);

		S_(5, 0);		printf("%*c", 25, 'C');
		S_(0, 2);		printf("%s", new_game.c_str());
		S_(3, 0);		printf("%*c", 25, 'S');
		S_(0, 2);		printf("%s", "GO TO SHOP");
		S_(3, 0);		printf("%*c", 25, 'B');
		S_(0, 2);		printf("%s", "SEE MY BULLETS");

		S_(6, 0);		printf("%*c", 24, ' ');

		cin >> op;	// OP IS THE USER CHOICE
		op = toupper(op);

		switch (op)
		{
		case 'C':
			return;	// THE MAIN MENU FUNCTION ENDS
		case 'S':
			shop.display();	// DIS
			G.bullet_ct_max = shop.play_bull.size() - 1;
		case 'B':
			shop.my_bullet();
		default:
			break;
		}
	}
}