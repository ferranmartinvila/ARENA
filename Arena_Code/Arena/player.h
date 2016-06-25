#ifndef _PLAYER_
#define _PLAYER_
#include "creature.h"
#include "object.h"
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

	//Constructor
	player(char* name, char* description, room* location, uint lvl) :creature(name, description, PLAYER, location, lvl){ 
		//Initial Stats
		live_points = 150;
		damage = 5;
		stamina = 2;
		build_from_lvl();
	}

	//FUNCTIONS
	//Lore
	void look_it()const;
	void look()const;
	void talk();
	//Inventory
	void equip_object();
	void unequip_object();
	//NPC ACTIONS
	void choose_option(char option);

};
#endif