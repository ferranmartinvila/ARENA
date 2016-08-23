#ifndef _TAMER_
#define _TAMER_

#include "creature.h"
#include "Pet.h"

class tamer :public creature{
public:

	//NON EXTRA DATA

	//Constructor
	tamer(entity* location, uint lvl) :creature(source.get_random_name(), "Tamers are special creatures with the hability to train beasts to serve their owners.", TAMER, location, lvl, 100, 500, 50, 50, 100){ lvl_up(lvl); }

	//FUNCTIONS
	//LORE---------------------------------------
	void talk(string instruction){
		//Initial talk
		if (state == TALK){
			this->state = ((creature*)this->entity_focused)->state = PET_TRADE;
			slim_printf(WHITE, "Hello I'm %s the tamer! Do you want a great creature?\n\nANIMALS:\n", this->name.get_string());
			this->show_storage_for_class(UNDEFINED, true);
		}
		//Sell pet
		else if (instruction.lenght() == 1){
			((creature*)this->entity_focused)->buy(((player*)entity_focused)->choose_item(instruction.get_string()[0], UNDEFINED));
		}
	}
};
#endif