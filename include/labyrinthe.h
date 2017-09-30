#ifndef LABYRINTHE_H
#define LABYRINTHE_H

void fillLaby(int labyrinthe[9][23]);
void showLaby(int labyrinthe[9][23]);
void initLaby(int labyrinthe[9][23]);

typedef struct {
	int high;
	int length;
}Dimension;

#endif
