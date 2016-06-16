#include "creature.h"

void creature::look_it()const{
	//Name & description
	printf("\n%s:\n%s\n", name.get_string(), description.get_string());
	//Stats
	printf("STATS:\nlive[%i]\nattack[%i]\ndefense[%i]\nstamina[%i]\n", live_points, damage, defense, stamina);
	//Storage
	printf("STORAGE:\n");
	list_double<entity*>::node* temp = buffer.first_element;
	if (temp == nullptr)printf("empty\n");
	while (temp){
		printf("%s\n", temp->data->name.get_string());
		temp = temp->next;
	}
}

void creature::update(){
	//Attack update
	if (state == ATTACK){
		attack();
	}
	//Talk update


}

void creature::move(DIRECTION direction){
	list_double<entity*>::node* temp = location->buffer.first_element;
	while (temp){
		if (((exit*)temp->data)->direction == direction && temp->data->type == EXIT){
			//Swap the creature allocation for other list
			this->location->buffer.swap_entities(this, ((exit*)temp->data)->next_room->buffer,location->buffer);
			//Change the location of the creature
			location = ((exit*)temp->data)->next_room;
			location->look_it();
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
			this->buffer.swap_entities((entity*)object_focused, buffer, location->buffer);
			//Change object location
			object_focused->location = this;
			printf("%s is now in your inventory.\n", object_focused->name.get_string());
		}
		else printf("This object isn't here\n");
	}
	else printf("Invalid Object\n");

}

void creature::pull(object* object_focused){
	if (entity_focused != nullptr){
		if (this->buffer.find_data((entity*)object_focused)){
			//Swap the object allocation for user 
			this->buffer.swap_entities((entity*)object_focused, location->buffer, buffer);
			//Change object location
			object_focused->location = location;
			printf("You throw the %s.\n", object_focused->name.get_string());
		}
		else printf("This object isn't in your inventory\n");
	}
	else printf("Invalid Object\n");

}

void creature::attack(){
	if (entity_focused != nullptr){
		if (entity_focused != this){
			state = ATTACK;
			//Focus the other creature to this & update state
			((creature*)entity_focused)->entity_focused = this;
			((creature*)entity_focused)->state = ATTACK;
			//Apply damage
			((creature*)entity_focused)->live_points -= damage;
			printf("%s damage %i to %s\n", name.get_string(), damage, entity_focused->name.get_string());
			if (((creature*)entity_focused)->live_points < 1){
				printf("%s defeat %s!", name.get_string(), entity_focused->name.get_string());
				((creature*)entity_focused)->drop(this);
				((creature*)entity_focused)->die();
				state = IDLE;
			}
		}
		else printf("You can't hit yourselve.\n");
	}
	else printf("Invalid Creature");
}

void creature::drop(creature* killer){
	if (this->buffer.empty() == false){
		list_double<entity*>::node* temp = buffer.first_element;
		list_double<entity*>::node* temp_next = temp->next;
		//Removes all the killed entity buffer data
		while (temp){
			this->buffer.swap_entities(temp->data, location->buffer, buffer);
			if (temp_next != nullptr)temp_next = temp_next->next;
			temp = temp_next;
		}
	}
	//Adds money & xp to the user avatar
	printf("+%i money +%i xp\n", money,xp);
	killer->money += money;
	killer->xp += xp;
}

void creature::die(){
	//Erase the creature from the location
	location->buffer.erase_data(this);
	state = DEAD;
}