/** 
 * @file obj.c 
*/
#include <stdio.h>
#include  <stdlib.h>
#include  <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "obj.h"

/**  * @brief  afficher obj . 
 * @param obj
 * @param screen    
 * @return Nothing  
*/
void affichageObj ( Objet obj , SDL_Surface *screen) 
{

SDL_BlitSurface(obj.image, NULL, screen, &(obj.position));
SDL_Flip(screen);

}
