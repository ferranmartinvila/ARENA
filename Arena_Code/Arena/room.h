#ifndef _ROOM_
#define _ROOM_

#include "entity.h"
class creature;

class room :public entity{
public:

	//EXIT SUBCLASS
	class exit :public entity{
	public:

		//DATA
		DIRECTION direction;
		room* from_room = nullptr;
		room* next_room = nullptr;

	public:

		//Constructor
		exit(char* name, char* description, room*from_room, room*next_room, DIRECTION direction);
	};

public:

	//Constructor
	room(char* name, char* description);

	//FUNCTIONS
	//System
	creature* generate_rand_enemy(uint);
	
	//Lore
	entity* find_exit(DIRECTION);

	//ARENA FUNCTIONS
	void arena_look(string)const;
	void arena_init(creature*);
	void check_arena_end(creature*);
	void generate_round(creature*, char);
	void arena_clean();
};
#endif