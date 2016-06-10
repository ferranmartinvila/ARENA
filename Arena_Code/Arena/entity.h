#ifndef _ENTITY_
#define _ENTITY_
#include "double_list.h"
#include "string.h"
#include "Globals.h"

enum TYPE{

	OBJECT,
	CREATURE,
	ROOM,
	EXIT,
	UNDEFINED
};

class entity{
public:

	//DATA
	TYPE type;
	string name;
	string description;
	list_double<entity*> buffer;


	//FUNCTIONS
	void look_it()const;
	//CONSTRUCTORS
	//Undefined constructor
	entity(){ name = nullptr, description = nullptr, type = UNDEFINED; }
	//Defined constructor
	entity(char* name,char* description,TYPE type):name(name),description(description),type(type){}
};
#endif