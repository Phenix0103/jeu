prog: main.o
	gcc mainclavier.c clavier.c -o prog -lSDL -lSDL_image
main.o: mainclavier.c
	gcc -c mainclavier.c

