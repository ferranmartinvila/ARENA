#include "entity.h"

void entity::look_it()const{
	printf("\n%s:\n%s\n", name.get_string(), description.get_string());
}