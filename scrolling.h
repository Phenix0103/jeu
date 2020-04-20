#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#define width 1360
#define height 613

#define mapw 5250
#define maph 613

#define xperso 0
#define yperso 768-250

#define xcollision 4000
#define ycollision 480


typedef struct 
{
  SDL_Surface *img ;
  SDL_Rect pos ; 

}Objet;



void initialiser (Objet *map ,Objet *wood ,Objet *boat,Objet *map2, Objet *failed )  ;
void setup (SDL_Surface *screen, Objet *map ,Objet *wood, Objet *boat,Objet *map2) ;
void affichage (SDL_Surface *screen ,Objet *boat ,Objet *wood,Objet *map,Objet *map2) ;
void scrolling_droit (SDL_Surface *screen , Objet *map,SDL_Rect *pos,Objet *boat) ;
void scrolling_gauche (SDL_Surface*screen , Objet *map,SDL_Rect *pos,Objet *boat) ;
void evenement (SDL_Surface *screen ,Objet *boat ,Objet *wood,Objet *map,int *running,SDL_Rect *pos,Objet *map2  ) ;
void free_memory (Objet *boat ,Objet *wood,Objet *map,Objet *map2) ;
void deplacement_objet(Objet *objet,int *running) ;
