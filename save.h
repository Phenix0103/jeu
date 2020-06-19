#ifndef SAVE_H_INCLUDED
#define SAVE_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

typedef struct 
{
	SDL_Surface *back;
    SDL_Surface *boutons[2];
    SDL_Rect savee,exit;
    SDL_Rect pos_menu;
    int image_courrante;
}Save;

void Init_Save(Save *s);
void Display_Save(Save *s,SDL_Surface*ecran);


#endif