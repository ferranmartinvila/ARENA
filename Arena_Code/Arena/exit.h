#ifndef _EXIT_
#define _EXIT_
#include "entity.h"
#include "room.h"
class exit:public entity{
public:
	//DATA
	DIRECTION direction;
	room* from_room = nullptr;
	room* next_room = nullptr;

	//Constructor
	exit(char* name, char* description, room*from_room, room*next_room, DIRECTION direction) :entity(name, description, EXIT), from_room(from_room), next_room(next_room), direction(direction) {}
};
#endif