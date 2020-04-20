#include "ennemi.h"

void Initialisation_Ennemi(Ennemi*e,SDL_Rect pos)
{
	e->Position.x=pos.x;
	e->Position.y=pos.y;

	e->Direction=true;
	e->Animation=0;

	e->images[0]=IMG_Load("ennemi.png");
	e->images[1]=IMG_Load("ennemi1.png");
	e->images[2]=IMG_Load("ennemi2.png");
	e->images[3]=IMG_Load("ennemi3.png");
	e->images[4]=IMG_Load("ennemi4.png");
	e->images[5]=IMG_Load("ennemi5.png");
	e->images[6]=IMG_Load("ennemi6.png");
	e->images[7]=IMG_Load("ennemi7.png");
	e->images[8]=IMG_Load("ennemi8.png");
}

void Animation_Ennemi(Ennemi *e,SDL_Surface *ecran)
{

	if(e->Direction)
	{
		SDL_BlitSurface(e->images[e->Animation], NULL, ecran, &(e->Position));
		SDL_Flip(ecran);
		SDL_Delay(200);
	}
	else
	{
		SDL_BlitSurface(e->images[8-e->Animation], NULL, ecran, &(e->Position));
		SDL_Flip(ecran);
		SDL_Delay(200);
	}
	

	e->Animation++;

	if(e->Animation==9)
	{
		e->Animation=0;
		if(e->Direction)
		{
			e->Direction=false;	
		}
		else
		{
			e->Direction=true;	
		}
	}
	if(e->Direction)
	{
		e->Position.x+=50;	
	}
	else
	{
		e->Position.x-=50;	
	}

}

void Free_Ennemi(Ennemi *e)
{
	for(int i=0;i<9;i++)
	{
		SDL_FreeSurface(e->images[i]);
	}
}

