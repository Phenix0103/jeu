/** 
 * @file score.c 
*/
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "score.h"

/**  * @brief  To initialize the score . 
 * @param s score  
 * @return Nothing  
*/
void init_score( score *s)
{
s->ps.x=200;
s->ps.y=0;
s->fond1=NULL;
s->scores=0;
}
/**  * @brief  To affiche the score . 
 * @param score s 
 * @param screen surface  
 * @param run int   
 * @return int  
*/
void afficherscore(score *s,SDL_Surface *screen)
{  
	char img[30];
	sprintf(img,"img/f%d.jpg",s->scores);
	s->fond1=IMG_Load(img); //load chargement des photos
	SDL_BlitSurface(s->fond1,NULL, screen,&s->ps);
	SDL_Flip(screen); //rafraichissement de l'ecran
	if(s->scores>=5)
	{
		SDL_BlitSurface(s->fond1,NULL, screen,&s->ps);
	}
}

void calcule_score(score *s)
{
	s->scores++;
}