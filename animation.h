#pragma once


typedef struct perso{

	int x,y,vx,vy;
	SDL_Surface *image, *image2;
	SDL_Rect position;
	SDL_Rect clips[5];
	//SDL_Rect clips2[5];
	float frame;
} perso;

void perso_Init(perso *p);
void perso_Render(perso *p, SDL_Surface **screen);

