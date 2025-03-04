menu: main.o SaveMenu.o InputsMenu.o omain.o M-main.o sourceBM.o 
	gcc main.o SaveMenu.o omain.o InputsMenu.o M-main.o sourceBM.o -o menu -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -g
main.o: main.c SaveHeader.h
	gcc -c main.c -o main.o
SaveMenu.o: SaveMenu.c SaveHeader.h
	gcc -c SaveMenu.c -o SaveMenu.o
InputsMenu.o: InputsMenu.c InputsMenu.h
	gcc -c InputsMenu.c -o InputsMenu.o
omain.o: omain.c omenu.h
	gcc -c omain.c -o omain.o
M-main.o: M-main.c M-main.h
	gcc -c M-main.c -o M-main.o
sourceBM.o: sourceBM.c functionBM.h
	gcc -c sourceBM.c -o sourceBM.o

