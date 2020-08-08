#pragma once		// JUST SOME FUNCTIONS WHICH ARE PRESENT IN DIFFERENT CPP FILES
#include "Shop.h"	// EG: RUN, MAIN MENU
#include <string>
#include <vector>
#include "Monster.h"
#include "Player.h"

void hide_cursor();	// BASIC.CPP

void display(Shop &, std::vector <Monster> &);	// BASIC.CPP

void input(Shop &);	// INPUT.CPP

bool run();	// GAME.CPP

void set_level();	// BASIC.CPP

void story();	// STORY.CPP

void main_menu(Shop &, std::string);	// MAIN MENU.CPP

void game_level(std::vector <Monster> &, Player &, Shop & shop);	// GAME.CPP