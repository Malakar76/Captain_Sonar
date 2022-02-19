//
// Created by robin on 19/02/2022.
//

#include "main_view.h"

void init_rbutton(View_elements *app,SDL_Rect rect){
    app->Rbutton=rect;
}

//Fonctions pour les Règles
void init_rules(View_elements *app){
    SDL_SetRenderDrawColor(app->rRenderer,255,255,255,255);
    SDL_SetRenderTarget(app->rRenderer,app->rRegles);
    SDL_Rect rect = {400,0,200,50} ;
    SDL_RenderFillRect(app->rRenderer,&rect);
    SDL_SetRenderTarget(app->rRenderer,NULL);
    init_rbutton(app,rect);
}

void show_rules(View_elements *app){
    SDL_RenderCopy(app->rRenderer,app->rRegles,NULL,NULL);
    SDL_RenderPresent(app->rRenderer);
    app->window=Rules;
}

//Fonctions pour les Crédits
void init_credit(View_elements *app){
    SDL_SetRenderDrawColor(app->rRenderer,255,255,255,255);
    SDL_SetRenderTarget(app->rRenderer,app->cCredit);
    SDL_Rect rect = {400,0,200,50} ;
    SDL_RenderFillRect(app->rRenderer,&rect);
    SDL_SetRenderTarget(app->rRenderer,NULL);
}

void show_credit(View_elements *app){
    SDL_RenderCopy(app->rRenderer,app->cCredit,NULL,NULL);
    SDL_RenderPresent(app->rRenderer);
    app->window=Credits;
}
