/**
* @file ennemi.h
*/
#ifndef ENNEMI_H_INCLUDED
#define ENNEMI_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
/**
* @struct Ennemi
* @brief struct for Ennemi
*/

typedef enum STATE STATE;
enum STATE{WAITING,FOLLOWING,ATTACKING};


typedef struct 
{
	SDL_Surface *images[9];
	SDL_Surface *attack;
	int Animation;
    SDL_Rect Position,Pos_real;
	bool Direction;
	STATE state;
	int Distance;
	int Distance_Attack;
	int killed;
}Ennemi;

void Initialisation_Ennemi(Ennemi *e,SDL_Rect pos);
void Affichage_Ennemi(Ennemi *e,SDL_Surface *ecran);
void Animation_Ennemi(Ennemi *e);

void AI_Ennemy(Ennemi *e,SDL_Rect pos_player,SDL_Rect pos_camera);

void Free_Ennemi(Ennemi *e);



#endif
