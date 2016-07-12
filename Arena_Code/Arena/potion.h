#ifndef _POTION_
#define _POTION_

#include "object.h"

class potion : public object{
public:

	POTION_TYPE potion_type;
	uint stat_regen;

	//Constructor
	potion(char*, char*, POTION_TYPE, uint );
	
	//FUNCTIONS
	void look_it()const;
	void pauted_look_it()const;
};
#endif