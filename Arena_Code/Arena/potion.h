#ifndef _POTION_
#define _POTION_

#include "object.h"

class potion : public object{
public:

	POTION_TYPE potion_type;
	uint stat_buff;

	//Constructor
	potion(char* name, char* description, POTION_TYPE potion_type, uint stat_buff, uint price);
	
	//FUNCTIONS
	void look_it()const;
	void pauted_look_it()const;
};
#endif