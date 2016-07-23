#include "room.h"
#include "creature.h"
#include "object.h"
#include <time.h>
#include <stdlib.h>
#include "Data_source.h"

//Monsters
#include "Goblin.h"



//ROOM CONSTRUCTOR-------------------------------
room::room(char* name, char* description) :entity(name, description, ROOM){}


//EXIT CONSTRUCTOR-------------------------------
room::exit::exit(char* name, char* description, room*from_room, room*next_room, DIRECTION direction) :entity(name, description, EXIT), from_room(from_room), next_room(next_room), direction(direction) {}


//SYSTEM-----------------------------------------
void room::arena_init(creature* player){
	player->state = IN_ARENA;
	system("cls");
	printf("\n\n_________________________________ARENA_ENTRANCE________________________________\n");
	printf("Choose the difficulty:\n\n[a] - Easy\n[b] - Medium\n[c] - Hard\n");
}

void room::check_arena_end(creature* survivor){
//TODO 



}

void room::generate_round(creature* player, char dificult){
	//Enemy ord total lvl
	uint global_lvl = player->lvl;
	//Choose difficult
	if (dificult == 'b'){ global_lvl *= 2, printf("MEDIUM MODE:\n"); }
	else if (dificult == 'c'){ global_lvl *= 3, printf("HARD MODE:\n"); }
	else if (dificult != 'a'){ global_lvl = 0, printf("Invalid selection.\n"); }
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
		printf("%s [Goblin] added.\n", enemy->name.get_string());
	}
}

creature* room::generate_rand_enemy(uint max_lvl ){
	srand((uint)time(NULL));
	//Random monster type
	uint monster_type = 1;
	//Random lvl 
	uint monster_level = (rand() % max_lvl)+1;
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
				printf("lvl %u live[%u]\n", ((creature*)temp->data)->lvl,((creature*)temp->data)->current_live_points);
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
		printf("--------------\n%s:\nLEVEL[%u]\nSTATS:\nlive[%i]\nattack[%u]\ndefense[%u]\nstamina[%u]\n", player->name.get_string(),player->lvl, player->current_live_points, player->damage, player->defense, player->stamina);
		//Show player usable buffer items
		temp = player->buffer.first_element;
		printf("Useful items:\n");
		uint k = 0;
		while (temp){
			if (((object*)temp->data)->object_type == POTION){ k++, printf("%s\n", temp->data->name.get_string()); }
			temp = temp->next;
		}
		if (k==0)printf("No usable items find.\n");
		printf("--------------\n");
	}
	//Invalid look
	else printf("Invalid look comand.\n");
}

entity* room::find_exit(DIRECTION direction){
	list_double<entity*>::node* temp = this->buffer.first_element;
	while (temp){
		if (((exit*)temp->data)->direction == direction && temp->data->type == EXIT)return temp->data;
		temp = temp->next;
	}
	printf("There's nothing in this direction.\n");
	return nullptr;
}

