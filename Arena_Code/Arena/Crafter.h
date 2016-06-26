#ifndef _CRAFTER_
#define _CRAFTER_
#include "creature.h"
class crafter :public creature{
public:
	//Constructor
	crafter(char* name, char* description, entity* location, uint lvl) : creature(name, description, CRAFTER, location, lvl){
		current_live_points = live_points = 500;
		damage = 50;
		lvl_up(lvl);
	}

	//FUNCTIONS
	void talk(){ printf("Hello im a Crafter\n"); };
	void craft(){};
};
#endif