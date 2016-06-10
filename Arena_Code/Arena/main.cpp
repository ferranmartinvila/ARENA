#include "World.h"
#include "Globals.h"
#include "string.h"

#include <stdio.h>
#include <Windows.h>
#include <conio.h>

#define INSTRUCTION_SIZE 35

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
	game.Initialize();
	//Game loop
	bool loop = true;
	while (loop){
		//timer
		current_time = GetTickCount();
		//Game update
		if (current_time > last_time + update_rate){
			printf("\nBase Code");
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
					printf("Instruction: %s\n", phrase);
					instruction = tokenize(phrase);
					loop = game.Apply_Instruction(instruction);
					phrase_position = 0;
				}
			}
		}
	}
	return 0;
}