#ifndef _GOBLIN_
#define _GOBLIN_
#include "creature.h"
class goblin :public creature{
public:

	//Constructor
	goblin(char* name, char* description, entity* location) : creature(name, description, GOBLIN, location, 20, 0, 5, 2, 50,30){}


	
	//FUNCTIONS

};
#endif