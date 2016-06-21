#include "player.h"

void player::look(entity* entity_focused)const{
	if (entity_focused != nullptr){
		list_double<entity*>::node* temp = location->buffer.first_element;
		while (temp){
			if (temp->data->name == entity_focused->name){
				entity_focused->look_it();
				break;
			}
			temp = temp->next;
		}
		if (entity_focused == location)entity_focused->look_it();
		else if (temp == nullptr)printf("This object is not here.");
	}
	else printf("Invalid object.");
}

void player::equip_object(){
	//Not entoty focused
	if (entity_focused == nullptr)printf("Invalid Object\n");
	//Invalid location
	else if (entity_focused->location != this)printf("You don't have this object\n");
	//Invalid entity type
	else if (entity_focused->type != OBJECT)printf("This object can't be equiped\n");
	//Item already equiped
	else if (entity_focused == helm || entity_focused == armor || entity_focused == globes || entity_focused == pants || entity_focused == boots || entity_focused == weapon)
			printf("%s was equiped before.\n", entity_focused->name.get_string());
	//Equip object and put the other current equipation to the inventory
	else{
		OBJECT_TYPE type_check = ((object*)entity_focused)->object_type;
		switch (type_check){
		case HELM:
			helm = (object*)entity_focused;
			buffer.erase_data(helm);
			printf("Now your helm is [%s]\n", helm->name.get_string());
			break;
		case ARMOR:
			armor = (object*)entity_focused;
			buffer.erase_data(armor);
			printf("Now your armor is [%s]\n", armor->name.get_string());
			break;
		case GLOBES:
			globes = (object*)entity_focused;
			buffer.erase_data(globes);
			printf("Now your globes is [%s]\n", globes->name.get_string());
			break;
		case PANTS:
			pants = (object*)entity_focused;
			buffer.erase_data(pants);
			printf("Now your pants is [%s]\n", pants->name.get_string());
			break;
		case BOOTS:
			boots = (object*)entity_focused;
			buffer.erase_data(boots);
			printf("Now your boots is [%s]\n", boots->name.get_string());
			break;
		case WEAPON:
			weapon = (object*)entity_focused;
			buffer.erase_data(weapon);
			printf("Now your weapon is [%s]\n", weapon->name.get_string());
			break;
		case POTION:
			printf("You can't equip a potion");
			break;
		case RUNE:
			printf("You can't equip a rune");
			break;
		}
	}
}