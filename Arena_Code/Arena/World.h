#ifndef _WORLD_
#define _WORLD_

#include "vector.h"
#include "entity.h"
#include "player.h"
#include "room.h"

class world{
private:

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
};
//External game data pointer
extern world* game;
#endif