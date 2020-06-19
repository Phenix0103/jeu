/**
* @file collisionbox.h
*/
#ifndef COLLISIONBOX_H_INCLUDED
#define COLLISIONBOX__H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

/**
* @struct box
* @brief struct for box
*/


int collision(SDL_Rect pos1,SDL_Rect pos2);

#endif
