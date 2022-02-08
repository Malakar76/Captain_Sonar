//
// Created by robin on 07/02/2022.
//

#include "main_view.h"

int init_view(View_elements * app) {
    int statut = EXIT_FAILURE;
    if (0 != SDL_Init(SDL_INIT_VIDEO)) {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        return statut;
    }
    if (0 != SDL_CreateWindowAndRenderer(600, 6000, SDL_WINDOW_SHOWN, &app->pwindow, &app->pRenderer)) {
        fprintf(stderr, "Erreur SDL_CreateWindowAndRenderer : %s", SDL_GetError());
        return statut;
    }
    statut=EXIT_SUCCESS;
    return statut;

}

int free_view(View_elements *app){
    SDL_DestroyRenderer(app->pRenderer);
    SDL_DestroyWindow(app->pwindow);
}