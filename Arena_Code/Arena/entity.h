#ifndef _ENTITY_
#define _ENTITY_

#include "double_list.h"
#include "string.h"
#include "Globals.h"
#include "Slim_printf.h"

class entity{
public:

	//DATA
	TYPE type;
	string name;
	string description;
	list_double<entity*> buffer;

	//Constructor
	entity(char* name, char* description, TYPE type);

	//FUNCTIONS
	//System
	virtual void look_it()const;
	virtual void update(){};
};
#endif