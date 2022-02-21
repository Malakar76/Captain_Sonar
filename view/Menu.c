//
// Created by robin on 17/02/2022.
//

#include "main_view.h"

void init_menu(View_elements *app){
    SDL_SetRenderDrawColor(app->rRenderer,255,255,255,255);
    SDL_SetRenderTarget(app->rRenderer,app->mMenu);
    int i=100;
    SDL_Rect rect = {200,0,200,50} ;
    for (int j=0;j<4;j++){
        rect.y=200+(j*i);
        SDL_RenderFillRect(app->rRenderer,&rect);
        app->Mbutton[j]=rect;
    }
    SDL_SetRenderTarget(app->rRenderer,NULL);

}

void show_menu(View_elements *app){
    SDL_RenderCopy(app->rRenderer,app->mMenu,NULL,NULL);
    SDL_RenderPresent(app->rRenderer);
    app->window=Menu;
}
