#ifndef _GOBLIN_
#define _GOBLIN_
#include "creature.h"
class goblin :public creature{
public:

	//Constructor
	goblin(char* name, char* description, entity* location, uint lvl) : creature(name, description, GOBLIN, location, lvl){
		//Initial Stats
		current_live_points = live_points = 20;
		damage = 3;
		stamina = 1;
		lvl_up(lvl);
	}
};
#endif