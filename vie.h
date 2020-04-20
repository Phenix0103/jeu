/** 
 * @file vie.h 
*/
#ifndef VIE_H_
#define VIE_H_
/**  
     * @struct vie
     * @brief struct for vie
*/
typedef struct vie
{
	
	SDL_Rect position;/*!< rectangle. */ 
	SDL_Surface *fond1;/*!< surface. */ 
	SDL_Surface *fond2;/*!< surface. */ 
	SDL_Surface *fond3;/*!< surface. */ 
	SDL_Surface *fond4;/*!< surface. */ 
	SDL_Surface *fond5;/*!< surface. */ 
        SDL_Surface *fond6;/*!< surface. */ 
}vie;

void initialiservie(vie *vie);
void affichervie(vie *vie,SDL_Rect *posj , SDL_Rect posobj,SDL_Surface *ecran , int *i);
int collisionbb( SDL_Rect posj , SDL_Rect posobj );
#endif
