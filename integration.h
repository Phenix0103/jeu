#ifndef INTEGRATION_H_INCLUDED
#define INTEGRATION_H_INCLUDED
#include <SDL/SDL.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>

#include"perso.h"
#include"scrolling.h"
#include"map.h"
#include "vie.h"
#include "ennemi.h"
#include"collisionbox.h"
#include "Perfect_Collision.h"
#include "enig.h"
#include "quiz.h"
#include"time.h"
#include "score.h"
#include"minimap.h"
#include "control.h"
#include "save.h"

#define FSP 30

#define width 1000
#define height 600




typedef struct
{
	int boucle;
	map m;
	Personnage p;
	Scroll s;
	SDL_Rect position_souris;
	vie v;
	Ennemi e;
	int enigme;
	int loadgame;
	Save ss;
	Time time;
	score sc;
	Minimap mm;
	int choixControl; 
	int choixPlayer;
	Control c;
}Integration;


void Initialisation(Integration *I);
void NewIntegration(Integration *I,SDL_Surface *ecran);
void FreeIntegaration(Integration *I);
void DisplayIntegration(Integration *I,SDL_Surface *ecran);
void PlayIntegration(Integration *I,SDL_Surface *ecran);
void UpdateIntegration(Integration *I,Uint32 dt,SDL_Surface*ecran);


void Init_Save(Save *s);
void Display_Save(Save *s,SDL_Surface*ecran);

int Menu_Save(Save *s,Integration *I,SDL_Surface*ecran);
void Load_Game(Integration *I,FILE *f);
void Save_Game(Integration *I);

#endif
