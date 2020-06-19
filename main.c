#include <stdio.h>
#include <stdlib.h>
#include <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include <SDL/SDL_mixer.h>
#include <stdbool.h>
#include <SDL/SDL_ttf.h>
#include <SDL/SDL_rotozoom.h>
#include "control.h"
#include "integration.h"
#include "integrationm.h"


void MenuchoixControl(SDL_Surface *screen,int choixplayer)
{
	SDL_Event event3;
    int boucle=1;
    SDL_Surface *images[4],*background;
    int selected_img=1;
    background=IMG_Load("ah.png");
    images[1]=IMG_Load("./csm/1.png");
    images[2]=IMG_Load("./csm/2.png");
    images[3]=IMG_Load("./csm/3.png");

    SDL_Rect posBlit={100,200};
  	SDL_EnableKeyRepeat(0,0);
    while(boucle==1)
    {
    	
    	SDL_PollEvent(&event3);
    	SDL_BlitSurface(background,NULL,screen,NULL);
    	SDL_BlitSurface(images[selected_img],NULL,screen,&posBlit);
    	SDL_Flip(screen);
    	switch (event3.type)
        { 
            case SDL_KEYDOWN:
            {
            	if(event3.key.keysym.sym==SDLK_RIGHT)
                {
                	selected_img++;
                }
                else if(event3.key.keysym.sym==SDLK_LEFT)
                {
                	selected_img--;
                }
                else if(event3.key.keysym.sym==SDLK_RETURN)
                {
                	if(selected_img==1)
                	{
                		Integration I;
                		I.choixControl=1;
                		I.choixPlayer=choixplayer;
						screen = SDL_SetVideoMode(1000, 600,32, SDL_HWSURFACE | SDL_DOUBLEBUF);
						NewIntegration(&I,screen);
						screen = SDL_SetVideoMode(1080,720,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
						boucle=0;
                	}
                	else
                	{
                		Integration I;
                		I.choixControl=2;
                		I.choixPlayer=choixplayer;
                		screen = SDL_SetVideoMode(1000, 600,32, SDL_HWSURFACE | SDL_DOUBLEBUF);
						NewIntegration(&I,screen);
						screen = SDL_SetVideoMode(1080,720,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
						boucle=0;
                	}
                }
                else if(event3.key.keysym.sym==SDLK_ESCAPE)
                {
                	boucle=0;
                }
                break;
            }
        }
        if(selected_img>3)
        {
        	selected_img=1;
        }
        else if(selected_img<1)
        {
        	selected_img=0;
        }
    }
}

int menuaboutcovid(SDL_Surface *ecran)
{
	SDL_Event event3;
    int boucle=1;
    SDL_Surface *images[4];
    int selected_img=1;
    images[1]=IMG_Load("./aboutcovid/1.png");
    images[2]=IMG_Load("./aboutcovid/2.png");
    images[3]=IMG_Load("./aboutcovid/3.png");
    while(boucle==1)
    {
    	
    	SDL_PollEvent(&event3);
    	SDL_BlitSurface(images[selected_img],NULL,ecran,NULL);
    	SDL_Flip(ecran);
    	switch (event3.type)
        { 
            case SDL_KEYDOWN:
            {
                if(event3.key.keysym.sym==SDLK_RETURN)
                {
                	selected_img++;
                	boucle=0;
                }
                else if(event3.key.keysym.sym==SDLK_ESCAPE)
                {
                	boucle=0;
                	return 0;
                }
                break;
            }
        }
        if(selected_img==4)
        {
        	boucle=0;
        	return 0;
        }
        return 0;
    }
}




SDL_Surface *loadimage(char name[]) 
{ 
	SDL_Surface* loadedImage = NULL; 
	SDL_Surface* optimizedImage = NULL;
	loadedImage = IMG_Load(name);
	if( loadedImage != NULL ) 
	{ 
		optimizedImage = SDL_DisplayFormatAlpha( loadedImage ); 
		SDL_FreeSurface( loadedImage ); 
	}
	return optimizedImage; 
}
//stoooop
void afficherMenu(SDL_Surface* screen,SDL_Surface *bg[],SDL_Surface *buttons[],SDL_Surface *settings[],SDL_Surface *levels[],SDL_Surface *players[],SDL_Surface *csm[],SDL_Surface *logo,SDL_Surface *Breturn,SDL_Surface *black,SDL_Rect posButtons,SDL_Rect posLevels,SDL_Rect posLogo,SDL_Rect posSettings,SDL_Rect posPlayers,SDL_Rect posCsm,SDL_Rect posBReturn,SDL_Rect posBlack1,SDL_Rect posBlack2,int menu,int level,int nbg,int nbut,int nset,int nlevel,int nplayer,int nCsm,SDL_Rect posControl,SDL_Surface*covid,SDL_Rect posCovid)
{
	SDL_BlitSurface( bg[nbg] , NULL , screen , NULL);
	
	if (menu==1)	//main
	{
		SDL_BlitSurface( logo , NULL , screen , &posLogo);
		SDL_BlitSurface(buttons[nbut],NULL,screen,&posButtons);
		SDL_BlitSurface(covid,NULL,screen,&posCovid);
	}

	if (menu==2) //settings
	{
		SDL_BlitSurface(settings[nset],NULL,screen,&posSettings);
		SDL_BlitSurface(settings[4],NULL,screen,&posControl);
	}

	if (menu==3)  //levels menu
	{		
		SDL_BlitSurface(levels[nlevel],NULL,screen,&posLevels);
		SDL_BlitSurface(Breturn,NULL,screen,&posBReturn);
		if (level==1)
		{
			SDL_BlitSurface(black,NULL,screen,&posBlack1);
			SDL_BlitSurface(black,NULL,screen,&posBlack2);
		}
		if (level==2)
			SDL_BlitSurface(black,NULL,screen,&posBlack2);
	}

	if (menu==4)  //players selection
	{		
		SDL_BlitSurface(players[nplayer],NULL,screen,&posPlayers);
		SDL_BlitSurface(Breturn,NULL,screen,&posBReturn);
	}

	if (menu==5)  //clavier souris manette
	{		
		SDL_BlitSurface(csm[nCsm],NULL,screen,&posCsm);
		SDL_BlitSurface(Breturn,NULL,screen,&posBReturn);
	}
}
//stoooop
void updateSouris(SDL_Event event,int *done,int *menu,int *selection,int level,int *multij,int *game,int *nbg,int *nbut,int *nset,int *nlevel,int *nplayer,int *nCsm,Mix_Chunk *effect,int *player,int *Csm,int *time,SDL_Surface *screen,SDL_Surface *buttons[],SDL_Surface *settings[],SDL_Surface *levels[],SDL_Surface *players[],SDL_Surface *csm[])
{
	switch(*menu)
	{
		case 1: //main
			if (event.type == SDL_MOUSEMOTION)
			{
				if( ( event.motion.x > ((screen->w/2)-(buttons[0]->w/2)) ) && (event.motion.x < ((screen->w/2)-(buttons[0]->w/2)+(buttons[0]->w) ) ) && (event.motion.y>273) && (event.motion.y<273+62) )
				{
					*nbut=1;
					
				}
			}
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				if( ( event.motion.x > ((screen->w/2)-(buttons[0]->w/2)) ) && (event.motion.x < ((screen->w/2)-(buttons[0]->w/2)+(buttons[0]->w) ) ) && (event.motion.y>273) && (event.motion.y<273+62) )
				{
					*menu=3;
				}
			}

			if (event.type == SDL_MOUSEBUTTONUP)
			{
				if( ( event.motion.x > 887 && event.motion.x < 987 ) && (event.motion.y>623 && event.motion.y<673) )
				{
					if(event.button.button == SDL_BUTTON_LEFT)
					{
						printf("covid.\n");
						bool test=1;
						while(test==1)
						{
							printf("%d.\n",test);
							test=menuaboutcovid(screen);
						}
					}
				}
			}
			if(event.type == SDL_MOUSEMOTION)
            {
                printf("Souris en position %d %d\n",event.motion.x, event.motion.y);
            }
			///////////////////////////

			if (event.type == SDL_MOUSEMOTION)
			{
				if(event.motion.x>(screen->w/2)-(buttons[0]->w/2) && (event.motion.x< ((screen->w/2)-(buttons[0]->w/2)+(buttons[0]->w) ) ) && (event.motion.y>273+62+30) && (event.motion.y<273+62+30+62))
				{
					*nbut=2;
					
				}
			}
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				if(event.motion.x>(screen->w/2)-(buttons[0]->w/2) && (event.motion.x< ((screen->w/2)-(buttons[0]->w/2)+(buttons[0]->w) ) ) && (event.motion.y>273+62+30) && (event.motion.y<273+62+30+62))
				{
					*menu=2;
				}
			}
			////////////////////////////
			
			if (event.type == SDL_MOUSEMOTION)
			{
				if(event.motion.x>(screen->w/2)-(buttons[0]->w/2) && (event.motion.x< ((screen->w/2)-(buttons[0]->w/2)+(buttons[0]->w) ) ) && (event.motion.y>273+62*2+30*2) && (event.motion.y<273+3*62+2*30))
				{
					*nbut=3;
					
				}
			}
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				if(event.motion.x>(screen->w/2)-(buttons[0]->w/2) && (event.motion.x< ((screen->w/2)-(buttons[0]->w/2)+(buttons[0]->w) ) ) && (event.motion.y>273+62*2+30*2) && (event.motion.y<273+3*62+2*30))
				{
					*done=0;
				}
			}
		break;

		case 2: //settings

			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				if( ( event.motion.x > ( (screen->w/2)-(settings[0]->w/2)+250 ) ) && (event.motion.x < ( (screen->w/2)-(settings[0]->w/2)+345 ) ) && (event.motion.y>(screen->h/2)-(settings[0]->h/2)+170) && (event.motion.y<(screen->h/2)-(settings[0]->h/2)+205) )
				{
					if(*nset==0)
						*nset=2;
					else if(*nset==2)
						*nset=0;
					else if(*nset==1)
						*nset=3;
					else if(*nset==3)
						*nset=1;
				}
			
				if( ( event.motion.x > ( (screen->w/2)-(settings[0]->w/2)+250 ) ) && (event.motion.x < ( (screen->w/2)-(settings[0]->w/2)+345 ) ) && (event.motion.y>(screen->h/2)-(settings[0]->h/2)+240) && (event.motion.y<(screen->h/2)-(settings[0]->h/2)+275) )
				{
					if(*nset==0)
						*nset=1;
					else if(*nset==1)
						*nset=0;
					else if(*nset==2)
						*nset=3;
					else if(*nset==3)
						*nset=2;
				}
				
				if( ( event.motion.x > ( (screen->w/2)-(settings[0]->w/2)+190 ) ) && (event.motion.x < ( (screen->w/2)-(settings[0]->w/2)+260 ) ) && (event.motion.y>(screen->h/2)-(settings[0]->h/2)+400) && (event.motion.y<(screen->h/2)-(settings[0]->h/2)+455) )
				{
					*menu=1;
				}
			}
			if (event.type == SDL_MOUSEBUTTONUP)
			{
				if( ( event.motion.x > 490 && event.motion.x < 620 ) && (event.motion.y>436 && event.motion.y<476) )
				{
					if(event.button.button == SDL_BUTTON_LEFT)
					{
						menukeyboard(screen);
						SDL_EnableKeyRepeat(0,0);
					}
				}
			}
			if(event.type == SDL_MOUSEMOTION)
            {
                printf("Souris en position %d %d\n",event.motion.x, event.motion.y);
            }
		break;

		case 3: //level

			if (event.type == SDL_MOUSEMOTION)
			{
				if( ( event.motion.x > ((screen->w/2)-(levels[0]->w/2)+85) ) && (event.motion.x < ((screen->w/2)-(levels[0]->w/2)+(levels[0]->w)+175) ) && (event.motion.y>((screen->h/2)-(levels[0]->h/2)+185)) && (event.motion.y<((screen->h/2)-(levels[0]->h/2)+235) ) )
				{
					*nlevel=1;
					
				}
			}
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				if( ( event.motion.x > ((screen->w/2)-(levels[0]->w/2)+85) ) && (event.motion.x < ((screen->w/2)-(levels[0]->w/2)+(levels[0]->w)+175) ) && (event.motion.y>((screen->h/2)-(levels[0]->h/2)+185)) && (event.motion.y<((screen->h/2)-(levels[0]->h/2)+235)) )
				{
					*menu=4;
				}
			}

			
			///////////////////////////

			if (event.type == SDL_MOUSEMOTION)
			{
				if( ( event.motion.x > ((screen->w/2)-(levels[0]->w/2)+200) ) && (event.motion.x < ((screen->w/2)-(levels[0]->w/2)+(levels[0]->w)+290) ) && (event.motion.y>((screen->h/2)-(levels[0]->h/2)+185)) && (event.motion.y<((screen->h/2)-(levels[0]->h/2)+235)) )
				{
					*nlevel=2;
					
				}
			}
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				if( ( event.motion.x > ((screen->w/2)-(levels[0]->w/2)+200) ) && (event.motion.x < ((screen->w/2)-(levels[0]->w/2)+(levels[0]->w)+290) ) && (event.motion.y>((screen->h/2)-(levels[0]->h/2)+185)) && (event.motion.y<((screen->h/2)-(levels[0]->h/2)+235)) )
				{
					*game=1;
				}
			}
			////////////////////////////
			
			if(level==2)
			{
				if (event.type == SDL_MOUSEMOTION)
				{
					if( ( event.motion.x > ((screen->w/2)-(levels[0]->w/2)+440) ) && (event.motion.x < ((screen->w/2)-(levels[0]->w/2)+(levels[0]->w)+530) ) && (event.motion.y>((screen->h/2)-(levels[0]->h/2)+185)) && (event.motion.y<((screen->h/2)-(levels[0]->h/2)+235)) )
					{
						*nlevel=3;
					
					}
				}
				if (event.type == SDL_MOUSEBUTTONDOWN)
				{
					if( ( event.motion.x > ((screen->w/2)-(levels[0]->w/2)+440) ) && (event.motion.x < ((screen->w/2)-(levels[0]->w/2)+(levels[0]->w)+530) ) && (event.motion.y>((screen->h/2)-(levels[0]->h/2)+185)) && (event.motion.y<((screen->h/2)-(levels[0]->h/2)+235)) )
					{
						*menu=4;
					}
				}
				///////////////////////////

				if (event.type == SDL_MOUSEMOTION)
				{
					if( ( event.motion.x > ((screen->w/2)-(levels[0]->w/2)+555) ) && (event.motion.x < ((screen->w/2)-(levels[0]->w/2)+(levels[0]->w)+645) ) && (event.motion.y>((screen->h/2)-(levels[0]->h/2)+185)) && (event.motion.y<((screen->h/2)-(levels[0]->h/2)+235)) )
					{
						*nlevel=4;
					
					}
				}
				if (event.type == SDL_MOUSEBUTTONDOWN)
				{
					if( ( event.motion.x > ((screen->w/2)-(levels[0]->w/2)+555) ) && (event.motion.x < ((screen->w/2)-(levels[0]->w/2)+(levels[0]->w)+645) ) && (event.motion.y>((screen->h/2)-(levels[0]->h/2)+185)) && (event.motion.y<((screen->h/2)-(levels[0]->h/2)+235)) )
					{
						*game=1;
					}
				}
			}

			if(level==3)
			{
				if (event.type == SDL_MOUSEMOTION)
				{
					if( ( event.motion.x > ((screen->w/2)-(levels[0]->w/2)+790) ) && (event.motion.x < ((screen->w/2)-(levels[0]->w/2)+(levels[0]->w)+885) ) && (event.motion.y>((screen->h/2)-(levels[0]->h/2)+185)) && (event.motion.y<((screen->h/2)-(levels[0]->h/2)+235)) )
					{
						*nlevel=5;
					
					}
				}
				if (event.type == SDL_MOUSEBUTTONDOWN)
				{
					if( ( event.motion.x > ((screen->w/2)-(levels[0]->w/2)+790) ) && (event.motion.x < ((screen->w/2)-(levels[0]->w/2)+(levels[0]->w)+885) ) && (event.motion.y>((screen->h/2)-(levels[0]->h/2)+185)) && (event.motion.y<((screen->h/2)-(levels[0]->h/2)+235)) )
					{
						*menu=4;
					}
				}
				///////////////////////////

				if (event.type == SDL_MOUSEMOTION)
				{
					if( ( event.motion.x > ((screen->w/2)-(levels[0]->w/2)+905) ) && (event.motion.x < ((screen->w/2)-(levels[0]->w/2)+(levels[0]->w)+995) ) && (event.motion.y>((screen->h/2)-(levels[0]->h/2)+185)) && (event.motion.y<((screen->h/2)-(levels[0]->h/2)+235)) )
					{
						*nlevel=6;
					
					}
				}
				if (event.type == SDL_MOUSEBUTTONDOWN)
				{
					if( ( event.motion.x > ((screen->w/2)-(levels[0]->w/2)+905) ) && (event.motion.x < ((screen->w/2)-(levels[0]->w/2)+(levels[0]->w)+995) ) && (event.motion.y>((screen->h/2)-(levels[0]->h/2)+185)) && (event.motion.y<((screen->h/2)-(levels[0]->h/2)+235)) )
					{
						*game=1;
					}
				}
			}
			
		break;

		case 4: //players

			if (event.type == SDL_MOUSEMOTION)
			{
				if( ( event.motion.x > ((screen->w/2)-(players[0]->w/2)+10) ) && (event.motion.x < ((screen->w/2)-(players[0]->w/2)+(players[0]->w)+300) ) && (event.motion.y>((screen->h/2)-(players[0]->h/2))) && (event.motion.y<((screen->h/2)+(players[0]->h/2)) ) )
				{
					*nplayer=1;
					
				}
			}
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				if( ( event.motion.x > ((screen->w/2)-(players[0]->w/2)+10) ) && (event.motion.x < ((screen->w/2)-(players[0]->w/2)+(players[0]->w)+300) ) && (event.motion.y>((screen->h/2)-(players[0]->h/2))) && (event.motion.y<((screen->h/2)+(players[0]->h/2)) ) )
				{
					//*player=1; //delta					
					//*menu=5;
					
				}
			}
			//////////////////////////

			if (event.type == SDL_MOUSEMOTION)
			{
				if( ( event.motion.x > ((screen->w/2)-(players[0]->w/2)+370) ) && (event.motion.x < ((screen->w/2)+(players[0]->w/2)) ) && (event.motion.y>((screen->h/2)-(players[0]->h/2))) && (event.motion.y<((screen->h/2)+(players[0]->h/2)) ) )
				{
					*nplayer=2;
					
				}
			}
			if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				if( ( event.motion.x > ((screen->w/2)-(players[0]->w/2)+370) ) && (event.motion.x < ((screen->w/2)+(players[0]->w/2)) ) && (event.motion.y>((screen->h/2)-(players[0]->h/2))) && (event.motion.y<((screen->h/2)+(players[0]->h/2)) ) )
				{
					//*player=2; //alpha					
					//*menu=5;
				
				}
			}
			//////////////////////////

			if (event.type == SDL_MOUSEBUTTONUP)
			{
			
				if( ( (event.motion.x > 700) && (event.motion.x < 1400)) )
				{
					//*player=1; //delta					
					//*menu=5;
					MenuchoixControl(screen,2);
					printf("choix 2\n");
				}
				else if ( (event.motion.x > 0) && (event.motion.x < 700)) {
					MenuchoixControl(screen,1);
					printf("choix 1\n");
				}
			}
			
		break;

		case 5:
		break;
	}	
}
//stooooop

