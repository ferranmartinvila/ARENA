#ifndef _CREATURE_
#define _CREATURE_
#include "entity.h"
#include "exit.h"
class object;
class creature :public entity{
public:

	//DATA
	//Type
	CREATURE_TYPE creature_type;
	//Lvl
	uint lvl;
	uint current_xp;
	uint next_lvl_xp;
	//State
	CREATURE_STATE state;
	//Location
	entity* location = nullptr;
	//Stats
	int live_points;
	int current_live_points;
	uint damage;
	uint defense;
	uint stamina;
	//Inventory
	uint money;
	//Action focus
	entity* entity_focused = nullptr;

	//Constructor
	creature(char* name, char* description, CREATURE_TYPE type, entity* location, uint lvl) :entity(name, description, CREATURE), creature_type(type), location(location), state(IDLE), lvl(lvl), current_xp(0), next_lvl_xp(100){}

	//FUNCTIONS
	//System
	void update();
	void check_lvl();
	void lvl_up(uint );
	//Lore
	virtual void look_it()const;
	bool show_storage_for_class(OBJECT_TYPE, bool)const;
	virtual void talk();
	//Position
	void move(DIRECTION );
	//Inventory
	void pick();
	void pull();
	bool buy(object* );
	bool sell(object* );
	//Fight
	void attack();
	void drop(creature* );
	//Live
	virtual void die();
	void regen();
};
#endif