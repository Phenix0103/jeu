#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include <unistd.h>
#include "map.h"

/**
* @file map.c
* @brief Testing Program
* @author f4
* @version 1.0
* @date 01-06-2020
*
* Testing program for map
*
*/

/**
* @brief To initialize map map.
* @param map map
* @param url the url of the image
* @return Nothing
*/
void initialiserfond(map *map)
{
map->stage=1;
map->fond = IMG_Load("img/map.png");
map->fondMask = IMG_Load("img/mask.png");
}

/**
* @brief To show map map .
* @param scren ecran
* @param map map
* @return Nothing
*/
void afficherfond(map *m,SDL_Rect camera,SDL_Surface *ecran,SDL_Rect posBlit)
{
 if(m->stage==1){
 	SDL_BlitSurface(m->fond,&camera, ecran,&posBlit);
 }


}


void freefond(map *m)
{
	SDL_FreeSurface(m->fond);
}



