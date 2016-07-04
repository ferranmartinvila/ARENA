#ifndef _MERCHANT_
#define _MERCHANT_
#include "creature.h"
class merchant :public creature{
public:

	//NON EXTRA DATA

	//Constructor
	merchant(char* name, char* description, entity* location, uint lvl) : creature(name, description, MERCHANT, location, lvl){
		//Initial Stats
		current_live_points = live_points = 500;
		damage = 50;
		lvl_up(lvl);
	}

	//FUNCTIONS
	void talk(){
		if (state == TALK){
			printf("Hey! Im the %s do you want to buy or sell some stuff?\n\n", name.get_string());
			state = BUY;
			((creature*)entity_focused)->state = BUY;
		}
		//Buy mode
		if (state == BUY){ printf("BUY MODE\n"), this->show_storage_for_class(UNDEFINED, true); }
		//Sell mode
		if (state == SELL){ printf("SELL MODE\n"), ((creature*)this->entity_focused)->show_storage_for_class(UNDEFINED, true); }
	}
};
#endif