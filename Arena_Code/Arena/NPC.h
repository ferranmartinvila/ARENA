#ifndef _NPC_
#define _NPC_
#include "creature.h"
class npc :public creature{
public:
	
	//NON EXTRA DATA
	//Constructor
	npc(char* name, char* description, CREATURE_TYPE type, entity* location, uint live_points, uint defense = 0, uint damage = 0, uint stamina = 0, uint money = 0, uint xp = 0) :creature(name, description, type, location, live_points, defense, damage, stamina, money, xp){}
	//FUNCTIONS
	virtual void talk(){ printf("Sorry I don't want to talk."); }
};
#endif