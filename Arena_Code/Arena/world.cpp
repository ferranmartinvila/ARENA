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

	

	//NPCs
	//Merchant
	merchant* Merchant = new merchant("Merchant", "This merchant have all the equipment needed for fight", Market, 25);
	data.push_back(Merchant);
	//Magic Merchant
	merchant* Magic_Merchant = new merchant("Runner", "This merchant have all type of runes to ugrade objects", Black_Market, 25);
	data.push_back(Magic_Merchant);
	printf("\n* NPCs added");
	//PLAYER AVATAR
	user = new player("Goul", "The shadows warrior", Principal_Square,1);
	data.push_back(user);
	printf("\n* user added");

	//OBJECTS
	//Fighter equipation
	object* Fighter_Helm = new object("Helm", "Basic but light helm", HELM, Principal_Square, 10, 2, 0, 2, 60);
	data.push_back(Fighter_Helm);
	object* Fighter_Armor = new object("Fighter Armor", "Basic but light Armor", ARMOR, Merchant, 25, 4, 0, 2, 150);
	data.push_back(Fighter_Armor);
	object* Fighter_Globes = new object("Fighter Globes", "Basic but light Globes", GLOBES, Merchant, 5, 1, 0, 2, 45);
	data.push_back(Fighter_Globes);
	object* Fighter_Pants = new object("Fighter Pants", "Basic but light Pants", PANTS, Merchant, 15, 3, 0, 2, 100);
	data.push_back(Fighter_Pants);
	object* Fighter_Boots = new object("Fighter Boots", "Basic but light Boots", BOOTS, Merchant, 10, 2, 0, 2, 50);
	data.push_back(Fighter_Boots);
	object* Fighter_Weapon = new object("Fighter Weapon", "Basic but light Weapon", WEAPON, Merchant, 0, 0, 10, 0, 250);
	data.push_back(Fighter_Weapon);
	//Assassin equipation
	object* Assassin_Helm = new object("AHelm", "Shiny golden helm", HELM, Principal_Square, 15, 3, 0, 3, 120);
	data.push_back(Assassin_Helm);
	object* Assassin_Armor = new object("Assassin Armor", "Shiny golden Armor", ARMOR, Principal_Square, 30, 5, 0, 3, 300);
	data.push_back(Assassin_Armor);
	object* Assassin_Globes = new object("Assassin Globes", "Shiny golden Globes", GLOBES, Merchant, 10, 2, 0, 3, 90);
	data.push_back(Assassin_Globes);
	object* Assassin_Pants = new object("Assassin Pants", "Shiny golden Pants", PANTS, Merchant, 20, 4, 0, 3, 200);
	data.push_back(Assassin_Pants);
	object* Assassin_Boots = new object("Assassin Boots", "Shiny golden Boots", BOOTS, Merchant, 15, 3, 0, 3, 100);
	data.push_back(Assassin_Boots);
	object* Assassin_Weapon = new object("Assassin Weapon", "Shiny golden Weapon", WEAPON, Merchant, 0, 0, 20, 0, 500);
	data.push_back(Assassin_Weapon);
	//Runes
	object* Vitality_Rune = new object("Rune of Vitality", "Adds a live buff to the object", RUNE, Magic_Merchant, 15, 0, 0, 0, 100);
	data.push_back(Vitality_Rune);
	object* Defence_Rune = new object("Rune of Defence", "Adds a defence buff to the object", RUNE, Magic_Merchant, 0, 15, 0, 0, 100);
	data.push_back(Defence_Rune);
	object* Attack_Rune = new object("Rune of Attack", "Adds a attack buff to the object", RUNE, Magic_Merchant, 0, 0, 15, 0, 100);
	data.push_back(Attack_Rune);
	object* Stamina_Rune = new object("Rune of Stamina", "Adds a stamina buff to the object", RUNE, Magic_Merchant, 0, 0, 0, 15, 100);
	data.push_back(Stamina_Rune);
	printf("\n* objects added");
	
	
	
	//GAME DATA STRUCT
	
	//NPCs
	//Merchant
	//Fighter equipation
	Merchant->buffer.push_back(Fighter_Helm);
	Merchant->buffer.push_back(Fighter_Armor);
	Merchant->buffer.push_back(Fighter_Globes);
	Merchant->buffer.push_back(Fighter_Pants);
	Merchant->buffer.push_back(Fighter_Boots);
	Merchant->buffer.push_back(Fighter_Weapon);
	//Assasin equipation
	Merchant->buffer.push_back(Assassin_Helm);
	Merchant->buffer.push_back(Assassin_Armor);
	Merchant->buffer.push_back(Assassin_Globes);
	Merchant->buffer.push_back(Assassin_Pants);
	Merchant->buffer.push_back(Assassin_Boots);
	Merchant->buffer.push_back(Assassin_Weapon);
	//Magic Merchant
	Magic_Merchant->buffer.push_back(Vitality_Rune);
	Magic_Merchant->buffer.push_back(Defence_Rune);
	Magic_Merchant->buffer.push_back(Attack_Rune);
	Magic_Merchant->buffer.push_back(Stamina_Rune);
	
	//MAP
	//Principal Square
	Principal_Square->buffer.push_back(Principal_Square_to_Market);
	Principal_Square->buffer.push_back(Principal_Square_to_Black_Market);
	Principal_Square->buffer.push_back(Principal_Square_to_House);
	Principal_Square->buffer.push_back(Principal_Square_to_Arena);
	Principal_Square->buffer.push_back(Assassin_Helm);
	Principal_Square->buffer.push_back(Fighter_Helm);
	Principal_Square->buffer.push_back(Assassin_Armor);
	Principal_Square->buffer.push_back(user);
	//Market
	Market->buffer.push_back(Market_to_Principal_Square);
	Market->buffer.push_back(Merchant);
	//Black Market
	Black_Market->buffer.push_back(Black_Market_to_Principal_Square);
	Black_Market->buffer.push_back(Magic_Merchant);
	//House
	House->buffer.push_back(House_to_Principal_Square);
	//Arena
	Arena->buffer.push_back(Arena_to_Principal_Square);
	printf("\n* game struct defined\n\n");


	


}

