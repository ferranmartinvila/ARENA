#ifndef _WORLD_
#define _WORLD_

#include "vector.h"
#include "Globals.h"
#include "string.h"
class entity;
class player;

#define MAX_ENTITY 38
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