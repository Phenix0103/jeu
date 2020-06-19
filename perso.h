#ifndef PERSO_H_INCLUDED
#define PERSO_H_INCLUDED
#include<stdio.h>
#include<stdlib.h>
#include<SDL/SDL_image.h>
#include<SDL/SDL_ttf.h>
#include<SDL/SDL_getenv.h>
#include<SDL/SDL_mixer.h>
#include<SDL/SDL.h>

#define STAT_SOL 0
#define STAT_AIR 1


#define acceleration 0.5
typedef struct
{ 
   	int velocity;//vitesse
   	int moving;//1 if moving keyboard / 2 if mouse  / 0if break;
   	int direction;//etat
    SDL_Rect position ,position_camera;
   	SDL_Surface *image,*image2;//,image[6];
   	SDL_Rect frame;
   	int status;
    //float x,y;
    float vx,vy;
    int jump;
    int attack;
}Personnage;


void perso_Init(Personnage *p,int choixperso);
void deplacer_perso(Personnage *p,SDL_Rect camera,Uint32 dt,SDL_Rect position_souris);
void perso_Render(Personnage *p, SDL_Surface *screen);
void Saute(Personnage *p,float impulsion);
void ControleSol(Personnage *p);
void Gravite(Personnage *p,float factgravite,float factsautmaintenu);



#endif
