#ifndef _ENCHANTER_
#define _ENCHANTER_

#include "creature.h"
#include "equipment.h"

class enchanter :public creature{
	public:

		//NON EXETRA DATA

		//Constructior
		enchanter(entity* location, uint lvl) : creature(source.get_random_name(), "Enchanters are especialized in upgrade equipment.", ENCHANTER, location, lvl, 100, 500, 50, 50, 100){ lvl_up(lvl); }

		//FUNCTIONS
		void talk(string instruction){
			//Initial talk
			if (state == TALK){
				state = UPGRADE;
				((creature*)entity_focused)->state = UPGRADE;
				slim_printf(WHITE, "Hello I'm %s i can upgrade your equip for the item level x 1000!\n\nITEMS LIST:\n\n", this->name.get_string());
				((creature*)entity_focused)->show_storage_for_class(EQUIP, true);
			}
			//Choose option 
			else if (instruction.lenght() == 1){
				//Upgrade item 
				upgrade_equip((creature*)entity_focused,((equip*)(((player*)entity_focused)->choose_item(instruction.get_string()[0], EQUIP))));
			}
			//Wrong instruction
			else slim_printf(WHITE, "Invalid Comand. \n");
		}

		void upgrade_equip(creature* owner,equip* target){
			if (target == nullptr)printf("Invalid comand.\n");
			if (owner->money < target->level * 1000)printf("You don't have enough money to upgrade %s\n", target->name.get_string());
			else if (target->level == 10)slim_printf(WHITE, "This item is at the max lvl\n");
			else{
				//Find lowest item buff state
				uint lowest_val;
				if (target->live_buff > target->defence_buff)lowest_val = target->defence_buff;
				if (target->defence_buff > target->attack_buff)lowest_val = target->attack_buff;
				if (target->attack_buff > target->agility_buff)lowest_val = target->agility_buff;
				if (lowest_val == 0)lowest_val++;
				//Upgrade equip & add new buffs to the target
				slim_printf(LIGHT_GREEN, "%s has been upgraded to level %u! + %u to all stats! \n\n", target->name.get_string(), target->level+1, lowest_val);
				target->live_buff += lowest_val;
				target->defence_buff += lowest_val;
				target->attack_buff += lowest_val;
				target->agility_buff += lowest_val;
				target->level++;
				//Show the upgraded item
				target->look_it();
			}
		}
};
#endif