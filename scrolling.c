#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include "scrolling.h"

void initialiser(Objet *map, Objet *wood, Objet *boat, Objet *map2, Objet *failed)
{
  SDL_WM_SetCaption("scrolling", NULL);

  failed->img = IMG_Load("01.png");
  failed->pos.x = 0;
  failed->pos.y = 0;

  map2->img = IMG_Load("unnamed4.jpg");
  map2->pos.x = 0;
  map2->pos.y = 0;

  map->img = IMG_Load("mask13.png");
  map->pos.x = 0;
  map->pos.y = 0;

  wood->img = IMG_Load("3.png");
  wood->pos.x = xperso;
  wood->pos.y = yperso;

  boat->img = IMG_Load("boatt.png");
  boat->pos.x = xcollision;
  boat->pos.y = ycollision;
}
void setup(SDL_Surface *screen, Objet *map, Objet *wood, Objet *boat, Objet *map2)
{

  SDL_BlitSurface(map->img, NULL, screen, &(map->pos));
  SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));

  SDL_BlitSurface(map2->img, NULL, screen, &(map->pos));
  SDL_BlitSurface(wood->img, NULL, screen, &(wood->pos));
  if(boat->pos.x >=0)
  SDL_BlitSurface(boat->img, NULL, screen, &(boat->pos));
  SDL_Flip(screen);
}

void affichage(SDL_Surface *screen, Objet *boat, Objet *wood, Objet *map, Objet *map2)
{
  SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 255, 255, 255));

  SDL_BlitSurface(map->img, &(map->pos), screen, NULL);
  SDL_BlitSurface(map2->img, &(map->pos), screen, NULL);
  SDL_BlitSurface(wood->img, NULL, screen, &(wood->pos));
  if(boat->pos.x >=0)
  {
SDL_BlitSurface(boat->img, NULL, screen, &(boat->pos));
  }
  
  SDL_Flip(screen) ;
}
void scrolling_droit(SDL_Surface *screen, Objet *map, SDL_Rect *pos, Objet *boat)
{
  if (map->pos.x <= mapw - 1368)
  {
    map->pos.x += 20;
    boat->pos.x -= 20;
    (pos->x) += 20;
  }
}
void scrolling_gauche(SDL_Surface *screen, Objet *map, SDL_Rect *pos, Objet *boat)
{
  if (map->pos.x >= 0)
  {
    map->pos.x -= 20;
    boat->pos.x += 20;
    (pos->x) -= 20;
  }
}

void evenement(SDL_Surface *screen, Objet *boat, Objet *wood, Objet *map, int *running, SDL_Rect *pos, Objet *map2)
{
  SDL_Event event;

  SDL_PollEvent(&event);
  switch (event.type)
  {
  case SDL_QUIT:
    *running = 0;
    break;
  case SDL_KEYDOWN:

    switch (event.key.keysym.sym)

    {

    case SDLK_RIGHT: // Flèche droite

      scrolling_droit(screen, map, pos, boat);
      affichage(screen, boat, wood, map, map2);

      SDL_Flip(screen);

      break;

    case SDLK_LEFT: // Flèche gauche
      scrolling_gauche(screen, map, pos, boat);
      affichage(screen, boat, wood, map, map2);

      SDL_Flip(screen);

      break;
    }

    break;
  }
}
void deplacement_objet(Objet *objet, int *running)
{
  SDL_Event event;

  SDL_PollEvent(&event);
  switch (event.type)
  {
  case SDL_QUIT:
    *running = 0;
    break;
  case SDL_KEYDOWN:
    switch (event.key.keysym.sym)
    {
    case SDLK_DOWN:
      objet->pos.y += 2;
      break;
    case SDLK_UP:
      objet->pos.y -= 2;
      break;
    case SDLK_RIGHT:
      if (objet->pos.x < (1368 - objet->img->w))
        objet->pos.x += 7;
      break;
    case SDLK_LEFT:
      objet->pos.x -= 7;
      break;
    }
  }
}

void free_memory(Objet *boat, Objet *wood, Objet *map, Objet *map2)
{
  SDL_FreeSurface(boat->img);
  SDL_FreeSurface(wood->img);
  SDL_FreeSurface(map->img);
  SDL_FreeSurface(map2->img);

  SDL_Quit();
}