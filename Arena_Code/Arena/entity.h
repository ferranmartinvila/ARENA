#ifndef _ENTITY_
#define _ENTITY_
class entity{
private:
	char*name;
	char* description;
public:
	//CONSTRUCTORS
	//Undefined constructor
	entity(){ name = nullptr, description = nullptr; }
	//Defined constructor
	entity(char* name,char* description):name(name),description(description){}
};
#endif