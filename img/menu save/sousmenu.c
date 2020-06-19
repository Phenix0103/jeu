#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_ttf.h>
#include "headers.h"

void initsousmenu(background *bouton1,background *bouton2,background *sousbg)
{
bouton1->img=IMG_Load("save.png");
bouton1->position.x=300;
bouton1->position.y=200;
bouton2->img=IMG_Load("resume.png");
bouton2->position.x=300;
bouton2->position.y=350;
sousbg->img=IMG_Load("sousmenu.png");
sousbg->position.x=200;
sousbg->position.y=150;
}
void freesousmenu(background *bouton1,background *bouton2,background *sousbg)
{
SDL_FreeSurface(bouton1->img);
SDL_FreeSurface(bouton2->img);
SDL_FreeSurface(sousbg->img);
}
void sousmenu(SDL_Surface *ecran,background *bouton1,background *bouton2,background *sousbg,ennemie *ennemie,personnage *p,int *continuer)
{
FILE *f=NULL;
f=fopen("save.txt","a+b");
SDL_BlitSurface(sousbg->img, NULL, ecran, &sousbg->position);
SDL_BlitSurface(bouton1->img, NULL, ecran, &bouton1->position);
SDL_BlitSurface(bouton2->img, NULL, ecran, &bouton2->position);
SDL_Flip(ecran);
int continueer=1;
SDL_Event event;
while(continueer==1)
{
SDL_WaitEvent(&event);
if (event.type == SDL_QUIT)
     {
       continuer = 0;
     }
else if((event.type == SDL_MOUSEBUTTONDOWN )||(event.type == SDL_KEYDOWN))
     {
        if((event.button.button == SDL_BUTTON_LEFT )||(event.key.keysym.sym == SDLK_RETURN))
        {
if ((event.button.x > bouton1->position.x) && (event.button.x < bouton1->position.x + bouton1->position.w) && (event.button.y > bouton1->position.y) && (event.button.y < bouton1->position.y + bouton1->position.h))
{
//freesousmenu(&bouton1,&bouton2,&sousbg);
fwrite(&(*p),sizeof(personnage),1,f);
fwrite(&(*ennemie),sizeof(ennemie),1,f);
*continuer=0;
continueer=0;
}
else if ((event.button.x > bouton2->position.x) && (event.button.x < bouton2->position.x + bouton2->position.w) && (event.button.y > bouton2->position.y) && (event.button.y < bouton2->position.y + bouton2->position.h))
{
continueer=0;
}
        }
     }
}
freesousmenu(bouton1,bouton2,sousbg);
fclose(f);
}
