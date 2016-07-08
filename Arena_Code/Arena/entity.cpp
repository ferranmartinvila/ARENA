#include "entity.h"
#include "creature.h"

void entity::look_it()const{
	printf("\n%s:\n%s\nCONTENT:\n", name.get_string(), description.get_string());
	list_double<entity*>::node* temp = buffer.first_element;
	uint k = 0;
	while (temp){
		//Creature Look
		if ((temp->data->type == CREATURE && ((creature*)temp->data)->creature_type != PLAYER)){
			printf("%s ", temp->data->name.get_string());
			switch (((creature*)temp->data)->creature_type){
			case GOBLIN:
				printf("[goblin]\n");
				break;
			case MERCHANT:
				printf("[merchant]\n");
				break;
			case RUNNER:
				printf("[runner]\n");
				break;
			}
			k++;
		}
		//Object Look
		else if ( temp->data->type == OBJECT){
			printf("%s\n", temp->data->name.get_string());
			k++;
		}
		//Counters
		
		temp = temp->next;
	}
	if (temp == nullptr && k == 0)printf("empty\n");
}