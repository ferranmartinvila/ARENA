#include "object.h"

void object::look_it()const{
	//Name & description
	printf("\n%s:\n%s\n", name.get_string(), description.get_string());
	//Stats
	printf("BUFFS:\nlive buff[%i]\nattack buff[%i]\ndefense buff[%i]\nstamina buff[%i]\n", live_buff, attack_buff, defence_buff, stamina_buff);
}