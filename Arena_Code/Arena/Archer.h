#ifndef _ARCHER_
#define _ARCHER_

#include "creature.h"

class archer :public creature{
public:
	//Constructor
	archer(entity* location, uint lvl) : creature(source.get_random_name(), "Expert in dodge and fight from the distance", GOBLIN, location, lvl){
		//Initial Stats
		current_live_points = live_points = 15;
		damage = 3;
		agility = 4;
		lvl_up(lvl);
	}
};
#endif