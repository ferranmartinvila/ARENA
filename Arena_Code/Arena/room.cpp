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
creature* room::generate_rand_enemy(uint* last_type, uint* last_lvl, uint max_lvl){
	srand((uint)time(NULL));
	//Random monster type
	uint rand_monster_type = (rand() % 9) + 1;
	//Random lvl 
	uint rand_monster_level = (rand() % max_lvl) + 1;
	//Monster pointer
	creature* rand_enemy = nullptr;
	//Randomize the lvl & mosnter type
	while (rand_monster_type == *last_type){
		rand_monster_type = (rand() % 9) + 1;
	}
	if (max_lvl > 1){
		while (rand_monster_level == *last_lvl){
			rand_monster_level = (rand() % 9) + 1;
		}
	}
	*last_type = rand_monster_type;
	*last_lvl = rand_monster_level;
	//Generate a monster with the rand pre-generated random data
	switch (rand_monster_type){
		//GOBLIN-----------------
	case 1:
		rand_enemy = new goblin((entity*)this, rand_monster_level);
		break;
		//ARCHER-----------------
	case 2:
		rand_enemy = new archer((entity*)this, rand_monster_level);
		break;
		//ORC--------------------
	case 3:
		rand_enemy = new orc((entity*)this, rand_monster_level);
		break;
		//ELF--------------------
	case 4:
		rand_enemy = new elf((entity*)this, rand_monster_level);
		break;
		//DEMON------------------
	case 5:
		rand_enemy = new demon((entity*)this, rand_monster_level);
		break;
		//GOLEM------------------
	case 6:
		rand_enemy = new golem((entity*)this, rand_monster_level);
		break;
		//HARPY------------------
	case 7:
		rand_enemy = new harpy((entity*)this, rand_monster_level);
		break;
		//MINOTAUR---------------
	case 8:
		rand_enemy = new minotaur((entity*)this, rand_monster_level);
		break;
		//CYCLOP-----------------
	case 9:
		rand_enemy = new cyclop((entity*)this, rand_monster_level);
		break;
		//GORGON-----------------
	case 10:
		rand_enemy = new gorgon((entity*)this, rand_monster_level);
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
	//Randomize data
	srand((uint)time(NULL));
	uint rand_type = (rand() % 9) + 1;
	uint rand_lvl = rand() % player->lvl;
	//Generate the ord 
	while (global_lvl > 0){
		enemy = generate_rand_enemy(&rand_type, &rand_lvl, player->lvl);
		global_lvl -= enemy->lvl;
		enemy->state = ATTACK;
		enemy->entity_focused = player;
		enemy->location = this;
		player->location->buffer.push_back(enemy);
		//Show enemy added
		switch (enemy->creature_type){
			//GOBLIN-----------------
		case GOBLIN:
			slim_printf(LIGHT_MAGENTA, "%s [GOBLIN] lvl %u added\n", enemy->name.get_string(), enemy->lvl);
			break;
			//ARCHER-----------------
		case ARCHER:
			slim_printf(LIGHT_MAGENTA, "%s [ARCHER] lvl %u added\n", enemy->name.get_string(), enemy->lvl);
			break;
			//ORC--------------------
		case ORC:
			slim_printf(LIGHT_MAGENTA, "%s [ORC] lvl %u added\n", enemy->name.get_string(), enemy->lvl);
			break;
			//ELF--------------------
		case ELF:
			slim_printf(LIGHT_MAGENTA, "%s [ELF] lvl %u added\n", enemy->name.get_string(), enemy->lvl);
			break;
			//DEMON------------------
		case DEMON:
			slim_printf(LIGHT_MAGENTA, "%s [DEMON] lvl %u added\n", enemy->name.get_string(), enemy->lvl);
			break;
			//GOLEM------------------
		case GOLEM:
			slim_printf(LIGHT_MAGENTA, "%s [GOLEM] lvl %u added\n", enemy->name.get_string(), enemy->lvl);
			break;
			//HARPY------------------
		case HARPY:
			slim_printf(LIGHT_MAGENTA, "%s [HARPY] lvl %u added\n", enemy->name.get_string(), enemy->lvl);
			break;
			//MINOTAUR---------------
		case MINOTAUR:
			slim_printf(LIGHT_MAGENTA, "%s [MINOTAUR] lvl %u added\n", enemy->name.get_string(), enemy->lvl);
			break;
			//CYCLOP-----------------
		case CYCLOP:
			slim_printf(LIGHT_MAGENTA, "%s [CYCLOP] lvl %u added\n", enemy->name.get_string(), enemy->lvl);
			break;
			//GORGON-----------------
		case GORGON:
			slim_printf(LIGHT_MAGENTA, "%s [GORGON] lvl %u added\n", enemy->name.get_string(), enemy->lvl);
			break;
		}
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