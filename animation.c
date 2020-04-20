#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "animation.h"

void perso_Init(perso *p){
	p->image = IMG_Load("1.png");
	p->image2 = IMG_Load("2.png");
	p->position.x = 200;
	p->position.y = 350;
	p->vx = 0; 
	//p->vy = 0;
	
	for (int i = 0; i < 5; i++ ){
		p->clips[i].x = i*250;
		p->clips[i].y = 0;
		p->clips[i].w = 250;
		p->clips[i].h = 250;
	}
	 //(int i = 0; i < 5; i++ ){
		//p->clips2[i].x = 1536 -(i + 1) * 250;
		//p->clips2[i].y = 0;
		//p->clips2[i].w = 250;
		//p->clips2[i].h = 250;
	//}
	
	p->frame = 0;
}

void perso_Render(perso *p, SDL_Surface **screen){
	if(p->vx >= 0){
		SDL_BlitSurface(p->image,&p->clips[(int) p->frame],*screen,&p->position);
	}
else{
	SDL_BlitSurface(p->image,&p->clips[(int) p->frame],*screen,&p->position);
		//SDL_BlitSurface(p->image2,&p->clips2[(int) p->frame],*screen,&p->position);

	}

	p->frame += 0.15f;
	if(p->frame > 5) {
		 p->frame = 1;
		p->vx *= 1;
	}
	p->position.x += p->vx;
		
}
