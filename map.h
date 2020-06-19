#ifndef MAP_H_INCLUDED
#define MAP_H_INCLUDED
/**
* @struct map
* @brief struct for map
*/
typedef struct map
{
	SDL_Rect position;  /*!< Rectangle*/
	SDL_Surface *fond; /*!< Surface*/
	SDL_Surface *fondMask;  /*!< Surface*/
	int stage;
}map;


void initialiserfond(map *map);

void afficherfond(map *m,SDL_Rect camera,SDL_Surface *ecran,SDL_Rect posBlit);

void freefond(map *m);
#endif 
