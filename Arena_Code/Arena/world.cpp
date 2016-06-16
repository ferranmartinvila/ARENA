#include "World.h"

void world::Initialize(){

	//ROOMS
	//Principal Square
	room* Principal_Square = new room("Principal Square", "This beautyfull place is the center of everything.");
	data.push_back(Principal_Square);
	//Market
	room* Market = new room("Market", "A great place to buy new equipation.");
	data.push_back(Market);
	//Black Market
	room* Black_Market = new room("Black Market", "This place is full of magic merchants.");
	data.push_back(Black_Market);
	//House
	room* House = new room("House", "The perfect place to save objects.");
	data.push_back(House);
	//Arena
	room* Arena = new room("Arena", "The ground if full of blood and the public shout kill!");
	data.push_back(Arena);
	printf("\n* rooms added");

	//EXITS
	//Principal Square
	exit* Principal_Square_to_Market = new exit("Market entrance", "From here you can listen the merchants negotiating.", Principal_Square, Market, EAST);
	data.push_back(Principal_Square_to_Market);
	exit* Principal_Square_to_Black_Market = new exit("Black Market entrance", "There's blue lights and objects floating.", Principal_Square, Black_Market, SOUTH);
	data.push_back(Principal_Square_to_Black_Market);
	exit* Principal_Square_to_House = new exit("House entrance", "There's your little but homely house.", Principal_Square, House, WEST);
	data.push_back(Principal_Square_to_House);
	exit* Principal_Square_to_Arena = new exit("Arena entrance", "From here you can smell the blood of the fighters.", Principal_Square, Arena, NORTH);
	data.push_back(Principal_Square_to_Arena);
	//Market
	exit* Market_to_Principal_Square = new exit("Market exit", "There's the Principal Square", Market, Principal_Square, WEST);
	data.push_back(Market_to_Principal_Square);
	//Black Market
	exit* Black_Market_to_Principal_Square = new exit("Black Market exit", "There's the Principal Square", Black_Market, Principal_Square, NORTH);
	data.push_back(Black_Market_to_Principal_Square);
	//House
	exit* House_to_Principal_Square = new exit("House exit", "There's the Principal Square", House, Principal_Square, EAST);
	data.push_back(House_to_Principal_Square);
	//Arena
	exit* Arena_to_Principal_Square = new exit("Arena exit", "There's the Principal Square", Arena, Principal_Square, SOUTH);
	data.push_back(Arena_to_Principal_Square);
	printf("\n* exits added");

	//OBJECTS
	//Fighter equipation
	object* Fighter_Helm = new object("Fighter Helm", "Basic but light helm", HELM,Principal_Square, 10, 2, 0, 2);
	data.push_back(Fighter_Helm);
	object* Fighter_Armor = new object("Fighter Armor", "Basic but light Armor", ARMOR,Principal_Square, 25, 4, 0, 2);
	data.push_back(Fighter_Armor);
	object* Fighter_Globes = new object("Fighter Globes", "Basic but light Globes", GLOBES,Principal_Square, 5, 1, 0, 2);
	data.push_back(Fighter_Globes);
	object* Fighter_Pants = new object("Fighter Pants", "Basic but light Pants", PANTS,Principal_Square, 15, 3, 0, 2);
	data.push_back(Fighter_Pants);
	object* Fighter_Boots = new object("Fighter Boots", "Basic but light Boots", BOOTS,Principal_Square, 10, 2, 0, 2);
	data.push_back(Fighter_Boots);
	object* Fighter_Weapon = new object("Fighter Weapon", "Basic but light Weapon", WEAPON,Principal_Square, 0, 0, 10, 0);
	data.push_back(Fighter_Weapon);
	//Assassin equipation
	object* Assassin_Helm = new object("Assassin Helm", "Shiny golden helm", HELM,Principal_Square, 15, 3, 0, 3);
	data.push_back(Assassin_Helm);
	object* Assassin_Armor = new object("Assassin Armor", "Shiny golden Armor", ARMOR,Principal_Square, 30, 5, 0, 3);
	data.push_back(Assassin_Armor);
	object* Assassin_Globes = new object("Assassin Globes", "Shiny golden Globes",GLOBES, Principal_Square, 10, 2, 0, 3);
	data.push_back(Assassin_Globes);
	object* Assassin_Pants = new object("Assassin Pants", "Shiny golden Pants", PANTS, Principal_Square, 20, 4, 0, 3);
	data.push_back(Assassin_Pants);
	object* Assassin_Boots = new object("Assassin Boots", "Shiny golden Boots", BOOTS, Principal_Square, 15, 3, 0, 3);
	data.push_back(Assassin_Boots);
	object* Assassin_Weapon = new object("Assassin Weapon", "Shiny golden Weapon", WEAPON, Principal_Square, 0, 0, 20, 0);
	data.push_back(Assassin_Weapon);
	//rest equipations
	printf("\n* objects added");

	//NPCs
	//Goblin
	goblin* Test_Goblin = new goblin("Goblin", "A little but fast green monster.", Principal_Square);
	data.push_back(Test_Goblin);
	

	//PLAYER AVATAR
	user = new player("Goul", "The shadows warrior", Principal_Square, 150, 0, 5, 15);
	data.push_back(user);
	printf("\n* user added");

	//GAME DATA STUCT
	//Principal Square
	Principal_Square->buffer.push_back(Principal_Square_to_Market);
	Principal_Square->buffer.push_back(Principal_Square_to_Black_Market);
	Principal_Square->buffer.push_back(Principal_Square_to_House);
	Principal_Square->buffer.push_back(Principal_Square_to_Arena);
	Principal_Square->buffer.push_back(Test_Goblin);
	Principal_Square->buffer.push_back(user);
	//Market
	Market->buffer.push_back(Market_to_Principal_Square);
	//Black Market
	Black_Market->buffer.push_back(Black_Market_to_Principal_Square);
	//House
	House->buffer.push_back(House_to_Principal_Square);
	//Arena
	Arena->buffer.push_back(Arena_to_Principal_Square);
	printf("\n* game struct defined");


	


}

