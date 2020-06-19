#include"perso.h"

void perso_Init(Personnage *p,int choixperso){

    if(choixperso==1){
        p->image = IMG_Load("img/playerR.png");
        p->image2 = IMG_Load("img/playerL.gif");
    }
    else{
        p->image = IMG_Load("img/player2R.gif");
        p->image2 = IMG_Load("img/player2L.gif");
    }
	
	p->position.x = 50;
	p->position.y = 350;//SCREEN_H - p->image[0]->h;
	p->position.w=255;
	p->position.h=261;
	
	//p->vx = 0; 
	p->direction=1;
	//p->vitesse=5;
	p->velocity=0;
    p->moving=0;
    p->position_camera=p->position;
       // p->Mass=70;
	
	/*p>position.w=p->image[0]->w;
	p->position.h=p->image[0]->h;*/
	
	p->frame.x=0;
	p->frame.y=0;
	p->frame.w=255;
	p->frame.h=261;

    p->status = STAT_SOL;
    p->vx = p->vy = 0.0f;

    p->jump=0;
    p->attack=0;
 }
void deplacer_perso(Personnage *p,SDL_Rect camera,Uint32 dt,SDL_Rect position_souris)
{ 
	if(p->moving==1 || p->moving==2){
        p->velocity+=acceleration*dt;
        if(p->velocity>60){
            p->velocity=60;
        }
        printf("%d\n",p->velocity );
    	if(p->moving==1)
    	{
    		if(p->direction==1)
    		{
    		  p->position.x+=p->velocity;
    		  //p->position.x+=50;
    		}
    		else if(p->direction==0)
    		{
    			p->position.x-=p->velocity;
                if(p->position.x<0){
                    p->position.x=0;
                }
    			//p->position.x-=50;
    		}
    	}
    	else if(p->moving==2)
    	{
    		if(position_souris.x>p->position.x){
    			p->position.x+=50;
    			p->direction=1;
    			if(position_souris.x<p->position.x){
    				p->moving=0;
    			}
    		}
    		else{
    			p->position.x-=50;
    			p->direction=0;
    			if(position_souris.x>p->position.x){
    				p->moving=0;
    			}
    		}
    	}
    }
    else{
    	p->velocity=0;
    }

    p->position_camera.x=p->position.x-camera.x;
    p->position_camera.y=p->position.y;

    if (p->position_camera.x>=1000)
    {
        p->position_camera.x=1000-250;
    }
    else if (p->position_camera.x <=0)
    {
        p->position_camera.x=0;
    }
  
 }


/*void blitBackground(SDL_Surface *Backg,SDL_Surface **screen,SDL_Rect position_Backg)
{ position_Backg.x=0;
  position_Backg.y=0;
   
SDL_BlitSurface(Backg,NULL,screen,&position_Backg);

  }*/


 void perso_Render(Personnage *p, SDL_Surface *screen){
   if(p->direction==1)
   	{
		SDL_BlitSurface(p->image,&p->frame,screen,&p->position_camera);
	}
         else//(p->direction==0)
	       // SDL_BlitSurface(p->image,&p->clips[(int) p->frame],*screen,&p->positionPerso);
		{SDL_BlitSurface(p->image2,&p->frame,screen,&p->position_camera);}

	         
	if(p->moving==1 || p->moving==2){
		p->frame.x += 255;
		if(p->frame.x >1530 ) {
			 p->frame.x = 0;
			//p->vx *= 1;
		}
	}
	if(p->moving==1){
		p->moving=0;
	}
	
	//p->positionPerso.x += p->vx;
	SDL_Flip(screen);
}
/*
int loadVoitureImages (Voiture * A)
{
	int i;
	char buf[50];
	char buf0[]="../images/voiture";
	char bmp[]=".bmp";
	for(i=0; i<4; i++)
        {
		sprintf(buf,"%s%d%s",buf0,i,bmp);
		A->image[i] = SDL_LoadBMP(buf);
		if (A->image[i]== NULL) 
                {
			printf("Unable to load  Voiture bitmap: %s\n", SDL_GetError());
			return (-1);
		}
		// set the color of Voiture background (white color) as transparent
		SDL_SetColorKey( A->image[i], SDL_SRCCOLORKEY, SDL_MapRGB(A->image[i]->format, 255, 255, 255) );
	}
	return(0);
}
*/

void Saute(Personnage *p,float impulsion)
{
    p->vy = -impulsion;
    p->status = STAT_AIR;
}



void ControleSol(Personnage *p)
{
    if (p->position.y>250.0f)
    {
        p->position.y = 250.0f;
        if (p->vy>0)
            {p->vy = 0.0f;}
        p->status = STAT_SOL;
    }
}


void Gravite(Personnage *p,float factgravite,float factsautmaintenu)
{
    if (p->status == STAT_AIR )
        {factgravite/=factsautmaintenu;}
    p->vy += factgravite;
}




















