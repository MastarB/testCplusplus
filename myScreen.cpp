#include "myScreen.h"
	
Screen& Screen::move(pos row, pos col)
{
	cur = row * width + col;
	return *this;
}
	
Screen& Screen::type(char c)
{
	if(isCharacter(c))
		field[cur++] = c;
	else switch(c)
	{
		//handle all kinds of special char
	}
	return *this;
}
	
Screen& Screen::set(char c)
{
 	if(isCharacter(c))
 		field[cur] = c;
 	return *this;
}