bool world::Apply_Instruction(vector<string> instruction){
	//Update the user pointed entity
	if ((instruction.buffer[0] == "look" || instruction.buffer[0] == "pick" || instruction.buffer[0] == "attack") && instruction.get_size() > 1){
		//the entity can have a composen name so the correct words are fused
		if (instruction.get_size()>2) instruction.buffer[1] += instruction.buffer[2];
		if (instruction.get_size()>3) instruction.buffer[1] += instruction.buffer[3];
		for (uint k = 0; k < MAX_ENTITY; k++){
			if (instruction.buffer[1] == data.buffer[k]->name){
				if (instruction.buffer[0] == "look")user->entity_focused = data.buffer[k];
				else if (instruction.buffer[0] == "pick" && data.buffer[k]->type == OBJECT)user->entity_focused = data.buffer[k];
				else if (instruction.buffer[0] == "attack" && data.buffer[k]->type == CREATURE)user->entity_focused = data.buffer[k];
				break;
			}
			else if (k == MAX_ENTITY - 1)user->entity_focused = nullptr;
		}
	}


	//quit instruction
	if (instruction.buffer[0] == "quit")return false;
	

	else if (user->state == IDLE){
		//look instruction
		if (instruction.buffer[0] == "look" && instruction.get_size() > 1){
			if (instruction.buffer[1] == "room")user->entity_focused = user->location;
			user->look(user->entity_focused);
		}
		//go instruction
		else if (instruction.buffer[0] == "go"){
			if (instruction.buffer[1] == "north")user->move(NORTH);
			else if (instruction.buffer[1] == "south")user->move(SOUTH);
			else if (instruction.buffer[1] == "east")user->move(EAST);
			else if (instruction.buffer[1] == "west")user->move(WEST);
		}
		//pick instruction
		else if (instruction.buffer[0] == "pick")user->pick((object*)user->entity_focused);
		//attack instruction
		else if (instruction.buffer[0] == "attack")user->attack();
	}
	//invalid instruction
	else printf("Invalid comand.");
	return true;
}