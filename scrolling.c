/**
* @file scrolling.c
*/
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "scrolling.h"
/**
* @brief To initialize background+perso.
* @param map the background
* @param wood personnage
* @param boat obstacle
* @param map2 backg2
* @param failed variable obstacle 
* @param 01.png the name of the image
* @param unnamed4.jp
* @return Nothing
*/
void scrolling_initialiser(Scroll *s,SDL_Rect position_perso,int width,int height)
{
  SDL_WM_SetCaption("scrolling", NULL);
  s->pos.x=position_perso.x-(width*.5);
  s->pos.y=0;
  s->pos.w=width;
  s->pos.h=height;
  
}
/**
* @brief affichage .
* @param  screen the screen
* @param map backg
* @param wood perso
* @return Nothing
*/

void scrolling_update(Scroll *s,SDL_Rect position_perso,int width,int height)
{
  s->pos.x=(position_perso.x + position_perso.w*.5)-(width*.5);
  
  if(s->pos.x >=mapw-width)
        {
            s->pos.x=mapw-width;
        }
      if(s->pos.x<=0)
      {
        s->pos.x=0;
      }
}
