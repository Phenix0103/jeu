
#include <stdio.h>
#include  <stdlib.h>
#include  <SDL/SDL.h>
#include <SDL/SDL_image.h>
#include"obj.h"
#include"vie.h"

int collisionbb( SDL_Rect posj , SDL_Rect posobj  )
{
 int x ; 
if ( ((posj.y+posj.h>=posobj.y)&&(posj.y<=posobj.y+posobj.h)&&(posj.x+posj.w>=posobj.x)&&(posj.x<=posobj.x+posobj.w)) )
{
	x=1 ; 
}

else x=0 ; 
return x ;
}
/**  * @brief  init vie. 
 * @param vie    
 * @return Nothing  
*/
void initialiservie(vie *vie)
{

vie->position.x = 0 ;
vie->position.y = 0 ;
vie->fond1 = IMG_Load("1.png");
vie->fond2 = IMG_Load("2.png");
vie->fond3 = IMG_Load("3.png");
vie->fond4 = IMG_Load("4.png");
vie->fond5 = IMG_Load("5.png");
vie->fond6 = IMG_Load("6.jpg");

}
/**  * @brief  afficher vie . 
 * @param vie
 * @param posj
* @param  posobj
* @param  ecran
 * @param    i    
 * @return Nothing  
*/
void affichervie(vie *vie,SDL_Rect *posj , SDL_Rect posobj,SDL_Surface *ecran , int *i )
{
 int k=collisionbb( (*posj) , posobj );

if(k==1)
{
(*posj).x+=200;
(*i)++;

}


if((*i)==0)
{

SDL_BlitSurface(vie->fond1,NULL, ecran,&vie->position);
SDL_Flip(ecran);
}

else if((*i)==1)
{

SDL_BlitSurface(vie->fond2,NULL, ecran,&vie->position);
SDL_Flip(ecran);
}
else if((*i)==2)
{
//(*posj).x=0;
SDL_BlitSurface(vie->fond3,NULL, ecran,&vie->position);
SDL_Flip(ecran);
}
 else if((*i)==3)
{
//(*posj).x=0;
SDL_BlitSurface(vie->fond4,NULL, ecran,&vie->position);
SDL_Flip(ecran);
}
else if((*i)==4)
{
//(*posj).x=0;
SDL_BlitSurface(vie->fond5,NULL, ecran,&vie->position);
SDL_Flip(ecran);
}
 else if((*i)==5)
{
//(*posj).x=0;
SDL_BlitSurface(vie->fond6,NULL, ecran,&vie->position);
SDL_Flip(ecran);
}

//strsep(5);


}
//stop
void initialiserObj( Objet *obj , char name[] , int x , int y ) 
{

	       obj->image =  IMG_Load(name); 
	      if  ( obj->image  ==  NULL )  { 
         printf ( "Can not load image of tux: %s \n " , SDL_GetError ()); 
         exit ( 1 ); 
     } 
     else 
     {
 
     obj->position.x  =  x ; 
     obj->position.y  =  y ; 
     obj->position.h  =  obj->image->h ;
obj->position.w = obj->image->w ;
}

}
//stop
void affichageObj ( Objet obj , SDL_Surface *screen) 
{

SDL_BlitSurface(obj.image, NULL, screen, &(obj.position));
SDL_Flip(screen);

}
//stop 
int main (){
SDL_Init(SDL_INIT_EVERYTHING);

SDL_Surface *screen ; 
Objet Obj, Obj1 ; 
vie vie;
SDL_Event event ; 
int done=0 , i=0 ; 

 if  ( SDL_Init ( SDL_INIT_VIDEO )  == -1 )  { 
         printf ( "Can not init SDL \n " ); 
 
     } 

     screen  =  SDL_SetVideoMode ( 1280 ,  720 ,  32 ,  SDL_HWSURFACE  |  SDL_DOUBLEBUF ); 
     if  ( screen  ==  NULL )  { 
         printf ( "Can not set video mode: \n "); 
         
     } 

     SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  0,  0 , 0)); 
     
initialiservie(&vie);
     initialiserObj(&Obj ,"C.png" ,  0 ,  0 ) ; 
     affichageObj (Obj ,screen) ;
     initialiserObj( &Obj1 ,"F.png" ,  500 ,  200 ) ; 
     affichageObj (Obj1 ,screen) ;

 SDL_EnableKeyRepeat(10,10) ;
    while  ( done==0 )  { 
         while  (SDL_PollEvent ( &event ))  { 
             switch  ( event.type )  { 
             case  SDL_QUIT : 
                 done  =  1 ; 
                 break ;  
    case SDL_KEYDOWN:

        switch(event.key.keysym.sym)

        {
      case SDLK_ESCAPE : 
done=1 ; 

case SDLK_LEFT : 

Obj.position.x-=10 ; 
SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  0,  0 , 0));
affichageObj (Obj ,screen) ;
affichageObj (Obj1 ,screen) ;

break ; 

case SDLK_RIGHT : 

Obj.position.x+=10 ; 
SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  0,  0 , 0));
affichageObj (Obj ,screen) ;
affichageObj (Obj1 ,screen) ;
break ; 
case SDLK_UP : 

Obj.position.y-=10 ; 
SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  0,  0 , 0));
affichageObj (Obj ,screen) ;
affichageObj (Obj1 ,screen) ;
break ; 
case SDLK_DOWN : 

Obj.position.y+=10 ; 
SDL_FillRect ( screen ,  NULL ,  SDL_MapRGB ( screen -> format,  0,  0 , 0));
affichageObj (Obj ,screen) ;
affichageObj (Obj1 ,screen) ;
break ; 


break ; 

		 
	
}
 }
affichervie(&vie, &Obj.position,Obj1.position,screen,&i);
SDL_Flip(screen);
}




}
return 0 ; 
}



