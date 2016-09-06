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

	uint level;

	//Constructor
	equip(char*, char*, OBJECT_TYPE, uint, uint, uint, uint ,uint);

	//FUNCTIONS
	void look_it()const;
	void pauted_look_it()const;
	void add_buffs(creature*);
	void rest_buffs(creature*);
};
#endif