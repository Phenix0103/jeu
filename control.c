#include "control.h"


void Init_Control(Control *c)
{
	FILE *fic;
	fic = fopen("settings.bin", "rb") ;
	if (fic==NULL){
		c->controls[0]=SDLK_RIGHT;
		c->controls[1]=SDLK_LEFT;
		c->controls[2]=SDLK_SPACE;
		c->controls[3]=SDLK_RETURN;
	}
	else{
		Control tmp;//temporaire 
		fread(&tmp,sizeof(Control),1,fic);
		c->controls[0]=tmp.controls[0];
		c->controls[1]=tmp.controls[1];
		c->controls[2]=tmp.controls[2];
		c->controls[3]=tmp.controls[3];
		fclose(fic) ;
	}
	
}


void Save_Control(Control c)
{
	FILE* fic=fopen("settings.bin","wb");
	fwrite(&c,sizeof(Control),1,fic);
	fclose(fic);
}

int select_settings(int i,Control *tmp)
{
  SDL_Event event1;
  int settings =1;
  printf("appuie.\n");
  SDL_EnableKeyRepeat(0,0);
  while(settings==1)
  {
    while(SDL_PollEvent(&event1))
    {
      if(event1.type==SDL_KEYDOWN)
        {
            tmp->controls[i]=event1.key.keysym.sym;          
            settings=0;
        } 
        else
        {
          settings=0;
        }  
    }
  }
  return 0;
}



int menukeyboard(SDL_Surface *ecran)
{
    SDL_Event event2;
    int boucle=1;

    Control c;
    Init_Control(&c);

    Control tmp=c;

    TTF_Init();//initialisation de TTF
    TTF_Font *police = NULL;//creation de pointeur Font
    SDL_Color couleurBlanche = {255,255,255},couleurNoir = {0,0,0};
    police = TTF_OpenFont("afont.ttf", 30);
    
    SDL_Surface *texte[5],*texte1[5],*back;
    back=IMG_Load("ah.png");
        
    SDL_Rect position_text1={570,270};
    SDL_Rect position_text2={570,330};
    SDL_Rect position_text3={570,387};
    SDL_Rect position_text4={570,440};

    SDL_Rect position_text11={300,270};
    SDL_Rect position_text22={300,330};
    SDL_Rect position_text33={300,387};
    SDL_Rect position_text44={300,440};

        texte1[0] = TTF_RenderText_Blended(police,"Move Right", couleurNoir);
        texte1[1] = TTF_RenderText_Blended(police,"Move Left", couleurNoir);
        texte1[2] = TTF_RenderText_Blended(police,"Jump", couleurNoir);
        texte1[3] = TTF_RenderText_Blended(police,"Attack", couleurNoir);
   
    SDL_EnableKeyRepeat(0,0);
    while(boucle==1)
    {

        for(int i=0;i<4;i++){
            texte[i] = TTF_RenderText_Blended(police,SDL_GetKeyName(tmp.controls[i]) , couleurNoir);
        }
        


        SDL_BlitSurface(back, NULL, ecran, NULL); 
        SDL_BlitSurface(texte[0], NULL, ecran, &position_text1); 
        SDL_BlitSurface(texte[1], NULL, ecran, &position_text2); 
        SDL_BlitSurface(texte[2], NULL, ecran, &position_text3); 
        SDL_BlitSurface(texte[3], NULL, ecran, &position_text4); 

        SDL_BlitSurface(texte1[0], NULL, ecran, &position_text11); 
        SDL_BlitSurface(texte1[1], NULL, ecran, &position_text22); 
        SDL_BlitSurface(texte1[2], NULL, ecran, &position_text33); 
        SDL_BlitSurface(texte1[3], NULL, ecran, &position_text44); 

        SDL_Flip(ecran);
    

        
        SDL_PollEvent(&event2);
        
        switch (event2.type)
        { 
            case SDL_KEYDOWN:
            {
                if(event2.key.keysym.sym==SDLK_ESCAPE)
                {
                  Save_Control(tmp);
                  return 0;
                }
                break;
            }
            case SDL_MOUSEMOTION:
            {
                printf("Souris en position %d %d\n",event2.motion.x, event2.motion.y);
            }
            case SDL_MOUSEBUTTONUP:
            {

                if((event2.motion.x>570 && event2.motion.x<630)&&(event2.motion.y>283 && event2.motion.y<304))
                {
                    if(event2.button.button == SDL_BUTTON_LEFT)
                    {
                        printf("appuie.\n");
                        select_settings(0,&tmp);
                    }

                }
                else if((event2.motion.x>570 && event2.motion.x<630)&&(event2.motion.y>340 && event2.motion.y<363))
                {
                    if(event2.button.button == SDL_BUTTON_LEFT)
                    {
                        select_settings(1,&tmp);
                    }
                    
                }
                else if((event2.motion.x>570 && event2.motion.x<630)&&(event2.motion.y>405 && event2.motion.y<425))
                {
                    if(event2.button.button == SDL_BUTTON_LEFT)
                    {
                        select_settings(2,&tmp);
                    }
                    
                }
                else if((event2.motion.x>570 && event2.motion.x<630)&&(event2.motion.y>453 && event2.motion.y<473))
                {
                    if(event2.button.button == SDL_BUTTON_LEFT)
                    {
                        select_settings(3,&tmp);
                    }
                    
                }
                break;
            }
            case SDL_QUIT:
            {           
                Save_Control(tmp);

                for(int i=0;i<4;i++){
                    SDL_FreeSurface(texte[i]);
                }

                SDL_Quit();
            }
        }
        for(int i=0;i<4;i++){
            SDL_FreeSurface(texte[i]);
        }   
    }           

}