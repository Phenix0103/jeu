#include "integrationm.h"


void Initialisationm(Integrationm *I)
{ 
  I->boucle=1;
  I->enigme=1;
 	initialiserfond(&(I->m));
  /****************************************/
 	perso_Init(&(I->p),1);
 	scrolling_initialiser(&(I->s),I->p.position,widthm,heightm);
  SDL_Rect posVie={700,0};
  initialiservie(&(I->v));
  I->v.position=posVie;
  SDL_Rect pos_ennemi={6000,400,150,150};
  Initialisation_Ennemi(&(I->e),pos_ennemi);
  /****************************************/
  perso_Init(&(I->p1),2);
  scrolling_initialiser(&(I->s1),I->p1.position,widthm,heightm);
  SDL_Rect posVie1={1600,0};
  initialiservie(&(I->v1));
  I->v1.position=posVie1;
  SDL_Rect pos_ennemi1={6000,400,150,150};
  Initialisation_Ennemi(&(I->e1),pos_ennemi1);
  initializerTemps(&(I->time));
  init_score(&(I->sc));
}

void DisplayIntegrationm(Integrationm *I,SDL_Surface *ecran)
{
  SDL_Rect posblit={0,0};
  afficherfond(&(I->m),I->s.pos,ecran,posblit);
  perso_Render(&(I->p),ecran);
  affichervie(&(I->v),ecran);
  if( I->e.killed==0)//si l'ennemi est encore en vie
  {
    Affichage_Ennemi(&(I->e),ecran);
  }
  /***********************************************/
  SDL_Rect posblit1={900,0};
  afficherfond(&(I->m),I->s1.pos,ecran,posblit1);
  perso_Render(&(I->p1),ecran);
  affichervie(&(I->v1),ecran);
  if( I->e1.killed==0)//si l'ennemi est encore en vie
  {
    Affichage_Ennemi(&(I->e1),ecran);
  }



  afficherTemps(&(I->time),ecran);
  afficherscore(&(I->sc),ecran);

  SDL_Flip(ecran);


  I->p.attack=0;
  I->p.jump=0;

  I->p1.attack=0;
  I->p1.jump=0;
}


