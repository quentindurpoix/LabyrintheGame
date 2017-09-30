#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

#include "../include/labyrinthe.h"

void fillLaby(int labyrinthe[9][23]){
    int ligne = 0;
    int colonne = 0;
    int tempValue = 1;

    //initialisation des cases
    for (ligne = 0; ligne < 9; ligne++) {
        for (colonne = 0; colonne < 23 ; colonne++) {
            if (ligne % 2 != 0) {//definit les murs horizontaux
                 labyrinthe[ligne][colonne] = 0;
            }
            else if (colonne % 2 != 0) {//definit les murs verticaux
                 labyrinthe[ligne][colonne] = 0;
            }
            else {
                labyrinthe[ligne][colonne] = tempValue;
                tempValue++;
            }
        }
    }
	
}

void initLaby(int labyrinthe[9][23]){
	int nbWallBroken = 0, xCase1 = 0, yCase1 = 0, xCase2 = 0, yCase2 = 0, tmpVal = 0, i = 0, j = 0, xWall = 0, yWall = 0;
	srandom(time(NULL));
	
	/*A perfect labyrinth contains (m - 1)(n - 1) walls closed (Wikipedia)*/
	while(nbWallBroken < ( (9/2+1) * (23/2+1) -1)){
		
        xCase1 = random() % 9;
        yCase1 = random() % 23;

        xCase2 = xCase1 + (random() % 3);
        yCase2 = yCase1 + (random() % 3);
		
		
		/*Even numbers are cells and not walls, we need cells*/
		if((xCase1 % 2 == 0) && (yCase1 % 2 == 0) && (xCase2 % 2 == 0) && (yCase2 % 2 == 0)){
			/*Case 2 must be inside the board*/
			if(xCase2 < 9 && xCase2 >= 0 && yCase2 < 23 && yCase2 >=0){
				/*Case 2 can't be a diagonal of Case 1 */
				if(abs(xCase1 - xCase2) != abs(yCase1 - yCase2)){
					tmpVal = labyrinthe[xCase2][yCase2];
					
					/*Value of each case must be different else they are already a path*/
					if(tmpVal != labyrinthe[xCase1][yCase1]){
						
						/*ID of the first case is affected to every cells of the path*/
						for(i = 0; i < 9; i++){
							for(j = 0; j < 23; j++){
								
								if(labyrinthe[i][j]==tmpVal){
									
									labyrinthe[i][j] = labyrinthe[xCase1][yCase1];
									
								}
								
							}
						}
						
						/*Now we remove the wall by replacing it by value of first case*/
						xWall = (xCase1 + xCase2) / 2;
						yWall = (yCase1 + yCase2) / 2;
						
						labyrinthe[xWall][yWall] = labyrinthe[xCase1][yCase1];
						
						nbWallBroken++;
					}
					
				}
				
			}
			
		}
		
	}
	
	/*We remove tempory values of cells to get our clean labyrinth*/
	for(i = 0; i < 9; i++){
		for(j = 0; j < 23; j++){
			
			if(labyrinthe[i][j]!= 0){
				
				labyrinthe[i][j] = 1;
				
			}
			
		}
	}
	
	
	
}

void showLaby(int labyrinthe[9][23]){
	int i = 0, j = 0;
	for (i = 0; i < 9; i++){
		for (j = 0; j < 23; j++){
			
			switch(labyrinthe[i][j]){
			
				case 0 : printf("#");
					 	 break;
						 
				case 1 : printf(" ");
						 break;
			}
		}
		
		printf("\n"); 
	}
	
}