#include "rune.h"

//COSTRUCTOR-------------------------------------
rune::rune(char* name, char* description, RUNE_TYPE rune_type) :object(name, description, RUNE, 150), rune_type(rune_type){}

//LORE------------------------------------------
void rune::pauted_look_it()const{
	printf("%s [", name.get_string());
	if (rune_type == LIVE_RUNE)printf("LIVE");
	else if (rune_type == DEFENCE_RUNE)printf("DEFENCE");
	else if (rune_type == ATTACK_RUNE)printf("ATTACK");
	else if (rune_type == STAMINA_RUNE)printf("STAMINA");
	printf("] -> Price: %u\n", price);
}