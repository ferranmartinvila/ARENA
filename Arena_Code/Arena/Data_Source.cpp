#include "Data_Source.h"
#include "equipment.h"
#include "potion.h"
#include "rune.h"
#include "Pet.h"

//CONSTRUCTOR------------------------------------
data_source::data_source(){
	unsigned int i = 0;
	//NAMES----------------------------
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
	names[i++] = ("Noah");
	names[i++] = ("Liam");
	names[i++] = ("Zoe");
	names[i++] = ("Mila");
	names[i++] = ("Aria");
	//25
	names[i++] = ("Leah");
	names[i++] = ("Caleb");
	names[i++] = ("Ian");
	names[i++] = ("Levi");
	names[i++] = ("Henk");
	//30
	names[i++] = ("Leo");
	names[i++] = ("Owen");
	names[i++] = ("Ezra");
	names[i++] = ("Ruby");
	names[i++] = ("Ayen");
	//35
	
		
	
	//PETS-----------------------------
	pet* Hell_Horse = new pet(nullptr, "Hell Horse", "Magic horse with flames in the tail", HELL_HORSE, nullptr, 1, 50, 0, 4, 15, 12, 2750);
	pets.push_back(Hell_Horse);
	pet* Turtle_of_Wind = new pet(nullptr, "Turtle of Wind", "A rare turtle with a wind shield", TURTLE_OF_WIND, nullptr, 1, 50, 65, 18, 8, 15, 3250);
	pets.push_back(Turtle_of_Wind);
	pet* Golden_Fox = new pet(nullptr, "Golden Fox", "A common golden fox fast as fuck", GOLDEN_FOX, nullptr, 1, 50, 80, 4, 4, 25, 1500);
	pets.push_back(Golden_Fox);
	pet* Unicorn = new pet(nullptr, "Unicorn", "Magic white shiny horse with wings", UNICORN, nullptr, 1, 50, 50, 2, 8, 15, 2000);
	pets.push_back(Unicorn);
	pet* Artic_Horse = new pet(nullptr, "Artic Horse", "Rare hore with a shield of ice aroun his body", ARTIC_HORSE, nullptr, 1, 50, 35, 15, 10, 10, 2250);
	pets.push_back(Artic_Horse);
	pet* Flying_Koi = new pet(nullptr, "Flying Koi", "Large magic fish with the hability of fly", FLYING_KOI, nullptr, 1, 50, 85, 0, 4, 18, 3000);
	pets.push_back(Flying_Koi);
	pet* Iron_Goat = new pet(nullptr, "Iron Goat", "Common goat with a metallic shield ready for the war", IRON_GOAT, nullptr, 1, 50, 35, 4, 4, 6, 5);
	pets.push_back(Iron_Goat);
	pet* Magic_Yak = new pet(nullptr, "Magic Yak", "A strong and calm magic yak whit heal powers", MAGIC_YAK, nullptr, 1, 50, 100, 4, 2, 0, 1850);
	pets.push_back(Magic_Yak);
	pet* Flying_Goldenfish = new pet(nullptr, "Flying Goldenfish", "Magic golden fish with the hability of fly", FLYING_GOLDFISH, nullptr, 1, 50, 75, 2, 8, 16, 2150);
	pets.push_back(Flying_Goldenfish);
	pet* Giant_Turtle = new pet(nullptr, "Giant Turtle", "The oldest and biggest creature you will ever see", GIANT_TURTLE, nullptr, 1, 50, 150, 16,15, 8, 3250);
	pets.push_back(Giant_Turtle);



	//EQUIPATION-----------------------
	//Fighter equipation
	equip* Fighter_Helm = new equip("Fighter Helm", "Basic but light helm", HELM, 10, 2, 0, 2, 60);
	equips.push_back(Fighter_Helm);
	equip* Fighter_Armor = new equip("Fighter Armor", "Basic but light Armor", ARMOR, 25, 4, 0, 2, 150);
	equips.push_back(Fighter_Armor);
	equip* Fighter_Globes = new equip("Fighter Globes", "Basic but light Globes", GLOBES, 5, 1, 0, 2, 45);
	equips.push_back(Fighter_Globes);
	equip* Fighter_Pants = new equip("Fighter Pants", "Basic but light Pants", PANTS, 15, 3, 0, 2, 100);
	equips.push_back(Fighter_Pants);
	equip* Fighter_Boots = new equip("Fighter Boots", "Basic but light Boots", BOOTS, 10, 2, 0, 2, 50);
	equips.push_back(Fighter_Boots);
	equip* Fighter_Weapon = new equip("Fighter Weapon", "Basic but light Weapon", WEAPON, 0, 0, 10, 0, 250);
	equips.push_back(Fighter_Weapon);
	//Assassin equipation
	equip* Assassin_Helm = new equip("Assassin Helm", "Shiny golden helm", HELM, 15, 3, 0, 3, 120);
	equips.push_back(Assassin_Helm);
	equip* Assassin_Armor = new equip("Assassin Armor", "Shiny golden Armor", ARMOR, 30, 5, 0, 3, 300);
	equips.push_back(Assassin_Armor);
	equip* Assassin_Globes = new equip("Assassin Globes", "Shiny golden Globes", GLOBES, 10, 2, 0, 3, 90);
	equips.push_back(Assassin_Globes);
	equip* Assassin_Pants = new equip("Assassin Pants", "Shiny golden Pants", PANTS, 20, 4, 0, 3, 200);
	equips.push_back(Assassin_Pants);
	equip* Assassin_Boots = new equip("Assassin Boots", "Shiny golden Boots", BOOTS, 15, 3, 0, 3, 100);
	equips.push_back(Assassin_Boots);
	equip* Assassin_Weapon = new equip("Assassin Weapon", "Shiny golden Weapon", WEAPON, 0, 0, 20, 0, 500);
	equips.push_back(Assassin_Weapon);



	//RUNES----------------------------
	//Grade I
	rune* Vitality_Rune_I = new rune("Rune of Vitality I", "Adds a small live buff to the object", LIVE_RUNE, 25, 150);
	runes.push_back(Vitality_Rune_I);
	rune* Defence_Rune_I = new rune("Rune of Defence I", "Adds a small defence buff to the object", DEFENCE_RUNE, 12, 150);
	runes.push_back(Defence_Rune_I);
	rune* Attack_Rune_I = new rune("Rune of Attack I", "Adds a small attack buff to the object", ATTACK_RUNE , 8, 150);
	runes.push_back(Attack_Rune_I);
	rune* Agility_Rune_I = new rune("Rune of Agility I", "Adds a small agility buff to the object", AGILITY_RUNE, 5, 150);
	runes.push_back(Agility_Rune_I);
	//Grade II
	rune* Vitality_Rune_II = new rune("Rune of Vitality II", "Adds a medium live buff to the object", LIVE_RUNE, 50, 300);
	runes.push_back(Vitality_Rune_II);
	rune* Defence_Rune_II = new rune("Rune of Defence II", "Adds a medium defence buff to the object", DEFENCE_RUNE, 24, 300);
	runes.push_back(Defence_Rune_II);
	rune* Attack_Rune_II = new rune("Rune of Attack II", "Adds a medium attack buff to the object", ATTACK_RUNE, 16, 300);
	runes.push_back(Attack_Rune_II);
	rune* Agility_Rune_II = new rune("Rune of Agility II", "Adds a medium agility buff to the object", AGILITY_RUNE, 10, 300);
	runes.push_back(Agility_Rune_II);
	//Grade III
	rune* Vitality_Rune_III = new rune("Rune of Vitality III", "Adds a huge live buff to the object", LIVE_RUNE, 100, 600);
	runes.push_back(Vitality_Rune_III);
	rune* Defence_Rune_III = new rune("Rune of Defence III", "Adds a huge defence buff to the object", DEFENCE_RUNE, 48, 600);
	runes.push_back(Defence_Rune_III);
	rune* Attack_Rune_III = new rune("Rune of Attack III", "Adds a huge attack buff to the object", ATTACK_RUNE, 32, 600);
	runes.push_back(Attack_Rune_III);
	rune* Agility_Rune_III = new rune("Rune of Agility III", "Adds a huge agility buff to the object", AGILITY_RUNE, 20, 600);
	runes.push_back(Agility_Rune_III);



	//POTIONS--------------------------
	//Grade I
	potion* Health_Potion_I = new potion("Potion of Live I", "Adds a little live buff to you", HEAL_POTION, 30, 35);
	potions.push_back(Health_Potion_I);
	potion* Defence_Potion_I = new potion("Potion of Defence I", "Adds a little defence buff to you", DEFENCE_POTION, 5,35);
	potions.push_back(Defence_Potion_I);
	potion* Attack_Potion_I = new potion("Potion of Attack I", "Adds a little attack buff to you", ATTACK_POTION, 3,35);
	potions.push_back(Attack_Potion_I);
	potion* Agility_Potion_I = new potion("Potion of Agility I", "Adds a little agility buff to you", AGILITY_POTION, 2,35);
	potions.push_back(Agility_Potion_I);
	//Grade II
	potion* Health_Potion_II = new potion("Potion of Live II", "Adds a medium live buff to you", HEAL_POTION, 60, 70);
	potions.push_back(Health_Potion_II);
	potion* Defence_Potion_II = new potion("Potion of Defence II", "Adds a medium defence buff to you", DEFENCE_POTION, 10, 70);
	potions.push_back(Defence_Potion_II);
	potion* Attack_Potion_II = new potion("Potion of Attack II", "Adds a medium attack buff to you", ATTACK_POTION, 6, 70);
	potions.push_back(Attack_Potion_II);
	potion* Agility_Potion_II = new potion("Potion of Agility II", "Adds a medium agility buff to you", AGILITY_POTION, 4, 70);
	potions.push_back(Agility_Potion_II);
	//Grade III
	potion* Health_Potion_III = new potion("Potion of Live III", "Adds a huge live buff to you", HEAL_POTION, 120, 140);
	potions.push_back(Health_Potion_III);
	potion* Defence_Potion_III = new potion("Potion of Defence III", "Adds a huge defence buff to you", DEFENCE_POTION, 20, 170);
	potions.push_back(Defence_Potion_III);
	potion* Attack_Potion_III = new potion("Potion of Attack III", "Adds a huge attack buff to you", ATTACK_POTION, 12, 170);
	potions.push_back(Attack_Potion_III);
	potion* Agility_Potion_III = new potion("Potion of Agility III", "Adds a huge agility buff to you", AGILITY_POTION, 8, 170);
	potions.push_back(Agility_Potion_III);
}

//GET FONT---------------------------------------
char* data_source::get_random_name(){
	//RESET
	if (names_used_result >(NAMES_STUFF / 2)){
		for (int k = 0; k < NAMES_STUFF; k++){
			names_used[k] = false;
		}
		names_used_result = 0;
	}
	//RAND NAME GENERATOR
	srand((unsigned int)time(NULL));
	int temp = rand() % NAMES_STUFF;
	while (names_used[temp] == true){
		temp = rand() % NAMES_STUFF;
		names_used_result++;
	}
	names_used[temp] = true;
	return names[temp].get_string();
};

pet* data_source::get_random_pet(){
	srand((unsigned int)time(NULL));
	return pets.buffer[rand() % PETS_STUFF];
}

equip* data_source::get_random_equip(){
	srand((unsigned int)time(NULL));
	return equips.buffer[rand() % EQUIP_STUFF];
}

rune* data_source::get_random_rune(){
	srand((unsigned int)time(NULL));
	return runes.buffer[rand() % RUNES_STUFF];
}

potion* data_source::get_random_potion(){
	srand((unsigned int)time(NULL));
	return potions.buffer[rand() % POTIONS_STUFF];
}