#ifndef _CREATURE_
#define _CREATURE_
#include "entity.h"
#include "exit.h"
enum CREATURE_TYPE{

	PLAYER,
	ENEMY

};

class creature :public entity{
public:

	//DATA
	room*location;
	CREATURE_TYPE creature_type;
	uint live_points;
	uint attack;
	uint defense;
	uint stamina;


	//Constructor
	creature(char* name, char* description, CREATURE_TYPE type, room* location, uint live_points, uint defense = 0, uint attack = 0, uint stamina = 0) :entity(name, description, CREATURE), live_points(live_points), defense(defense), attack(attack), stamina(stamina), creature_type(type),location(location) {}

	//FUNCTIONS
	void move(DIRECTION direction);
};
#endif