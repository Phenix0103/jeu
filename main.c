#include <stdio.h>
#include <stdlib.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include "SDL/SDL_getenv.h"
//#include "SDL/SDL_mixer"
#include"SDL/SDL_ttf.h"
#include "joueur.h"

int main(){
	SDL_Surface *screen, *detec;
	SDL_Event e;
clavier in;
SDL_Rect positiondetec;
	screen = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE);
detec = IMG_Load("detective.png");
	perso p;
	perso_Init(&p);
	
 do {
        UpdateEvent(&in); // saisie clavier
        if (in.key[SDLK_UP]){
            positiondetec.y -= 1;
        }
        if (in.key[SDLK_DOWN]){
            positiondetec.y += 1;
        }
        if (in.key[SDLK_RIGHT]){
            positiondetec.x += 1;        }
        if (in.key[SDLK_LEFT]){
            positiondetec.x -= 1;
        }
          affichage(&p,screen);
} while (!in.key[SDLK_ESCAPE]);
  
	int running = 1;

	while(running){
		while(SDL_PollEvent(&e)){
			if(e.type == SDL_QUIT || e.key.keysym.sym == SDLK_ESCAPE){
				running = 0;
			}
		}

		SDL_FillRect(screen,NULL,0x000000);

		perso_Render(&p,&screen);

		SDL_Delay(25);
		SDL_Flip(screen);
	}
SDL_FreeSurface(detec);	
	SDL_Quit();
}
