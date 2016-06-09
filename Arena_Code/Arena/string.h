#ifndef _string_
#define _string_
#include "vector.h"
class string{
private:

	char* STR = nullptr;
	unsigned int max_capacity;

public:

	string();
	string(const char*cadena);
	string(const string& copy);
	~string();


	unsigned int lenght()const;
	const char*c_str()const;
	bool empty()const;
	bool erase();
	bool operator ==(const string& string);
	bool operator ==(const char* string);
	void operator +=(const char*string);//es suma a si mateix amb una cadena
	void operator +=(const string& string);//es suma a si mateix amb una class cadena
	string* operator +(const char*string)const;//resultat now sumant cadena 
	string* operator +(const string& string)const;//resultat now sumant class cadena
	void operator =(const char*string);//operator = //es modifica igualant a class cadena
	void operator =(const string& string);//es modifica igualnt a class cadena
	bool operator!=(const char* string);
	bool operator !=(const string&string);
	char* get_string();
	void memory_size(unsigned int);
};
vector<string> tokenize(char*);//separa l'ordre
#endif