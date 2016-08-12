#ifndef _PLAYER_
#define _PLAYER_

#include "creature.h"
class object;
class room;

class player :public creature{
public:

	//Equipation
	object* helm = nullptr;
	object* armor = nullptr;
	object* globes = nullptr;
	object* pants = nullptr;
	object* boots = nullptr;
	object* weapon = nullptr;
	//Inventory size
	uint inventory_size = 6;
	//Spawn location
	room* hub;

	//Constructor
	player(char* name, char* description, room* location, uint lvl);

	//FUNCTIONS
	//System
	void update();
	void reset();
	//Lore
	void look_it()const;
	void look(string);
	void talk(string);
	//Inventory
	void equip_object();
	void unequip_object();
	//NPC ACTIONS
	object* choose_item(char , OBJECT_TYPE);
};
#endif