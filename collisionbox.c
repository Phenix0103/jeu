#include"collisionbox.h"


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

void Free_Box(Box *b)
{
	SDL_FreeSurface(b->Image);
}