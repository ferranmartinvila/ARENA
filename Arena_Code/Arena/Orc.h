#ifndef _ORC_
#define _ORC_

#include "creature.h"

class orc :public creature{
public:
	//Constructor
	orc(entity* location, uint lvl) : creature(source.get_random_name(), "A strong and green monster", ORC, location, lvl){
		//Initial Stats
		current_live_points = live_points = 50;
		defense = 4;
		damage = 5;
		agility = 0;
		lvl_up(lvl);
	}
};
#endif