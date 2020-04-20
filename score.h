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
typedef struct score
{
SDL_Rect ps;/*!< rectangle. */ 
 SDL_Surface *fond1;/*!< Surface. */ 
}score;
void init_score( score *s);
int afficherscore(score *s,SDL_Surface *screen,int *run  );



