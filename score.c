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
s->ps.x=0;
s->ps.y=0;
s->fond1=NULL;
}
/**  * @brief  To affiche the score . 
 * @param score s 
 * @param screen surface  
 * @param run int   
 * @return int  
*/
int afficherscore(score *s,SDL_Surface *screen,int *run  )
{  char img[30];
int i;
   for(i=0;i<6;i++)
{

sprintf(img,"f%d.jpg",i);
s->fond1=IMG_Load(img);
SDL_FillRect(screen,	NULL,SDL_MapRGB(screen->format,0,0,0));
SDL_BlitSurface(s->fond1,NULL, screen,&s->ps);
SDL_Delay(500);
SDL_Flip(screen);
if(i==5)
{
SDL_BlitSurface(s->fond1,NULL, screen,&s->ps);
SDL_Delay(500);
*run=0;
}
}


return i;
}
