#include "creature.h"
#include <stdio.h>

void creature::move(DIRECTION direction){
	list_double<entity*>::node* temp = location->buffer.first_element;
	while (temp){
		if (((exit*)temp->data)->direction == direction){
			//Erese the creture from the current location
			location->buffer.erase_data(this);
			//Push the creature to the next location
			((exit*)temp->data)->next_room->buffer.push_back(this);
			//Change the location of the creature
			location = ((exit*)temp->data)->next_room;
			printf("%s:\n%s", location->name, location->description);
			break;
		}
		temp = temp->next;
	}
	if (temp == nullptr)printf("There's nothing in that direction.");
}