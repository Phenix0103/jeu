prog:main.o collisionbox.o
	gcc main.o collisionbox.o -o prog -lSDL -lSDL_image
main.o:main.c
	gcc -c main.c 
collisionbox.o:collisionbox.c
	gcc -c collisionbox.c
