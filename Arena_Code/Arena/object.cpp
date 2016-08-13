#include "object.h"
#include "creature.h"
//CONSTRUCTOR----------------
object::object(char* name, char* description, OBJECT_TYPE object_type , uint price) :entity(name, description, OBJECT), object_type(object_type),price(price){}



//LORE-----------------------
void object::look_it()const{
	//Name & description
	slim_printf(WHITE, "\n%s: ", name.get_string());
	printf("%s\n", description.get_string());
	slim_printf(WHITE, "price [%i]\n", price);
}

void object::pauted_look_it()const{
	slim_printf(LIGHT_CYAN, "%s: %s", name.get_string(), description.get_string());
	printf("->");
	slim_printf(LIGHT_GREEN, "Price: %u\n", price);
}



