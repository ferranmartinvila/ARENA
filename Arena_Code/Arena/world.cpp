#include "World.h"
#include "string.h"

//Creatures
#include "player.h"
#include "Merchant.h"
#include "Runner.h"
#include "Tamer.h"
#include "Enchanter.h"

//Objects
#include "room.h"
#include "Data_source.h"

void world::Initialize(){

	//ROOMS--------------------------------------
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
	room* Arena = new room("Arena", "The ground is full of blood and the public shout kill!");
	data.push_back(Arena);


	
	//EXITS--------------------------------------
	//Principal Square
	room::exit* Principal_Square_to_Market = new room::exit("Market entrance", "From here you can listen the merchants negotiating.", Principal_Square, Market, EAST);
	data.push_back(Principal_Square_to_Market);
	room::exit* Principal_Square_to_Black_Market = new room::exit("Black Market entrance", "There's blue lights and objects floating.", Principal_Square, Black_Market, SOUTH);
	data.push_back(Principal_Square_to_Black_Market);
	room::exit* Principal_Square_to_House = new room::exit("House entrance", "There's your little but homely house.", Principal_Square, House, WEST);
	data.push_back(Principal_Square_to_House);
	room::exit* Principal_Square_to_Arena = new room::exit("Arena entrance", "From here you can smell the blood of the fighters.", Principal_Square, Arena, NORTH);
	data.push_back(Principal_Square_to_Arena);
	//Market
	room::exit* Market_to_Principal_Square = new room::exit("Market exit", "There's the Principal Square", Market, Principal_Square, WEST);
	data.push_back(Market_to_Principal_Square);
	//Black Market
	room::exit* Black_Market_to_Principal_Square = new room::exit("Black Market exit", "There's the Principal Square", Black_Market, Principal_Square, NORTH);
	data.push_back(Black_Market_to_Principal_Square);
	//House
	room::exit* House_to_Principal_Square = new room::exit("House exit", "There's the Principal Square", House, Principal_Square, EAST);
	data.push_back(House_to_Principal_Square);
	//Arena
	room::exit* Arena_to_Principal_Square = new room::exit("Arena exit", "There's the Principal Square", Arena, Principal_Square, SOUTH);
	data.push_back(Arena_to_Principal_Square);

	

	//NPCs---------------------------------------
	//Equipment Merchant
	merchant* Equipment_Merchant = new merchant(Market, 25);
	data.push_back(Equipment_Merchant);
	//Runes Merchant
	merchant* Runes_Merchant = new merchant(Black_Market, 25);
	data.push_back(Runes_Merchant);
	//Potions Merchant
	merchant* Potions_Merchant = new merchant(Market, 25);
	data.push_back(Potions_Merchant);
	//Runner
	runner*Runner = new runner(Black_Market, 25);
	data.push_back(Runner);
	//Tamer
	tamer*Tamer = new tamer(House, 25);
	data.push_back(Tamer);
	//Enchanter
	enchanter*Enchanter = new enchanter(Black_Market, 25);
	data.push_back(Enchanter);


	//PLAYER AVATAR------------------------------
	player* User = new player("Goul", "The shadows warrior", Principal_Square,1);
	//User Build
	User->hub = Principal_Square;
	User->buffer.push_back((entity*)source.potions.buffer[0]);
	User->buffer.push_back((entity*)source.potions.buffer[1]);
	User->buffer.push_back((entity*)source.equips.buffer[1]);
	User->buffer.push_back((entity*)source.runes.buffer[1]);
	data.push_back(User);

	
	//OBJECTS------------------------------------
	//Push equip
	int h = source.equips.get_size();
	for (int k = 0; k < h; k++){
		data.push_back(source.equips.buffer[k]);
	}
	//Push runes
	h = source.runes.get_size();
	for (int k = 0; k < h; k++){
		data.push_back(source.runes.buffer[k]);
	}
	//Push potions
	h = source.potions.get_size();
	for (int k = 0; k < h; k++){
		data.push_back((entity*)source.potions.buffer[k]);
	}
	//Push pets
	h = source.pets.get_size();
	for (int k = 0; k < h; k++){
		data.push_back((entity*)source.pets.buffer[k]);
	}

	//GAME DATA STRUCT---------------------------
	//Data Pointers----------
	arena = Arena;
	user = User;



	//NPCs-------------------
	//Equipment Merchant
	h = source.equips.get_size();
	for (int k = 0; k < h; k++){
		Equipment_Merchant->buffer.push_back(source.equips.buffer[k]);
	}
	//Runes Merchant
	h = source.runes.get_size();
	for (int k = 0; k < h; k++){
		Runes_Merchant->buffer.push_back(source.runes.buffer[k]);
	}
	//Potions Merchant
	h = source.potions.get_size();
	for (int k = 0; k < h; k++){
		Potions_Merchant->buffer.push_back((entity*)source.potions.buffer[k]);
	}
	//Pets Tamer
	h = source.pets.get_size();
	for (int k = 0; k < h; k++){
		Tamer->buffer.push_back((entity*)source.pets.buffer[k]);
	}
	


	//MAP--------------------
	//Principal Square
	Principal_Square->buffer.push_back(Principal_Square_to_Market);
	Principal_Square->buffer.push_back(Principal_Square_to_Black_Market);
	Principal_Square->buffer.push_back(Principal_Square_to_House);
	Principal_Square->buffer.push_back(Principal_Square_to_Arena);
	Principal_Square->buffer.push_back(user);
	//Market
	Market->buffer.push_back(Market_to_Principal_Square);
	Market->buffer.push_back(Equipment_Merchant);
	Market->buffer.push_back(Potions_Merchant);
	//Black Market
	Black_Market->buffer.push_back(Black_Market_to_Principal_Square);
	Black_Market->buffer.push_back(Runes_Merchant);
	Black_Market->buffer.push_back(Runner);
	Black_Market->buffer.push_back(Enchanter);
	//House
	House->buffer.push_back(House_to_Principal_Square);
	House->buffer.push_back(Tamer);
	//Arena
	Arena->buffer.push_back(Arena_to_Principal_Square);
}

