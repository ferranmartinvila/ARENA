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
	player(char* name, char* description, room* location, uint live_points, uint defense = 0, uint attack = 0, uint stamina = 0) :creature(name, description, PLAYER, location, live_points, defense, attack, stamina){}

	//FUNCTIONS
	//Lore
	void look()const;
	void talk();
	//Inventory
	void equip_object();
	void unequip_object();
	//NPC ACTIONS
	void choose_option(char option);
	void buy(object*);
	void sell(object*);

};
#endif