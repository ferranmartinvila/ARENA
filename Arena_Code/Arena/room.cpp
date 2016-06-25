#include "room.h"
#include "exit.h"

entity* room::find_exit(DIRECTION direction){
	list_double<entity*>::node* temp = this->buffer.first_element;
	while (temp){
		if (((exit*)temp->data)->direction == direction && temp->data->type == EXIT)return temp->data;
		temp = temp->next;
	}
	printf("There's nothing in this direction.\n");
	return nullptr;
}