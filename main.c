#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "scrolling.h"
#include "Perfect_Collision.h"
//stop
void initialiser(Objet *map, Objet *wood, Objet *boat, Objet *map2, Objet *failed)
{
  SDL_WM_SetCaption("scrolling", NULL);

  failed->img = IMG_Load("01.png");
  failed->pos.x = 0;
  failed->pos.y = 0;

  map2->img = IMG_Load("unnamed4.jpg");
  map2->pos.x = 0;
  map2->pos.y = 0;

  map->img = IMG_Load("mask13.png");
  map->pos.x = 0;
  map->pos.y = 0;

  wood->img = IMG_Load("3.png");
  wood->pos.x = xperso;
  wood->pos.y = yperso;

  boat->img = IMG_Load("boatt.png");
  boat->pos.x = xcollision;
  boat->pos.y = ycollision;
}
//stop
void setup(SDL_Surface *screen, Objet *map, Objet *wood, Objet *boat, Objet *map2)
{

  SDL_BlitSurface(map->img, NULL, screen, &(map->pos));
  SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));

  SDL_BlitSurface(map2->img, NULL, screen, &(map->pos));
  SDL_BlitSurface(wood->img, NULL, screen, &(wood->pos));
  if(boat->pos.x >=0)
  SDL_BlitSurface(boat->img, NULL, screen, &(boat->pos));
  SDL_Flip(screen);
}

//stop
void deplacement_objet(Objet *objet, int *running)
{
  SDL_Event event;

  SDL_PollEvent(&event);
  switch (event.type)
  {
  case SDL_QUIT:
    *running = 0;
    break;
  case SDL_KEYDOWN:
    switch (event.key.keysym.sym)
    {
    case SDLK_DOWN:
      objet->pos.y += 2;
      break;
    case SDLK_UP:
      objet->pos.y -= 2;
      break;
    case SDLK_RIGHT:
      if (objet->pos.x < (1368 - objet->img->w))
        objet->pos.x += 7;
      break;
    case SDLK_LEFT:
      objet->pos.x -= 7;
      break;
    }
  }
}
//stop
void evenement(SDL_Surface *screen, Objet *boat, Objet *wood, Objet *map, int *running, SDL_Rect *pos, Objet *map2)
{
  SDL_Event event;

  SDL_PollEvent(&event);
  switch (event.type)
  {
  case SDL_QUIT:
    *running = 0;
    break;
  case SDL_KEYDOWN:

    switch (event.key.keysym.sym)

    {

    case SDLK_RIGHT: // Flèche droite

      scrolling_droit(screen, map, pos, boat);
      affichage(screen, boat, wood, map, map2);

      SDL_Flip(screen);

      break;

    case SDLK_LEFT: // Flèche gauche
      scrolling_gauche(screen, map, pos, boat);
      affichage(screen, boat, wood, map, map2);

      SDL_Flip(screen);

      break;
    }

    break;
  }
}
//stop
void scrolling_gauche(SDL_Surface *screen, Objet *map, SDL_Rect *pos, Objet *boat)
{
  if (map->pos.x >= 0)
  {
    map->pos.x -= 20;
    boat->pos.x += 20;
    (pos->x) -= 20;
  }
}
//stop
void free_memory(Objet *boat, Objet *wood, Objet *map, Objet *map2)
{
  SDL_FreeSurface(boat->img);
  SDL_FreeSurface(wood->img);
  SDL_FreeSurface(map->img);
  SDL_FreeSurface(map2->img);

  SDL_Quit();
}
//stop
int Collision_Parfaite(SDL_Surface *Background,Coordinate C)
{int collision=0;
SDL_Color color ;


SDL_GetRGB(getpixel(Background,C),Background->format,&color.r,&color.g,&color.b);

if (color.r==0 && color.g==0 && color.b==0)
{collision=1;}

return collision;

}


