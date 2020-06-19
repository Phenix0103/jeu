#include "integration.h"


void Initialisation(Integration *I)
{ 
  I->boucle=1;
 	initialiserfond(&(I->m));
 	perso_Init(&(I->p),I->choixPlayer);
 	scrolling_initialiser(&(I->s),I->p.position,width,height);
  initialiservie(&(I->v));
  SDL_Rect pos_ennemi={2000,400,150,150};
  Initialisation_Ennemi(&(I->e),pos_ennemi);
  I->enigme=1;
  initializerTemps(&(I->time));
  init_score(&(I->sc));
  Init_MiniMap(&(I->mm),I->p.position);
  Init_Control(&(I->c));

  /******************** load game *********************/
  if(I->loadgame==1){
    FILE* f=fopen("save.bin","rb");
    if(f!=NULL){
      Load_Game(I,f);
    }  
  }
  
  
}

void DisplayIntegration(Integration *I,SDL_Surface *ecran)
{
  SDL_Rect posblit={0,0};
  afficherfond(&(I->m),I->s.pos,ecran,posblit);
  perso_Render(&(I->p),ecran);
  affichervie(&(I->v),ecran);
  if( I->e.killed==0)//si l'ennemi est encore en vie
  {
    Affichage_Ennemi(&(I->e),ecran);
  }
  afficherTemps(&(I->time),ecran);
  afficherscore(&(I->sc),ecran);
  Display_MiniMap(&(I->mm),ecran);
  SDL_Flip(ecran);
  
  I->p.attack=0;
  I->p.jump=0;

}


