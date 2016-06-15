#include "creature.h"

void creature::move(DIRECTION direction){
	list_double<entity*>::node* temp = location->buffer.first_element;
	while (temp){
		if (((exit*)temp->data)->direction == direction && temp->data->type == EXIT){
			//Swap the creature allocation for other list
			this->location->buffer.swap_entities(this, ((exit*)temp->data)->next_room->buffer,buffer);
			//Change the location of the creature
			location = ((exit*)temp->data)->next_room;
			printf("%s:\n%s", location->name.get_string(), location->description.get_string());
			break;
		}
		temp = temp->next;
	}
	if (temp == nullptr)printf("There's nothing there.");
}

void creature::pick(object* object_focused){
	if (entity_focused != nullptr){
		if (location->buffer.find_data((entity*)object_focused)){
			//Swap the object allocation for user 
			buffer.swap_entities((entity*)object_focused, buffer, location->buffer);
			object_focused->location = this;
			printf("%s is now in your inventory.", object_focused->name.get_string());
		}
		else printf("This object isn't here");
	}
	else printf("Invalid Object");

}