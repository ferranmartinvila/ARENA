#include "potion.h"

//SYSTEM-----------------------------------------
potion::potion(char* name, char* description, POTION_TYPE potion_type, uint lvl) :object(name, description, POTION, lvl*100), potion_type(potion_type){
	if (potion_type == HEAL_POTION)stat_regen = 5;
	else stat_regen = 2;
}

//LORE-------------------------------------------
void potion::look_it()const{
	printf("%s: %s -> regen[%u] ", name.get_string(), description.get_string(),stat_regen);
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