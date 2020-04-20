#include <stdio.h>
#include "SDL/SDL.h"
#include "SDL/SDL_image.h"
#include"SDL/SDL_ttf.h"
#include "joueur.h"


void perso_Init(perso *p){
	p->image = IMG_Load("1.png");
	p->image2 = IMG_Load("2.png");
	p->position.x = 200;
	p->position.y = 350;
	p->vx = 0; 
	//p->vy = 0;
	
	for (int i = 0; i < 3; i++ ){
		p->clips[i].x = i*250;
		p->clips[i].y = 0;
		p->clips[i].w = 250;
		p->clips[i].h = 250;
	}
	 //(int i = 0; i < 3; i++ ){
		//p->clips2[i].x = 1536 -(i + 1) * 250;
		//p->clips2[i].y = 0;
		//p->clips2[i].w = 250;
		//p->clips2[i].h = 250;
	//}
	
	p->frame = 0;
     p->imagperso=IMG_Load("detective.png");
   /*p->positionperso.x = (ecran -> w / 2) - (p->positionperso-> w / 2);
     p->positionperso.y = (ecran -> h / 2) - (p->positionperso -> h / 2);*/
p->positionperso.x = 200;
	p->positionperso.y = 350;
}

void affichage(perso *p, SDL_Surface *screen)
{ 
    SDL_BlitSurface(p->image, NULL,screen, &p->position);
     SDL_BlitSurface(p->imagperso, NULL,screen, &p->positionperso);
        SDL_Flip(screen);//refraichir l ecran

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
	if(p->frame > 3) {
		 p->frame = 1;
		p->vx *= 1;
	}
	p->position.x += p->vx;
		
}

void UpdateEvent(clavier *in){
    SDL_Event event;
    while (SDL_PollEvent(&event)){
        switch (event.type){
            case SDL_KEYDOWN : // quand on presse 
                in -> key[event.key.keysym.sym] = 1; // la touche est presse
                break;
            case SDL_KEYUP : // quand on depresse
                in -> key[event.key.keysym.sym] = 0; // la touche n'est pas presse
                break;
            default :
                break;
        }
    }
}


