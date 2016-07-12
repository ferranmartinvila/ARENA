#ifndef _OBJECT_
#define _OBJECT_

#include "entity.h"
class creature;

class object :public entity{
public:

	//DATA
	OBJECT_TYPE object_type;
	uint price;

	//Constructor
	object(char* name, char* description, OBJECT_TYPE object_type, uint price);
	
	//FUNCTIONS
	void look_it()const;
	virtual void pauted_look_it()const;
};
#endif