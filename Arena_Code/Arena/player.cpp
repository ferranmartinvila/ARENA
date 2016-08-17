#include "player.h"
#include "equipment.h"
#include "object.h"
#include "room.h"
#include "potion.h"

#include <stdlib.h>

//CONSTRUCTOR------------------------------------
player::player(char* name, char* description, room* location, uint lvl) :creature(name, description, PLAYER, location, lvl){
	//Initial Stats
	live_points = 150;
	defence = 0;
	damage = 5;
	agility = 30;
	lvl_up(lvl);
}


//SYSTEM-----------------------------------------
void player::update(){
	//TODO
	//Attack update
	if (state == ATTACK)attack();
	//Health update
	else if (current_live_points < (int)live_points && state != IN_ARENA)regen();
	//Dead update
	else if (state == DEAD)slim_printf(WHITE, "\n\nYou are dead enter RESET to respawn.\n\n");
}

void player::reset(){
	//Erase player buffer
	this->buffer.erase_all();
	slim_printf(CYAN, "Bag items deleted.\n");
	
	//Erase money & current xp
	this->money = 0;
	this->current_xp = 0;
	slim_printf(CYAN, "\nMoney and current xp reset to zero.\n");
	
	//Revive player
	this->state = IDLE;
	this->regen();
	slim_printf(CYAN, "\nStates reset.\n");
	
	//Reset player location
	this->location->buffer.erase_data(this);
	this->location = this->hub;
	this->hub->buffer.push_back(this);
	slim_printf(CYAN, "\nYou curren location is %s.\n\n", this->location->name.get_string());
}


//LORE-------------------------------
void player::look_it()const{
	system("cls");
	//Name & description
	slim_printf(WHITE, "%s: %s\n\n", name.get_string(), description.get_string());
	//Stats & buffed stats
	slim_printf(LIGHT_MAGENTA, "LEVEL[%u] -> next lvl (%u xp)\n\n", lvl, next_lvl_xp - current_xp);
	slim_printf(WHITE, "STATS:\n");
	slim_printf(LIGHT_GREEN, "live[%i]", live_points); slim_printf(LIGHT_MAGENTA, " +[%u]\n", const_live_buff);
	slim_printf(LIGHT_GREEN, "attack[%u]", damage); slim_printf(LIGHT_MAGENTA, " +[%u]\n", const_attack_buff);
	slim_printf(LIGHT_GREEN, "defense[%u]", defence); slim_printf(LIGHT_MAGENTA, " +[%u]\n", const_defense_buff);
	slim_printf(LIGHT_GREEN, "agility[%u]", agility); slim_printf(LIGHT_MAGENTA, " +[%u]\n", const_agility_buff);
	slim_printf(LIGHT_GREEN, "\nmoney -> %u\n", money);
	//Equipation
	slim_printf(WHITE, "\nEQUIPATION:\n");
	if (helm)slim_printf(LIGHT_CYAN, "helm [%s]\n", helm->name.get_string());
	else printf("helm none\n");
	if (armor)slim_printf(LIGHT_CYAN, "armor [%s]\n", armor->name.get_string());
	else printf("armor none\n");
	if (globes)slim_printf(LIGHT_CYAN, "globes [%s]\n", globes->name.get_string());
	else printf("globes none\n");
	if (pants)slim_printf(LIGHT_CYAN, "pants [%s]\n", pants->name.get_string());
	else printf("pants none\n");
	if (boots)slim_printf(LIGHT_CYAN, "boots [%s]\n", boots->name.get_string());
	else printf("boots none\n");
	if (weapon)slim_printf(LIGHT_CYAN, "weapon [%s]\n", weapon->name.get_string());
	else printf("weapon none\n");
	//Storage
	slim_printf(WHITE, "\nSTORAGE:\n");
	list_double<entity*>::node* temp = buffer.first_element;
	if (temp == nullptr)printf("empty\n");
	while (temp){
		slim_printf(LIGHT_CYAN,"%s\n", temp->data->name.get_string());
		temp = temp->next;
	}
}

void player::talk(string instruction){
	if (entity_focused == nullptr)printf("Invalid Creature\n");
	else if (entity_focused == this)printf("You can't talk to yourselve.\n");
	else if (((creature*)entity_focused)->location != this->location)printf("This NPC is not here.\n");
	else{
		//Focus the NPC to you
		((creature*)entity_focused)->entity_focused = this;
		//NPC & user TALK state
		this->state = TALK;
		((creature*)entity_focused)->state = TALK;
		//Apply NPC talk 
		((creature*)entity_focused)->talk(instruction);
	}
}

