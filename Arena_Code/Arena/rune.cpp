#include "rune.h"

//COSTRUCTOR-------------------------------------
rune::rune(char* name, char* description, RUNE_TYPE rune_type) :object(name, description, RUNE, 150), rune_type(rune_type){}

//LORE------------------------------------------
void rune::pauted_look_it()const{
	//Name
	slim_printf(LIGHT_CYAN, "%s [", name.get_string());
	//Rune type
	if (rune_type == LIVE_RUNE)slim_printf(WHITE, "LIVE");
	else if (rune_type == DEFENCE_RUNE)slim_printf(WHITE, "DEFENCE");
	else if (rune_type == ATTACK_RUNE)slim_printf(WHITE, "ATTACK");
	else if (rune_type == STAMINA_RUNE)slim_printf(WHITE, "STAMINA");
	slim_printf(LIGHT_CYAN, "]");
	printf(" -> ");
	//Price
	slim_printf(LIGHT_GREEN, "Price: %u\n", price);
}