#ifndef _PLAYER_
#define _PLAYER_
#include "creature.h"
class player :public creature{

	//NO EXTRA DATA

public:

	//Constructor
	player(char* name, char* description, uint live_points, uint defense = 0, uint attack = 0, uint stamina = 0) :creature(name, description, PLAYER, live_points, defense, attack, stamina){}
};
#endif