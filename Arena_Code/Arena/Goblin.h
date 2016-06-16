#ifndef _GOBLIN_
#define _GOBLIN_
#include "NPC.h"
class goblin :public npc{
public:

	//Constructor
	goblin(char* name, char* description, entity* location) : npc(name, description, GOBLIN, location, 20, 0, 5, 2, 50,30){}


	//FUNCTIONS

};
#endif