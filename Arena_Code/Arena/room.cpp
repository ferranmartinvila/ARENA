#include "room.h"

//ROOM CONSTRUCTOR-------------------
room::room(char* name, char* description) :entity(name, description, ROOM){}


//EXIT CONSTRUCTOR-------------------
room::exit::exit(char* name, char* description, room*from_room, room*next_room, DIRECTION direction) :entity(name, description, EXIT), from_room(from_room), next_room(next_room), direction(direction) {}


//FUNCTIONS---------------------------
entity* room::find_exit(DIRECTION direction){
	list_double<entity*>::node* temp = this->buffer.first_element;
	while (temp){
		if (((exit*)temp->data)->direction == direction && temp->data->type == EXIT)return temp->data;
		temp = temp->next;
	}
	printf("There's nothing in this direction.\n");
	return nullptr;
}