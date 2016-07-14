#include "room.h"
#include "creature.h"
#include <time.h>
#include <stdlib.h>
#include "Data_Tank.h"

//Monsters
#include "Goblin.h"

//ROOM CONSTRUCTOR-------------------------------
room::room(char* name, char* description) :entity(name, description, ROOM){}


//EXIT CONSTRUCTOR-------------------------------
room::exit::exit(char* name, char* description, room*from_room, room*next_room, DIRECTION direction) :entity(name, description, EXIT), from_room(from_room), next_room(next_room), direction(direction) {}


//SYSTEM-----------------------------------------
creature room::generate_rand_enemy(creature* player){
	srand((uint)time(NULL));
	//Random monster type
	uint monster_type = rand() % 1;
	//Rnadom lvl lower than lvl + 2
	uint monster_level = rand() % player->lvl + 2;
	//Monster pointer
	creature* rand_enemy = nullptr;
	switch (monster_type){
		case 1:
			rand_enemy = new goblin((entity*)this, monster_level);
		break;
	}
	return *rand_enemy;
}

void room::generate_round(creature* player){
	//TODO ROUND GENERATOR
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