void player::look(string instruction){
	bool checked = false;
	if (entity_focused == nullptr){
		//look room instruction
		if (instruction == "room")entity_focused = location;
		//look me instruction
		else if (instruction == "me")entity_focused = this;
		//directional look instruction
		else{
			if (instruction == "north"){ entity_focused = ((room*)location)->find_exit(NORTH), checked = true; }
			else if (instruction == "east"){ entity_focused = ((room*)location)->find_exit(EAST), checked = true; }
			else if (instruction == "west"){ entity_focused = ((room*)location)->find_exit(WEST), checked = true; }
			else if (instruction == "south"){ entity_focused = ((room*)location)->find_exit(SOUTH), checked = true; }
		}
	}
	//Apply result look instruction
	if (entity_focused != nullptr){
		list_double<entity*>::node* temp = nullptr;
		//Find the entity in the location buffer
		temp = location->buffer.first_element;
		while (temp){
			if (temp->data->name == entity_focused->name){
				entity_focused->look_it();
				break;
			}
			temp = temp->next;
		}
		//Find the entity in the user buffer
		if (temp == nullptr){
			temp = this->buffer.first_element;
			while (temp){
				if (temp->data->name == entity_focused->name){
					entity_focused->look_it();
					break;
				}
				temp = temp->next;
			}
		}
		//Look room
		if (entity_focused == location)entity_focused->look_it();
		//Entity out of sight
		else if (temp == nullptr)printf("This entity is out of shight.\n");
	}
	else if(checked == false)printf("Invalid Entity.\n");
}


//INVENTORY--------------------------------------
void player::equip_object(){
	//Not entoty focused
	if (entity_focused == nullptr)printf("Invalid Object\n");
	//Invalid location
	else if (this->buffer.find_data(entity_focused) == false)printf("You don't have this object\n");
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
			((equip*)item_focused)->rest_buffs(this);
			this->buffer.push_back(item_focused);
			printf("[%s] has been unequiped.\n", item_focused->name.get_string());
		}
		//Add the equip buffs & erase it from bag
		((equip*)entity_focused)->add_buffs(this);
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
		((equip*)item_focused)->rest_buffs(this);
		//Push the unequiped item to the bag
		this->buffer.push_back(item_focused);
		printf("[%s] is now in your bag.\n", item_focused->name.get_string());
	}
	//Not equiped object
	else printf("This object isn't equiped.\n");
}


//LIVE-------------------------------------------
void player::drink(){
	//Wrong cases
	if (this->entity_focused == nullptr)slim_printf(WHITE, "Invalid Name.\n");
	else if (((object*)entity_focused)->object_type != POTION)slim_printf(WHITE, "Invalid Object.\n");
	//Correct case
	else{
		//Stat buff
		uint buff_points = ((potion*)entity_focused)->stat_buff;
		//Show result
		slim_printf(LIGHT_GREEN, "You drink %s & buff %u stat points!", ((potion*)this->entity_focused)->name.get_string(), buff_points);
		//Pointer focus 
		switch (((potion*)this->entity_focused)->potion_type){
		case HEAL_POTION:
			const_live_buff +=buff_points;
			slim_printf(LIGHT_MAGENTA, "[LIVE BUFF %u]\n\n", this->const_live_buff);
			break;
		case DEFENCE_POTION:
			const_defense_buff += buff_points;
			slim_printf(LIGHT_MAGENTA, "[DEFENCE BUFF %u]\n\n", this->const_defense_buff);
			break;
		case ATTACK_POTION:
			const_attack_buff += buff_points;
			slim_printf(LIGHT_MAGENTA, "[ATTACK BUFF %u]\n\n", this->const_attack_buff);
			break;
		case AGILITY_POTION:
			const_agility_buff += buff_points;
			slim_printf(LIGHT_MAGENTA, "[AGILITY BUFF %u]\n\n", this->const_agility_buff);
			break;
		}
		//Delete the potion
		this->buffer.erase_data(entity_focused);
	}
}


//NPC ACTIONS------------------------------------
object* player::choose_item(char option, OBJECT_TYPE type){
	//Temp data
	list_double<entity*>::node* temp = nullptr;
	char init = '`';
	//In extern buffer action
	if (state == BUY)temp = this->entity_focused->buffer.first_element;
	//In intern buffer action
	else if (state == SELL || state == EXTRACT_RUNES || state == FUSE_RUNES)temp = this->buffer.first_element;
	if (temp == nullptr){ printf("Invalid Selection.\n");return false; }
	//Find the item position in the focused buffer
	OBJECT_TYPE ob_type = ((object*)temp->data)->object_type;
	while (init < option && temp != nullptr){
		ob_type = ((object*)temp->data)->object_type;
		//Only count especific type
		if (ob_type == type || type == UNDEFINED || (type == EQUIP && (ob_type == HELM || ob_type == ARMOR || ob_type == GLOBES || ob_type == PANTS || ob_type == BOOTS || ob_type == WEAPON)))init++;
		if (init != option)temp = temp->next;
	}
	//Invalid selection
	if (temp == nullptr || (((object*)temp->data)->object_type != type && (type != UNDEFINED && type != EQUIP))){
		printf("Invalid Selection.\n");
		return nullptr;
	}
	//Valid Selection
	else return (object*)temp->data;
}