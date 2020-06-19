#ifndef INTEGRATIONM_H_INCLUDED
#define INTEGRATIONM_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include"integration.h"
/*#include"perso.h"
#include"scrolling.h"
#include"map.h"
#include "vie.h"
#include "ennemi.h"
#include"collisionbox.h"
#include "Perfect_Collision.h"
#include "enig.h"
#include "quiz.h"

#define FSP 10

#define width 500
#define height 600*/

#define widthm 900
#define heightm 600

typedef struct
{
	int boucle;
	int enigme;
	map m;
	Time time;
	score sc;
	/************************************/
	Personnage p;
	Scroll s;
	SDL_Rect position_souris;
	vie v;
	Ennemi e;

	/***********************************/
	Personnage p1;
	Scroll s1;
	vie v1;
	Ennemi e1;

}Integrationm;


void Initialisationm(Integrationm *I);
void NewIntegrationm(Integrationm *I,SDL_Surface *ecran);
void FreeIntegarationm(Integrationm *I);
void DisplayIntegrationm(Integrationm *I,SDL_Surface *ecran);
void PlayIntegrationm(Integrationm *I,SDL_Surface *ecran);
void UpdateIntegrationm(Integrationm *I,Uint32 dt,SDL_Surface*ecran);

#endif
