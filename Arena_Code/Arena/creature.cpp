#include "creature.h"
#include "object.h"
#include "room.h"
#include "potion.h"

//SYSTEM-------------------------------

creature::creature(char* name, char* description, CREATURE_TYPE type, entity* location, uint lvl) :entity(name, description, CREATURE), creature_type(type), location(location), state(IDLE), lvl(lvl), current_xp(0), next_lvl_xp(100){}

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

	case RUNNER:
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

bool creature::show_storage_for_class(OBJECT_TYPE type, bool show)const{
	//Creature buffer pointer
	list_double<entity*>::node* temp = this->buffer.first_element;
	//Index of type item
	char k = 'a';
	//Number of items
	uint elements = 0;
	while (temp){
		if (((object*)temp->data)->object_type == type ||type == UNDEFINED){
			//Show all the type object states
			if (show){
				printf("[%c] -",k);
				((object*)temp->data)->pauted_look_it();
			}
			k++;
			elements++;
		}
		temp = temp->next;
	}
	//Empty(false) else true
	if (elements == 0){ printf("\nempty\n"); return false; }
	else return true;
}

void creature::talk(){
	//Predeterminate talk
	printf("Sorry I don't want to talk.\n");
	this->state = IDLE;
	((creature*)this->entity_focused)->state = IDLE;
}

//POSITION------------------------
void creature::move(DIRECTION direction){
	list_double<entity*>::node* temp = location->buffer.first_element;
	while (temp){
		if (((room::exit*)temp->data)->direction == direction && temp->data->type == EXIT){
			//Swap the creature allocation for other list
			this->location->buffer.pass_entity(this, ((room::exit*)temp->data)->next_room->buffer, location->buffer);
			//Change the location of the creature
			location = ((room::exit*)temp->data)->next_room;
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

bool creature::buy(object* to_buy){
	if (to_buy != nullptr){
		if (to_buy->price > this->money){ printf("You don't have enough money for [%s].\n", to_buy->name.get_string()); return false; }
		else{
			//Rest user money and push the object
			this->money -= to_buy->price;
			this->buffer.push_back(to_buy);
			//Erase the item from the merchant
			this->entity_focused->buffer.erase_data(to_buy);
			printf("You buy [%s] -%u money\n\n", to_buy->name.get_string(), to_buy->price);
			return true;
		}
	}
	else return false;
}

bool creature::sell(object* to_sell){
	if (to_sell != nullptr){
		//Adds user money and push the object to merchant
		this->money += to_sell->price;
		this->buffer.erase_data(to_sell);
		printf("You sell [%s] +%u money\n\n", to_sell->name.get_string(), to_sell->price);
		return true;
	}
	return false;
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
	killer->current_xp += this->current_xp;
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

void creature::drink(){
	if (entity_focused == nullptr)printf("Invalid Name.\n");
	else if (((object*)entity_focused)->object_type != POTION)printf("Invalid Object.\n");
	else{
		//Potion regen points
		uint buff_number = ((potion*)this->entity_focused)->stat_regen;
		if (((potion*)this->entity_focused)->potion_type == HEAL_POTION){
			//Creature live points to max hp
			uint regen_mark = this->live_points - this->current_live_points;
			//Regen the just live
			if (buff_number > regen_mark)buff_number = regen_mark;
			//Show the result
			if (this->creature_type == PLAYER)printf("You");
			else printf("%s", this->name.get_string());
			printf(" regen %i points of live -> live points [%i]\n", buff_number, current_live_points);
		}
		else{
			//Regen samina (no limit) 
			this->stamina += buff_number;
			//Show the result
			if (this->creature_type == PLAYER)printf("You");
			else printf("%s", this->name.get_string());
			printf(" regen %i points of stamina -> stamina [%u]\n", buff_number, stamina);
		}
	}
}