#ifndef _OBJECT_
#define _OBJECT_
#include "entity.h"
class creature;
class object :public entity{
public:

	//DATA
	OBJECT_TYPE object_type;
	uint live_buff;
	uint defence_buff;
	uint attack_buff;
	uint stamina_buff;
	uint price;

	//Constructor
	object(char* name, char* description, OBJECT_TYPE object_type, uint live_buff = 0, uint defence_buff = 0, uint attack_buff = 0, uint stamina_buff = 0, uint price = 0) :entity(name, description, OBJECT), object_type(object_type) , live_buff(live_buff), defence_buff(defence_buff), attack_buff(attack_buff), stamina_buff(stamina_buff),price(price) {}

	//FUNCTIONS
	//Lore
	void look_it()const;
	//Buffs
	void add_buffs(creature* );
	void rest_buffs(creature* );
	void upgrade(uint );
};
#endif