void update (int key,int *done,int *menu,int *selection,int level,int *multij,int *game,int *nbg,int *nbut,int *nset,int *nlevel,int *nplayer,int *nCsm,Mix_Chunk *effect,int *player,int *Csm,int *time,SDL_Surface *screen)
{
	int now=0;	
	
	switch (key)
	{
	case 1 : //escape
		if ((*menu)==5) //player selection
		{
			(*menu)=4; 
			if ((*nset)==0 || (*nset)==1)
				Mix_PlayChannel(-1,effect,0);
		}		

		if ((*menu)==4) //player selection
		{
			(*menu)=3; 
			if ((*nset)==0 || (*nset)==1)
				Mix_PlayChannel(-1,effect,0);
		}
 		
		else if ((*menu)==2 || (*menu)==3) 
		{
			(*menu)=1; 
			if ((*nset)==0 || (*nset)==1)
				Mix_PlayChannel(-1,effect,0);
		}

		else if ((*menu)==1) (*done)=0;
	break;
	case 2 : //down
		switch (*menu)
		{				
		case 1 : //main

		(*nbut)++;
			if ((*nbut)>=4) 
			{					
			(*nbut)=1;
			if ((*nset)==0 || (*nset)==1)
				Mix_PlayChannel(-1,effect,0);
			}

			break;

		case 2 : //settings

			if ((*selection)==1) 
			{					
			(*selection) =2;
			if ((*nset)==0 || (*nset)==1)
				Mix_PlayChannel(-1,effect,0);
			}

			else if ((*selection)==2) 
			{					
			(*selection) =1;
			if ((*nset)==0 || (*nset)==1)
				Mix_PlayChannel(-1,effect,0);
			}

			break;
		}
	break;
	case 3 : //up
		switch (*menu)
		{				
		case 1 : //main

			(*nbut)--;
			if ((*nbut)<=0)
			{					
				(*nbut)=3;
				if ((*nset)==0 || (*nset)==1)
					Mix_PlayChannel(-1,effect,0);
			}
			break;

		case 2 : //settings

			if ((*selection)==1) 
			{					
				(*selection) =2;
				if ((*nset)==0 || (*nset)==1)
					Mix_PlayChannel(-1,effect,0);
			}

				else if ((*selection)==2) 
			{					
				(*selection) =1;
				if ((*nset)==0 || (*nset)==1)
					Mix_PlayChannel(-1,effect,0);
			}
			break;
		}
	break;
	case 4 : //rigth
		if ((*menu)==3)
		{
			if (level==1)
			{
				(*nlevel)++;
				if ((*nlevel)==3) (*nlevel)=1;
				if ((*nset)==0 || (*nset)==1)						
					Mix_PlayChannel(-1,effect,0);
			}

			if (level==2)
			{
				(*nlevel)++;
				if ((*nlevel)==5) (*nlevel)=1;
				if ((*nset)==0 || (*nset)==1)						
					Mix_PlayChannel(-1,effect,0);
			}

			if (level==3)
			{
				(*nlevel)++;
				if ((*nlevel)==7) (*nlevel)=1;
				if ((*nset)==0 || (*nset)==1)						
					Mix_PlayChannel(-1,effect,0);
			}
		}

		if ((*menu)==4)
		{
			(*nplayer)++;
			if ((*nplayer)==3) (*nplayer)=1;
			if ((*nset)==0 || (*nset)==1)						
					Mix_PlayChannel(-1,effect,0);
		}

		if ((*menu)==5)
		{
			(*nCsm)++;
			if ((*nCsm)==4) (*nCsm)=1;
			if ((*nset)==0 || (*nset)==1)						
					Mix_PlayChannel(-1,effect,0);
		}
	break;
	case 5 : //left
		if ((*menu)==3)
		{
			if (level==1)
			{
				(*nlevel)--;
				if ((*nlevel)<=0) (*nlevel)=2;
				if ((*nset)==0 || (*nset)==1)						
					Mix_PlayChannel(-1,effect,0);
			}

			if (level==2)
			{
				(*nlevel)--;
				if ((*nlevel)<=0) (*nlevel)=4;
				if ((*nset)==0 || (*nset)==1)						
					Mix_PlayChannel(-1,effect,0);
			}

			if (level==3)
			{
				(*nlevel)++;
				if ((*nlevel)<=0) (*nlevel)=6;
				if ((*nset)==0 || (*nset)==1)						
					Mix_PlayChannel(-1,effect,0);
			}
		}

		if (*menu==4)
		{
			(*nplayer)--;
			if ((*nplayer)<=0) (*nplayer)=2;
			if ((*nset)==0 || (*nset)==1)						
					Mix_PlayChannel(-1,effect,0);
		}
	
		if (*menu==5)
		{
			(*nCsm)--;
			if ((*nCsm)<=0) (*nCsm)=3;
			if ((*nset)==0 || (*nset)==1)						
					Mix_PlayChannel(-1,effect,0);
		}
	break;
	case 6 : //return (ki tenzel 3al entrer)
		switch (*menu)
		{				
		case 1 :
			if ((*nbut)==1) 
			{
				(*menu)=3; 
				if ((*nset)==0 || (*nset)==1)
					Mix_PlayChannel(-1,effect,0);}//levels menu
			if ((*nbut)==2) 
			{
				(*menu)=2;  
				if ((*nset)==0 || (*nset)==1)						
					Mix_PlayChannel(-1,effect,0);} //settings
			if ((*nbut)==3) (*done)=0; //quit
			break;

		case 2 : 
			(*menu)=1;  
			if ((*nset)==0 || (*nset)==1)
				Mix_PlayChannel(-1,effect,0);
			break;

		case 3 :// menu ali tekhtar bih solo wala duo
			if ((*nlevel)==1 || (*nlevel)==3 || (*nlevel)==5)//solo
			{
				///continuenewgame
				int continueNewgame;
				Menu_Load(screen,&continueNewgame);
				if(continueNewgame==1)//newgame
				{
					(*multij)=0;
					(*menu)=4; //choisir le joueur
					if ((*nset)==0 || (*nset)==1)						
						Mix_PlayChannel(-1,effect,0);
				}
				else if(continueNewgame==2)//continue
				{
					Integration I;
					I.loadgame=1;
					NewIntegration(&I,screen);
				}
				
			}
			if ((*nlevel)==2 || (*nlevel)==4 || (*nlevel)==6)//multiplayer "duo"
			{
				screen = SDL_SetVideoMode(1800, 600,32, SDL_HWSURFACE | SDL_DOUBLEBUF);
				Integrationm Im;
				NewIntegrationm(&Im,screen);
				screen = SDL_SetVideoMode(1080,720,32,SDL_HWSURFACE|SDL_DOUBLEBUF);
				SDL_EnableKeyRepeat(0,0);
			}
			break;
		case 4 :
			if ((*nplayer)==1)
				(*player)=1; //delta
				
			if ((*nplayer)==2)
				(*player)=2; //alpha
			
			(*menu)=5;
			break;

		case 5 :
			if ((*nCsm)==1)
				(*Csm)=1; //clavier
				
			if ((*nCsm)==2)
				(*Csm)=2; //souris

			if ((*nCsm)==3)
				(*Csm)=3; //manette
			
			(*game)=1; //le jeu commence
			break;
		}
	break;
	case 7 : //space
		switch (*menu)
		{				
		case 2 :
			switch (*selection)
			{
			case 1:
				if ((*nset)==0) (*nset)=2;					
				else if ((*nset)==1) (*nset)=3;					
				else if ((*nset)==2) 
				{ 
					(*nset)=0; 
					Mix_PlayChannel(-1,effect,0);
				}				
				else if ((*nset)==3)
				{ 
					(*nset)=1; 
					Mix_PlayChannel(-1,effect,0);
				}		
			break;
			case 2:
				if ((*nset)==0) 
				{
					(*nset)=1; 
					Mix_PlayChannel(-1,effect,0);	
					Mix_PauseMusic();
				}				
				else if ((*nset)==1)	
				{
					(*nset)=0; 
					Mix_PlayChannel(-1,effect,0);	
					Mix_ResumeMusic();
				}					
				else if ((*nset)==2) {(*nset)=3;	Mix_PauseMusic();}				
				else if ((*nset)==3) {(*nset)=2;     Mix_ResumeMusic();}
			break;
			}
		break;//case2
		}// switch
	break;
	}//switch
	
	now=SDL_GetTicks();
	if((now-(*time))>250)
	{	
		(*nbg)++;
		(*time)=SDL_GetTicks();
	}
    	if((*nbg) >= 12) (*nbg) = 0;
}

