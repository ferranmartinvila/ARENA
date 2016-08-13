#ifndef _RUNNER_
#define _RUNNER_

#include "creature.h"
#include "equipment.h"
#include "rune.h"

class runner :public creature{
public:
	//DATA
	rune* rune_choosed;
	equip* item_choosed;

	//Constructor
	runner(entity* location, uint lvl) : creature(source.get_random_name(), "The runner is the only in Arena that can fuse materials", RUNNER, location, lvl){
		current_live_points = live_points = 500;
		damage = 50;
		lvl_up(lvl);
	}

	//FUNCTIONS
	//LORE---------------------------------------
	void talk(string instruction){
		//Initial talk
		if (state == TALK){
			//Pre-reset
			this->item_choosed = nullptr;
			this->rune_choosed = nullptr;
			//Init
			slim_printf(WHITE, "Hello im  %s  the runner of arena!\n\n", this->name.get_string());
			state = FUSE_RUNES;
			((creature*)entity_focused)->state = FUSE_RUNES;
			//Initial print
			re_print();
		}
		//Change fuse/extract mode
		else if (instruction == "change"){
			//FUSE to EXTRACT
			if (state == FUSE_RUNES){ ((creature*)entity_focused)->state = EXTRACT_RUNES, state = EXTRACT_RUNES; }
			//EXTRACT to FUSE
			else { ((creature*)entity_focused)->state = FUSE_RUNES, state = FUSE_RUNES; }
			//Re-print the focused storage & restart mode
			item_choosed = nullptr;
			rune_choosed = nullptr;
			//Re-print
			re_print();
		}
		//Choose option 
		else if (instruction.lenght() == 1){
			//Choose rune
			if (rune_choosed == nullptr && state == FUSE_RUNES){
				//TODO REPAIR 
				rune_choosed = (rune*)((player*)entity_focused)->choose_item(instruction.get_string()[0], RUNE);
				if (rune_choosed != nullptr)re_print();
			}
			//Choose item
			else {
				item_choosed = (equip*)((player*)entity_focused)->choose_item(instruction.get_string()[0], EQUIP);
			}
		}
		else printf("Invalid Comand.\n");
		//Apply FUSE mode
		if (item_choosed != nullptr && rune_choosed != nullptr && state == FUSE_RUNES){
			bool done = false;
			done = this->add_rune(item_choosed, rune_choosed);
			item_choosed = nullptr;
			if (done){ rune_choosed = nullptr,re_print();}
		}
		//Apply EXTRACT mode
		else if (item_choosed != nullptr && rune_choosed == nullptr && state == EXTRACT_RUNES){
			bool done = false;
			done = this->extract_rune(item_choosed);
			item_choosed = nullptr;
			rune_choosed = nullptr;
			if (done)re_print();
		}
		
	}

	void re_print()const{
		//EXTRCT mode
		if (state == EXTRACT_RUNES && item_choosed == nullptr && rune_choosed == nullptr){ slim_printf(WHITE, "EXTRACT MODE:\n\n"), printf("Choose the item.\n"), ((creature*)entity_focused)->show_storage_for_class(EQUIP, true), printf("\n"); }
		//FUSE mode
		//1st step
		else if (state == FUSE_RUNES && rune_choosed == nullptr){ slim_printf(WHITE, "FUSE MODE:\n\n"), printf("Choose the rune.\n\n"), ((creature*)entity_focused)->show_storage_for_class(RUNE, true), printf("\n"); }
		//2nd step
		else if (state == FUSE_RUNES && item_choosed == nullptr){ slim_printf(WHITE, "FUSE MODE:\n\n"), printf("Choose the item.\n\n"), ((creature*)entity_focused)->show_storage_for_class(EQUIP, true), printf("\n"); }
	}



	//RUNE CRAFT---------------------------------
	bool add_rune(equip* target, rune* rune){
		//Rune cell full
		if (target->buffer.empty() == false){printf("%s was fused to a rune before.\n", target->name.get_string()); return false;}
		else{
			//Push the rune to the item buffer
			target->buffer.push_back(rune);
			//Delete the rune from the creature buffer
			this->entity_focused->buffer.erase_data(rune);
			//Apply rune buffs to object & show the result
			slim_printf(LIGHT_GREEN, "%s has been added to %s ", rune->name.get_string(), target->name.get_string());
			if (rune->rune_type == LIVE_RUNE){ target->live_buff += rune->enchant_points, slim_printf(LIGHT_GREEN, "+%u live\n\n", rune->enchant_points); }
			else if (rune->rune_type == DEFENCE_RUNE){ target->defence_buff += rune->enchant_points, slim_printf(LIGHT_GREEN, "+%u defence\n\n", rune->enchant_points); }
			else if (rune->rune_type == ATTACK_RUNE){ target->attack_buff += rune->enchant_points, slim_printf(LIGHT_GREEN, "+%u attack\n\n", rune->enchant_points); }
			else if (rune->rune_type == STAMINA_RUNE){ target->stamina_buff += rune->enchant_points, slim_printf(LIGHT_GREEN, "+%u stamina\n\n", rune->enchant_points); }
			//Targets reset
			this->item_choosed = nullptr;
			this->rune_choosed = nullptr;
			return true;
		}
	}

	bool extract_rune(equip* font){
		//Empty font
		if (font->buffer.empty()){printf("%s have no runes fused.\n", font->name.get_string());return false;}
		else{
			//Focus the rune
			rune* result_rune = ((rune*)font->buffer.first_element->data);
			//Push the rune into the focused creature buffer
			this->entity_focused->buffer.push_back(result_rune);
			//Erase the rune from the font
			font->buffer.pop_back();
			//Rest the rune buffs & show the result
			slim_printf(LIGHT_GREEN, "%s has been extracted from %s ", result_rune->name.get_string(), font->name.get_string());
			if (result_rune->rune_type == LIVE_RUNE){ font->live_buff -= result_rune->enchant_points, slim_printf(LIGHT_RED, "-%u live", result_rune->enchant_points); }
			else if (result_rune->rune_type == DEFENCE_RUNE){ font->defence_buff -= result_rune->enchant_points, slim_printf(LIGHT_RED, "-%u defence", result_rune->enchant_points); }
			else if (result_rune->rune_type == ATTACK_RUNE){ font->attack_buff -= result_rune->enchant_points, slim_printf(LIGHT_RED, "-%u attack", result_rune->enchant_points); }
			else if (result_rune->rune_type == STAMINA_RUNE){ font->stamina_buff -= result_rune->enchant_points, slim_printf(LIGHT_RED, "-%u stamina", result_rune->enchant_points); }
			printf("\n\n");
			this->item_choosed = nullptr;
			return true;
		}
	}
};
#endif