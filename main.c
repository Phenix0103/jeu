/** 
 * @file main.c 
 * @brief Testing Program. 
 * @author  OTAIL MARZOUK 
 * @version 0.1 
 * @date Apr 23, 2019  *
  * Testing program for SCORE
  *  */ 
 

#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "score.h"
void init_score( score *s)
{
s->ps.x=0;
s->ps.y=0;
s->fond1=NULL;
}
//stop
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
//stop
int main()
{ 
	SDL_Surface *screen;
        int i;
       score s;
int run =1;
 SDL_Init ( SDL_INIT_VIDEO ) ;
screen=SDL_SetVideoMode(1024,630,32,SDL_HWSURFACE  |  SDL_DOUBLEBUF );

 init_score( &s);
 while (run)
{
//SDL_FillRect(screen,	NULL,SDL_MapRGB(screen->format,0,0,0));
 i=afficherscore(&s,screen,&run  );
if(i==6)
run=0;
SDL_Flip(screen);

}
  SDL_FreeSurface(screen);
      SDL_Quit();
return 0;
}
