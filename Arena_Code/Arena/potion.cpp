#include "potion.h"


potion::potion(char* name, char* description, POTION_TYPE potion_type, uint lvl) :entity(name,description, POTION), potion_type(potion_type), lvl(lvl){


}