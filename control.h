#ifndef CONTROL_H_INCLUDED
#define CONTROL_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <stdbool.h>
#include <SDL/SDL_ttf.h>



typedef struct Control
{
	int controls[5];
}Control;

void Init_Control(Control *c);
void Save_Control(Control c);
int select_settings(int i,Control *tmp);
int menukeyboard(SDL_Surface *ecran);

#endif
