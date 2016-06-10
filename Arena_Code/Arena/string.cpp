#define _CRT_SECURE_NO_WARNINGS
#include"string.h"
#include<string.h>
#include<stdlib.h>
string::string(){
	STR = new char[20];
	memory_size(20);
}

string::string(const char*cadena){
	int size = strlen(cadena);
	STR = new char[size + 1];
	memory_size(size + 1);
	strcpy_s(STR, size + 1, cadena);
}


string::string(const string& copy){
	int size = strlen(copy.STR);
	STR = new char[size + 1];
	memory_size(size + 1);
	strcpy_s(STR, size + 1, copy.STR);
}

string::~string(){
	delete STR;
	STR = nullptr;
}

//string lenght
unsigned int string::lenght()const{
	return strlen(STR);
}

//acces private string
const char* string::c_str()const{
	return STR;
}

//empty condition
bool string::empty()const{
	if (strlen(STR))return true;
	else return false;
}

bool string::erase(){
	delete STR;
	STR = nullptr;
	return true;
}

//get string
char* string::get_string()const{
	return STR;
}

//operator ==
bool string::operator==(const string& string){
	if (strcmp(STR, string.STR))return false;
	else return true;
}
bool string::operator ==(const char* word){
	if (strcmp(STR, word))return false;
	else return true;
}
//operator !=
bool string::operator!=(const string& string){
	if (strcmp(STR, string.STR))return true;
	else return false;
}
bool string::operator !=(const char* word){
	if (strcmp(STR, word))return true;
	else return false;
}

//operator +=
void string::operator +=(const char* string){
	if (strlen(string) + strlen(STR) <= max_capacity){
		strcat(STR, string);
	}
	else{
		memory_size(strlen(string) + strlen(STR) + 1);
		delete STR;
		STR = new char[strlen(STR) + strlen(STR) + 1];
		strcat(STR, string);
	}
}
void string::operator+=(const string& string){
	if (strlen(string.STR) + strlen(STR) <= max_capacity){
		strcat(strcat(STR, " "), string.STR);
	}
	else{
		char* str_cpy = STR;
		memory_size(strlen(string.STR) + strlen(STR) + 1);
		delete STR;
		STR = new char[strlen(string.STR) + strlen(STR) + 1];
		strcat(strcat(STR, " "), string.STR);
	}
}

//operator =
void string::operator =(const char* string){
	if (string != NULL){
		if (strlen(string) <= strlen(STR)){
			{
				strcpy_s(STR, strlen(STR) + 1, string);
			}
		}
		else{
			memory_size(strlen(string) + 1);
			delete STR;
			STR = new char[max_capacity];

			strcpy_s(STR, max_capacity, string);
		}
	}
}
void string::operator =(const string& string){

	if (string.lenght() < strlen(STR) || max_capacity >= string.max_capacity)
	{
		strcpy_s(STR, strlen(STR) + 1, string.STR);
	}
	else{
		memory_size(strlen(string.STR) + 1);
		delete STR;
		STR = new char[max_capacity];

		strcpy_s(STR, max_capacity, string.STR);
	}
}

//operator +
string string::operator +(const char* string_entered)const{
	string result = (strcat(STR, string_entered));
	return result;
}
string string::operator +(const string& string_entered)const{

	string result = (strcat(strcat({ STR }, " "), { string_entered.STR }));
	return result;
}

void string::memory_size(unsigned int size){
	max_capacity = size;
}

vector<string> tokenize(char* phrase){
	vector<string> instruction;
	//array that contain all de phrase characters
	//array with the different words
	char*word[5] = { nullptr, nullptr, nullptr, nullptr, nullptr };
	word[0] = strtok(phrase, " ");
	instruction.push_back(word[0]);
	for (int k = 1; k < 5; k++){
		if (word[k - 1] != NULL){
			word[k] = strtok(NULL, " ");
			if (word[k] != NULL){
				instruction.push_back(word[k]);
			}
		}
	}

	return instruction;
}


