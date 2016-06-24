#include "player.h"

void player::talk(){
	if (entity_focused != nullptr){
		if (entity_focused != this){
			//Focus the NPC to you
			((creature*)entity_focused)->entity_focused = this;
			//NPC & user TALK state
			this->state = TALK;
			((creature*)entity_focused)->state = TALK;
			//Apply NPC talk 
			((creature*)entity_focused)->talk();
			
		}
		else printf("You can't talk to yourselve.\n");
	}
	else printf("Invalid Creature\n");
}

void player::look()const{
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
	//Item already equiped
	else if (entity_focused == helm || entity_focused == armor || entity_focused == globes || entity_focused == pants || entity_focused == boots || entity_focused == weapon)
			printf("%s is still equiped.\n", entity_focused->name.get_string());
	//Equip object and put the other current equipation to the inventory
	else{
		OBJECT_TYPE type_check = ((object*)entity_focused)->object_type;
		object* item_focused = nullptr;
		//Find the item object type and equip it
		if (type_check == POTION || type_check == RUNE)printf("Invalid Object\n");
		else if (type_check == HELM){ item_focused = helm, helm = (object*)entity_focused; }
		else if (type_check == ARMOR){item_focused = armor, armor = (object*)entity_focused;}
		else if (type_check == GLOBES){item_focused = globes, globes = (object*)entity_focused;}
		else if (type_check == PANTS){item_focused = pants, pants = (object*)entity_focused;}
		else if (type_check == BOOTS){item_focused = boots, boots = (object*)entity_focused;}
		else if (type_check == WEAPON){ item_focused = weapon, weapon = (object*)entity_focused;}
		//If there was other item equiped before replace buffs & push it to the bag
		if (item_focused != nullptr){
			((object*)item_focused)->rest_buffs(this);
			this->buffer.push_back(item_focused);
			printf("[%s] has been unequiped.\n", item_focused->name.get_string());
		}
		//Add the equip buffs & erase it from bag
		((object*)entity_focused)->add_buffs(this);
		buffer.erase_data(entity_focused);
		printf("[%s] has been equiped\n", entity_focused->name.get_string());
	}
}

void player::unequip_object(){
	//Not entoty focused
	if (entity_focused == nullptr)printf("Invalid Object\n");
	//Unequip the object
	else if (entity_focused == helm || entity_focused == armor || entity_focused == globes || entity_focused == pants || entity_focused == boots || entity_focused == weapon){
		//Entity type check
		OBJECT_TYPE type_check = ((object*)entity_focused)->object_type;
		//Object pointer
		object* item_focused = nullptr;
		//Find the object cell end erase it
		if (type_check == HELM){ item_focused = helm, helm = nullptr; }
		else if (type_check == ARMOR){ item_focused = armor, armor = nullptr; }
		else if (type_check == GLOBES){ item_focused = globes, globes = nullptr; }
		else if (type_check == PANTS){ item_focused = pants, pants = nullptr; }
		else if (type_check == BOOTS){ item_focused = boots, boots = nullptr; }
		else if (type_check == WEAPON){ item_focused = weapon, weapon = nullptr; }
		//Rest teh item buffs
		item_focused->rest_buffs(this);
		//Push the unequiped item to the bag
		this->buffer.push_back(item_focused);
		printf("[%s] is now in your bag.\n", item_focused->name.get_string());
	}
	//Not equiped object
	else printf("This object isn't equiped.\n");
}

void player::choose_option(char option){
		list_double<entity*>::node* temp = this->entity_focused->buffer.first_element;
		char init = 'a';
		uint position = 0;
		while (init < option){
			init++;
			position++;
			temp = temp->next;
		}
		if (position > this->entity_focused->buffer.get_size() + 1)printf("Invalid Selection.\n");
		else this->buy((object*)temp);
}

void player::buy(object* to_buy){
	if (to_buy->price > this->money)printf("You don't have enough money.\n");
	else{
		//Rest user money and push the object
		this->money -= to_buy->price;
		this->buffer.push_back(to_buy);
		//Erase the item from the merchant
		this->entity_focused->buffer.erase_data(to_buy);
		printf("You buy [%s]\n", to_buy->name.get_string());
	}
}

void player::sell(object* to_sell){
	//Adds user money and push the object to merchant
	this->money += to_sell->price;
	this->buffer.erase_data(to_sell);
	printf("You sell [%s]\n", to_sell->name.get_string());
}