//
// Created by robin on 17/02/2022.
//

/**
 * \file Menu.c
 * \brief Fichier Menu.
 *
 * Fichier qui gère la création et l'affichage du Menu
 */
#include "main_view.h"

int init_menu(View_elements *app) {
    SDL_Texture *tmp = NULL;
    SDL_Surface *surface = NULL;
    surface = IMG_Load("Ressources/Menu.jpg");
    if (surface == NULL) {
        fprintf(stderr, "Erreur SDL_CreateSurface : %s", SDL_GetError());
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(tmp);
        return EXIT_FAILURE;
    }
    tmp = SDL_CreateTextureFromSurface(app->rRenderer, surface);
    if (tmp == NULL) {
        fprintf(stderr, "Erreur SDL_CreateTexture: %s", SDL_GetError());
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(tmp);
        return EXIT_FAILURE;
    }
    SDL_SetRenderTarget(app->rRenderer, app->mMenu);
    SDL_Rect rect = {0, -1, 1600, 900};
    SDL_RenderCopy(app->rRenderer, tmp, &rect, NULL);
    SDL_DestroyTexture(tmp);
    SDL_FreeSurface(surface);
    SDL_SetRenderTarget(app->rRenderer, NULL);
    SDL_Rect rect1 = {650, 265, 300, 105};
    SDL_Rect rect2 = {650, 405, 300, 105};
    SDL_Rect rect3 = {650, 540, 300, 105};
    SDL_Rect rect4 = {650, 680, 300, 105};
    app->Mbutton[0]=rect1;
    app->Mbutton[1]=rect2;
    app->Mbutton[2]=rect3;
    app->Mbutton[3]=rect4;
    return EXIT_SUCCESS;
}

void show_menu(View_elements *app){
    SDL_RenderCopy(app->rRenderer,app->mMenu,NULL,NULL);
    SDL_RenderPresent(app->rRenderer);
    app->window=Menu;
}
