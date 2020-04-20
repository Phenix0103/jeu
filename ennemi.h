#ifndef ENNEMI_H_INCLUDED
#define ENNEMI_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

typedef struct 
{
	SDL_Surface *images[9];
	int Animation;
    SDL_Rect Position;
	bool Direction;
}Ennemi;

void Initialisation_Ennemi(Ennemi *e,SDL_Rect pos);
void Animation_Ennemi(Ennemi *e,SDL_Surface *ecran);
void Free_Ennemi(Ennemi *e);



#endif
