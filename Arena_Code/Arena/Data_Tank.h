#ifndef _DATA_TANK_
#define _DATA_TANK_
#include"Data_source.h"
#ifdef MAIN_FILE
data_source source;
#else
extern data_source source;
#endif
#endif