bool world::Apply_Instruction(vector<string> instruction){
	
	//ENTITY FOCUS-------------------------------
	//Vector position that have to be compared
	uint position = 1;
	//Update the user pointed entity
	if (user->state == IDLE)user->entity_focused = nullptr;
	if ((user->state == IDLE || user->state == ATTACK || user->state == IN_ARENA) && instruction.get_size() > 1){
		
		//to instructions
		if (instruction.buffer[1] == "to" && instruction.get_size() > 2){
			position++;
		}
		//entity names that content of
		else if (instruction.get_size() > 4 && instruction.buffer[2] == "of"){
			instruction.buffer[position] += instruction.buffer[position + 1];
			instruction.buffer[position] += instruction.buffer[position + 2];
			instruction.buffer[position] += instruction.buffer[position + 3];
		}
		//general large instructions
		else
		{
			if (instruction.get_size() > 2) instruction.buffer[position] += instruction.buffer[position + 1];
		}
		//Arena buffer focus
		if (user->location == arena){
			//Find data in temp arena data
			for (uint k = 0; k < arena->buffer.get_size(); k++){
				if (instruction.buffer[position] == arena->buffer[k]->name)user->entity_focused = arena->buffer[k];
			}
		}
		//Game buffer focus
		else {
			//Find the entity in world data
			for (uint k = 0; k < MAX_ENTITY; k++){
				if (instruction.buffer[position] == data.buffer[k]->name)user->entity_focused = data.buffer[k];
			}
		}
		
	}
	
	//QUITS--------------------------------------
	if (instruction.buffer[0] == "quit"){
		//Quit from the game
		if (user->state == IDLE){
			//Show results
			printf("\nSee you soon %s!\n\n", user->name.get_string());
			//Break the loop
			return false;
		}
		//Quit from the action
		else if (user->state != IN_ARENA){
			//Resets the states
			user->state = ((creature*)user->entity_focused)->state = IDLE;
			//Show results
			printf("\nSee you soon %s!\n\n", user->entity_focused->name.get_string());
		}
		//Invalid Quit
		else printf("You can't quit now.\n\n");
	}
	 

	//STATE ACTIONS------------------------------
	//NPC Talk(Buy/Sell/Fuse_Runes/Extract_Runes/Pet_Trade/Upgrade)
	else if (user->state == BUY || user->state == SELL  || user->state == FUSE_RUNES || user->state == EXTRACT_RUNES || user->state == PET_TRADE || user->state == UPGRADE)((creature*)user->entity_focused)->talk(instruction.buffer[0]);
	
	//ARENA FIGHT--------------------------------
	else if (user->state == IN_ARENA){
		if (instruction.get_size() == 1 && instruction.buffer[0].lenght() == 1)((room*)user->location)->generate_round(user, instruction.buffer[0].get_string()[0]);
		else if (instruction.buffer[0] == "attack")user->attack();
		else if (instruction.buffer[0] == "drink")user->drink();
		else slim_printf(WHITE, "Invalid comand.\n\n");
	}


	//DEAD(RESET)--------------------------------
	else if (instruction.buffer[0] == "RESET" && user->state == DEAD)user->reset();


	//HELP---------------------------------------
	else if (instruction.buffer[0] == "help"){
		slim_printf(WHITE, "help"); printf(" -> Show all the instructions\n");
		slim_printf(WHITE, "quit"); printf("(in idle) -> Quit from the game\n");
		slim_printf(WHITE, "quit"); printf("(in action) -> Quit from the action\n");
		slim_printf(WHITE, "go + direction"); printf(" -> Move around the rooms\n");
		slim_printf(WHITE, "look + me"); printf(" -> Look avatar\n");
		slim_printf(WHITE, "look + room"); printf(" -> Look current location\n");
		slim_printf(WHITE, "look + direction"); printf(" -> Look in the choosed direction\n");
		slim_printf(WHITE, "look + entity name"); printf(" -> Look the entity\n");
		slim_printf(WHITE, "pick + item name"); printf(" -> Pick the choosed item\n");
		slim_printf(WHITE, "throw + item name"); printf(" -> Throw the choosed item\n");
		slim_printf(WHITE, "equip + item name"); printf(" -> Equip the choosed item\n");
		slim_printf(WHITE, "unequip + item name"); printf(" -> Unequip the choosed item\n");
		slim_printf(WHITE, "spawn + pet name"); printf(" -> Spawn the choosed pet\n");
		slim_printf(WHITE, "unspawn + pet name"); printf(" -> Unspawn the choosed pet\n");
		slim_printf(WHITE, "drink + potion name"); printf(" -> Drink the selected potion\n");
		slim_printf(WHITE, "attack + NPC name"); printf(" -> Attack the focused NPC\n");
		slim_printf(WHITE, "talk to + NPC name"); printf(" -> Start a conversation with a NPC\n");
		slim_printf(WHITE, "buy + item name"); printf("(in talk with Merchant) -> Buy the choosed item\n");
		slim_printf(WHITE, "sell + item name"); printf("(in talk with Merchant)->Sell the choosed item\n");
		slim_printf(WHITE, "change"); printf("(in talk with Merchant) -> Swap between SELL & BUY mode\n");
		slim_printf(WHITE, "change"); printf("(in talk with Runner) -> Swap between FUSE & EXTRACT mode\n");
		slim_printf(WHITE, "a...z"); printf("(in talk with NPC) -> Choose option\n");
		slim_printf(WHITE, "RESET"); printf("(in dead state) -> Reset the user bag, money & current xp\n\n");
	}
	
	//IDLE ACTIONS-------------------------------
	else if (user->state == IDLE && instruction.get_size() > 1){
		//LOOK instruction
		if (instruction.buffer[0] == "look" && instruction.get_size() > 1)user->look(instruction.buffer[1]);
		//GO instruction
		else if (instruction.buffer[0] == "go")user->move(instruction.buffer[1]);
		//PICK instruction
		else if (instruction.buffer[0] == "pick")user->pick();
		//PULL instruction
		else if (instruction.buffer[0] == "throw")user->pull();
		//EQUIP instruction
		else if (instruction.buffer[0] == "equip")user->equip_object();
		//UNEQUIP instruction
		else if (instruction.buffer[0] == "unequip")user->unequip_object();
		//SPAWN instruction
		else if (instruction.buffer[0] == "spawn")user->spawn_creature();
		//UNSPAWN instruction
		else if (instruction.buffer[0] == "unspawn")user->unspawn_creature();
		//DRINK instruction
		else if (instruction.buffer[0] == "drink")user->drink();
		//TALK instruction
		else if (instruction.buffer[0] == "talk" && instruction.buffer[1] == "to")user->talk("default");
		//ATTACK instruction
		else if (instruction.buffer[0] == "attack")user->state = ATTACK;
		//invalid instruction
		else slim_printf(WHITE, "Invalid comand.\n\n");
	}
	else slim_printf(WHITE, "Invalid comand.\n\n");
	return true;
}