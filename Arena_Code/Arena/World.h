#ifndef _WORLD_
#define _WORLD_

#include "vector.h"
#include "entity.h"
#include "player.h"
#include "room.h"
#include "exit.h"
#include "string.h"

class world{
private:

	player* user;
	vector<entity*> data;

public:

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