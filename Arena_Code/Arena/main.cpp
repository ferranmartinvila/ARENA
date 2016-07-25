#include <stdio.h>
#include <Windows.h>
#include <conio.h>

#define INSTRUCTION_SIZE 35
#define MAIN_FILE
#define _SLIM_PRINTF_DEF_FILE_
#include "Data_source.h"
#include "Slim_printf.h"
#include "World.h"
#include "entity.h"


int main(){

	//Instruction data
	char phrase[INSTRUCTION_SIZE];
	uint phrase_position = 0;
	vector<string> instruction;
	//Real time data
	uint current_time = 0;
	uint last_time = 0;
	uint update_rate = 1000;
	//World data
	world game;
	
	printf("                              |ARENA THE GAME|\n\n");
	printf("-> enter help to see all the commands\n");
	//Game loop
	bool loop = true;
	while (loop){
		//timer
		current_time = GetTickCount();
		//Game update
		if (current_time > last_time + update_rate){
			
			//World data update
			for (uint k = 0; k < MAX_ENTITY; k++){
				game.data.buffer[k]->update();
			}
			
			//Arena data update
			uint arena_data = game.arena->buffer.get_size();
			for (uint h = 0; h < arena_data; h++){
				if(game.arena->buffer[h]->name != "Goul")game.arena->buffer[h]->update();
				arena_data = game.arena->buffer.get_size();
			}
			
			//Time update
			last_time = current_time;
		}
		//User imput
		if (_kbhit()){
			phrase[phrase_position] = _getch();
			phrase_position++;
			if (phrase[phrase_position - 1] == '\r'){
				if (phrase_position - 1 == 0){
					phrase_position = 0;
				}
				else{
					phrase[phrase_position - 1] = '\0';
					printf("Instruction: %s\n\n", phrase);
					instruction = tokenize(phrase);
					loop = game.Apply_Instruction(instruction);
					phrase_position = 0;
				}
			}
		}
	}
	return 0;
}