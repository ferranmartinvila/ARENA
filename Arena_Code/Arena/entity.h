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
	entity* location = nullptr;
	list_double<entity*> buffer;

	//Constructor
	entity(char* name, char* description, TYPE type, entity* location = nullptr) :name(name), description(description), type(type), location(location){}

	//FUNCTIONS
	virtual void look_it()const;
	virtual void update(){};
};
#endif