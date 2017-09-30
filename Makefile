#
# ENSICAEN
# 6 Boulevard Maréchal Juin
# F-14050 Caen Cedex
#
# Copyright (C) 2017 Quentin DURPOIX-ESPINASSON (durpoix@ecole.ensicaen.fr)
#

main : main.o labyrinthe.o
	gcc main.o labyrinthe.o -o main

labyrinthe.o : src/labyrinthe.c 
	gcc -Wall -Wextra -ansi -pedantic -I. -c src/labyrinthe.c

main.o : src/main.c 
	gcc -Wall -Wextra -ansi -pedantic -I. -c src/main.c

clean : 
	rm *.o main