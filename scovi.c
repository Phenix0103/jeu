#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <time.h>
#include <unistd.h>
#include "scovi.h"
#include <stdlib.h>
void initialiserscore(score *score){

score->posScore.x=5;
score->posScore.y=5;
score->nb=00;
score->textScore=NULL;
}

void loadFont(TTF_Font **police)
{
	TTF_Init(); //== -1
		//printf("Erreur d'initialisation de TTF_Init : %s\n", TTF_GetError());

	//}else{
	*police = TTF_OpenFont("this.ttf", 50);

}

void calculerScore(score *score,int d){
if(d==1){
score->nb++;
}
}
void afficherscore(score *score , SDL_Surface *ecran,TTF_Font *police){
char afs[50];
if(score->nb<=0) score->nb=0;
	sprintf(afs,"score= %d s",score->nb);
SDL_Color couleurNoire = {0, 0, 0};
	SDL_Color couleurBlanche = {255, 255, 255};

	score->textScore = TTF_RenderText_Blended(police,afs,couleurNoire);
	SDL_SetColorKey(score->textScore, SDL_SRCCOLORKEY, SDL_MapRGB(score->textScore->format, 255, 255, 255));
	SDL_BlitSurface(score->textScore,NULL,ecran,&score->posScore);
}
void freeFont(TTF_Font **police)
{
	TTF_CloseFont(*police); /* Doit être avant TTF_Quit() */
    TTF_Quit();	
}


void initialiservie(vie *vie)
{
vie->nb=3;
vie->position.x = 0 ;
vie->position.y = 0 ;
vie->fond3 = IMG_Load("v1.png");
vie->fond2 = IMG_Load("v2.png");
vie->fond1 = IMG_Load("v3.png");
vie->fond5 = IMG_Load("GameOver1.png");
}

void affichervie(vie *vie,SDL_Surface *ecran)
{
if(vie->nb==3)
{
SDL_BlitSurface(vie->fond3,NULL, ecran,&vie->position);

}
if(vie->nb==2)
{
SDL_BlitSurface(vie->fond2,NULL, ecran,&vie->position);
}
if(vie->nb==1)
{
SDL_BlitSurface(vie->fond1,NULL, ecran,&vie->position);
}
if(vie->nb==0)
{
SDL_BlitSurface(vie->fond5,NULL, ecran,&vie->position);
vie->nb=3;

SDL_Flip(ecran);
sleep(4);

}
}
