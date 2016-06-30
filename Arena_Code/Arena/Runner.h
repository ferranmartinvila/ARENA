#ifndef _RUNNER_
#define _RUNNER_
#include "creature.h"
class runner :public creature{
public:
	//Constructor
	runner(char* name, char* description, entity* location, uint lvl) : creature(name, description, CRAFTER, location, lvl){
		current_live_points = live_points = 500;
		damage = 50;
		lvl_up(lvl);
	}

	//FUNCTIONS
	void talk(){
		//Pointer to user buffer
		list_double<entity*>::node* temp = entity_focused->buffer.first_element;
		//Search runes
		uint runes_in = 0;
		while (temp){
			if (((object*)temp->data)->object_type == RUNE)runes_in++;
			temp = temp->next;
		}
		//Presentation
		printf("Hello im the %s of arena!\n",this->name.get_string());
		//If player have runes
		if (this->show_objects_class(RUNE,false) == true){
			printf("Do you want to fuse some runes?\n");
			printf("Your runes:\n\n");
			this->show_objects_class(RUNE, true);
		}
		//If not
		else printf("Sorry, runes are the only objects that can be fused with equipation.\n"
			"Return when you have some of them.\n");
	};
	void fuse_rune(){};
};
#endif