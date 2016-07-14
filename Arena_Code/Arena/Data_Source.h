#ifndef _DATA_SOURCE_
#define _DATA_SOURCE_

#include "string.h"
#include <time.h>
#include <stdlib.h>
#include "vector.h"
class equip;
class potion;
class rune;

#define NAMES_STUFF 20
#define EQUIP_STUFF 12
#define RUNES_STUFF 4
#define POTIONS_STUFF 4

class data_source{
public:
	//NAMES DATA----------------------------
	/*
		[0]Kali
		[1]Vito
		[2]Darcy
		[3]Minta
		[4]Lyla
		[5]Derick
		[6]Alline
		[7]Clark
		[8]Luen
		[9]Britt
		[10]Janek
		[11]Abbie
		[12]Hisu
		[13]Jolie
		[14]Doug
		[15]Cayla
		[16]Rayn
		[17]Ozell
		[18]Sau
		[19]Gena
	*/
	string names[20];
	
	//EQUIP DATA----------------------------
	/*
		//Fighter Equip
		[0]Fighter_Helm 
		[1]Fighter_Armor
		[2]Fighter_Globes
		[3]Fighter_Pants
		[4]Fighter_Boots
		[5]Fighter_Weapon
		//Assassin Equip
		[6]Assassin_Helm
		[7]Assassin_Armor
		[8]Assassin_Globes
		[9]Assassin_Pants
		[10]Assassin_Boots
		[11]Assassin_Weapon
	*/
	vector<equip*>equips;
	
	//RUNES DATA----------------------------
	/*
		[0]Vitality_Rune
		[1]Defence_Rune
		[2]Attack_Rune
		[3]Stamina_Rune
	*/
	vector<rune*>runes;

	//POTIONS DATA--------------------------
	/*
		[0]Health_Potion
		[1]Stamina_Potion
	*/
	vector<potion*>potions;


	bool generated;
private:

	bool names_used[20];
	int names_used_result = 0;

public:

	//Constructor
	data_source();

	//FUNCTIONS
	char* get_random_name();
	equip* get_random_equip();
	rune* get_random_rune();
	potion* get_random_potion();
};
#endif