#include <iostream>
#include "Game.h"
#include <conio.h>
#include <Windows.h>

using namespace std;

#define FOR(w) for(int i = 0; i < w; i++)

void S(int x = 2, int y = 2)
{
	FOR(x)
		printf("\n");
	FOR(y)
		printf("\t");
}

void skip()
{
	FOR(200000)
		if (_kbhit())
		{
			_getch();
			break;
		}

	system("CLS");
}

void story()
{
#define P printf

	system("CLS");
	S(8, 3);	P("ONCE UPON A TIME, LONG LONG AGO....");	skip();


	S(8);	P("THE VILLAGERS OF THE NHIO VALLEY WERE ATTACKED");
	S();	P("BY THE MONSTERS OF THE BLACK MOUNTAIN...");	skip();

	S(8);	P("THEY LOST A LOT OF THEIR WEALTH AND RESOURCES");
	S();	P("THEIR SAMURAI'S WERE OF NO MATCH TO THE MONSTERS...");	skip();

	S(8);	P("TO PROTECT THEMSELVES FROM FURTHER ATTACKS");
	S();	P("THEY CALLED UPON THE BEST SAMURAI IN JAPAN TO SAVE THEM...");	skip();

	S(2, 3);	P("IT IS NOW YOUR DUTY TO PROTECT THEM");

	S(4, 2);	P("TO MOVE");
	S(0, 4);	P("TO PAUSE P");
	S(3);		P("UP");
	S(0);		P("W");
	S(0);		P("PREVIOUS BULLET N");

	S();		P("LEFT");
	S(0);		P("A");
	S(0);		P("NEXT BULLET\tM");
	S();		P("RIGHT");
	S(0);		P("D");
	S();		P("DOWN");
	S(0);		P("S");
	S(0);		P("TO SHOOT\t<space>");

	skip();
}