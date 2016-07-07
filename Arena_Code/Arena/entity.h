#ifndef _ENTITY_
#define _ENTITY_

#include "double_list.h"
#include "string.h"
#include "Globals.h"

class entity{
public:

	//DATA
	TYPE type;
	string name;
	string description;
	list_double<entity*> buffer;

	//Constructor
	entity(char* name, char* description, TYPE type) :name(name), description(description), type(type){}

	//FUNCTIONS
	virtual void look_it()const;
	virtual void update(){};
};
#endif