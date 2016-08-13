#ifndef _EQUIPMENT_
#define _EQUIPMENT_

#include "object.h"
class creature;

class equip :public object{
public:

	uint live_buff;
	uint defence_buff;
	uint attack_buff;
	uint agility_buff;

	//Constructor
	equip(char*, char*, OBJECT_TYPE, uint, uint, uint, uint ,uint);

	//FUNCTIONS
	void add_buffs(creature*);
	void rest_buffs(creature*);
	void pauted_look_it()const;
};
#endif