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
	if (instruction.buffer[0] == "look"){
		//the entity can have a composen nameso the correct words are fused
		if (instruction.get_size()>2) instruction.buffer[1] += instruction.buffer[2];
		if (instruction.get_size()>3) instruction.buffer[1] += instruction.buffer[3];
		for (uint k = 0; k < MAX_ENTITY; k++){
			if (instruction.buffer[1] == data.buffer[k]->name){
				user->entity_focused = data.buffer[k];
				break;
			}
			else if (k == MAX_ENTITY - 1)user->entity_focused = nullptr;
		}
	}


	//quit instruction
	if (instruction.buffer[0] == "quit")return false;
	//look instruction
	else if (instruction.buffer[0] == "look")user->look(user->entity_focused);
	//go instruction
	else if (instruction.buffer[0] == "go"){
		if (instruction.buffer[1] == "north")user->move(NORTH);
		else if (instruction.buffer[1] == "south")user->move(SOUTH);
		else if (instruction.buffer[1] == "east")user->move(EAST);
		else if (instruction.buffer[1] == "west")user->move(WEST);
	}
	//invalid instruction
	else printf("Invalid comand.");
	return true;
}