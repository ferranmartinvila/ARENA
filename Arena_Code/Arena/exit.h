#ifndef _EXIT_
#define _EXIT_
#include "entity.h"
#include "room.h"
enum DIRECTION{
	NORTH,
	SOUTH,
	EAST,
	WEST
};

class exit:public entity{
private:
	DIRECTION direction;
	room* from_room;
	room* next_room;

public:

	//Constructor
	exit(char* name, char* description, room*from, room*to, DIRECTION direction) :entity(name, description, EXIT), from_room(from_room), next_room(next_room), direction(direction) {}
};
#endif