#include <stdio.h>
#include "../include/labyrinthe.h"

int main()
{
	Dimension dimension;
	dimension.high = 9;
	dimension.length = 23;
	
	int labyrinthe[9][23];
	
	fillLaby(labyrinthe);
	initLaby(labyrinthe);
	showLaby(labyrinthe);
	
	
		
    return 0;
}