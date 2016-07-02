#ifndef _RUNNER_
#define _RUNNER_
#include "creature.h"
class runner :public creature{
public:
	//DATA
	object* rune_choosed;
	object* item_choosed;

	//Constructor
	runner(char* name, char* description, entity* location, uint lvl) : creature(name, description, CRAFTER, location, lvl){
		current_live_points = live_points = 500;
		damage = 50;
		lvl_up(lvl);
	}

	//FUNCTIONS
	void talk(){
		//Item & Rune choosed
		if (item_choosed != nullptr && rune_choosed != nullptr)this->add_rune(item_choosed, rune_choosed);
		//Presentation
		else if (state == TALK){
			printf("Hello im the %s of arena!\n", this->name.get_string());
			state = FUSE_RUNES;
			((creature*)entity_focused)->state = FUSE_RUNES;

			//If player have runes
			if (((creature*)this->entity_focused)->show_storage_for_class(RUNE, false)){
				printf("Do you want to fuse some runes?\n");
				printf("Your runes:\n\n");
				((creature*)this->entity_focused)->show_storage_for_class(RUNE, true);
			}
			//If not
			else printf("Sorry, runes are the only objects that can be fused with equipation.\n"
				"Return when you have some of them.\n");
		}

	};
	bool add_rune(object* target, object* rune){
		//Rune cell full
		if (target->buffer.empty() == false){ printf("%s was fused to a rune before.\n", target->name.get_string()); return false; }
		//Invalid type
		if (target->object_type == RUNE || target->object_type == POTION){printf("Invalid Object.\n"); return false; }
		else{
			//Push the rune to the item buffer
			target->buffer.push_back(rune);
			//Delete the rune from the creature buffer
			this->entity_focused->buffer.erase_data(rune);
			//Apply rune buffs to object & show the result
			printf("%s has been added to %s ", rune->name.get_string(), target->name.get_string());
			if (rune->live_buff){ target->live_buff += rune->live_buff, printf("+%u live", rune->live_buff); }
			if (rune->defence_buff){ target->defence_buff += rune->defence_buff, printf("+%u defence", rune->defence_buff); }
			if (rune->attack_buff){ target->attack_buff += rune->attack_buff, printf("+%u attack", rune->attack_buff); }
			if (rune->stamina_buff){ target->stamina_buff += rune->stamina_buff, printf("+%u stamina", rune->stamina_buff); }
			printf("\n");
			return true;
		}
	}
};
#endif