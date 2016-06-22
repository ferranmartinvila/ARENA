#include "object.h"
#include "creature.h"

void object::look_it()const{
	//Name & description
	printf("\n%s:\n%s\n", name.get_string(), description.get_string());
	//Stats
	printf("BUFFS:\nlive buff[%i]\nattack buff[%i]\ndefense buff[%i]\nstamina buff[%i]\n", live_buff, attack_buff, defence_buff, stamina_buff);
}

void object::add_buffs(creature* target){
	//Adds all the object buffs to the creature and output the result
	if (live_buff > 0){ target->live_points += live_buff, printf("+%u live", live_buff); }
	if (defence_buff > 0){ target->defense += defence_buff, printf("+%u defence", defence_buff); }
	if (attack_buff > 0){ target->damage += attack_buff, printf("+%u attack", attack_buff); }
	if (stamina_buff > 0){ target->stamina += stamina_buff, printf("+%u stamina", stamina_buff); }
	printf("\n");
}

void object::rest_buffs(creature* target){
	//Rest all the object buffs to the creature and output the result
	if (live_buff > 0){ target->live_points -= live_buff, printf("-%u live", live_buff); }
	if (defence_buff > 0){ target->defense -= defence_buff, printf("-%u defence", defence_buff); }
	if (attack_buff > 0){ target->damage -= attack_buff, printf("-%u attack", attack_buff); }
	if (stamina_buff > 0){ target->stamina -= stamina_buff, printf("-%u stamina", stamina_buff); }
	printf("\n");
}