#ifndef COLLISIONBOX_H_INCLUDED
#define COLLISIONBOX__H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>


typedef struct 
{
	SDL_Surface *Image;
    SDL_Rect position;
	bool Direction;
	bool Collision;
}Box;

void Initialisation_Box(Box *b,SDL_Rect pos,SDL_Surface *img);
void Deplacement(Box *b);
bool collision (Box *b1,Box *b2);
void Free_Box(Box *b);

#endif
