#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "../include/labyrinthe.h"

void fillLaby(int ** labyrinth, Dimension dimension){
    int row = 0;
    int column = 0;
    int tempValue = 1;
    for (row = 0; row < dimension.high; row++) {
        for (column = 0; column < dimension.length ; column++) {
            if (row % 2 != 0) {
                 labyrinth[row][column] = 0;
            }
            else if (column % 2 != 0) {
                 labyrinth[row][column] = 0;
            }
            else {
                labyrinth[row][column] = tempValue;
                tempValue++;
            }
        }
    }
	
}

void initLaby(int ** labyrinth, Dimension dimension){
	int nbWallBroken = 0, xCase1 = 0, yCase1 = 0, xCase2 = 0, yCase2 = 0, tmpVal = 0, i = 0, j = 0, xWall = 0, yWall = 0;
	srandom(time(NULL));
	
 	dimension.high -= 2;
	dimension.length -= 2;
	
	/*A perfect labyrinth contains (m - 1)(n - 1) walls closed (Wikipedia)*/
	while(nbWallBroken < ( (dimension.high/2+1) * (dimension.length/2+1) -1)){
		
        xCase1 = random() % dimension.high;
        yCase1 = random() % dimension.length;

        xCase2 = xCase1 + (random() % 3);
        yCase2 = yCase1 + (random() % 3);
		
		
		/*Even numbers are cells and not walls, we need cells*/
		if((xCase1 % 2 == 0) && (yCase1 % 2 == 0) && (xCase2 % 2 == 0) && (yCase2 % 2 == 0)){
			/*Case 2 must be inside the board*/
			if(xCase2 < dimension.high && xCase2 >= 0 && yCase2 < dimension.length && yCase2 >=0){
				/*Case 2 can't be a diagonal of Case 1 */
				if(abs(xCase1 - xCase2) != abs(yCase1 - yCase2)){
					tmpVal = labyrinth[xCase2][yCase2];
					
					/*Value of each case must be different else they are already a path*/
					if(tmpVal != labyrinth[xCase1][yCase1]){
						
						/*ID of the first case is affected to every cells of the path*/
						for(i = 0; i < dimension.high; i++){
							for(j = 0; j < dimension.length; j++){
								
								if(labyrinth[i][j]==tmpVal){
									
									labyrinth[i][j] = labyrinth[xCase1][yCase1];
									
								}
								
							}
						}
						
						/*Now we remove the wall by replacing it by value of first case*/
						xWall = (xCase1 + xCase2) / 2;
						yWall = (yCase1 + yCase2) / 2;
						
						labyrinth[xWall][yWall] = labyrinth[xCase1][yCase1];
						
						nbWallBroken++;
					}
					
				}
				
			}
			
		}
		
	}
	/*We remove tempory values of cells to get our clean labyrinth*/
	for(i = 0; i < dimension.high; i++){
		for(j = 0; j < dimension.length; j++){
			
			if(labyrinth[i][j]!= 0){
				
				labyrinth[i][j] = 1;
				
			}
			
		}
	}
	
 	dimension.high += 2;
	dimension.length += 2;
	
}

void showLaby(int ** labyrinth, Dimension dimension){
	int i = 0, j = 0;
	
	for (j = 0; j < dimension.length; j++){
		
		printf("# "); 
		
		}
	
	printf("\n"); 
	
	for (i = 0; i < dimension.high-2; i++){
		printf("# ");
		for (j = 0; j < dimension.length-2; j++){
			
			
			switch(labyrinth[i][j]){
			
				case 0 : printf("# ");
					 	 break;
						 
				case 1 : printf("  ");
						 break;
			}
			
		}
		printf("#\n");
	}
	for (j = 0; j < dimension.length; j++){
		
		printf("# "); 
		
		}
	
	printf("\n");
	
}