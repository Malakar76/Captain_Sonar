//
// Created by robin on 17/02/2022.
//

#include "main_view.h"

int init_battlefield(View_elements * app){
    SDL_Texture * tmp=NULL;
    SDL_Surface * surface=NULL;
    surface=IMG_Load("/home/robin/Projet_C/Ressources/Mission_Antartica.jpg");
    if (surface==NULL){
        fprintf(stderr, "Erreur SDL_CreateSurface : %s", SDL_GetError());
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(tmp);
        return EXIT_FAILURE;
    }
    tmp=SDL_CreateTextureFromSurface(app->rRenderer,surface);
    if (tmp==NULL){
        fprintf(stderr, "Erreur SDL_CreateTexture: %s", SDL_GetError());
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(tmp);
        return EXIT_FAILURE;
    }
    app->tBattlefield= SDL_CreateTexture(app->rRenderer,SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET,600,600);
    if (app->tBattlefield==NULL){
        fprintf(stderr, "Erreur SDL_CreateTexture: %s", SDL_GetError());
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(tmp);
        return EXIT_FAILURE;
    }
    SDL_SetRenderTarget(app->rRenderer, app->tBattlefield);
    SDL_RenderCopy(app->rRenderer, tmp, NULL, NULL);
    SDL_DestroyTexture(tmp);
    SDL_FreeSurface(surface);
    SDL_SetRenderTarget(app->rRenderer, NULL);
    return EXIT_SUCCESS;

}

void show_battlefield(View_elements *app){
    SDL_RenderCopy(app->rRenderer,app->tBattlefield,NULL,NULL);
    SDL_RenderPresent(app->rRenderer);
    app->window=Battlefield;
}

int init_choix_carte(View_elements * app){

}
void show_choix_carte(View_elements *app){
    SDL_RenderCopy(app->rRenderer,app->cCarte,NULL,NULL);
    SDL_RenderPresent(app->rRenderer);
    app->window=Choix_Carte;
}