//stop
SDL_Color GetPixel(SDL_Surface *background ,Coordinate C)
{


SDL_Color color;
Uint32 col=0;

char* pPosition=(char*) background->pixels;
pPosition+=(background->pitch *C.Y);
pPosition+=(background->format->BytesPerPixel *C.X);
memcpy(&col,pPosition,background->format->BytesPerPixel);


SDL_GetRGB(col,background->format,&color.r, &color.g, &color.b);
return (color);




}
Uint32 getpixel(SDL_Surface *surface,Coordinate C)
{
    int bpp = surface->format->BytesPerPixel;
   
    Uint8 *p = (Uint8 *)surface->pixels + C.Y * surface->pitch + C.X * bpp;

    switch(bpp) {
    case 1:
        return *p;
        break;

    case 2:
        return *(Uint16 *)p;
        break;

    case 3:
        if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
            return p[0] << 16 | p[1] << 8 | p[2];
        else
            return p[0] | p[1] << 8 | p[2] << 16;
        break;

    case 4:
        return *(Uint32 *)p;
        break;

    default:
        return 0;      
    }
}
//stop
void affichage(SDL_Surface *screen, Objet *boat, Objet *wood, Objet *map, Objet *map2)
{
  SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));

  SDL_BlitSurface(map->img, &(map->pos), screen, NULL);
  SDL_BlitSurface(map2->img, &(map->pos), screen, NULL);
  SDL_BlitSurface(wood->img, NULL, screen, &(wood->pos));
  if(boat->pos.x >=0)
  {
SDL_BlitSurface(boat->img, NULL, screen, &(boat->pos));
  }
  
  SDL_Flip(screen) ;
}
void scrolling_droit(SDL_Surface *screen, Objet *map, SDL_Rect *pos, Objet *boat)
{
  if (map->pos.x <= mapw - 1368)
  {
    map->pos.x += 20;
    boat->pos.x -= 20;
    (pos->x) += 20;
  }
}
//stop
int main()
{
SDL_Surface *screen = NULL ;
Objet map,wood,boat,map2,failed ;
SDL_Rect pos ;
Coordinate C ;
int running=1,collision3=0,running8=1 ;
SDL_Event event ;
FILE *f ;

 f=fopen("test.txt","a") ;

 screen= SDL_SetVideoMode(width, height, 32, SDL_HWSURFACE|SDL_DOUBLEBUF  );
 
  
  initialiser (&map ,&wood ,&boat,&map2,&failed ) ;
  setup (screen,&map ,&wood,&boat,&map2) ;

  SDL_EnableKeyRepeat(10, 10);
  while(running){
      if(map.pos.x<=0 )
         {
               
          deplacement_objet(&wood,&running) ;
          setup (screen,&map,&wood,&boat,&map2) ;
          if(wood.pos.x>=500)
          {
           pos=wood.pos ;
           evenement (screen ,&boat ,&wood,&map,&running,&pos,&map2 ) ;
          }
         }

       else if(map.pos.x>=mapw-1368)
       {

            deplacement_objet(&wood,&running) ;
          

            affichage (screen,&boat ,&wood,&map,&map2) ;
              //SDL_Flip(screen) ;
            
            
            if(wood.pos.x<=500)
            {
              
              evenement (screen ,&boat ,&wood,&map,&running,&pos,&map2 ) ;
               
            }
       } 
       else
         {             
             evenement (screen ,&boat ,&wood,&map,&running ,&pos,&map2) ;
             
         } 
             C.X=pos.x+50 ;
             C.Y=pos.y+(wood.img->h /2) ;
             
             collision3=Collision_Parfaite(map.img,C) ;
             if(collision3)
              {
                fprintf(f,"c.x=%d c.y= %d",C.X,C.Y) ;
               
                while(running8){
                  SDL_BlitSurface(failed.img, NULL, screen, &(failed.pos));
                SDL_Flip(screen) ;
                SDL_WaitEvent(&event) ;
                        switch(event.type)
              {
                case SDL_QUIT:
                running8 = 0 ;
                    running=0 ;
                break;
                case SDL_KEYDOWN :
              switch(event.key.keysym.sym)
               {
                 case SDLK_ESCAPE:
                    running8=0 ;
                     affichage (screen,&boat ,&wood,&map,&map2) ;
                  break ;
               }
               break ;
              } 
                }
                affichage (screen,&boat ,&wood,&map,&map2) ; 
                SDL_Flip(screen) ;
              } 
      
     }
    free_memory (&boat ,&wood,&map,&map2) ;

    
    fclose(f) ;
    return EXIT_SUCCESS;
}