//stoooop
void input (int *done, int *key,SDL_Event *event)
{
	(*key)=0;
	if(SDL_PollEvent(event)) 
	{
	        switch (event->type) 
		{
		    case SDL_QUIT: 
				(*done)=0;
				break;

		    case SDL_KEYDOWN:

			if(event->key.keysym.sym==SDLK_ESCAPE)
			(*key)=1;//escape		
			
			if(event->key.keysym.sym==SDLK_DOWN)
			(*key)=2;//down

			if(event->key.keysym.sym==SDLK_UP)
			(*key)=3; //up
			
			if(event->key.keysym.sym==SDLK_RIGHT)
			(*key)=4;//rigth
			
			if(event->key.keysym.sym==SDLK_LEFT)
			(*key)=5;//left
			
			if(event->key.keysym.sym==SDLK_RETURN)
			(*key)=6;//return
			
			if(event->key.keysym.sym==SDLK_SPACE)
			(*key)=7;//space
			
                }//switch
        }
}


//stoop

void initialiserMenu(SDL_Surface** screen,SDL_Surface *bg[],SDL_Surface *buttons[],SDL_Surface *settings[],SDL_Surface *levels[],SDL_Surface *players[],SDL_Surface *csm[],SDL_Surface **logo,SDL_Surface **Breturn,SDL_Surface **black,Mix_Music **music,Mix_Chunk **effect, SDL_Rect *posButtons,SDL_Rect *posLevels,SDL_Rect *posLogo,SDL_Rect *posSettings,SDL_Rect *posPlayers,SDL_Rect *posCsm,SDL_Rect *posBReturn,SDL_Rect *posBlack1,SDL_Rect *posBlack2,SDL_Rect *posControl,SDL_Rect *posCovid,SDL_Surface*covid)
{

	
	if(SDL_Init(SDL_INIT_VIDEO)!=0)
		printf("Unable to initialize SDL : %s\n",SDL_GetError());

	if(Mix_OpenAudio(44100,MIX_DEFAULT_FORMAT,MIX_DEFAULT_CHANNELS,1024)==-1)
		printf("Unable to initialize Mix : %s\n",Mix_GetError());

	*music=Mix_LoadMUS("music.mp3");
	*effect=Mix_LoadWAV("effect.wav");	
	
	SDL_WM_SetIcon(loadimage("layer 0"),NULL);
	SDL_WM_SetCaption("PLOTTWIST","PLOTTWIST");

	*screen = SDL_SetVideoMode(1080,720,32,SDL_HWSURFACE|SDL_DOUBLEBUF);


	if(*screen==NULL)
		printf("Unable to set video mode: %s \n",SDL_GetError());

	bg[0] = loadimage("./layers/Layer1.gif");
	bg[1] = loadimage("./layers/Layer2.gif");
	bg[2] = loadimage("./layers/Layer3.gif");
	bg[3] = loadimage("./layers/Layer4.gif");
	bg[4] = loadimage("./layers/Layer5.gif");
	bg[5] = loadimage("./layers/Layer6.gif");
	bg[6] = loadimage("./layers/Layer7.gif");
	bg[7] = loadimage("./layers/Layer8.gif");
	bg[8] = loadimage("./layers/Layer9.gif");
	bg[9] = loadimage("./layers/Layer10.gif");
	bg[10] = loadimage("./layers/Layer11.gif");
	bg[11] = loadimage("./layers/Layer12.gif");

	*logo = loadimage("logo taille sur 1080.png");

	buttons[0] = loadimage("./buttons/0.png");
	buttons[1] = loadimage("./buttons/1.png");
	buttons[2] = loadimage("./buttons/2.png");
	buttons[3] = loadimage("./buttons/3.png");

	covid = loadimage("./aboutcovid/aboutc.png");

	settings[0] = loadimage("./settings/1.png");
	settings[1] = loadimage("./settings/2.png");
	settings[2] = loadimage("./settings/3.png");
	settings[3] = loadimage("./settings/4.png");
	settings[4] = loadimage("./settings/controls.png");

	levels[0] = loadimage("./levels/0.png");
	levels[1] = loadimage("./levels/1.png");
	levels[2] = loadimage("./levels/2.png");
	levels[3] = loadimage("./levels/3.png");
	levels[4] = loadimage("./levels/4.png");
	levels[5] = loadimage("./levels/5.png");
	levels[6] = loadimage("./levels/6.png");

	*black = loadimage("./levels/black.png");

	players[0] = loadimage("./players/1.png");
	players[1] = loadimage("./players/2.png");
	players[2] = loadimage("./players/3.png");

	csm[0] = loadimage("./csm/0.png");
	csm[1] = loadimage("./csm/1.png");
	csm[2] = loadimage("./csm/2.png");
	csm[3] = loadimage("./csm/3.png");

	*Breturn = loadimage("return.png");

	posLogo->x=((*screen)->w/2)-((*logo)->w/2);
	posLogo->y=40;

	posButtons->x=((*screen)->w/2)-(buttons[0]->w/2);
	posButtons->y=273;

	posSettings->x=((*screen)->w/2)-(settings[0]->w/2);
	posSettings->y=((*screen)->h/2)-(settings[0]->h/2);

	posLevels->x=0;
	posLevels->y=((*screen)->h/2)-(levels[0]->h/2);

	posPlayers->x=((*screen)->w/2)-(players[0]->w/2);
	posPlayers->y=((*screen)->h/2)-(players[0]->h/2);

	posCsm->x=((*screen)->w/2)-(csm[0]->w/2);
	posCsm->y=((*screen)->h/2)-(csm[0]->h/2);
	
	posBReturn->x=14;
	posBReturn->y=7;

	posBlack1->x=408;
	posBlack1->y=256;

	posBlack2->x=758;
	posBlack2->y=256;

	posControl->x=490;
	posControl->y=436;

	posCovid->x=887;
	posCovid->y=623;
}
//stooooop



 

