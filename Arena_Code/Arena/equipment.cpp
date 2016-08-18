#include "equipment.h"
#include "creature.h"

//CONSTRUCTOR----------------
equip::equip(char* name, char* description, OBJECT_TYPE object_type, uint live_buff = 0, uint defence_buff = 0, uint attack_buff = 0, uint agility_buff = 0, uint price = 0) :object(name, description, object_type, price), live_buff(live_buff), defence_buff(defence_buff), attack_buff(attack_buff), agility_buff(agility_buff){}

//LORE-----------------------
void equip::look_it()const{
	slim_printf(WHITE, "%s: %s\n\nBUFFS:\n", name.get_string(), description.get_string());
	slim_printf(LIGHT_GREEN, "live [%u]\nattack[%u]\ndefence[%u]\nagility[%u]\n", live_buff, attack_buff, defence_buff, agility_buff);
	slim_printf(LIGHT_MAGENTA, "Price -> [%u]\n\n",price);
}

void equip::pauted_look_it()const{
	slim_printf(LIGHT_CYAN, "%s [", name.get_string());
	slim_printf(LIGHT_MAGENTA, "live  %u || atk %u || def %u || agi %u", live_buff, attack_buff, defence_buff, agility_buff);
	slim_printf(LIGHT_CYAN,"]");
	printf(" -> ");
	slim_printf(LIGHT_GREEN, "Price: %u\n", price);
}

//BUFFS----------------------
void equip::add_buffs(creature* target){
	//Adds all the object buffs to the creature and output the result
	if (live_buff > 0){ target->live_points += live_buff, slim_printf(LIGHT_MAGENTA, " +%u live ", live_buff); }
	if (defence_buff > 0){ target->defence += defence_buff, slim_printf(LIGHT_MAGENTA, " +%u defence ", defence_buff); }
	if (attack_buff > 0){ target->damage += attack_buff, slim_printf(LIGHT_MAGENTA, " +%u attack ", attack_buff); }
	if (agility_buff > 0){ target->agility += agility_buff, slim_printf(LIGHT_MAGENTA, " +%u agility ", agility_buff); }
	printf("\n\n");
}

void equip::rest_buffs(creature* target){
	//Rest all the object buffs to the creature and output the result
	if (live_buff > 0){ target->live_points -= live_buff, slim_printf(LIGHT_RED, " -%u live ", live_buff); }
	if (defence_buff > 0){ target->defence -= defence_buff, slim_printf(LIGHT_RED, " -%u defence ", defence_buff); }
	if (attack_buff > 0){ target->damage -= attack_buff, slim_printf(LIGHT_RED, " -%u attack ", attack_buff); }
	if (agility_buff > 0){ target->agility -= agility_buff, slim_printf(LIGHT_RED, " -%u agility ", agility_buff); }
	printf("\n\n");
}