#ifndef _SLIM_PRINTF_
#define _SLIM_PRINTF_

#include "Globals.h"
#include <stdio.h>                 
#include <windows.h>

#ifdef _SLIM_PRINTF_DEF_FILE_
char *convert(unsigned int num, int base)
{
	//Char font
	static char Representation[] = "0123456789ABCDEF";
	//Char buffer
	static char buffer[50];
	//Char pointer
	char *ptr;

	//Initialize var
	ptr = &buffer[49];
	*ptr = '\0';

	//Change the base of the value to the choosed base or data type
	do
	{
		*--ptr = Representation[num%base];
		num /= base;
	} while (num != 0);

	//Return the pointer to the choosed char converted
	return(ptr);
}

void slim_printf(COLOR color, char* format, ...)
{
	//Char array base
	char *phrase;
	//Char focused integrer value
	int i;
	//Char focused pointer
	char *s;

	//Change to the choosed color
	HANDLE out_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(out_handle, color);

	//Initialize arguments 
	va_list arg;
	va_start(arg, format);

	for (phrase = format; *phrase != '\0'; phrase++)
	{
		//Char array position
		int position = 0;
		//Char array lenght
		int lenght = strlen(format);
		//Search the %[] operators
		while (*phrase != '%' && position < lenght)
		{
			putchar(*phrase);
			phrase++;
			position++;
		}

		phrase++;

		//Transform the %[] operators
		switch (*phrase)
		{
		case 'c': i = va_arg(arg, int);          //char case representation
			fputs(convert(i, 10), stdout);
			break;
		case 's': s = va_arg(arg, char *);       //string case representation
			fputs(s, stdout);
			break;
		case 'u': i = va_arg(arg, unsigned int); //unsigned decimal case representation
			fputs(convert(i, 10), stdout);
			break;
		case 'i': i = va_arg(arg, int);          //decimal case representation
			fputs(convert(i, 10), stdout);
			break;
		}
	}

	//Clean up arguments
	va_end(arg);

	//Reset the txt color
	SetConsoleTextAttribute(out_handle, NORMAL);
}
#else 
char *convert(unsigned int num, int base);
void slim_printf(COLOR color, char* format, ...);
#endif
#endif