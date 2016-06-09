#ifndef _CREATURE_
#define _CREATURE_
#include "Globals.h"
#include "entity.h"

enum CREATURE_TYPE{

	PLAYER,
	ENEMY

};

class creature :public entity{
private:

	CREATURE_TYPE type;
	uint live_points;
	uint attack;
	uint defense;
	uint stamina;

public:

	creature(char* name, char* description, CREATURE_TYPE type, uint live_points, uint defense = 0, uint attack = 0, uint stamina = 0) :entity(name, description, CREATURE), live_points(live_points), defense(defense), attack(attack), stamina(stamina), type(type) {}
};
#endif