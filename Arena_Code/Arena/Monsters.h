#ifndef _MONSTERS_
#define _MONSTERS_

#include "creature.h"

//GOBLIN-----------------------------------------
class goblin :public creature{
public:
	goblin(entity* location, uint lvl) : creature(source.get_random_name(), "Little green monster", GOBLIN, location, lvl, 100, 20, 0, 3, 1){ lvl_up(lvl); }
};
//ORC--------------------------------------------
class orc :public creature{
public:
	orc(entity* location, uint lvl) : creature(source.get_random_name(), "A strong and green monster", ORC, location, lvl, 100, 25, 0, 3, 0){ lvl_up(lvl); }
};
//ARCHER-----------------------------------------
class archer :public creature{
public:
	archer(entity* location, uint lvl) : creature(source.get_random_name(), "Expert in dodge and fight from the distance", ARCHER, location, lvl, 100, 15, 0, 3, 4){ lvl_up(lvl); }
};
//ELF--------------------------------------------
class elf :public creature{
public:
	elf(entity* location, uint lvl) : creature(source.get_random_name(), "Human with pointed ears and magic habilities", ELF, location, lvl, 100, 30, 2, 4, 2){ lvl_up(lvl); }
};
//DEMON------------------------------------------
class demon :public creature{
public:
	demon(entity* location, uint lvl) : creature(source.get_random_name(), "Ared and evil creature similar to a demonic goat", DEMON, location, lvl, 100, 40, 0, 6, 0){ lvl_up(lvl); }
};
//GOLEM------------------------------------------
class golem :public creature{
public:
	golem(entity* location, uint lvl) : creature(source.get_random_name(), "Strong fighter created from mud", GOLEM, location, lvl, 100, 65, 2, 3, 0){ lvl_up(lvl); }
};
//HARPY------------------------------------------
class harpy :public creature{
public:
	harpy(entity* location, uint lvl) : creature(source.get_random_name(), "Evil eagle with human head", HARPY, location, lvl, 100, 25, 0, 2, 5){ lvl_up(lvl); }
};
//MINOTAUR---------------------------------------
class minotaur :public creature{
public:
	minotaur(entity* location, uint lvl) : creature(source.get_random_name(), "Big and strong fighter half human half bull", MINOTAUR, location, lvl, 100, 50, 3, 6, 2){ lvl_up(lvl); }
};
//CYCLOP-----------------------------------------
class cyclop :public creature{
public:
	cyclop(entity* location, uint lvl) : creature(source.get_random_name(), "Strong giant with only one eye", CYCLOP, location, lvl, 100, 80, 3, 10, 0){ lvl_up(lvl); }
};
//GORGON-----------------------------------------
class gorgon :public creature{
public:
	gorgon(entity* location, uint lvl) : creature(source.get_random_name(), "Evil roc creature similar to a little dragon", GORGON, location, lvl, 100, 45, 3, 5, 3){ lvl_up(lvl); }
};
#endif