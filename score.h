	/** 
 * @file enigme.h 
*/
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
/** 
* @struct score
* @brief struct for score
*/
typedef struct score //structure de score avec deux champs sdl rect et surface
{
	SDL_Rect ps;/*!< rectangle. */ 
 	SDL_Surface *fond1;/*!< Surface. */ 
	int scores;
}score;
void init_score( score *s);
void calcule_score(score *s);
void afficherscore(score *s,SDL_Surface *screen );



