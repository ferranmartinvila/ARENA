#ifndef _MONSTERS_
#define _MONSTERS_

#include "creature.h"

//GOBLIN-----------------------------------------
class goblin :public creature{
public:

	//Constructor
	goblin(entity* location, uint lvl) : creature(source.get_random_name(), "Little green monster", GOBLIN, location, lvl){
		//Initial Stats
		current_live_points = live_points = 20;
		defence = 0;
		damage = 3;
		agility = 1;
		lvl_up(lvl);
	}
};
//ORC--------------------------------------------
class orc :public creature{
public:

	//Constructor
	orc(entity* location, uint lvl) : creature(source.get_random_name(), "A strong and green monster", ORC, location, lvl){
		//Initial Stats
		current_live_points = live_points = 50;
		defence = 3;
		damage = 5;
		agility = 0;
		lvl_up(lvl);
	}
};
//ARCHER-----------------------------------------
class archer :public creature{
public:

	//Constructor
	archer(entity* location, uint lvl) : creature(source.get_random_name(), "Expert in dodge and fight from the distance", ARCHER, location, lvl){
		//Initial Stats
		current_live_points = live_points = 15;
		defence = 0;
		damage = 3;
		agility = 4;
		lvl_up(lvl);
	}
};
//ELF--------------------------------------------
class elf :public creature{
public:

	//Constructor
	elf(entity* location, uint lvl) : creature(source.get_random_name(), "Human with pointed ears and magic habilities", ELF, location, lvl){
		//Initial Stats
		current_live_points = live_points = 30;
		defence = 2;
		damage = 4;
		agility = 2;
		lvl_up(lvl);
	}
};
//DEMON------------------------------------------
class demon :public creature{
public:

	//Constructor
	demon(entity* location, uint lvl) : creature(source.get_random_name(), "Ared and evil creature similar to a demonic goat", DEMON, location, lvl){
		//Initial Stats
		current_live_points = live_points = 40;
		defence = 0;
		damage = 6;
		agility = 0;
		lvl_up(lvl);
	}
};
//GOLEM------------------------------------------
class golem :public creature{
public:

	//Constructor
	golem(entity* location, uint lvl) : creature(source.get_random_name(), "Strong fighter created from mud", GOLEM, location, lvl){
		//Initial Stats
		current_live_points = live_points = 65;
		defence = 2;
		damage = 3;
		agility = 0;
		lvl_up(lvl);
	}
};
//HARPY------------------------------------------
class harpy :public creature{
public:

	//Constructor
	harpy(entity* location, uint lvl) : creature(source.get_random_name(), "Evil eagle with human head", HARPY, location, lvl){
		//Initial Stats
		current_live_points = live_points = 25;
		defence = 0;
		damage = 2;
		agility = 5;
		lvl_up(lvl);
	}
};
//MINOTAUR---------------------------------------
class minotaur :public creature{
public:

	//Constructor
	minotaur(entity* location, uint lvl) : creature(source.get_random_name(), "Big and strong fighter half human half bull", MINOTAUR, location, lvl){
		//Initial Stats
		current_live_points = live_points = 50;
		defence = 3;
		damage = 6;
		agility = 2;
		lvl_up(lvl);
	}
};
//CYCLOP-----------------------------------------
class cyclop :public creature{
public:

	//Constructor
	cyclop(entity* location, uint lvl) : creature(source.get_random_name(), "Strong giant with only one eye", CYCLOP, location, lvl){
		//Initial Stats
		current_live_points = live_points = 80;
		defence = 3;
		damage = 10;
		agility = 0;
		lvl_up(lvl);
	}
};
//GORGON-----------------------------------------
class gorgon :public creature{
public:

	//Constructor
	gorgon(entity* location, uint lvl) : creature(source.get_random_name(), "Evil roc creature similar to a little dragon", GORGON, location, lvl){
		//Initial Stats
		current_live_points = live_points = 45;
		defence = 3;
		damage = 5;
		agility = 3;
		lvl_up(lvl);
	}
};
#endif