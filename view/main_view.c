//
// Created by robin on 07/02/2022.
//

/**
 * \file main_view.c
 * \brief Fonction principale de la vue.
 *
 * Fonction principale pour la gestion de la vue du projet
 */

#include "main_view.h"

int init_view(View_elements * app) {
    int statut = EXIT_FAILURE;
    IMG_Init(IMG_INIT_JPG);
    if (0 != SDL_Init(SDL_INIT_VIDEO)) {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        return statut;
    }
    if (0 != SDL_CreateWindowAndRenderer(600, 600, SDL_WINDOW_SHOWN, &app->wwindow, &app->rRenderer)) {
        fprintf(stderr, "Erreur SDL_CreateWindowAndRenderer : %s", SDL_GetError());
        return statut;
    }
    app->tBattlefield= SDL_CreateTexture(app->rRenderer,SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET,600,600);
    if(NULL == app->tBattlefield) {
        fprintf(stderr, "Erreur SDL_CreateTexture : %s", SDL_GetError());
        return statut;
    }
    app->mMenu= SDL_CreateTexture(app->rRenderer,SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET,600,600);
    if(NULL == app->mMenu) {
        fprintf(stderr, "Erreur SDL_CreateTexture : %s", SDL_GetError());
        return statut;
    }
    app->rRegles= SDL_CreateTexture(app->rRenderer,SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET,600,600);
    if(NULL == app->rRegles) {
        fprintf(stderr, "Erreur SDL_CreateTexture : %s", SDL_GetError());
        return statut;
    }
    app->cCredit= SDL_CreateTexture(app->rRenderer,SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET,600,600);
    if(NULL == app->cCredit) {
        fprintf(stderr, "Erreur SDL_CreateTexture : %s", SDL_GetError());
        return statut;
    }
    statut=EXIT_SUCCESS;
    return statut;

}

void free_view(View_elements *app){
    SDL_DestroyRenderer(app->rRenderer);
    SDL_DestroyWindow(app->wwindow);
    SDL_DestroyTexture(app->mMenu);
    SDL_DestroyTexture(app->tBattlefield);
    SDL_DestroyTexture(app->rRegles);
    SDL_DestroyTexture(app->cCredit);
    IMG_Quit();
}



int init_all_view(View_elements *app){
    init_menu(app);
    if(init_battlefield(app) !=EXIT_SUCCESS){
        return EXIT_FAILURE;
    }
    init_credit(app);
    init_choix_carte(app);
    init_rules(app);
    return EXIT_SUCCESS;
}
