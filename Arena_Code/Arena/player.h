#ifndef _PLAYER_
#define _PLAYER_
#include "creature.h"
class player :public creature{
public:

	//NONE EXTRA DATA


	//FUNCTIONS
	void look(entity* entity_focused)const;
	//Constructor
	player(char* name, char* description, room* location, uint live_points, uint defense = 0, uint attack = 0, uint stamina = 0) :creature(name, description, PLAYER, location, live_points, defense, attack, stamina){}
};
#endif