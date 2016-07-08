#ifndef _POTION_
#define _POTION_
#include "entity.h"
class potion : public entity{
public:

	POTION_TYPE potion_type;
	uint stat_regen;
	uint effect_time;
	uint lvl;

	//Constructor
	potion(char*, char*, POTION_TYPE, uint );
	
	//TODO: Complete Functions
	//Functions
	//System
	void lvl_up();
	//Buffs
	bool drink();
	void combine(potion*);
};
#endif