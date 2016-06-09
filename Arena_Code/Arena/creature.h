#ifndef _CREATURE_
#define _CREATURE_
#include "Globals.h"
#include "entity.h"
class creature :public entity{
private:

	uint live_points;
	uint attack;
	uint defense;
	uint stamina;

public:

	creature(char* name, char* description, uint live_points, uint defense = 0, uint attack = 0, uint stamina = 0) :entity(name, description), live_points(live_points), defense(defense), attack(attack), stamina(stamina){}
};
#endif