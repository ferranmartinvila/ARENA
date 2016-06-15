#ifndef _CREATURE_
#define _CREATURE_
#include "entity.h"
#include "exit.h"
#include "object.h"
class object;
class creature :public entity{
public:

	//DATA
	CREATURE_TYPE creature_type;
	uint live_points;
	uint attack;
	uint defense;
	uint stamina;
	uint money;
	entity* entity_focused = nullptr;

	//Constructor
	creature(char* name, char* description, CREATURE_TYPE type, entity* location, uint live_points, uint defense = 0, uint attack = 0, uint stamina = 0, uint money = 0) :entity(name, description, CREATURE,location), live_points(live_points), defense(defense), attack(attack), stamina(stamina), creature_type(type),money(money) {}

	//FUNCTIONS
	void move(DIRECTION direction);
	void pick(object* object_focused);
};
#endif