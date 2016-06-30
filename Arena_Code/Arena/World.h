#ifndef _WORLD_
#define _WORLD_

//Source
#include "vector.h"
#include "string.h"
#include "entity.h"
//Objects
#include "room.h"
#include "exit.h"
#include "object.h"
//Creatures
#include "player.h"
#include "Goblin.h"
#include "Merchant.h"
#include "Runner.h"

// 34 with Golbin + Crafter
#define MAX_ENTITY 34
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