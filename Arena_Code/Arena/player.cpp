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