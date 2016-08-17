#ifndef _WORLD_
#define _WORLD_

#include "vector.h"
#include "Globals.h"
#include "string.h"
class entity;
class player;
class room;

#define MAX_ENTITY 54
class world{
public:

	//User data
	player* user;

	//Arena data
	entity* arena;

	//Static world data
	vector<entity*> data;

	//Constructor
	world(){
		Initialize();
	}
	//Destructor
	~world(){
		data.clean();
	}
	//FUNCTIONS
	void Initialize();
	bool Apply_Instruction(vector<string> instruction);
};
#endif