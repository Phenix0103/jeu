/**
* @file collisionbox.c
*/
#include"collisionbox.h"
/**
* @brief To initialize the box .
* @param b the box
* @param img the image
* @return Nothing
*/



int collision(SDL_Rect position1,SDL_Rect position2)
{
	if( (position1.x > (position2.x+position2.w)) || (position2.x > (position1.x + position1.w)) || 
	(position1.y > (position2.y + position2.h)) || (position2.y > (position1.y + position1.h)) )
	{
		return 0;//pas de collision
	}
	else
	{
		return 1;//colllision
	}
}

