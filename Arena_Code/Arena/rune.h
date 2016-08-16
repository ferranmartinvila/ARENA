#ifndef _RUNE_
#define _RUNE_

#include "object.h"

class rune :public object{
public:

	RUNE_TYPE rune_type;
	uint enchant_points;

	//Constructor
	rune(char* name, char* description, RUNE_TYPE rune_type, uint enchant_points, uint price);

	//FUNCTIONS
	void look_it()const;
	void pauted_look_it()const;

};
#endif