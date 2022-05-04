//
// Created by robin on 19/02/2022.
//
/**
 * \file rules_and_credit.c
 * \brief Fichier Règles et Crédits.
 *
 * Fichier qui gère la création et l'affichage des règles et des crédits
 * mais aussi la musique
 */

#include "main_view.h"

void init_rbutton(View_elements *app){
    SDL_Rect rect = {1470,0,130,120} ;
    app->Rbutton=rect;
}

//Fonctions pour les Règles
int init_rules(View_elements *app){
    SDL_Texture * tmp=NULL;
    SDL_Surface * surface=NULL;
    surface=IMG_Load("Ressources/Rules.jpg");
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
    SDL_SetRenderTarget(app->rRenderer, app->rRegles);
    SDL_Rect rect ={0,0,1600,900};
    SDL_RenderCopy(app->rRenderer, tmp, &rect, &rect);
    SDL_DestroyTexture(tmp);
    SDL_FreeSurface(surface);
    SDL_SetRenderTarget(app->rRenderer, NULL);
    return EXIT_SUCCESS;
}

void show_rules(View_elements *app){
    SDL_RenderCopy(app->rRenderer,app->rRegles,NULL,NULL);
    SDL_RenderPresent(app->rRenderer);
    app->window=Rules;
}

//Fonctions pour les Crédits
int init_credit(View_elements *app){
    SDL_Texture * tmp=NULL;
    SDL_Surface * surface=NULL;
    surface=IMG_Load("Ressources/Credits.jpg");
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
    SDL_SetRenderTarget(app->rRenderer, app->cCredit);
    SDL_Rect rect ={0,0,1600,900};
    SDL_RenderCopy(app->rRenderer, tmp, &rect, &rect);
    SDL_DestroyTexture(tmp);
    SDL_FreeSurface(surface);
    SDL_SetRenderTarget(app->rRenderer, NULL);
    return EXIT_SUCCESS;
}

void show_credit(View_elements *app){
    SDL_RenderCopy(app->rRenderer,app->cCredit,NULL,NULL);
    SDL_RenderPresent(app->rRenderer);
    app->window=Credits;
}

int start_music(Mix_Music * music){
    music=Mix_LoadMUS("Ressources/music_sample.mp3");
    if(!music) {
        printf("Mix_LoadMUS(\"Ressources/music_sample.mp3\"): %s\n", Mix_GetError());
    }
    if(Mix_PlayMusic(music, -1)==-1) {
        printf("Mix_PlayMusic: %s\n", Mix_GetError());
    }
    Mix_VolumeMusic(128);
    return 1;
}

int resume_music(View_elements * app){
    SDL_Rect rect={508,43,159,155};
    Mix_ResumeMusic();
    SDL_SetRenderTarget(app->rRenderer,app->VBattlefield->Battlefield_current);
    SDL_RenderCopy(app->rRenderer,app->VBattlefield->FinSon,&rect,&app->VBattlefield->Bbutton[9]);
    SDL_SetRenderTarget(app->rRenderer,NULL);
    SDL_RenderCopy(app->rRenderer,app->VBattlefield->Battlefield_current,NULL,NULL);
    SDL_RenderPresent(app->rRenderer);
    return 1;
}

int pause_music(View_elements * app){
    SDL_Rect rect={507,204,159,155};
    Mix_PauseMusic();
    SDL_SetRenderTarget(app->rRenderer,app->VBattlefield->Battlefield_current);
    SDL_RenderCopy(app->rRenderer,app->VBattlefield->FinSon,&rect,&app->VBattlefield->Bbutton[9]);
    SDL_SetRenderTarget(app->rRenderer,NULL);
    SDL_RenderCopy(app->rRenderer,app->VBattlefield->Battlefield_current,NULL,NULL);
    SDL_RenderPresent(app->rRenderer);
    return 0;
}
