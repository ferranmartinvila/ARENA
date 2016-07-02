#include "creature.h"
#include "object.h"
//SYSTEM-------------------------------
void creature::update(){
	//Attack update
	if (state == ATTACK){
		attack();
	}
	//Health update
	else if (current_live_points < live_points)regen();
}

void creature::check_lvl(){
	if (current_xp >= next_lvl_xp){
		lvl++;
		current_xp -= next_lvl_xp;
		printf("[%s] lvl up!\n");
		lvl_up(1);
	}
}

void creature::lvl_up(uint levels){
	//Universal levels
	for (uint k = 0; k < levels; k++){
		next_lvl_xp *= 2;
	}
	//Type check
	CREATURE_TYPE check = this->creature_type;
	//Upgrade checking the creature type
	switch (check){
	
	case PLAYER:
		live_points += 15 * levels;
		damage += 2 * levels;
		defense += 2 * levels;
		stamina += 1 * levels;
		break;
	
	case GOBLIN:
		live_points += 5 * levels;
		damage += 2 * levels;
		defense += 1 * levels;
		money += 10 * levels;
		current_xp = levels * 20;
		break;
	
	case MERCHANT:
		live_points += 50 * levels;
		damage += 20 * levels;
		money += 200 * levels;
		break;

	case CRAFTER:
		live_points += 50 * levels;
		damage += 20 * levels;
		money += 200 * levels;
	}
}

//LORE--------------------------------
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

void creature::show_storage()const{
	//Item index
	char k = 'a';
	//Number of items
	uint elements = 0;
	//Items states index
	printf("STORAGE:\nOption || Item || live_buff || def_buff || attack_buff || stamina_buff || price\n\n");
	//Prints all the buffer items
	list_double<entity*>::node* temp = this->buffer.first_element;
	while (temp){
		printf("[%c] -%s [ %i | %i | %i | %i ] price:%i\n", k, temp->data->name.get_string(), ((object*)temp->data)->live_buff, ((object*)temp->data)->defence_buff, ((object*)temp->data)->attack_buff, ((object*)temp->data)->stamina_buff, ((object*)temp->data)->price);
		k++;
		elements++;
		temp = temp->next;
	}
	//In case of empty buffer
	if (elements == 0)printf("empty\n");
}

bool creature::show_storage_for_class(OBJECT_TYPE type, bool show)const{
	//Creature buffer pointer
	list_double<entity*>::node* temp = this->buffer.first_element;
	//Index of type item
	char k = 'a';
	//Number of items
	uint elements = 0;
	while (temp){
		if (((object*)temp->data)->object_type == type){
			//Show all the type object states
			if (show)printf("[%c] -%s [ %i | %i | %i | %i ] price:%i\n", k, temp->data->name.get_string(), ((object*)temp->data)->live_buff, ((object*)temp->data)->defence_buff, ((object*)temp->data)->attack_buff, ((object*)temp->data)->stamina_buff, ((object*)temp->data)->price);
			k++;
			elements++;
		}
		temp = temp->next;
	}
	//Empty(false) else true
	if (elements == 0)return false;
	else return true;
}

void creature::talk(){
	//Predeterminate talk
	printf("Sorry I don't want to talk.\n");
}

//POSITION------------------------
void creature::move(DIRECTION direction){
	list_double<entity*>::node* temp = location->buffer.first_element;
	while (temp){
		if (((exit*)temp->data)->direction == direction && temp->data->type == EXIT){
			//Swap the creature allocation for other list
			this->location->buffer.pass_entity(this, ((exit*)temp->data)->next_room->buffer, location->buffer);
			//Change the location of the creature
			location = ((exit*)temp->data)->next_room;
			location->look_it();
			break;
		}
		temp = temp->next;
	}
	if (temp == nullptr)printf("There's nothing there.");
}

//INVENTORY-----------------------
void creature::pick(){
	if (entity_focused != nullptr){
		if (location->buffer.find_data(entity_focused)){
			//Swap the object allocation for user 
			this->buffer.pass_entity(entity_focused, buffer, location->buffer);
			printf("%s is now in your inventory.\n", entity_focused->name.get_string());
		}
		else printf("This object isn't here\n");
	}
	else printf("Invalid Object\n");

}

void creature::pull(){
	if (entity_focused != nullptr){
		if (this->buffer.find_data(entity_focused) == true){
			//Swap the object allocation for user 
			this->buffer.pass_entity(entity_focused, location->buffer, buffer);
			printf("You throw the %s.\n", entity_focused->name.get_string());
		}
		else printf("This object isn't in your inventory\n");
	}
	else printf("Invalid Object\n");

}

void creature::buy(object* to_buy){
	if (to_buy->price > this->money)printf("You don't have enough money for [%s].\n",to_buy->name.get_string());
	else{
		//Rest user money and push the object
		this->money -= to_buy->price;
		this->buffer.push_back(to_buy);
		//Erase the item from the merchant
		this->entity_focused->buffer.erase_data(to_buy);
		printf("You buy [%s] -%u money\n", to_buy->name.get_string(), to_buy->price);
	}
}

void creature::sell(object* to_sell){
	//Adds user money and push the object to merchant
	this->money += to_sell->price;
	this->buffer.erase_data(to_sell);
	printf("You sell [%s] +%u money\n", to_sell->name.get_string(), to_sell->price);
}

//FIGHT----------------------------
void creature::attack(){
	if (entity_focused != nullptr){
		if (entity_focused != this){
			state = ATTACK;
			//Focus the other creature to this & update state
			((creature*)entity_focused)->entity_focused = this;
			((creature*)entity_focused)->state = ATTACK;
			//Apply damage
			((creature*)entity_focused)->current_live_points -= damage;
			printf("%s damage %i to %s\n", name.get_string(), damage, entity_focused->name.get_string());
			if (((creature*)entity_focused)->current_live_points <= 0){
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
			this->buffer.pass_entity(temp->data, location->buffer, buffer);
			if (temp_next != nullptr)temp_next = temp_next->next;
			temp = temp_next;
		}
	}
	//Adds money & xp to the winner creature
	printf("+%i money +%i xp\n",money, current_xp);
	killer->money += money;
	killer->current_xp += current_xp;
}

//LIVE-------------------------
void creature::die(){
	//Erase the creature from the location
	location->buffer.erase_data(this);
	state = DEAD;
}

void creature::regen(){
	//Regen the live points
	while (current_live_points < live_points){
		current_live_points++;
	}
}