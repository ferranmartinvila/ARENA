#ifndef _ROOM_
#define _ROOM_
#include "entity.h"
class room :public entity{
	
	//NO EXTRA DATA

public:

	//Constructor
	room(char* name, char* description) :entity(name, description, ROOM){}
};
#endif