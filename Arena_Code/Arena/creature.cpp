#include "creature.h"
#include "object.h"
#include "room.h"
#include "potion.h"

//SYSTEM-------------------------------

creature::creature(char* name, char* description, CREATURE_TYPE type, entity* location, uint lvl) :entity(name, description, CREATURE), creature_type(type), location(location), state(IDLE), lvl(lvl), current_xp(0), next_lvl_xp(100){}

void creature::update(){
	//Attack update
	if (state == ATTACK)attack();
	//Health update
	else if ((uint)current_live_points < live_points && state != IN_ARENA)regen();
}

void creature::check_lvl(){
	if (current_xp >= next_lvl_xp){
		lvl++;
		current_xp -= next_lvl_xp;
		slim_printf(LIGHT_MAGENTA, "[%s] lvl up!\n");
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
		agility += 1 * levels;
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
	slim_printf(WHITE, "\n%s:", name.get_string());
	printf(" %s\n\n", description.get_string());
	//Stats
	slim_printf(WHITE, "STATS:\n");
	slim_printf(LIGHT_GREEN, "live[%i]\nattack[%i]\ndefense[%i]\nagility[%i]\n\n", live_points, damage, defense, agility);
	//Storage
	slim_printf(WHITE, "STORAGE:\n");
	list_double<entity*>::node* temp = buffer.first_element;
	if (temp == nullptr)printf("empty\n");
	while (temp){
		slim_printf(LIGHT_CYAN, "%s\n", temp->data->name.get_string());
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
	if (temp == nullptr){ printf("\nempty\n"); return false; }
	OBJECT_TYPE ob_type = ((object*)temp->data)->object_type;
	while (temp){
		ob_type = ((object*)temp->data)->object_type;
		if (ob_type == type || type == UNDEFINED || (type == EQUIP && (ob_type == HELM || ob_type == ARMOR || ob_type == GLOBES || ob_type == PANTS || ob_type == BOOTS || ob_type == WEAPON))){
			//Show all the type object states
			if (show){
				slim_printf(WHITE, "[ %c ] - ",k);
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

void creature::talk(string instruction){
	//Predeterminate talk
	printf("Sorry I don't want to talk.\n");
	this->state = IDLE;
	((creature*)this->entity_focused)->state = IDLE;
}

//POSITION------------------------
void creature::move(string instruction){
	//Choose the direction
	DIRECTION direct_check = UNKKOWN;
	if (instruction == "north")direct_check = NORTH;
	else if (instruction == "south")direct_check = SOUTH;
	else if (instruction == "east")direct_check = EAST;
	else if (instruction == "west")direct_check = WEST;
	else slim_printf(WHITE, "Invalid direction.\n");
	
	//Find the exit
	list_double<entity*>::node* temp = location->buffer.first_element;
	if (direct_check == UNKKOWN)temp = nullptr;
	while (temp){
		if (((room::exit*)temp->data)->direction == direct_check && temp->data->type == EXIT){
			//Swap the creature allocation for other list
			this->location->buffer.pass_entity(this, ((room::exit*)temp->data)->next_room->buffer, location->buffer);
			//Change the location of the creature
			location = ((room::exit*)temp->data)->next_room;
			//Arena entrance case
			location->name != "Arena" ? location->look_it() : ((room*)location)->arena_init(this); 
			break;
		}
		temp = temp->next;
	}
	if (temp == nullptr && direct_check != UNKKOWN)printf("There's nothing there.\n");
	
}

//INVENTORY-----------------------
void creature::pick(){
	if (entity_focused == nullptr)slim_printf(WHITE, "Invalid Name.\n");
	else if (entity_focused->type != OBJECT)slim_printf(WHITE, "Invalid entity.\n");
	else{
		if (location->buffer.find_data(entity_focused)){
			//Swap the object allocation for user 
			this->buffer.pass_entity(entity_focused, buffer, location->buffer);
			slim_printf(LIGHT_GREEN, "%s is now in your inventory.\n", entity_focused->name.get_string());
		}
		else printf("This object isn't here\n");
	}
}

void creature::pull(){
	if (entity_focused == nullptr)slim_printf(WHITE, "Invalid Name.\n");
	else if (entity_focused->type != OBJECT)slim_printf(WHITE, "Invalid entity.\n");
	else{
		if (this->buffer.find_data(entity_focused) == true){
			//Swap the object allocation for user 
			this->buffer.pass_entity(entity_focused, location->buffer, buffer);
			slim_printf(LIGHT_GREEN, "You throw the %s.\n", entity_focused->name.get_string());
		}
		else printf("This object isn't in your inventory\n");
	}
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
			slim_printf(LIGHT_GREEN, "You buy [%s]", to_buy->name.get_string());
			slim_printf(LIGHT_RED, " -%u money\n\n", to_buy->price);
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
		slim_printf(LIGHT_GREEN, "You sell [%s] +%u money\n\n", to_sell->name.get_string(), to_sell->price);
		return true;
	}
	return false;
}

//FIGHT----------------------------
void creature::attack(){
	//Pointer of creature attacked
	creature* target = (creature*)this->entity_focused;
	//Wrong general options
	if (target == nullptr){ slim_printf(WHITE, "Invalid Creature"); }
	else if (target == this){ printf("You can't hit yourself.\n"); }
	else if (target->location != this->location){this->state = IDLE,target->state = IDLE, printf("The enemy isn't here.\n"); }
	//Wrong focus options
	else if (target->state == DEAD){
		if (this->creature_type == PLAYER)printf("%s is dead.\n", target->name.get_string());
		if (this->location->name == "Arena")this->state = IN_ARENA;
		else this->state = IDLE;
		this->entity_focused = nullptr;
	}
	//Attack
	else{
		state = ATTACK;
		//Focus the other creature to player
		if (this->creature_type == PLAYER){ 
			target->entity_focused = this, target->state = ATTACK;
		}
		//Apply damage
		target->current_live_points -= damage;
		printf("----------->\n");
		//User case
		if (this->creature_type == PLAYER)slim_printf(LIGHT_GREEN, "You damage %i to %s\n", damage, target->name.get_string());
		//Enmey case
		else slim_printf(LIGHT_RED, "%s damage %i to you\n", name.get_string(), damage);
		//Target defeat
		if (target->current_live_points <= 0){

			//Show result
			//Player case
			if (this->creature_type == PLAYER)slim_printf(LIGHT_GREEN, "\nYou defeat %s!  ", target->name.get_string());
			//Enemy case
			else slim_printf(LIGHT_RED, " \n%s defeat you! ", name.get_string());

			//Enemy case
			if (target->creature_type != PLAYER){
				target->drop(this);
				target->die();
			}
			//Player case
			else target->state = DEAD;

			//Fight end state
			if (location->name == "Arena"){ state = IN_ARENA, ((room*)location)->check_arena_end(this); }
			else state = IDLE;
		}
		printf("-----------\n");
	}
}

void creature::drop(creature* killer){
	//Adds money & xp to the winner creature
	killer->money += money;
	killer->current_xp += this->current_xp;
	slim_printf(LIGHT_GREEN, "+%i money +%i xp\n\n", money, current_xp);
}

//LIVE-------------------------
void creature::die(){
	//Erase the creature from the location
	this->location->buffer.erase_data(this);
}

void creature::regen(){
	//Regen the live points
	while ((uint)current_live_points < live_points){
		current_live_points++;
	}
}

void creature::drink(){
	if (entity_focused == nullptr)slim_printf(WHITE, "Invalid Name.\n");
	else if (((object*)entity_focused)->object_type != POTION)slim_printf(WHITE, "Invalid Object.\n");
	else{
		//Stat pointer
		uint* uint_stat_target = nullptr;
		int* int_stat_target = nullptr;
		switch (((potion*)this->entity_focused)->potion_type){
		case HEAL_POTION:
			int_stat_target = &current_live_points;
			break;
		case DEFENCE_POTION:
			uint_stat_target = &defense;
			break;
		case ATTACK_POTION:
			uint_stat_target = &damage;
			break;
		case AGILITY_POTION:
			uint_stat_target = &agility;
			break;
		}
		//Potion regen points
		uint buff_number = ((potion*)entity_focused)->stat_regen;
		if (((potion*)this->entity_focused)->potion_type == HEAL_POTION)
		{
			while (buff_number + current_live_points > live_points){
				buff_number--;
			}
			*int_stat_target += buff_number;
		}
		//Apply the potion
		else *uint_stat_target += buff_number;
		//Show the result
		if (this->creature_type == PLAYER)slim_printf(LIGHT_GREEN, "You");
		else slim_printf(LIGHT_GREEN, "%s", this->name.get_string());
		slim_printf(LIGHT_GREEN, " drink %s & regen %u stat points![current stat points %u]\n", ((potion*)this->entity_focused)->name.get_string(), buff_number, buff_number);
	}
}