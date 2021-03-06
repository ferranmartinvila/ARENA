#ifndef _CREATURE_
#define _CREATURE_

#include "entity.h"
#include "Data_source.h"
class object;

//CREATURE CLASS
class creature :public entity{
public:

	//DATA
	//Type
	CREATURE_TYPE creature_type;
	//Lvl
	uint lvl = 0;
	uint current_xp;
	uint next_lvl_xp;
	//State
	CREATURE_STATE state;
	//Location
	entity* location = nullptr;
	//Stats
	uint live_points;
	int current_live_points;
	uint damage;
	uint defence;
	uint agility;
	//Inventory
	uint money;
	//Action focus
	entity* entity_focused = nullptr;

	//Constructor
	creature(char* name, char* description, CREATURE_TYPE type, entity* location, uint lvl, uint next_lvl_xp, uint live_points, uint defence, uint damage, uint agility);

	//FUNCTIONS
	//System
	void update();
	void check_lvl();
	void lvl_up(uint );
	//Lore
	virtual void look_it()const;
	bool show_storage_for_class(OBJECT_TYPE, bool)const;
	virtual void talk(string);
	//Position
	void move(string);
	//Inventory
	void pick();
	void pull();
	bool buy(entity*);
	bool sell(entity*);
	//Fight
	void attack();
	void drop(creature* );
	//Live
	virtual void die();
	void regen();
};
#endif