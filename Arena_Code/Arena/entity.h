#ifndef _ENTITY_
#define _ENTITY_
class entity{
private:
	char*name;
	char* description;
public:
	entity(char* name,char* description):name(name),description(description){}
};
#endif