/**
* @file ennemi.c
*/
#include "ennemi.h"
/**
* @brief To initialize the ennemi .
* @param e the ennemi
* @return Nothing
*/


void Initialisation_Ennemi(Ennemi*e,SDL_Rect pos)
{
	e->Position=pos;

	e->Pos_real=pos;

	e->Direction=true;
	e->Animation=0;


	e->images[0]=IMG_Load("img/ennemi.png");
	e->images[1]=IMG_Load("img/ennemi1.png");
	e->images[2]=IMG_Load("img/ennemi2.png");
	e->images[3]=IMG_Load("img/ennemi3.png");
	e->images[4]=IMG_Load("img/ennemi4.png");
	e->images[5]=IMG_Load("img/ennemi5.png");
	e->images[6]=IMG_Load("img/ennemi6.png");
	e->images[7]=IMG_Load("img/ennemi7.png");
	e->images[8]=IMG_Load("img/ennemi8.png");

	e->attack=IMG_Load("img/attack.png");
	
	e->state=WAITING;
	e->Distance=600;
	e->Distance_Attack=300;

	e->killed=0;
}
/**
* @brief animation ennemi  .
* @param e the ennemi
* @param ecran pour l'affichage
* @return Nothing
*/


void Affichage_Ennemi(Ennemi *e,SDL_Surface *ecran)
{
	if(e->state==ATTACKING)
	{
		SDL_BlitSurface(e->attack, NULL, ecran, &(e->Pos_real));
		SDL_Flip(ecran);
	}
	else
	{
	if(e->Direction)
	{
		SDL_BlitSurface(e->images[e->Animation], NULL, ecran, &(e->Pos_real));
		SDL_Flip(ecran);
	}
	else//ken thb trja3 3al isar
	{
		SDL_BlitSurface(e->images[8-e->Animation], NULL, ecran, &(e->Pos_real));
		SDL_Flip(ecran);
	}
	}
}

void Animation_Ennemi(Ennemi *e)
{	
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
		e->Position.x+=10;	
	}
	else
	{
		e->Position.x-=10;	
	}

}


/**
* @brief 2éme tache intlig artif .
* @param e the ennemi
* @param ecra
* @return Nothing
*/
// zedtha tb3a prototype 2 'intig artif"
void AI_Ennemy(Ennemi *e,SDL_Rect pos_player,SDL_Rect pos_camera)
{
	int distance =pos_player.x - e->Position.x;

	if( (distance>0) && (distance< e->Distance_Attack))  //0<distance<300
	{
		e->state=ATTACKING;
	}
	else if ((distance<0) && (distance > (- e->Distance_Attack) )) //-300<distance<0
	{
		e->state=ATTACKING;
	}
	else if( (distance>e->Distance_Attack) && (distance< e->Distance))  //0<distance<300
	{
		e->state=FOLLOWING;
	}
	else if ((distance<(-e->Distance_Attack)) && (distance > (- e->Distance) )) //-300<distance<0
	{
		e->state=FOLLOWING;
	}
	else
	{
		e->state=WAITING;	
	}

	switch(e->state)
	{
		case WAITING:
		{
			Animation_Ennemi(e);
			break;
		}
		case FOLLOWING:
		{		
			if(distance<0)
			{
				e->Position.x-=15;
			}
			else
			{
				e->Position.x+=15;
			}
			break;
		}
		case ATTACKING:
		{		
			if(distance<0)
			{
				e->Position.x-=15;
			}
			else
			{
				e->Position.x+=15;
			}
			break;
		}
	}
	e->Pos_real.x=e->Position.x - pos_camera.x;
    e->Pos_real.y=e->Position.y;

}
/**
* @brief free ennemi .
* @param e the ennemi
* @return Nothing
*/

void Free_Ennemi(Ennemi *e)
{
	for(int i=0;i<9;i++)
	{
		SDL_FreeSurface(e->images[i]);
	}
}