int main()
{

	SDL_Event event;
	SDL_Surface *screen =NULL,*lampe[2],*bg[12],*buttons[4],*settings[5],*levels[7],*players[3],*csm[4],*logo =NULL,*Breturn,*black,*covid;
	SDL_Rect posButtons,posLevels,posLogo,posSettings,posPlayers,posCsm,posBReturn,posBlack1,posBlack2,posLampe,posControl,posCovid;
	int done=1,time=0,menu=1,level=1,selection=1,key=0,multij=0,game=0,player=0,Csm=0;
	int nbg=0,nbut=0,nset=0,nlevel=0,nplayer=0,nCsm=0;
	Mix_Music *music;
	Mix_Chunk *effect;


	initialiserMenu(&screen,bg,buttons,settings,levels,players,csm,&logo,&Breturn,&black,&music,&effect,&posButtons,
&posLevels,&posLogo,&posSettings,&posPlayers,&posCsm,&posBReturn,&posBlack1,&posBlack2,&posControl,&posCovid,covid);

	Mix_PlayMusic(music,-1);
	
while(done==1)
{
	
	
	input(&done,&key,&event);

	update(key,&done,&menu,&selection,level,&multij,&game,&nbg,&nbut,&nset,&nlevel,&nplayer,&nCsm,effect,&player,&Csm,&time,screen);
	
	updateSouris(event,&done,&menu,&selection,level,&multij,&game,&nbg,&nbut,&nset,&nlevel,&nplayer,&nCsm,effect,&player,&Csm,
&time,screen,buttons,settings,levels,players,csm);

	afficherMenu(screen,bg,buttons,settings,levels,players,csm,logo,Breturn,black,posButtons,posLevels,posLogo,posSettings, posPlayers,posCsm,posBReturn,posBlack1,posBlack2,menu,level,nbg,nbut,nset,nlevel,nplayer,nCsm,posControl,covid,posCovid);

    	SDL_Flip(screen);

}

SDL_FreeSurface(screen);
for(int i=0;i<12;i++)
	SDL_FreeSurface(bg[i]);
for(int i=0;i<4;i++)
	SDL_FreeSurface(buttons[i]);
for(int i=0;i<4;i++)
	SDL_FreeSurface(settings[i]);
for(int i=0;i<7;i++)
	SDL_FreeSurface(levels[i]);
SDL_FreeSurface(logo);
for(int i=0;i<3;i++)
	SDL_FreeSurface(players[i]);
SDL_FreeSurface(Breturn);
SDL_FreeSurface(black);
Mix_FreeMusic(music);
Mix_FreeChunk(effect);

SDL_Quit;
}


