/**
* @file scrolling.h
*/
#ifndef SCROLLING_H_INCLUDED
#define SCROLLING_H_INCLUDED

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>


#define mapw 8000
#define maph 800



typedef struct 
{
  SDL_Rect pos; 
}Scroll;



void scrolling_initialiser(Scroll *s,SDL_Rect position_perso,int width,int height);

void scrolling_update(Scroll *s,SDL_Rect position_perso,int width,int height);

#endif