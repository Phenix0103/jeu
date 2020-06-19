/**
* @file enig.h
*/
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
/**
* @struct enigme
* @brief struct for enigme
*/
typedef struct
{
 SDL_Surface * img;/*!< surface. */
 SDL_Rect 	p; /*!< peciser la position de l'image par rapport la surface*/
}enigme;

void init_enigme(enigme * e) ;
void  generate_afficher (SDL_Surface * screen  , char image [],enigme *e,int *alea) ;
int solution_e (char image []) ;
int resolution (int * running,int *run);
int afficher_resultat (SDL_Surface * screen,int s,int r,enigme *en) ;
int jouer_enigme(SDL_Surface *screen);
