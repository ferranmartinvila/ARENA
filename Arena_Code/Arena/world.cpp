#include "World.h"

void world::Initialize(){
	//PLAYER AVATAR
	player* user = new player("Goul", "The shadow warrior", 150, 0, 5, 15);
	data.push_back(user);
	printf("\n*user added");

	//ROOMS
	room* Principal_Square = new room("Principal Square", "This beautyfull place is the center of everything.");
	data.push_back(Principal_Square);
	printf("\n*map added");


}