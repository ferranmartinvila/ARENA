#ifndef _ENTITY_
#define _ENTITY_
#include "double_list.h"
enum TYPE{

	OBJECT,
	CREATURE,
	ROOM,
	EXIT,
	UNDEFINED
};

class entity{
private:

	TYPE type;
	char*name;
	char* description;
	list_double<entity*> buffer;

public:

	//CONSTRUCTORS
	//Undefined constructor
	entity(){ name = nullptr, description = nullptr, type = UNDEFINED; }
	//Defined constructor
	entity(char* name,char* description,TYPE type):name(name),description(description),type(type){}
};
#endif