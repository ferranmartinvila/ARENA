#ifndef _MERCHANT_
#define _MERCHANT_
#include "creature.h"
class merchant :public creature{
public:
	//NON EXTRA DATA
	//Constructor
	merchant(char* name, char* description, entity* location) : creature(name, description, MERCHANT, location, 100, 0, 1000){}

	//FUNCTIONS
	void talk(){
		if(state == TALK)printf("Hey! Im the %s do you want to buy or sell some stuff?\n\n", name.get_string());
		if (state == TALK){ 
			state = BUY; 
			((creature*)entity_focused)->state = BUY;
		}
		//Buy mode
		if (state == BUY){ printf("BUY MODE\n"),show_storage(this); }
		//Sell mode
		if (state == SELL){ printf("SELL MODE\n"), show_storage((creature*)this->entity_focused); }
	}
};
#endif