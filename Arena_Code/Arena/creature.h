#ifndef _CREATURE_
#define _CREATURE_
#include "entity.h"
#include "exit.h"
class object;
class creature :public entity{
public:

	//DATA
	CREATURE_TYPE creature_type;
	uint live_points;
	uint damage;
	uint defense;
	uint stamina;
	uint money;
	uint xp;
	CREATURE_STATE state;
	entity* entity_focused = nullptr;

	//Constructor
	creature(char* name, char* description, CREATURE_TYPE type, entity* location, uint live_points, uint defense = 0, uint damage = 0, uint stamina = 0, uint money = 0, uint xp = 0) :entity(name, description, CREATURE, location), live_points(live_points), defense(defense), damage(damage), stamina(stamina), creature_type(type), money(money), xp(xp), state(IDLE) {}

	//FUNCTIONS
	//System
	void update();
	//Lore
	void look_it()const;
	void show_storage(creature* )const;
	virtual void talk();
	//Position
	void move(DIRECTION );
	//Inventory
	void pick();
	void pull();
	//Fight
	void attack();
	void drop(creature* );
	void die();
};
#endif