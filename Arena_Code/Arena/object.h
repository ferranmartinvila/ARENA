#ifndef _OBJECT_
#define _OBJECT_
#include "Globals.h"
#include "entity.h"
class object :public entity{
private:

	uint live_buff;
	uint defence_buff;
	uint attack_buff;
	uint stamina_buff;

public:

	//Constructor
	object(char* name, char* description, TYPE type, uint live_buff = 0, uint defence_buff = 0, uint attack_buff = 0, uint stamina_buff = 0) :entity(name, description, type), live_buff(live_buff), defence_buff(defence_buff), attack_buff(attack_buff), stamina_buff(stamina_buff) {}
};
#endif