#include "player.h"
#include <stdlib.h>
void player::look_it()const{
	system("cls");
	//Name & description
	printf("\n%s:\n%s\n", name.get_string(), description.get_string());
	//Stats
	printf("lvl[%i]\nSTATS:\nlive[%i]\nattack[%i]\ndefense[%i]\nstamina[%i]\nmoney[%i]\n", current_xp, live_points, damage, defense, stamina, money);
	//Equipation
	printf("EQUIPATION:\n");
	if (helm)printf("helm [%s]\n", helm->name.get_string());
	else printf("helm none\n");
	if (armor)printf("armor [%s]\n", armor->name.get_string());
	else printf("armor none\n");
	if (globes)printf("globes [%s]\n", globes->name.get_string());
	else printf("globes none\n");
	if (pants)printf("pants [%s]\n", pants->name.get_string());
	else printf("pants none\n");
	if (boots)printf("boots [%s]\n", boots->name.get_string());
	else printf("boots none\n");
	if (weapon)printf("weapon [%s]\n", weapon->name.get_string());
	else printf("weapon none\n");
	//Storage
	printf("STORAGE:\n");
	list_double<entity*>::node* temp = buffer.first_element;
	if (temp == nullptr)printf("empty\n");
	while (temp){
		printf("%s\n", temp->data->name.get_string());
		temp = temp->next;
	}
}

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
		//Find the item in the location buffer
		while (temp){
			if (temp->data->name == entity_focused->name){
				entity_focused->look_it();
				break;
			}
			temp = temp->next;
		}
		//Look room
		if (entity_focused == location)entity_focused->look_it();
		//Entity out of sight
		else if (temp == nullptr)printf("This object is not here.\n");
	}
	else printf("Invalid object.\n");
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
	//Temp data
	list_double<entity*>::node* temp = nullptr;
	char init = 'a';
	uint position = 0;
	//In BUY MODE focus the entity_focuse buffer
	if (state == BUY)temp = this->entity_focused->buffer.first_element;
	//In SELL MODE focus this buffer
	else if (state == SELL)temp = this->buffer.first_element;
	//Find the item position in the focused buffer
	while (init < option && temp != nullptr){
		init++;
		position++;
		temp = temp->next;
	}
	//Invalid selection
	if (temp == nullptr)printf("Invalid Selection.\n");
	//Valid Selection
	else {
		//In BUY MODE
		if(state == BUY)this->buy((object*)temp->data);
		//In SELL MODE
		if(state == SELL)this->sell((object*)temp->data);
	}
}