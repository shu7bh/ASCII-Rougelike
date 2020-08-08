#include <iostream>
#include "Game.h"
#include <Windows.h>
#include <conio.h>
#include "Shop.h"
#include "Basic.h"

using namespace std;

extern Game G;

#define DIR(dir_) G.Dir.dir_
#define IN G.input
#define CHECK(dir_) IN == DIR(dir_)

void input(Shop & shop)
{
	int time_count = 100;
	while (time_count) //Check for keyboard hit
	{
		//Check if timer expired or not
		/*if (((clock() - start) / CLOCKS_PER_SEC) >= 0.001)
		{
		user_input = 'Y';
		break;
		}*/

		if (_kbhit())
		{
			if (G.input_ct)	// So that for the initial
				if (CHECK(down) || CHECK(up) || CHECK(lft) || CHECK(ryt))//bullet movement
					G.last_in = IN;	//it will be easy to know which 
											//position it has to go in.
			IN = toupper(_getch());

			/*72 - up
			80 - down
			75 - left
			77 - right*/
			switch (IN)
			{
			case 'P':
				main_menu(shop, "CONTINUE TO GAME");
				break;

			case 'N':
				if (G.bullet_ct)
					--G.bullet_ct;
				else
					G.bullet_ct = G.bullet_ct_max;
				break;

			case 'M':
				if (G.bullet_ct_max == G.bullet_ct)
					G.bullet_ct = 0;
				else
					++G.bullet_ct;

			default:
				break;
			}

			if (!G.input_ct)	// Initally the input will be 
				if (IN != G.space_)	//the same as what the user entered.
					G.last_in = IN;
				else
					G.last_in = DIR(up);

			G.input_ct++;
			break;
		}
		else
			if (G.input_ct == 0)
			{
				G.last_in = IN = DIR(up);
				G.input_ct++;
			}

		Sleep(1);
		time_count--;
	}
}