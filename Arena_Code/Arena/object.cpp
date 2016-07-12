#include "object.h"
#include "creature.h"
//CONSTRUCTOR----------------
object::object(char* name, char* description, OBJECT_TYPE object_type , uint price) :entity(name, description, OBJECT), object_type(object_type),price(price){}



//LORE-----------------------
void object::look_it()const{
	//Name & description
	printf("\n%s:%s\n", name.get_string(), description.get_string());
	printf("price [%i]\n", price);
}

void object::pauted_look_it()const{
	printf("%s: %s -> Price: %u\n", name.get_string(), description.get_string(), price);
}



