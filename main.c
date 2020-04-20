#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "collisionbox.h"
//stop
void Initialisation_Box(Box *b,SDL_Rect pos,SDL_Surface *img)
{
	b->position.x=pos.x;
	b->position.y=pos.y;
	b->position.w=pos.w;
	b->position.h=pos.h;
	b->Direction=true;
	b->Collision=false;
	b->Image=img;
}
 //stop
bool collision (Box *b1,Box *b2)
{
	if( (b1->position.x > (b2->position.x+b2->position.w)) || (b2->position.x > (b1->position.x + b1->position.w)) || 
	(b1->position.y > (b2->position.y + b2->position.h)) || (b2->position.y > (b1->position.y + b1->position.h)) )
	{
		return false;
	}
	else
	{
		return true;
	}
}
//stop
void Free_Box(Box *b)
{
	SDL_FreeSurface(b->Image);
}
//stop
int main()
{
	SDL_Surface *ecran;
	SDL_Surface *background;
	background=IMG_Load("arrierePlan.png");
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		fprintf(stderr, "Echec \n");
		return 1;
	}
	
	ecran = SDL_SetVideoMode(1200, 800, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

	Box b1,b2;
	SDL_Rect pos1={100,650,150,150};/*  +++++++++++++++++++   */
	SDL_Rect pos2={600,650,150,150};

	SDL_Surface *img1,*img2;
	img1=IMG_Load("C.png");/*  +++++++++++++++++++   */
	img2=IMG_Load("ennemi.png");

	Initialisation_Box(&b1,pos1,img1);
	Initialisation_Box(&b2,pos2,img2);
	SDL_Event event;
	bool boucle=true,coll=false;

	while(boucle)
	{
		SDL_BlitSurface(background,NULL,ecran,NULL);
		SDL_BlitSurface(b1.Image,NULL,ecran,&b1.position);
		SDL_BlitSurface(b2.Image,NULL,ecran,&b2.position);
		SDL_Flip(ecran);
		coll=collision (&b1,&b2);

		SDL_EnableKeyRepeat(5,5);
		SDL_PollEvent(&event);
		if(coll)
		{
			coll=false;
			if(b1.Direction)
			{
				b1.position.x--;
			}
			else
			{
				b1.position.x++;
			}
		}
		else
		{
		switch (event.type)
		{ 
			case SDL_KEYDOWN:
			{
				if(event.key.keysym.sym==SDLK_RIGHT)
				{
					b1.position.x+=10;
					b1.Direction=true;
				}
				if(event.key.keysym.sym==SDLK_LEFT)
				{
					b1.position.x-=10;
					b1.Direction=false;
				}
				if(event.key.keysym.sym==SDLK_UP)
				{
					b1.position.y-=10;
				}
				if(event.key.keysym.sym==SDLK_DOWN)
				{
					b1.position.y+=10;
				}
				break;
			}
			case SDL_QUIT:
			{
				Free_Box(&b1);
				Free_Box(&b2);			
				SDL_Quit();
			}
		}
		}
		
	}
	Free_Box(&b1);
	Free_Box(&b2);			
	SDL_Quit();
	exit(0);

	return EXIT_SUCCESS;
	return 0;
}
