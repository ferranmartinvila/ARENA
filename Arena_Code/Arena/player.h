#ifndef _PLAYER_
#define _PLAYER_

#include "creature.h"
class object;
class room;
class pet;

class player :public creature{
public:

	//Player buff states
	uint const_live_buff = 0;
	uint const_defense_buff = 0;
	uint const_attack_buff = 0;
	uint const_agility_buff = 0;
	//Equipation
	object* helm = nullptr;
	object* armor = nullptr;
	object* globes = nullptr;
	object* pants = nullptr;
	object* boots = nullptr;
	object* weapon = nullptr;
	//Spawn location
	room* hub;
	//Pet pointer
	pet* monster;

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
	void spawn_creature();
	void unspawn_creature();
	//Live
	void drink();
	//NPC ACTIONS
	entity* choose_item(char , OBJECT_TYPE);
};
#endif