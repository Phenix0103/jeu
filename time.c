#include <stdio.h>


#include"time.h"
/**
* @file time.c
* @brief Testing Program
* @author f4
* @version 1.0
* @date 01-06-2020
*
* Testing program for time
*
*/

/**
* @brief To initialize Time time.
* @param Time time
* @param url the url of the image
* @return Nothing
*/
void initializerTemps(Time *time){
	TTF_Init();
	time->font = TTF_OpenFont("font.ttf", 32);

	time->time = 0;

	sprintf(time->timeString,"00:00");

	SDL_Color color = {255,255,255};

	time->msg = TTF_RenderText_Solid(time->font,time->timeString,color);

}

/**
* @brief To show Time time .
* @param scren screen
* @param Time time
* @return Nothing
*/


void afficherTemps(Time *time, SDL_Surface *screen){

	SDL_Color color = {255,255,255};

	time->time++;

	if(time->time % 40 == 0){

		sprintf(time->timeString,"%02d:%02d\n",time->time/40/40,(time->time/40)%40);

		time->msg = TTF_RenderText_Solid(time->font,time->timeString,color);

	}

	SDL_BlitSurface(time->msg,NULL,screen,NULL);

}

