jeu:main.o integration.o integrationm.o perso.o scrolling.o map.o vie.o ennemi.o collisionbox.o  Perfect_Collision.o enig.o quiz.o time.o score.o minimap.o control.o save.o
	gcc main.o integration.o integrationm.o perso.o scrolling.o map.o vie.o ennemi.o collisionbox.o Perfect_Collision.o enig.o quiz.o time.o score.o minimap.o control.o save.o -o jeu -lSDL -lSDL_image -lSDL_mixer -lSDL_ttf -lSDL_gfx
main.o:main.c
	gcc -c main.c
integration.o:integration.c
	gcc -c integration.c
integrationm.o:integrationm.c
	gcc -c integrationm.c
map.o:map.c
	gcc -c map.c
perso.o:perso.c
	gcc -c perso.c
scrolling.o:scrolling.c
	gcc -c scrolling.c
vie.o:vie.c
	gcc -c vie.c
ennemi.o:ennemi.c
	gcc -c ennemi.c
collisionbox.o:collisionbox.c
	gcc -c collisionbox.c
Perfect_Collision.o:Perfect_Collision.c
	gcc -c Perfect_Collision.c
enig.o:enig.c
	gcc -c enig.c
quiz.o:quiz.c
	gcc -c quiz.c
time.o:time.c
	gcc -c time.c
score.o:score.c
	gcc -c score.c
minimap.o:minimap.c
	gcc -c minimap.c
control.o:control.c
	gcc -c control.c
save.o:save.c
	gcc -c save.c
