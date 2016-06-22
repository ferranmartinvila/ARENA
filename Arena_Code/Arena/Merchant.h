#ifndef _MERCHANT_
#define _MERCHANT_
#include "creature.h"
class merchant :public creature{
public:
	//NON EXTRA DATA
	//Constructor
	merchant(char* name, char* description, entity* location) : creature(name, description, MERCHANT, location, 100, 0, 1000){}

	//FUNCTIONS
	void talk()const{
		printf("Hey! Im %s do you want to buy some stuff?\n\n", name.get_string());
		show_storage();
	}
	void show_storage()const{
		char k = 'a';
		printf("STORAGE:\nOption || Item || live_buff || def_buff || attack_buff || stamina_buff || price\n\n");
		list_double<entity*>::node* temp = this->buffer.first_element;
		while (temp){
			printf("[%c] -%s [ %i | %i | %i | %i ] price:%i\n", k, temp->data->name.get_string(), ((object*)temp->data)->live_buff, ((object*)temp->data)->defence_buff, ((object*)temp->data)->attack_buff, ((object*)temp->data)->stamina_buff, ((object*)temp->data)->price);
			k++;
			temp = temp->next;
		}
		if (k == 0)printf("empty");
	}
};
#endif