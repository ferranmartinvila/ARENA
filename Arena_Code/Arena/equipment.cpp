#include "equipment.h"
#include "creature.h"

//CONSTRUCTOR----------------
equip::equip(char* name, char* description, OBJECT_TYPE object_type, uint price , uint live_buff = 0, uint defence_buff = 0, uint attack_buff = 0, uint stamina_buff = 0) :object(name, description, object_type, price), live_buff(live_buff), defence_buff(defence_buff), attack_buff(attack_buff), stamina_buff(stamina_buff){}

//LORE-----------------------
void equip::pauted_look_it()const{
	printf("%s [live  %u ||atk %u || def %u || stm %u ] -> Price: %u\n", name.get_string(), live_buff, attack_buff, defence_buff, stamina_buff, price);
}

//BUFFS----------------------
void equip::add_buffs(creature* target){
	//Adds all the object buffs to the creature and output the result
	if (live_buff > 0){ target->live_points += live_buff, printf("+%u live", live_buff); }
	if (defence_buff > 0){ target->defense += defence_buff, printf("+%u defence", defence_buff); }
	if (attack_buff > 0){ target->damage += attack_buff, printf("+%u attack", attack_buff); }
	if (stamina_buff > 0){ target->stamina += stamina_buff, printf("+%u stamina", stamina_buff); }
	printf("\n");
}

void equip::rest_buffs(creature* target){
	//Rest all the object buffs to the creature and output the result
	if (live_buff > 0){ target->live_points -= live_buff, printf("-%u live", live_buff); }
	if (defence_buff > 0){ target->defense -= defence_buff, printf("-%u defence", defence_buff); }
	if (attack_buff > 0){ target->damage -= attack_buff, printf("-%u attack", attack_buff); }
	if (stamina_buff > 0){ target->stamina -= stamina_buff, printf("-%u stamina", stamina_buff); }
	printf("\n");
}