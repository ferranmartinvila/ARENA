#ifndef _DATA_SOURCE_
#define _DATA_SOURCE_

#include "string.h"
#include <time.h>
#include <stdlib.h>
#include "vector.h"
class equip;
class potion;
class rune;
class pet;

#define NAMES_STUFF 35
#define PETS_STUFF 10
#define EQUIP_STUFF 12
#define RUNES_STUFF 12
#define POTIONS_STUFF 12

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
		[20]Noah
		[21]Liam
		[22]Zoe
		[23]Mila
		[24]Aria
		[25]Leah
		[26]Caleb
		[27]Ian
		[28]Levi
		[29]Henk
		[30]Leo
		[31]Owen
		[32]Ezra
		[33]Ruby
		[34]Ayen


	*/
	string names[NAMES_STUFF];
	


	//PETS DATA-----------------------------
	/*
		[0]hell_horse
		[1]turtle_of_wind
		[2]golden_fox
		[3]unicorn
		[4]artic_horse
		[5]flying_koi
		[6]iron_goat
		[7]magic_yak
		[8]flying_goldenfish
		[9]giant_turtle
	*/
	vector<pet*>pets;

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
		[0]Vitality_Rune I
		[1]Defence_Rune I
		[2]Attack_Rune I
		[3]Stamina_Rune I
		[4]Vitality_Rune II
		[5]Defence_Rune II
		[6]Attack_Rune II
		[7]Stamina_Rune II
		[8]Vitality_Rune III
		[9]Defence_Rune III
		[10]Attack_Rune III
		[11]Stamina_Rune III
	*/
	vector<rune*>runes;

	//POTIONS DATA--------------------------
	/*
		[0]Health_Potion I
		[1]Defence_Potion I
		[2]Attack_Potion I
		[3]Agility_Potion I
		[4]Health_Potion II
		[5]Defence_Potion II
		[6]Attack_Potion II
		[7]Agility_Potion II
		[8]Health_Potion III
		[9]Defence_Potion III
		[10]Attack_Potion III
		[11]Agility_Potion III
	*/
	vector<potion*>potions;


	bool generated;
private:

	bool names_used[NAMES_STUFF];
	int names_used_result = 0;

public:

	//Constructor
	data_source();

	//FUNCTIONS
	char* get_random_name();
	pet* get_random_pet();
	equip* get_random_equip();
	rune* get_random_rune();
	potion* get_random_potion();
	
};
#ifdef MAIN_FILE
data_source source;
#else
extern data_source source;
#endif
#endif