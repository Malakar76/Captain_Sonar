//
// Created by robin on 07/02/2022.
//

#ifndef PROJET_C_MAIN_VIEW_H
#define PROJET_C_MAIN_VIEW_H

#include "SDL2/SDL.h"
typedef struct {
    SDL_Window *pwindow;
    SDL_Renderer *pRenderer;
}View_elements;

int init_view(View_elements * app);
int free_view(View_elements * app);



#endif //PROJET_C_MAIN_VIEW_H
