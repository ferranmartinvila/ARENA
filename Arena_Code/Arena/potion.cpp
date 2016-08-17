#include "potion.h"

//SYSTEM-----------------------------------------
potion::potion(char* name, char* description, POTION_TYPE potion_type, uint stat_buff, uint price) :object(name, description, POTION, price), potion_type(potion_type), stat_buff(stat_buff){}

//LORE-------------------------------------------
void potion::look_it()const{
	slim_printf(WHITE, "%s: %s", name.get_string(), description.get_string());
	printf(" -> ");
	slim_printf(LIGHT_MAGENTA, "buffs[%u]\n\n", stat_buff);
}

void potion::pauted_look_it()const{
	//Name
	slim_printf(LIGHT_CYAN, "%s [", name.get_string());
	//Potion type
	if (potion_type == HEAL_POTION)slim_printf(WHITE, "HEAL");
	else if (potion_type == DEFENCE_POTION)slim_printf(WHITE, "DEFENCE");
	else if (potion_type == ATTACK_POTION)slim_printf(WHITE, "ATTACK");
	else if (potion_type == AGILITY_POTION)slim_printf(WHITE, "AGILITY");
	slim_printf(LIGHT_CYAN, "]");
	printf(" -> ");
	//Price
	slim_printf(LIGHT_GREEN, "Price: %u\n", price);
}