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
    int Resolution_x =1600;
    int Resolution_y=900;
    int statut = EXIT_FAILURE;
    IMG_Init(IMG_INIT_JPG);


    if (0 != SDL_Init(SDL_INIT_VIDEO)) {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        return statut;
    }
    if (0 != SDL_CreateWindowAndRenderer(Resolution_x, Resolution_y, SDL_WINDOW_SHOWN, &app->wwindow, &app->rRenderer)) {
        fprintf(stderr, "Erreur SDL_CreateWindowAndRenderer : %s", SDL_GetError());
        return statut;
    }
    app->tBattlefield= SDL_CreateTexture(app->rRenderer,SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET,Resolution_x,Resolution_y);
    if(NULL == app->tBattlefield) {
        fprintf(stderr, "Erreur SDL_CreateTexture : %s", SDL_GetError());
        return statut;
    }
    app->mMenu= SDL_CreateTexture(app->rRenderer,SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET,Resolution_x,Resolution_y);
    if(NULL == app->mMenu) {
        fprintf(stderr, "Erreur SDL_CreateTexture : %s", SDL_GetError());
        return statut;
    }
    app->rRegles= SDL_CreateTexture(app->rRenderer,SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET,Resolution_x,Resolution_y);
    if(NULL == app->rRegles) {
        fprintf(stderr, "Erreur SDL_CreateTexture : %s", SDL_GetError());
        return statut;
    }
    app->cCredit= SDL_CreateTexture(app->rRenderer,SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET,Resolution_x,Resolution_y);
    if(NULL == app->cCredit) {
        fprintf(stderr, "Erreur SDL_CreateTexture : %s", SDL_GetError());
        return statut;
    }
    app->cCarte= SDL_CreateTexture(app->rRenderer,SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET,Resolution_x,Resolution_y);
    if(NULL == app->cCarte) {
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
    SDL_DestroyTexture(app->cCarte);
    IMG_Quit();
    while (Mix_Init(0)){
        Mix_Quit();
    }
}



int init_all_view(View_elements *app){
    if(init_menu(app)!=EXIT_SUCCESS){
        return EXIT_SUCCESS;
    }
    if(init_battlefield(app) !=EXIT_SUCCESS){
        return EXIT_FAILURE;
    }
    if(init_choix_carte(app) !=EXIT_SUCCESS){
        return EXIT_FAILURE;
    }
    if(init_rules(app) !=EXIT_SUCCESS){
        return EXIT_FAILURE;
    }
    if(init_credit(app) !=EXIT_SUCCESS){
        return EXIT_FAILURE;
    }
    init_rbutton(app);
    return EXIT_SUCCESS;
}


