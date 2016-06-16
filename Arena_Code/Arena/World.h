#ifndef _WORLD_
#define _WORLD_

#include "vector.h"
#include "entity.h"
#include "player.h"
#include "room.h"
#include "exit.h"
#include "object.h"
#include "Goblin.h"
#include "string.h"


#define MAX_ENTITY 27
class world{
public:

	//DATA
	player* user;
	vector<entity*> data;


	//Constructor
	world(){

	}
	//Destructor
	~world(){
		data.clean();
	}
	//FUNCTIONS
	void Initialize();
	bool Apply_Instruction(vector<string> instruction);
};
//External game data pointer
extern world* game;
#endif