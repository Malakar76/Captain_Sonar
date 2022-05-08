//
// Created by robin on 08/05/2022.
//

/**
 * \file Music.c
 * \brief Fichier Musique.
 * Fichier qui gère la création et l'utilisation de la musique
 */

#include "main_view.h"

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
