//
// Created by robin on 07/02/2022.
//
/**
 * \file main_controller.c
 * \brief Fonction principale du controller.
 *
 * Fonction principale pour la gestion du controller du projet
 */
#include "main_controller.h"

void controller(View_elements *app){
    SDL_Event event;
    int run =1;

    while (run ==1){
        SDL_WaitEvent(&event);
        switch(event.type){
            case SDL_QUIT: run =0;
            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button==SDL_BUTTON_LEFT){
                    if (event.button.windowID== SDL_GetWindowID(app->pwindow)){
                        run=0;
                    }
                }




        }
    }
}
