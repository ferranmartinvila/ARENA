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
	equip* Fighter_Helm = new equip("Helm", "Basic but light helm", HELM, 10, 2, 0, 2, 60);
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
	rune* Vitality_Rune = new rune("Rune of Vitality", "Adds a live buff to the object", LIVE_RUNE);
	runes.push_back(Vitality_Rune);
	rune* Defence_Rune = new rune("Rune of Defence", "Adds a defence buff to the object", DEFENCE_RUNE);
	runes.push_back(Defence_Rune);
	rune* Attack_Rune = new rune("Rune of Attack", "Adds a attack buff to the object", ATTACK_RUNE);
	runes.push_back(Attack_Rune);
	rune* Stamina_Rune = new rune("Rune of Stamina", "Adds a stamina buff to the object", STAMINA_RUNE);
	runes.push_back(Stamina_Rune);



	//POTIONS--------------------------
	potion* Health_Potion = new potion("Health potion", "Regen health points", HEAL_POTION, 1);
	potions.push_back(Health_Potion);
	potion* Defence_Potion = new potion("Defence potion", "Regen defence points", DEFENCE_POTION, 1);
	potions.push_back(Defence_Potion);
	potion* Attack_Potion = new potion("Attack potion", "Regen attack points", ATTACK_POTION, 1);
	potions.push_back(Attack_Potion);
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
	return equips.buffer[rand() % EQUIP_STUFF];
}

object* data_source::get_random_rune(){
	srand((unsigned int)time(NULL));
	return runes.buffer[rand() % RUNES_STUFF];
}

potion* data_source::get_random_potion(){
	srand((unsigned int)time(NULL));
	return potions.buffer[rand() % POTIONS_STUFF];
}

