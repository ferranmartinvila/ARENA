#include "entity.h"
#include "creature.h"
void entity::look_it()const{
	printf("\n%s:\n%s\nCONTENT:", name.get_string(), description.get_string());
	list_double<entity*>::node* temp = this->buffer.first_element;
	uint k = 0;
	while (temp){
		if (temp->data->type != EXIT  && temp->data->name != "Goul"){
			printf("\n%s", temp->data->name.get_string());
			k++;
		}
		temp = temp->next;
	}
	if (temp == nullptr && k == 0)printf("empty\n");
}