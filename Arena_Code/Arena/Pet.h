#ifndef _PETS_
#define _PETS_

#include "creature.h"

//PET DATA BASE----------------------------------
class pet :public creature{
public:

	creature* owner;
	uint price;

	//Constructor
	pet(creature* owner, char* name, char* description, CREATURE_TYPE type, entity* location, uint lvl, uint next_lvl_xp, uint live_points, uint defence, uint damage, uint agility, uint price) : creature(name, description, type, location, lvl, next_lvl_xp, live_points, defence, damage, agility), owner(owner), price(price){ lvl_up(lvl); }
																																													
};
#endif