#include <stdio.h>
#include <stdlib.h>
#include "../include/labyrinthe.h"

int main()
{
	Dimension dimension;
	dimension.high = 51;
	dimension.length = 61;
	
	int ** laby = NULL;     
	int i;
	laby = malloc(dimension.high * sizeof(int*));    
	                                   
	for (i=0; i<dimension.high; i++){
		
	    laby[i] = malloc(dimension.length * sizeof(int)); 
		
	}

	fillLaby(laby, dimension);
	initLaby(laby, dimension);
	showLaby(laby, dimension);
	
	free(laby);
		
    return 0;
	
}