#ifndef _DATA_SOURCE_
#define _DATA_SOURCE_

#include "string.h"
#include <time.h>
#include <stdlib.h>

#define NAMES_STUFF 20
class data_source{
private:
	//SOURCE DATA
	string names[20];
public:
	//Constructor
	data_source(){
		unsigned int i = 0;
		//Names Definition
		//0
		names[i++] = ("Kali");
		names[i++] = ("Vito");
		names[i++] = ("Darcy");
		names[i++] = ("Minta");
		names[i++] = ("Lyla");
		//5
		names[i++] = ("Derick");
		names[i++] = ("Alline");
		names[i++] = ("Clark");
		names[i++] = ("Luen");
		names[i++] = ("Britt");
		//10
		names[i++] = ("Janek");
		names[i++] = ("Abbie");
		names[i++] = ("Hisu");
		names[i++] = ("Jolie");
		names[i++] = ("Doug");
		//15
		names[i++] = ("Cayla");
		names[i++] = ("Rayn");
		names[i++] = ("Ozell");
		names[i++] = ("Sau");
		names[i++] = ("Gena");
		//20
	};

	//FUNCTIONS
	char* get_random_name(){
		//TODO: repair 
		srand((unsigned int)time(NULL));
		unsigned int k = rand() % NAMES_STUFF;
		return names[rand() % NAMES_STUFF].get_string();
	};
};

//USABLE DATA SOURCE
data_source source;
#endif