/**
* @file enigf.c
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <SDL/SDL.h>
#include <SDL/SDL_mixer.h>
#include <SDL/SDL_image.h>
#include "enig.h"
/**
* @brief initialiser enigme
* @param e enigme
* @return Nothing
*/
void init_enigme(enigme * e)
{
	e->p.x=0;
	e->p.y=0;	
	e->img=NULL;


}
/**
* @brief afficher
* @param screen the screen
* @param image
* @param e enigme
* @return Nothing
*/
 void generate_afficher (SDL_Surface * screen  , char image [],enigme *e,int *alea)
{ 
	int test=*alea ;
do{
 *alea = 1+ rand()%3;
}while(*alea==test) ;
 sprintf(image ,"img/%d.png",*alea);
e->img = IMG_Load(image);// charger l'image
 SDL_BlitSurface(e->img,NULL,screen,&(e->p)) ;//coller l'image sur la surface 
  SDL_Flip(screen) ;//raffraichir l'ecran
}
 
 int solution_e (char image []) // declaration solution 
 {
 	int solution =0 ;
 	
 	if(strcmp(image,"img/1.png")==0)
 	{
     solution =1 ;
 	}
 	else  	if(strcmp(image,"img/2.png")==0)
 	{
 		solution =2;

 	}
 	else 	if(strcmp(image,"img/3.png")==0)
 	{
 		solution =1;	
 	}
 	return solution;
 }

int resolution (int * running,int *run )
{
	SDL_Event event ;//declarer une variable de type SDL_Event
  int r=0 ;
	SDL_PollEvent(&event);// a l'ecoute
	switch(event.type)
	{
		  case SDL_QUIT:
			        *running= 0 ;
                *run = 0;
				break ;

       case SDL_KEYDOWN : // les evenements clavier
            switch( event.key.keysym.sym )
                {
			  case  SDLK_a: 
			  r= 1;
			   break ;
			   case  SDLK_b :
			   r= 2;
			   break;
			  // case SDLK_e: 
			  // r=3 ;
			  // break;
			    }
       break ;

                 
	}
  return r ;
}
 /**
* @brief afficher resultat
* @param screen the screen
* @param s entier
* @param r entier
* @param en enigme
* @return Nothing
*/
 int afficher_resultat (SDL_Surface * screen,int s,int r,enigme *en)
 {
 
 	if (r==s)
 	{
 		en->img=IMG_Load("img/00.jpg");//afficher image past
 		SDL_BlitSurface(en->img, NULL, screen, &(en->p)) ;
        SDL_Flip(screen);
        SDL_Delay(2000);
        return 1;
 	}
 	else
 	{
 		en->img=IMG_Load("img/11.jpg"); //afficher l'image falled
 		SDL_BlitSurface(en->img, NULL, screen, &(en->p)) ;
        SDL_Flip(screen);//raffraichir l'affichage
        SDL_Delay(2000);
        return 0;
 	}
 }
 

int jouer_enigme(SDL_Surface *screen)
{
	enigme  e;
	int s,r,run =1,running=1,alea;
	char image[30]="";
	SDL_Event event;
    srand(time(NULL));
    int verif=0;
   
	 screen=SDL_SetVideoMode(700,500,32,SDL_HWSURFACE  |  SDL_DOUBLEBUF );
	 init_enigme(&e);
	
	 while (run)
	 {
	    running=1,r=0 ;
	     SDL_PollEvent(&event);
           switch(event.type)
            {
              case SDL_QUIT:
                run = 0;
			  break ;
            }	
        	
      generate_afficher ( screen  , image ,&e,&alea) ;
	        

      s=solution_e (image );
			do{
			r=resolution (&running,&run);
			}while((r>3 || r<1) && running!=0) ;
			
			
      while(running){
		return afficher_resultat (screen,s,r,&e) ;	       
    } 	
   }
      SDL_FreeSurface(screen);
      SDL_Quit();
	return 0;
}