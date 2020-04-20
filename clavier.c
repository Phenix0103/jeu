#include"clavier.h"


void UpdateEvent(clavier *in){
    SDL_Event event;
    while (SDL_PollEvent(&event)){
        switch (event.type){
            case SDL_KEYDOWN : // quand on presse 
                in -> key[event.key.keysym.sym] = 1; // la touche est presse
                break;
            case SDL_KEYUP : // quand on depresse
                in -> key[event.key.keysym.sym] = 0; // la touche n'est pas presse
                break;
            default :
                break;
        }
    }
}
