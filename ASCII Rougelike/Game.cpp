#include <iostream>
#include "Game.h"
#include <vector>
#include "Bullet.h"
#include "Player.h"
#include "Shop.h"
#include "Basic.h"
#include <Windows.h>
#include <conio.h>

Game G;	// CREATING OBJ G WHICH WILL BE USED IN THE WHOLE PROGRAM

vector <Bullet> Bul, Mon_Bul;	// CREATING 2 OBJ OF BULLET CLASS

using namespace std;

#define SPACE printf("\n\n\n\n\n\n\n\n\n");
#define SHOP(x) shop.play_bull[G.bullet_ct].x
#define FOR(x) for(int i = 0; i < x; i++)

bool run()
{
	Shop shop;	// CREATNG SHOP OBJ WHICH WILL STORE ALL THE DIFF TYPES OF BULLETS

	main_menu(shop, "NEW GAME");

	story();

	char *temp = new char[50];

	if (_kbhit())
		cin.getline(temp, 50);

	delete[] temp;

	for (G.cur_lev = 0; G.cur_lev < 9; G.cur_lev++) // TO GO THROUGH THE 10 LEVELS
	{
		if (G.cur_lev)
			main_menu(shop, "ADVANCE TO NEXT LEVEL");
		system("CLS");
		SPACE;	printf("%*s%i", 40, "LEVEL ", G.cur_lev + 1);	Sleep(4000);
		system("CLS");
		SPACE;	printf("%*s", 45, "BATTLE TIME");	Sleep(4000);

		G.init();	// INITIALIZING SOME VARIABLES OF THE GAME CLASS FOR EVERY LEVEL
		set_level();	// SETTING THE LEVEL
		Player P;	// CREATING A PLAYER OBJ
		vector < Monster > Mon;	// CREATING A VECOTR MONSTER

		FOR(G.mon_ct)
			Mon.push_back(Monster());	// CREATING NEW MONSTERS UPTO MON_CT

		while (G.P_.health >= 0 && G.XP < G.max_XP)
			game_level(Mon, P, shop);

		if (G.P_.health < 0)
		{
			system("CLS");
			SPACE;
			cout << "\t\t\t\tYOU HAVE LOST!!!";
			Sleep(4000);
			return true;
		}
		else if (G.XP >= G.max_XP)
		{
			system("CLS");
			SPACE;
			cout << "\t\t\tYOU HAVE COMPLETED THE LEVEL";
			if (G.cur_lev == 9)
			{
				SPACE;
				cout << "YOU HAVE SUCCESSFULLY SAVED THE NHIO VALLEY FROM THE MONSTERS";
				SPACE;
				cout << "\t\t\tENTER ANY KEY TO EXIT";
				_getch();
				exit(0);
			}
		}

		Sleep(4000);
		FOR(G.mon_ct)
			Mon.pop_back();	// DESTROYING THE OBJ AT THE END OF THE LEVEL
		int size_ = Bul.size();	// CREATING TEMP VAR SIZE
		FOR(size_)
			Bul.pop_back();	// DESTROYING THE BULLET CLASS
	}
}

void game_level(vector <Monster> & Mon, Player & P, Shop & shop)
{
	// THIS FUNCTION WILL EXECUTE FOR A PARTICULAR LEVEL

	G.P_.health += 0.01;	// HEALTH INCREASES EVERY TIME THE FUNCT IS RUN
	system("CLS");
	display(shop, Mon);	// DISPLAYING THE GAME
	input(shop);	// INPUTTING IF THE USER HAS ENTERED A CHAR
	P.move();	// THE PLAYER MOVES

	if (G.input == G.f_space)	// IF USER PRESSES THE SPACE - BAR
	{	// A NEW OBJECT IS CREATED IN BUL VECTOR
		Bul.push_back(Bullet(SHOP(get_name()), SHOP(get_damage()),
			SHOP(get_shape()), SHOP(get_speed()), G.last_in));

		if (SHOP(get_quan()) > 0)
			SHOP(set_quan(SHOP(get_quan()) - 1));
	}

	if (!SHOP(get_quan()))	// IF THE NO. OF BULLETS OF CERTAIN
	{	// TYPE IS OVER THAT BULLECT OBJ WILL ERASE
		shop.play_bull[G.bullet_ct] = shop.play_bull.back();
		shop.play_bull.pop_back();
		G.bullet_ct_max--;	// THE MAX_BULL WILL DECREASE BY 1
		if (G.bullet_ct)
			G.bullet_ct--;	// THE CURRENT BULLET_CT WILL DECREASE BY 1
		else
			G.bullet_ct = G.bullet_ct_max;
	}

	FOR(Bul.size())	// THE BULLET MOVES
		if (!Bul[i].move(Mon))
			Bul.erase(Bul.begin() + i);	// POP_BACK CANT BE USED SINCE FEW ERRORS WILL
								// OCCUR
	FOR(Mon_Bul.size())
		if (!Mon_Bul[i].move(Mon))	// THE MONSTER_BUL EXECUTES
			Mon_Bul.erase(Mon_Bul.begin() + i);	// SIMILAR CASE AS BEFORE

	FOR(G.mon_ct)
		if (Mon[i].get_health() < 0)	// IF THE MONSTER HAS LOST ALL ITS HEALTH
		{
			G.XP += Mon[i].get_xp();	// THE PLAYER XP WILL INCREASE
			Mon[i].f_space(Mon[i].row_(), Mon[i].col_()); // THE POS OF THE MONSTER
			Mon[i] = Mon.back();	// WILL AGAIN BECOME A FREE_SPACE
			Mon.pop_back();	// THE LAST OBJ WILL GET DELETED SINCE THE LAST BULLET POS
			Mon.push_back(Monster());	// HAS ALREADY BEEN SHIFTED
		}	// A NEW MONSTER OBJ IS BEING CREATED TO KEEP THE NUM OF MONSTERS SAME

	FOR(G.mon_ct)	// THE MONSTERS WILL MOVE
	{
		if (!Mon[i].move())	// IF THE MON ISNT BEING ABLE TO MOVE IT IS DUE TO THE FACT
			Mon_Bul.push_back(Bullet(Mon[i].get_name(), Mon[i].get_bul_att(), // THAT 
				Mon[i].get_bul_speed(), Mon[i].row_(), Mon[i].col_(),// IT WILL SHOOT A
				Mon[i].get_dir(), Mon[i].get_bul_shape()));// BULLET
		// A NEW OBJ IS BEING CREATED OF THE BULLET CLASS

		if (!Mon[i].check())	// TO CHECK WHETHER THE PLAYER HAS LOST OR NOT
			return;
	}

	if (G.input == G.f_space)
		G.input = G.last_in;	// SETTING THE INPUT TO THE LAST_IN
					// SO AS TO REMEMBER THE DIR IN WHICH THE PLAYER LAST MOVED IN
}