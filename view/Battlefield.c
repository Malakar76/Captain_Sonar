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
    SDL_SetRenderTarget(app->rRenderer, app->tBattlefield);
    SDL_Rect rect ={0,0,1000,750};
    SDL_RenderCopy(app->rRenderer, tmp, NULL, &rect);
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
    SDL_Texture * tmp=NULL;
    SDL_Surface * surface=NULL;
    surface=IMG_Load("/home/robin/Projet_C/Ressources/Choix_carte.jpg");
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
    SDL_SetRenderTarget(app->rRenderer, app->cCarte);
    SDL_Rect rect ={0,0,1600,900};
    SDL_RenderCopy(app->rRenderer, tmp, &rect, &rect);
    SDL_DestroyTexture(tmp);
    SDL_FreeSurface(surface);
    SDL_SetRenderTarget(app->rRenderer, NULL);
    SDL_Rect rect1={190,430,300,90};
    SDL_Rect rect2={950,430,300,90};
    app->CCarte[0]=rect1;
    app->CCarte[1]=rect2;
    return EXIT_SUCCESS;

}

void show_choix_carte(View_elements *app){
    SDL_RenderCopy(app->rRenderer,app->cCarte,NULL,NULL);
    SDL_RenderPresent(app->rRenderer);
    app->window=Choix_Carte;
}