void PlayIntegration(Integration *I,SDL_Surface *ecran)
{
  Uint32 t_prev,dt=1;

  DisplayIntegration(I,ecran);
  while(I->boucle==1)
  {  
    t_prev=SDL_GetTicks();
    UpdateIntegration (I,dt,ecran);
    DisplayIntegration(I,ecran);

    if(I->p.position.x>4000 && I->enigme==1)
    {
      I->boucle=jouer_enigme(ecran);
      I->enigme++;
      ecran = SDL_SetVideoMode(1000, 600,32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    }

    if(I->p.position.x>6000)
    {
      if(play_enigme2(ecran)==1)
      {
        printf("you win !\n");
      }
      else{
        printf("you lost !\n");
      }
      I->boucle=0;
    }



    dt=SDL_GetTicks()-t_prev;
    if (1000/FSP>dt){
      SDL_Delay(1000/FSP-dt);
    }
  }
}




void NewIntegration(Integration *I,SDL_Surface *ecran)
{
printf ("init game");
Initialisation(I);
SDL_EnableKeyRepeat(5,5);
do
{
printf ("play game");
PlayIntegration(I,ecran);
}
while (I->boucle==1);
	FreeIntegaration(I);
}


void UpdateIntegration(Integration *I,Uint32 dt,SDL_Surface*ecran)
{  
  /********** JUmp *************/
  float lateralspeed = 0.5f;
  float airlateralspeedfacteur = 0.5f;
  float maxhspeed = 3.0f;
  float adherance = 1.5f;//pour le freinage et sous 1 n'a pas de sens
  float impulsion = 6.0f;
  float factgravite = 0.5f;
  float factsautmaintenu = 3.0f;
  /********** JUmp *************/

  SDL_Event event;
    
  while(SDL_PollEvent(&event))
  {
    switch (event.type)
    {
      case SDL_MOUSEBUTTONUP:
      {
        if(I->choixControl==2)
        {


        if(event.button.button == SDL_BUTTON_LEFT)
        {
          I->p.moving=2;
          I->position_souris.x=event.motion.x+I->s.pos.x;
          I->position_souris.y=event.motion.y;        
        }
        else if(event.button.button == SDL_BUTTON_RIGHT)   
        {
          fprintf(stderr," jump \n");
          I->p.jump=1;
        }
        
      }
        break;
      }
      case SDL_KEYDOWN:
      {
        if(I->choixControl==1)
        {


        if(event.key.keysym.sym==I->c.controls[0])
        {
          I->p.moving=1;
          I->p.direction=1;
          I->p.vx+=lateralspeed;
          fprintf(stderr," right \n");
          
        }
        else if(event.key.keysym.sym==I->c.controls[1])
        {
          I->p.moving=1;
          I->p.direction=0;
          I->p.vx-=lateralspeed;
          fprintf(stderr," left \n");
          
        }
        else if(event.key.keysym.sym==I->c.controls[3])
        {
          fprintf(stderr," attack\n");
          I->p.attack=1;
        }
        else if(event.key.keysym.sym==I->c.controls[2])
        {
          fprintf(stderr," jump \n");
          I->p.jump=1;
          
        }

      }
         if(event.key.keysym.sym==SDLK_ESCAPE)
        {
          fprintf(stderr," quit\n");
           I->boucle=Menu_Save(&(I->ss),I,ecran); 
        }
        break;
      }
      case SDL_QUIT:
      {
        I->boucle=Menu_Save(&(I->ss),I,ecran); 
        break;
      }
      
    }
  }
  /**********       Jump    *************/
  if (I->p.status == STAT_AIR) // (*2)
       { lateralspeed*= airlateralspeedfacteur;}
    if (I->p.direction==0) // (*1)
        {I->p.vx-=lateralspeed;}
    if (I->p.direction==0)
        {I->p.vx+=lateralspeed;}
    if (I->p.status == STAT_SOL) // (*3)
        {I->p.vx/=adherance;}

  if (I->p.vx>maxhspeed) // (*4)
    {I->p.vx = maxhspeed;}
  if (I->p.vx<-maxhspeed)
    {I->p.vx = -maxhspeed;}
  if (I->p.jump==1 && I->p.status == STAT_SOL)
    {Saute(&(I->p),impulsion);
      printf("jumpp\n");}

  Gravite(&(I->p),factgravite,factsautmaintenu);
  ControleSol(&(I->p));
  

  I->p.position.x+=I->p.vx;
  I->p.position.y+=I->p.vy;
 
  /******************   Deplacement personnage      *************/
  deplacer_perso(&(I->p),I->s.pos,dt,I->position_souris);
  
  /******************   update scrolling     *************/
  scrolling_update(&(I->s),I->p.position,width,height);

  if( I->e.killed==0)//si l'ennemi est encore en vie
  {
    /******************   update ennemi     *************/

    AI_Ennemy(&(I->e),I->p.position,I->s.pos);

    /******************   Collision avec l'ennemi     *************/
  
    if(collision(I->p.position,I->e.Position)==1 && I->p.attack==1)
    {
      I->e.killed=1;
    }
    else if(collision(I->p.position,I->e.Position)==1)
    {
      I->v.nb--;
    }

  }
  
  if(I->v.nb==0)
  {
    I->boucle=0;
  }

  /******************   Collision parfaite      *************/
  Coordinate C;
  if(I->p.direction==1)
  {
    C.X=I->p.position.x + I->p.position.w;
    C.Y=I->p.position.y + ( I->p.position.h /2);
    if(Collision_Parfaite(I->m.fondMask,C)==1)
    {
      I->p.position.x-=I->p.velocity;
    }
  }
  else
  {
    C.X=I->p.position.x ;
    C.Y=I->p.position.y + ( I->p.position.h /2);
    if(Collision_Parfaite(I->m.fondMask,C)==1)
    {
      I->p.position.x+=I->p.velocity;
    }
  }


  /******************   update score     *************/
  I->sc.scores=I->p.position.x/1000;

  /******************   Mini map      *************/
  Update_MiniMap(&(I->mm),I->p.position);
  
  
}


void FreeIntegaration(Integration *I)
{ 
  freefond(&(I->m));
  
  fprintf(stderr,"free game \n");  
}




/************************************* Save ********************************************/


void Save_Game(Integration *I)
{
  FILE* f=fopen("save.bin","wb");
  fwrite(I,sizeof(Integration),1,f);
  fclose(f);
}

void Load_Game(Integration *I,FILE *f)
{ 
  Integration tmp;
  fread(&tmp,sizeof(Integration),1,f);

  I->e.Position=tmp.e.Position;

  I->choixControl=tmp.choixControl;

  I->p.position.x=tmp.p.position.x;
  I->p.position.y=tmp.p.position.y;
  I->p.position.w=tmp.p.position.w;
  I->p.position.h=tmp.p.position.h;
  I->p.direction=tmp.p.direction;
  I->sc.scores=tmp.sc.scores;
  I->time.time=tmp.time.time;
  scrolling_update(&(I->s),I->p.position,width,height);
  fclose(f);
}



int Menu_Save(Save *s,Integration *I,SDL_Surface*ecran)
{
  Init_Save(s);
  SDL_Event event1;
  int continuer=1;
  SDL_EnableKeyRepeat(0,0);
  while(continuer==1)
  {
    Display_Save(s,ecran);
    while (SDL_PollEvent(&event1))
    {
      switch (event1.type)
      { 
        case SDL_KEYDOWN:
        {
          if(event1.key.keysym.sym==SDLK_ESCAPE)
            {
              SDL_EnableKeyRepeat(5,5);
              return 1;
            }
            break;
        }
        case SDL_MOUSEMOTION:
        {
          printf("Souris en position %d %d\n",event1.motion.x, event1.motion.y);
        }
        case SDL_MOUSEBUTTONUP:
        {

          if((event1.motion.x>s->savee.x && event1.motion.x<s->savee.x+s->savee.w)&&(event1.motion.y>s->savee.y && event1.motion.y<s->savee.y+s->savee.h))
          {
            s->image_courrante=1;
            if(event1.button.button == SDL_BUTTON_LEFT)
            {
              Save_Game(I);
              return 0;
            }
          }
          else if((event1.motion.x>s->exit.x && event1.motion.x<s->exit.x +s->exit.w)&&(event1.motion.y>s->exit.y  && event1.motion.y<s->exit.y+s->exit.h ))
          {
            s->image_courrante=2;
            if(event1.button.button == SDL_BUTTON_LEFT)
            {
              
              return 0;
            }
          }
          break;
        }

      }
    }
    if(s->image_courrante<1)
    {
      s->image_courrante=2;
    }
    if(s->image_courrante>2)
    {
      s->image_courrante=1;
    }
    
  }
}