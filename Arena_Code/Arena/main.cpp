#include <stdio.h>
#include <Windows.h>
#include <conio.h>
#include "World.h"
#include "entity.h"

#define INSTRUCTION_SIZE 35
//External data main location
#define MAIN_FILE
#include "Data_source.h"

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
			list_double<entity*>::node* temp = game.arena->buffer.first_element;
			while (temp){
				temp->data->update();
				temp = temp->next;
			}
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