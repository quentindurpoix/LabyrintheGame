#ifndef LABYRINTHE_H
#define LABYRINTHE_H


typedef struct {
	int high;
	int length;
}Dimension;

void fillLaby(int ** labyrinth, Dimension dimension);
void showLaby(int ** labyrinth, Dimension dimension);
void initLaby(int ** labyrinth, Dimension dimension);



#endif
