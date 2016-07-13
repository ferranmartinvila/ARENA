#ifndef _MERCHANT_
#define _MERCHANT_

#include "creature.h"
#include "Data_Tank.h"

class merchant :public creature{
public:

	//NON EXTRA DATA

	//Constructor
	merchant(entity* location, uint lvl) : creature(source.get_random_name(), "Merchants are especialized in buy and sell things.", MERCHANT, location, lvl){
		//Initial Stats
		current_live_points = live_points = 500;
		damage = 50;
		lvl_up(lvl);
	}

	//FUNCTIONS
	void talk(string instruction){
		//Initial talk
		if (state == TALK){
			printf("Hey! Im %s the merchant! do you want to buy or sell some stuff?\n\n", name.get_string());
			state = BUY;
			((creature*)entity_focused)->state = BUY;
			printf("BUY MODE\n"), this->show_storage_for_class(UNDEFINED, true);
		}
		//Change the mode
		else if (instruction == "change"){
			//BUY to SELL
			if (state == BUY){ ((creature*)entity_focused)->state = SELL, state = SELL; }
			//SELL to BUY
			else if (state == SELL){ ((creature*)entity_focused)->state = BUY, state = BUY; }
			//Re-print
			re_print();
		}
		//Choose option 
		else if (instruction.lenght() == 1){
			bool done = false;
			//Buy
			if (state == BUY)done = ((creature*)entity_focused)->buy(((player*)entity_focused)->choose_item(instruction.get_string()[0], UNDEFINED));
			//Sell
			else if (state == SELL)done = ((creature*)entity_focused)->sell(((player*)entity_focused)->choose_item(instruction.get_string()[0], UNDEFINED));
			//Re-print
			if(done)re_print();
		}
		else printf("Invalid Comand.\n");
	}

	void re_print()const{
		if (state == BUY){ printf("BUY MODE\n"), this->show_storage_for_class(UNDEFINED, true); }
		//Sell mode
		else if (state == SELL){ printf("SELL MODE\n"), ((creature*)this->entity_focused)->show_storage_for_class(UNDEFINED, true); }
	}
};
#endif