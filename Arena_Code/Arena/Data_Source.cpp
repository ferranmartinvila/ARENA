#include "Data_Source.h"

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



	//EQUIPATION-----------------------
	//Fighter equipation
	object* Fighter_Helm = new object("Helm", "Basic but light helm", HELM, 10, 2, 0, 2, 60);
	equip.push_back(Fighter_Helm);
	object* Fighter_Armor = new object("Fighter Armor", "Basic but light Armor", ARMOR, 25, 4, 0, 2, 150);
	equip.push_back(Fighter_Armor);
	object* Fighter_Globes = new object("Fighter Globes", "Basic but light Globes", GLOBES, 5, 1, 0, 2, 45);
	equip.push_back(Fighter_Globes);
	object* Fighter_Pants = new object("Fighter Pants", "Basic but light Pants", PANTS, 15, 3, 0, 2, 100);
	equip.push_back(Fighter_Pants);
	object* Fighter_Boots = new object("Fighter Boots", "Basic but light Boots", BOOTS, 10, 2, 0, 2, 50);
	equip.push_back(Fighter_Boots);
	object* Fighter_Weapon = new object("Fighter Weapon", "Basic but light Weapon", WEAPON, 0, 0, 10, 0, 250);
	equip.push_back(Fighter_Weapon);
	//Assassin equipation
	object* Assassin_Helm = new object("Assassin Helm", "Shiny golden helm", HELM, 15, 3, 0, 3, 120);
	equip.push_back(Assassin_Helm);
	object* Assassin_Armor = new object("Assassin Armor", "Shiny golden Armor", ARMOR, 30, 5, 0, 3, 300);
	equip.push_back(Assassin_Armor);
	object* Assassin_Globes = new object("Assassin Globes", "Shiny golden Globes", GLOBES, 10, 2, 0, 3, 90);
	equip.push_back(Assassin_Globes);
	object* Assassin_Pants = new object("Assassin Pants", "Shiny golden Pants", PANTS, 20, 4, 0, 3, 200);
	equip.push_back(Assassin_Pants);
	object* Assassin_Boots = new object("Assassin Boots", "Shiny golden Boots", BOOTS, 15, 3, 0, 3, 100);
	equip.push_back(Assassin_Boots);
	object* Assassin_Weapon = new object("Assassin Weapon", "Shiny golden Weapon", WEAPON, 0, 0, 20, 0, 500);
	equip.push_back(Assassin_Weapon);
	


	//RUNES----------------------------
	object* Vitality_Rune = new object("Rune of Vitality", "Adds a live buff to the object", RUNE, 15, 0, 0, 0, 0);
	runes.push_back(Vitality_Rune);
	object* Defence_Rune = new object("Rune of Defence", "Adds a defence buff to the object", RUNE, 0, 15, 0, 0, 100);
	runes.push_back(Defence_Rune);
	object* Attack_Rune = new object("Rune of Attack", "Adds a attack buff to the object", RUNE, 0, 0, 15, 0, 100);
	runes.push_back(Attack_Rune);
	object* Stamina_Rune = new object("Rune of Stamina", "Adds a stamina buff to the object", RUNE, 0, 0, 0, 15, 100);
	runes.push_back(Stamina_Rune);



	//POTIONS--------------------------
	potion* Health_Potion = new potion("Health potion", "Regen health points", HEAL_POTION, 1);
	potions.push_back(Health_Potion);
	potion* Stamina_Potion = new potion("Stamina potion", "Regen stamina points", STAMINA_POTION, 1);
	potions.push_back(Stamina_Potion);
};


//FUNCTIONS--------------------------------------
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

object* data_source::get_random_equip(){
	srand((unsigned int)time(NULL));
	return equip.buffer[rand() % EQUIP_STUFF];
}

object* data_source::get_random_rune(){
	srand((unsigned int)time(NULL));
	return runes.buffer[rand() % RUNES_STUFF];
}

potion* data_source::get_random_potion(){
	srand((unsigned int)time(NULL));
	return potions.buffer[rand() % POTIONS_STUFF];
}

