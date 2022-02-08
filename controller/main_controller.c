//
// Created by robin on 07/02/2022.
//

#include "main_controller.h"
void controller(View_elements *app){
    SDL_Event event;
    int run =1;

    while (run ==1){
        SDL_WaitEvent(&event);
        switch(event.type){
            case SDL_QUIT: run =0;
        }
    }
}