void PlayIntegrationm(Integrationm *I,SDL_Surface *ecran)
{
  Uint32 t_prev,dt=1;

  DisplayIntegrationm(I,ecran);
  while(I->boucle==1)
  {  
    t_prev=SDL_GetTicks();
    UpdateIntegrationm(I,dt,ecran);
    DisplayIntegrationm(I,ecran);

    if((I->p.position.x>4000 || I->p1.position.x>4000) && I->enigme==1)
    {
      I->boucle=jouer_enigme(ecran);
      I->enigme++;
      ecran = SDL_SetVideoMode(1800, 600,32, SDL_HWSURFACE | SDL_DOUBLEBUF);
    }

    if(I->p.position.x>7500 || I->p1.position.x>7500)
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




void NewIntegrationm(Integrationm *I,SDL_Surface *ecran)
{
printf ("init game");
Initialisationm(I);
SDL_EnableKeyRepeat(5,5);
do
{
printf ("play game");
PlayIntegrationm(I,ecran);
}
while (I->boucle==1);
	FreeIntegarationm(I);
}


void UpdateIntegrationm(Integrationm*I,Uint32 dt,SDL_Surface*ecran)
{  
  SDL_Event event;
    
  while(SDL_PollEvent(&event))
  {
    switch (event.type)
    {
      case SDL_KEYDOWN:
      {
        if(event.key.keysym.sym==SDLK_RIGHT)
        {
          I->p.moving=1;
          I->p.direction=1;
          fprintf(stderr," right \n");
          
        }
        else if(event.key.keysym.sym==SDLK_LEFT)
        {
          I->p.moving=1;
          I->p.direction=0;
          fprintf(stderr," left \n");
          
        }
        else if(event.key.keysym.sym==SDLK_RETURN)
        {
          fprintf(stderr," attack\n");
          I->p.attack=1;
        }
        else if(event.key.keysym.sym==SDLK_SPACE)
        {
          fprintf(stderr," jump \n");
          I->p.jump=1;
          
        }
        else if(event.key.keysym.sym==SDLK_d)
        {
          fprintf(stderr," right\n");
          I->p1.moving=1;
          I->p1.direction=1;
        }
        else if(event.key.keysym.sym==SDLK_q)
        {
          I->p1.moving=1;
          I->p1.direction=0;
          fprintf(stderr," left \n");
        }
        else if(event.key.keysym.sym==SDLK_z)
        {
          I->p1.jump=1;
          fprintf(stderr," jump \n");
        }
        else if(event.key.keysym.sym==SDLK_s)
        {
          I->p1.attack=1;
          fprintf(stderr," attack \n");
        }
        else if(event.key.keysym.sym==SDLK_ESCAPE)
        {
          fprintf(stderr," quit\n");
          I->boucle=0;
           
        }
        break;
      }
      case SDL_QUIT:
      {
        I->boucle=0;
        break;
      }
      
    }
  }
  /**********       Jump1    *************/
   /********** JUmp *************/
  float lateralspeed = 0.5f;
  float airlateralspeedfacteur = 0.5f;
  float maxhspeed = 3.0f;
  float adherance = 1.5f;//pour le freinage et sous 1 n'a pas de sens
  float impulsion = 6.0f;
  float factgravite = 0.5f;
  float factsautmaintenu = 3.0f;
  /********** JUmp *************/

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

  /**********       Jump2    *************/
   /********** JUmp *************/
  float lateralspeed1 = 0.5f;
  float airlateralspeedfacteur1 = 0.5f;
  float maxhspeed1 = 3.0f;
  float adherance1 = 1.5f;//pour le freinage et sous 1 n'a pas de sens
  float impulsion1 = 6.0f;
  float factgravite1 = 0.5f;
  float factsautmaintenu1 = 3.0f;
  /********** JUmp *************/

  if (I->p1.status == STAT_AIR) // (*2)
       { lateralspeed1*= airlateralspeedfacteur1;}
    if (I->p1.direction==0) // (*1)
        {I->p1.vx-=lateralspeed1;}
    if (I->p1.direction==0)
        {I->p1.vx+=lateralspeed1;}
    if (I->p1.status == STAT_SOL) // (*3)
        {I->p1.vx/=adherance1;}

  if (I->p1.vx>maxhspeed1) // (*4)
    {I->p1.vx = maxhspeed1;}
  if (I->p1.vx<-maxhspeed1)
    {I->p1.vx = -maxhspeed1;}
  if (I->p1.jump==1 && I->p1.status == STAT_SOL)
    {Saute(&(I->p1),impulsion1);
      printf("jumpp\n");}

  Gravite(&(I->p1),factgravite1,factsautmaintenu1);
  ControleSol(&(I->p1));
  

  I->p1.position.x+=I->p1.vx;
  I->p1.position.y+=I->p1.vy;

  /******************************************************************/

  deplacer_perso(&(I->p),I->s.pos,dt,I->position_souris);
  
  scrolling_update(&(I->s),I->p.position,widthm,heightm);


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

  if( I->e1.killed==0)//si l'ennemi est encore en vie
  {
    /******************   update ennemi     *************/
    SDL_Rect posBlitEnnemy2=I->s.pos;
    posBlitEnnemy2.x+600;
    AI_Ennemy(&(I->e1),I->p.position,posBlitEnnemy2);

    /******************   Collision avec l'ennemi     *************/
  
    if(collision(I->p1.position,I->e1.Position)==1 && I->p1.attack==1)
    {
      I->e1.killed=1;
    }
    else if(collision(I->p1.position,I->e1.Position)==1)
    {
      I->v1.nb--;
    }

  }

  if(I->v.nb==0 || I->v1.nb==0)
  {
    I->boucle=0;
  }

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


  /******************************************************************/

  deplacer_perso(&(I->p1),I->s1.pos,dt,I->position_souris);
  
  scrolling_update(&(I->s1),I->p1.position,widthm,heightm);

  AI_Ennemy(&(I->e1),I->p1.position,I->s1.pos);

  if(collision(I->p1.position,I->e1.Position)==1)
  {
    I->v1.nb--;
  }

  if(I->v1.nb==0)
  {
    I->boucle=0;
  }

  Coordinate C1;
  if(I->p1.direction==1)
  {
    C1.X=I->p.position.x + I->p1.position.w;
    C1.Y=I->p.position.y + ( I->p1.position.h /2);
    if(Collision_Parfaite(I->m.fondMask,C1)==1)
    {
      I->p1.position.x-=I->p1.velocity;
    }
  }
  else
  {
    C1.X=I->p1.position.x ;
    C1.Y=I->p1.position.y + ( I->p1.position.h /2);
    if(Collision_Parfaite(I->m.fondMask,C1)==1)
    {
      I->p1.position.x+=I->p1.velocity;
    }
  }


  /******************   update score pour les deux joueurs    *************/
  I->sc.scores=(I->p.position.x+I->p1.position.x)/2000;
  /******************     *************/

  I->p1.position_camera.x+=900;
  I->e1.Pos_real.x+=900;
  
}


void FreeIntegarationm(Integrationm *I)
{ 
  freefond(&(I->m));
  
  fprintf(stderr,"free game \n");  
}