int Menu_Load(SDL_Surface*ecran,int*continueNewgame)//menu bech tekhtar continuer wala new game
{
  SDL_Surface *background,*BoutonC,*BoutonCS,*BoutonN,*BoutonNS;

  background=IMG_Load("ah.png");
  TTF_Init();

  TTF_Font *police = NULL,*policeS=NULL;
  SDL_Color couleurNoir = {0,0,0};
  police = TTF_OpenFont("afont.ttf", 30);
  policeS = TTF_OpenFont("afont.ttf", 40);

  BoutonC = TTF_RenderText_Blended(police, "Continue", couleurNoir);
  BoutonCS = TTF_RenderText_Blended(policeS, "Continue", couleurNoir);

  BoutonN = TTF_RenderText_Blended(police, "New Game", couleurNoir);
  BoutonNS = TTF_RenderText_Blended(policeS, "New Game", couleurNoir);

  SDL_Rect posBouton[3];

  posBouton[1].x=400;
  posBouton[1].y=200;

  posBouton[2].x=400;
  posBouton[2].y=400;

  int image_courrante=1;

  SDL_Surface *image=NULL,*rotation=NULL ;

  SDL_Rect rect;

  double angle = 0;

  double zoom = 1;

  int sens = 1;
  image=IMG_Load("img/rotozoom.png");

  SDL_Event event3;
  int continuer=1;
  SDL_EnableKeyRepeat(0,0);
  while(continuer==1)
  {
  	SDL_BlitSurface(background,NULL,ecran,NULL);

  	 rotation = rotozoomSurface(image, angle, zoom, 0); //On transforme la surface image.

        
        
        //On repositionne l'image en fonction de sa taille.

        //rect.x =  event.button.x - rotation->w / 2;

        //rect.y =  event.button.y - rotation->h / 2;

          rect.x =   rotation->w / 2;

        rect.y =   rotation->h / 2;

        SDL_BlitSurface(rotation , NULL, ecran, &rect); //On affiche la rotation de la surface image.

        SDL_FreeSurface(rotation); //On efface la surface rotation car on va la redéfinir dans la prochaine boucle. Si on ne le fait pas, cela crée une fuite de mémoire. 

 

        if(zoom >= 2){sens = 0;}

        else if(zoom <= 0.5){sens = 1;}

 

        if(sens == 0){zoom -= 0.01;}

        else{zoom += 0.01;}

   	if(image_courrante==1)
    {
    	SDL_BlitSurface(BoutonCS,NULL,ecran,&posBouton[1]);
    	SDL_BlitSurface(BoutonN,NULL,ecran,&posBouton[2]);

    }
    else if(image_courrante==2)
    {
    	SDL_BlitSurface(BoutonC,NULL,ecran,&posBouton[1]);
    	SDL_BlitSurface(BoutonNS,NULL,ecran,&posBouton[2]);
    }
    SDL_UpdateRect(ecran, 0, 0, 0, 0);
    printf("%d\n",image_courrante);
    
    while(SDL_PollEvent(&event3))
    {
      switch (event3.type)
      { 
        case SDL_KEYDOWN:
        {
          if(event3.key.keysym.sym==SDLK_DOWN)
          {
            image_courrante++;
          }
          else if(event3.key.keysym.sym==SDLK_UP)
          {
            image_courrante--;
          }
          else if(event3.key.keysym.sym==SDLK_ESCAPE)
          {
            SDL_EnableKeyRepeat(0,0);
            (*continueNewgame)=0;
            return 0;
          }
          if(event3.key.keysym.sym==SDLK_RETURN)
          {
            if(image_courrante==1)
            {
            	(*continueNewgame)=2;//continue
              return 0; 
            }
            else if(image_courrante==2)
            {
              	(*continueNewgame)=1;//loadgame
              return 0;
            }
          }
          break;
        }
       

      }
  }
    
    if(image_courrante<1)
    {
      image_courrante=2;
    }
    if(image_courrante>2)
    {
      image_courrante=1;
    }
   
  }
  return 0;
}