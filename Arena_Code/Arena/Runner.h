#ifndef _RUNNER_
#define _RUNNER_

#include "creature.h"
#include "object.h"
#include "Data_Source.h"

class runner :public creature{
public:
	//DATA
	object* rune_choosed;
	object* item_choosed;

	//Constructor
	runner(entity* location, uint lvl) : creature(source.get_random_name(), "The runner is the only in Arena that can fuse materials", CRAFTER, location, lvl){
		current_live_points = live_points = 500;
		damage = 50;
		lvl_up(lvl);
	}

	//FUNCTIONS
	void talk(){
		//Presentation
		if (state == TALK){
			//Pre-reset
			this->item_choosed = nullptr;
			this->rune_choosed = nullptr;
			//Init
			printf("Hello im the %s of arena!\n", this->name.get_string());
			state = FUSE_RUNES;
			((creature*)entity_focused)->state = FUSE_RUNES;
		}

		//FUSE state 
		if (state == EXTRACT_RUNES && item_choosed == nullptr && rune_choosed == nullptr){ printf("EXTRACT MODE:\n\nChoose the item.\n"), ((creature*)entity_focused)->show_storage_for_class(UNDEFINED, true); }
		//EXTRACT state
		else if (state == FUSE_RUNES && item_choosed == nullptr && rune_choosed == nullptr){ printf("FUSE MODE:\n\nChoose the rune.\n"), ((creature*)entity_focused)->show_storage_for_class(RUNE, true); }
		//Apply FUSE state
		else if (item_choosed != nullptr && rune_choosed != nullptr && state == FUSE_RUNES){
			bool done = false;
			done = this->add_rune(item_choosed, rune_choosed);
			item_choosed = nullptr;
			if (done){ rune_choosed = nullptr,this->talk(); }
		}
		//Apply EXTRACT state
		else if (item_choosed != nullptr && rune_choosed == nullptr && state == EXTRACT_RUNES){
			bool done = false;
			done = this->extract_rune(item_choosed);
			item_choosed = rune_choosed = nullptr;
			if(done)this->talk();
		}
	}
	bool add_rune(object* target, object* rune){
		//Rune cell full
		if (target->buffer.empty() == false){printf("%s was fused to a rune before.\n", target->name.get_string()); return false;}
		//Invalid type
		if (target->object_type == RUNE || target->object_type == POTION){ printf("Invalid Object.\n"); return false; }
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
			printf("\n\n");
			this->item_choosed = this->rune_choosed = nullptr;
			return true;
		}
	}
	bool extract_rune(object* font){
		//Empty font
		if (font->buffer.empty()){printf("%s have no runes fused.\n", font->name.get_string());return false;}
		else{
			//Focus the rune
			object* result_rune = ((object*)font->buffer.first_element->data);
			//Push the rune into the focused creature buffer
			this->entity_focused->buffer.push_back(result_rune);
			//Erase the rune from the font
			font->buffer.pop_back();
			//Rest the rune buffs & show the result
			printf("%s has been extracted from %s ", result_rune->name.get_string(), font->name.get_string());
			if (result_rune->live_buff){ font->live_buff -= result_rune->live_buff, printf("-%u live", result_rune->live_buff); }
			if (result_rune->defence_buff){ font->defence_buff -= result_rune->defence_buff, printf("-%u defence", result_rune->defence_buff); }
			if (result_rune->attack_buff){ font->attack_buff -= result_rune->attack_buff, printf("-%u attack", result_rune->attack_buff); }
			if (result_rune->stamina_buff){ font->stamina_buff -= result_rune->stamina_buff, printf("-%u stamina", result_rune->stamina_buff); }
			printf("\n\n");
			this->item_choosed = nullptr;
			return true;
		}
	}
};
#endif