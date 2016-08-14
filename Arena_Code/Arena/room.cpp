#include "room.h"
#include "creature.h"
#include "object.h"
#include <time.h>
#include <stdlib.h>
#include "Data_source.h"
#include "Monsters.h"

//ROOM CONSTRUCTOR-------------------------------
room::room(char* name, char* description) :entity(name, description, ROOM){}


//EXIT CONSTRUCTOR-------------------------------
room::exit::exit(char* name, char* description, room*from_room, room*next_room, DIRECTION direction) :entity(name, description, EXIT), from_room(from_room), next_room(next_room), direction(direction) {}


//SYSTEM-----------------------------------------
creature* room::generate_rand_enemy(uint max_lvl){
	srand((uint)time(NULL));
	//Random monster type
	uint monster_type = 1;
	//Random lvl 
	uint monster_level = (rand() % max_lvl) + 1;
	//Monster pointer
	creature* rand_enemy = nullptr;
	switch (monster_type){
	case 1:
		rand_enemy = new goblin((entity*)this, monster_level);
		break;
	}
	return rand_enemy;
}

//LORE-------------------------------------------
entity* room::find_exit(DIRECTION direction){
	list_double<entity*>::node* temp = this->buffer.first_element;
	while (temp){
		if (((exit*)temp->data)->direction == direction && temp->data->type == EXIT)return temp->data;
		temp = temp->next;
	}
	printf("There's nothing in this direction.\n");
	return nullptr;
}

//ARENA FUNCTIONS--------------------------------
void room::arena_look(string instruction)const{
	//Look room
	if (instruction == "room"){
		//Print the enemies
		list_double<entity*>::node* temp = this->buffer.first_element;
		while (temp){
			if (temp->data->type == CREATURE && ((creature*)temp->data)->creature_type != PLAYER){
				printf("%s ", temp->data->name);
				switch (((creature*)temp->data)->creature_type){
				case GOBLIN:
					printf("[goblin]");
					break;
				}
				printf("lvl %u live[%u]\n", ((creature*)temp->data)->lvl, ((creature*)temp->data)->current_live_points);
			}
			temp = temp->next;
		}
	}
	//Look avatar
	else if (instruction == "me"){
		//Find player in arena buffer
		list_double<entity*>::node* temp = this->buffer.first_element;
		creature* player = nullptr;
		while (temp){
			if (((creature*)temp->data)->creature_type == PLAYER)player = (creature*)temp->data;
			temp = temp->next;
		}
		//Shwo basic player stats
		printf("--------------\n%s:\nLEVEL[%u]\nSTATS:\nlive[%i]\nattack[%u]\ndefense[%u]\nagility[%u]\n", player->name.get_string(), player->lvl, player->current_live_points, player->damage, player->defense, player->agility);
		//Show player usable buffer items
		temp = player->buffer.first_element;
		printf("Useful items:\n");
		uint k = 0;
		while (temp){
			if (((object*)temp->data)->object_type == POTION){ k++, printf("%s\n", temp->data->name.get_string()); }
			temp = temp->next;
		}
		if (k == 0)printf("No usable items find.\n");
		printf("--------------\n");
	}
	//Invalid look
	else printf("Invalid look comand.\n");
}

void room::arena_init(creature* player){
	player->state = IN_ARENA;
	system("cls");
	slim_printf(LIGHT_GREEN, "\n\n_________________________________ARENA_ENTRANCE________________________________\n\n");
	slim_printf(WHITE, "Choose the difficulty:\n\n[a] - Easy\n[b] - Medium\n[c] - Hard\n");
}

void room::check_arena_end(creature* survivor){
	//Check if there's only only one survivor
	int k;
	int size = this->buffer.get_size();
	for (k = 0; k < size; k++){
		if (this->buffer[k] != survivor && this->buffer[k]->type == CREATURE)break;
		else if (k == size)k++;
	}
	//Check survivor type
	//Player win
	if (this->buffer[k] == nullptr && survivor->creature_type == PLAYER){
		survivor->state = IDLE;
		this->arena_clean();
		slim_printf(LIGHT_CYAN, "\n\nCongratulation you win! Now you are free!\n\n");
	}
	//Arena win
	else if(survivor->creature_type != PLAYER){
		this->arena_clean();
		fflush(stdin);
		slim_printf(LIGHT_RED, "\n\nThe arena beat you!\n\n");
	}
}

void room::generate_round(creature* player, char dificult){
	//Enemy ord total lvl
	uint global_lvl = player->lvl;
	//Choose difficult
	if (dificult == 'b'){ global_lvl *= 2, slim_printf(WHITE, "MEDIUM MODE:\n\n"); }
	else if (dificult == 'c'){ global_lvl *= 3, slim_printf(WHITE, "HARD MODE:\n\n"); }
	else if (dificult != 'a'){ global_lvl = 0, printf("Invalid selection.\n"); }
	else slim_printf(WHITE, "EASY MODE:\n\n");
	//Enemies pointer
	creature* enemy = nullptr;
	//Generate the ord 
	while (global_lvl > 0){
		enemy = generate_rand_enemy(player->lvl);
		global_lvl -= enemy->lvl;
		enemy->state = ATTACK;
		enemy->entity_focused = player;
		enemy->location = this;
		player->location->buffer.push_back(enemy);
		slim_printf(LIGHT_MAGENTA, "%s [Goblin] added.\n", enemy->name.get_string());
	}
}

void room::arena_clean(){
	//Temporal node pointers
	list_double<entity*>::node* temp = this->buffer.last_element();
	list_double<entity*>::node* temp_prev = temp->prev;
	//Erase all the data of the room buffer except the user
	while (temp){
		if (temp->data->type == CREATURE && ((creature*)temp->data)->creature_type != PLAYER)this->buffer.erase_node(temp);
		else if (temp->data->type != EXIT && temp->data->type != CREATURE )this->buffer.erase_node(temp);
		temp = temp_prev;
		if (temp_prev != nullptr)temp_prev = temp_prev->prev;
	}
}