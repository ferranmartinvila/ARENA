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
	printf("%s [", name.get_string());
	if (potion_type == HEAL_POTION)printf("HEAL");
	else if (potion_type == STAMINA_POTION)printf("STAMINA");
	printf("] -> Price: %u\n", price);
}