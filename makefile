scrolling:main.o scrolling.o Perfect_Collision.o
	gcc   main.o scrolling.o Perfect_Collision.o -o scrolling -lSDL -lSDL_image 
main.o:main.c
	gcc -c main.c -g

scrolling.o:scrolling.c
	gcc -c scrolling.c -g 

Perfect_Collision.o:Perfect_Collision.c
	gcc -c Perfect_Collision.c -g 



