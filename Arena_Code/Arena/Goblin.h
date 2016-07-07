#ifndef _GOBLIN_
#define _GOBLIN_

#include "creature.h"
#include "Data_Source.h"

class goblin :public creature{
public:

	//Constructor
	goblin(entity* location, uint lvl) : creature(source.get_random_name(), "Little green monster", GOBLIN, location, lvl){
		//Initial Stats
		current_live_points = live_points = 20;
		damage = 3;
		stamina = 1;
		lvl_up(lvl);
	}
};
#endif