#include "World.h"

void world::Initialize(){

	//PLAYER AVATAR
	player* user = new player("Goul", "The shadow warrior", 150, 0, 5, 15);
	data.push_back(user);
	printf("\n*user added");

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
	printf("\n*rooms added");

	//EXITS
	//Principal Square
	exit* Principal_Square_to_Market = new exit("Market entrance", "From here you can listen the merchants negotiating.", Principal_Square, Market, EAST);
	exit* Principal_Square_to_Black_Market = new exit("Black Market entrance", "There's blue lights and objects floating.", Principal_Square, Black_Market, SOUTH);
	exit* Principal_Square_to_House = new exit("House entrance", "There's your little but homely house.", Principal_Square, House, WEST);
	exit* Principal_Square_to_Arena = new exit("Arena entrance", "From here you can smell the blood and tears of the fighters.", Principal_Square, Arena, NORTH);
	//Market
	exit* Market_to_Principal_Square = new exit("Market exit", "There's the Principal Square", Market, Principal_Square, WEST);
	//Black Market
	exit* Black_Market_to_Principal_Square = new exit("Black Market exit", "There's the Principal Square", Black_Market, Principal_Square, NORTH);
	//House
	exit* House_to_Principal_Square = new exit("House exit", "There's the Principal Square", House, Principal_Square, EAST);
	//Arena
	exit* Arena_to_Principal_Square = new exit("Arena exit", "There's the Principal Square", Arena, Principal_Square, SOUTH);
	printf("\n*exits added");

	//GAME DATA STUCT
	//Principal Square
	Principal_Square->insert(Principal_Square_to_Market);
	Principal_Square->insert(Principal_Square_to_Black_Market);
	Principal_Square->insert(Principal_Square_to_House);
	Principal_Square->insert(Principal_Square_to_Arena);
	Principal_Square->insert(user);
	//Market
	Market->insert(Market_to_Principal_Square);
	//Black Market
	Black_Market->insert(Black_Market_to_Principal_Square);
	//House
	House->insert(House_to_Principal_Square);
	//Arena
	Arena->insert(Arena_to_Principal_Square);
	printf("\n*game struct defined");



}

bool world::Apply_Instruction(vector<string> instruction){
	if (instruction.buffer[0] == "quit")return false;
	else if (instruction.buffer[0] == "go"){
		if (instruction.buffer[1] == "north")user->move(NORTH);
		else if (instruction.buffer[1] == "south")user->move(SOUTH);
		else if (instruction.buffer[1] == "east")user->move(EAST);
		else if (instruction.buffer[1] == "west")user->move(WEST);
	}
	return true;
}