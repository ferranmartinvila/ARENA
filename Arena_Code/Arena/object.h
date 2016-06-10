#ifndef _OBJECT_
#define _OBJECT_
#include "Globals.h"
#include "entity.h"
#include "room.h"
class object :public entity{
public:

	//DATA
	room*location;
	uint live_buff;
	uint defence_buff;
	uint attack_buff;
	uint stamina_buff;


	//Constructor
	object(char* name, char* description, room* location, uint live_buff = 0, uint defence_buff = 0, uint attack_buff = 0, uint stamina_buff = 0) :entity(name, description, OBJECT), live_buff(live_buff), defence_buff(defence_buff), attack_buff(attack_buff), stamina_buff(stamina_buff), location(location) {}
};
#endif