bool world::Apply_Instruction(vector<string> instruction){
	//ENTITY FOCUS--------------------
	//Vector position that have to be compared
	uint position = 1;
	//Update the user pointed entity
	if ((instruction.buffer[0] == "look" || instruction.buffer[0] == "pick" || instruction.buffer[0] == "throw" 
		|| instruction.buffer[0] == "attack" || instruction.buffer[0] == "talk" 
		|| instruction.buffer[0] == "equip" || instruction.buffer[0] == "unequip") && instruction.get_size() > 1 && user->state == IDLE){
		//the entity can have a composen name so the correct words are fused
		if (instruction.buffer[1] == "to")position++;
		else
		{
			if (instruction.get_size() > 2) instruction.buffer[position] += instruction.buffer[position + 1];
			if (instruction.get_size() > 3) instruction.buffer[position + 1] += instruction.buffer[position + 3];
		}
		//Find the entity checking the user instruction
		for (uint k = 0; k < MAX_ENTITY; k++){
			if (instruction.buffer[position] == data.buffer[k]->name){
				if (instruction.buffer[0] == "look")user->entity_focused = data.buffer[k];
				else if ((instruction.buffer[0] == "pick"  || instruction.buffer[0] == "throw" 
						|| instruction.buffer[0] == "equip" ||instruction.buffer[0] == "unequip") && data.buffer[k]->type == OBJECT)user->entity_focused = data.buffer[k];
				else if ((instruction.buffer[0] == "attack" || instruction.buffer[0] == "talk") && data.buffer[k]->type == CREATURE)user->entity_focused = data.buffer[k];
				if (data.buffer[k]->type == OBJECT)printf("\n[item]%s", data.buffer[k]->name.get_string());
				break;
			}
			//Reset the entity focused
			else if (k == MAX_ENTITY - 1)user->entity_focused = nullptr;
		}
	}
	else if(user->state == IDLE)user->entity_focused = nullptr;

	
	
	//STATE ACTIONS--------------------
	//Talk(Buy/Sell/Converse)
	if ((user->state == BUY || user->state == SELL) && instruction.buffer[0] != "quit"){
		//Change trade mode
		if (instruction.buffer[0] == "change"){
			//BUY to SELL
			if (user->state == BUY){ user->state = SELL, ((creature*)user->entity_focused)->state = SELL; }
			//SELL to BUY
			else if (user->state == SELL){ user->state = BUY, ((creature*)user->entity_focused)->state = BUY; }
			//Re-print the storage
			((creature*)user->entity_focused)->talk();
		}
		//Choose option 
		else if (instruction.buffer[0].lenght() == 1 && instruction.get_size() == 1){
			//Apply choosed option
			user->choose_option(instruction.buffer[0].get_string()[0]);
		}
		else printf("Invalid Comand.\n");
	}
		
	
	//QUITS---------------------------
	else if (instruction.buffer[0] == "quit")
		//Quit from the game
		if (user->state == IDLE)return false;
		else {
			//Quit from the action
			printf("\nSee you soon!\n");
			//Resets the states
			user->state = IDLE;
			((creature*)user->entity_focused)->state = IDLE;
		}


	//INTRUCTIONS--------------------
	else if (user->state == IDLE){
		//LOOK instruction
		if (instruction.buffer[0] == "look" && instruction.get_size() > 1){
			//look room instruction
			if (instruction.buffer[1] == "room")user->entity_focused = user->location;
			//look me instruction
			else if (instruction.buffer[1] == "me")user->entity_focused = user;
			//directional look instruction
			else{
				if (instruction.buffer[1] == "north")user->entity_focused =((room*)user->location)->find_exit(NORTH);
				else if (instruction.buffer[1] == "east")user->entity_focused = ((room*)user->location)->find_exit(EAST);
				else if(instruction.buffer[1] == "west")user->entity_focused = ((room*)user->location)->find_exit(WEST);
				else if(instruction.buffer[1] == "south")user->entity_focused = ((room*)user->location)->find_exit(SOUTH);
			}
			//Apply look instruction
			user->look();
		}
		//GO instruction
		else if (instruction.buffer[0] == "go"){
				 if (instruction.buffer[1] == "north")user->move(NORTH);
			else if (instruction.buffer[1] == "south")user->move(SOUTH);
			else if (instruction.buffer[1] == "east")user->move(EAST);
			else if (instruction.buffer[1] == "west")user->move(WEST);
		}
		//PICK instruction
		else if (instruction.buffer[0] == "pick")user->pick();
		//PULL instruction
		else if (instruction.buffer[0] == "throw")user->pull();
		//EQUIP instruction
		else if (instruction.buffer[0] == "equip")user->equip_object();
		//UNEQUIP instruction
		else if (instruction.buffer[0] == "unequip")user->unequip_object();
		//TALK instruction
		else if (instruction.buffer[0] == "talk")user->talk();
		//ATTACK instruction
		else if (instruction.buffer[0] == "attack")user->attack();
		//invalid instruction
		else printf("Invalid comand.\n");
	}
	return true;
}