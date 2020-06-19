#ifndef VIE_H_INCLUDED
#define VIE_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_getenv.h>
#include<SDL/SDL_mixer.h>
#include<SDL/SDL.h>
/**
* @struct vie
* @brief struct for vie 
*/

typedef struct vie
{
	int nb;
	SDL_Rect position; /*!< Rectangle*/
	SDL_Surface *fond1; /*!< Surface*/
	SDL_Surface *fond2; /*!< Surface*/
	SDL_Surface *fond3; /*!< Surface*/
	SDL_Surface *fond4; /*!< Surface*/
	SDL_Surface *fond5; /*!< Surface*/
}vie;

void initialiservie(vie *vie);
void affichervie(vie *vie,SDL_Surface *ecran);

#endif
