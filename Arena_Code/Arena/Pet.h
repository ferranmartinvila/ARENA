#ifndef _PETS_
#define _PETS_

#include "player.h"
#include "equipment.h"

//PET DATA BASE----------------------------------
class pet :public creature{
public:

	creature* owner;
	uint price;

	//Constructor
	pet(creature* owner, char* name, char* description, CREATURE_TYPE type, entity* location, uint lvl, uint next_lvl_xp, uint live_points, uint defence, uint damage, uint agility, uint price) : creature(name, description, type, location, lvl, next_lvl_xp, live_points, defence, damage, agility), owner(owner), price(price){ lvl_up(lvl); }
	
	//FUNCTIONS
	//LORE---------------------------------------
	void look_it()const{
		slim_printf(WHITE, "%s: ", name.get_string());
		printf("%s\n\n", description);
		slim_printf(WHITE, "STATS:\n");
		slim_printf(LIGHT_MAGENTA, "live[%i]\nattack[%i]\ndefense[%i]\nagility[%i]\n", live_points, damage, defence, agility);
		slim_printf(LIGHT_GREEN, "Price: %u\n\n", price);
		//Storage
		slim_printf(WHITE, "STORAGE:\n");
		list_double<entity*>::node* temp = buffer.first_element;
		if (temp == nullptr)printf("empty\n");
		equip* equip_data = nullptr;
		while (temp){
			equip_data = ((equip*)temp->data);
			slim_printf(LIGHT_CYAN, "%s", temp->data->name.get_string());
			printf("->");
			slim_printf(LIGHT_MAGENTA, "[ V %u || D %u || AT %u || AGI %u ]\n", equip_data->live_buff, equip_data->defence_buff, equip_data->attack_buff, equip_data->agility_buff);
			temp = temp->next;
		}
	}
	void pauted_look_it()const{
		slim_printf(LIGHT_CYAN, "%s -> [", name.get_string());
		slim_printf(LIGHT_MAGENTA, "%u||%u||%u||%u", live_points, defence, damage, agility);
		slim_printf(LIGHT_CYAN, "] ");
		slim_printf(LIGHT_GREEN, "Price: %u\n", price);
	}
};
#endif