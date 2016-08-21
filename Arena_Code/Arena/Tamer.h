#ifndef _TAMER_
#define _TAMER_

#include "creature.h"
#include "Pet.h"

class tamer :public creature{
public:

	//NON EXTRA DATA

	//Constructor
	tamer(entity* location, uint lvl) :creature(source.get_random_name(), "Tamers are special creatures with the habiliti to train beasts to serve their owners.", TAMER, location, lvl, 100, 500, 50, 50, 100){ lvl_up(lvl); }

	//FUNCTIONS



};
#endif