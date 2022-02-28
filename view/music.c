//
// Created by robin on 21/02/2022.
//

/**
 * \file music.c
 * \brief Fichier de gestion du son.
 *
 * Fichier qui gère la musique dans le jeu
 */

#include "main_view.h"

//il faut remettre l'initialisation du module de la musique dans le controller.
void start_music(){
    Mix_Music *music;
    music=Mix_LoadMUS("Ressources/music_sample.mp3");
    if(!music) {
        printf("Mix_LoadMUS(\"Ressources/music_sample.mp3\"): %s\n", Mix_GetError());
    }
    if(Mix_PlayMusic(music, -1)==-1) {
        printf("Mix_PlayMusic: %s\n", Mix_GetError());
    }
    Mix_VolumeMusic(128);

}
