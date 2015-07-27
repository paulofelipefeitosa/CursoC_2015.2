#include "changechar.h"

char change_char(char *c)
{
	if(*c==-96 || *c==-125 || *c==-58)
		return 'a';
	else if(*c==-75 || *c==-74 || *c==-57)
		return 'A';
	else if(*c==-126 || *c==-120)
		return 'e';
	else if(*c==-112 || *c==-46)
		return 'E';
	else if(*c==-95)
		return 'i';
	else if(*c==-42)
		return 'I';
	else if(*c==-94 || *c==-28 || *c==-109)
		return 'o';
	else if(*c==-30 || *c==-27 || *c==-32)
		return 'O';
	else if(*c==-93)
		return 'u';
	else if(*c==-23)
		return 'U';
	else if(*c==-121)
		return 'c';
	else if(*c==-128)
		return 'C';
	else
		return *c;
}