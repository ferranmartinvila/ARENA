#ifndef _PLAYER_
#define _PLAYER_
#include "creature.h"
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


	//FUNCTIONS
	void look(entity* entity_focused)const;
	void equip_object();
	void unequip_object();
	//Constructor
	player(char* name, char* description, room* location, uint live_points, uint defense = 0, uint attack = 0, uint stamina = 0) :creature(name, description, PLAYER, location, live_points, defense, attack, stamina){}
};
#endif