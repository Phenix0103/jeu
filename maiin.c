#include<SDL/SDL.h>
#include<SDL/SDL_ttf.h>
#include"time.h"

void initializerTemps(Time *time){

	time->font = TTF_OpenFont("font.ttf", 32);

	time->time = 0;

	sprintf(time->timeString,"00:00");

	SDL_Color color = {255,255,255};

	time->msg = TTF_RenderText_Solid(time->font,time->timeString,color);

}




void afficherTemps(Time *time, SDL_Surface **screen){

	SDL_Color color = {255,255,255};

	time->time++;

	if(time->time % 40 == 0){

		sprintf(time->timeString,"%02d:%02d\n",time->time/40/40,(time->time/40)%40);

		time->msg = TTF_RenderText_Solid(time->font,time->timeString,color);

	}

	SDL_BlitSurface(time->msg,NULL,*screen,NULL);

}


int main()

{

SDL_Surface *screen;




	SDL_Init(SDL_INIT_EVERYTHING);

	TTF_Init();

	

	Time time;

	initializerTemps(&time);

	screen = SDL_SetVideoMode(800,600,32,SDL_HWSURFACE);

	int running = 1;

	SDL_Event event;

	while(running){

		while(SDL_PollEvent(&event))

		{




			if(event.type==SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)){

				running = 0;

			}




		}




			SDL_FillRect(screen,NULL,0x000000);

			afficherTemps(&time,&screen);

			SDL_Flip(screen);

			SDL_Delay(16);

	}

	

	SDL_Quit();

}

