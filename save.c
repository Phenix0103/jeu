#include "save.h"


void Init_Save(Save *s)
{
  s->back=IMG_Load("img/sousmenu.png");
  s->boutons[0]=IMG_Load("img/save.png");
  s->boutons[1]=IMG_Load("img/exit22.jpg");
  s->savee.x=200;
  s->savee.y=300;
  s->savee.w=170;
  s->savee.h=50;
  s->exit.x=400;
  s->exit.y=300;
  s->exit.w=170;
  s->exit.h=50;
  s->pos_menu.x=200;
  s->pos_menu.y=100;
  s->image_courrante=1;
}


void Display_Save(Save *s,SDL_Surface*ecran)
{
  SDL_BlitSurface(s->back,NULL,ecran,&(s->pos_menu));
  SDL_BlitSurface(s->boutons[0],NULL,ecran,&(s->savee));
  SDL_BlitSurface(s->boutons[1],NULL,ecran,&(s->exit));
  SDL_Flip(ecran);
}