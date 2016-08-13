#include "entity.h"
#include "creature.h"

//CONSTRUCTOR------------------------------------
entity::entity(char* name, char* description, TYPE type) :name(name), description(description), type(type){}

//SYSTEM-----------------------------------------
void entity::look_it()const{
	slim_printf(WHITE, "\n%s:\n", name.get_string());
	printf("%s\n\n", description.get_string());
	slim_printf(WHITE,"CONTENT:\n", description.get_string());
	list_double<entity*>::node* temp = buffer.first_element;
	uint k = 0;
	while (temp){
		//Creature Look
		if ((temp->data->type == CREATURE && ((creature*)temp->data)->creature_type != PLAYER)){
			printf("%s ", temp->data->name.get_string());
			switch (((creature*)temp->data)->creature_type){
			case GOBLIN:
				slim_printf(GREEN,"[goblin]\n");
				break;
			case MERCHANT:
				slim_printf(LIGHT_CYAN,"[merchant]\n");
				break;
			case RUNNER:
				slim_printf(LIGHT_MAGENTA, "[runner]\n");
				break;
			}
			k++;
		}
		//Object Look
		else if ( temp->data->type == OBJECT ||temp->data->type == POTION){
			printf("%s\n", temp->data->name.get_string());
			k++;
		}
		//Counters
		
		temp = temp->next;
	}
	if (temp == nullptr && k == 0)printf("empty\n");
	printf("\n");
}