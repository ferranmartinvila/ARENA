#include "rune.h"

//COSTRUCTOR-------------------------------------
rune::rune(char* name, char* description, RUNE_TYPE rune_type, uint enchant_points, uint price) :object(name, description, RUNE, price), rune_type(rune_type), enchant_points(enchant_points){}

//LORE------------------------------------------
void rune::look_it()const{
	slim_printf(WHITE, "%s: %s", name.get_string(), description.get_string());
	printf(" -> ");
	slim_printf(LIGHT_MAGENTA, "adds[%u]\n\n", this->enchant_points);
}

void rune::pauted_look_it()const{
	//Name
	slim_printf(LIGHT_CYAN, "%s [", name.get_string());
	//Rune type
	if (rune_type == LIVE_RUNE)slim_printf(WHITE, "LIVE");
	else if (rune_type == DEFENCE_RUNE)slim_printf(WHITE, "DEFENCE");
	else if (rune_type == ATTACK_RUNE)slim_printf(WHITE, "ATTACK");
	else if (rune_type == AGILITY_RUNE)slim_printf(WHITE, "AGILITY");
	slim_printf(LIGHT_CYAN, "]");
	printf(" -> ");
	//Price
	slim_printf(LIGHT_GREEN, "Price: %u\n", price);
}