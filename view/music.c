//
// Created by robin on 21/02/2022.
//
#include "main_view.h"

void start_music(){
    Mix_Music *music;
    music=Mix_LoadMUS("/home/robin/Projet_C/Ressources/illumination-paul-yudin-main-version-02-48-17315.mp3");
    if(!music) {
        printf("Mix_LoadMUS(\"/home/robin/Projet_C/Ressources/illumination-paul-yudin-main-version-02-48-17315.mp3\"): %s\n", Mix_GetError());
    }
    if(Mix_PlayMusic(music, -1)==-1) {
        printf("Mix_PlayMusic: %s\n", Mix_GetError());
    }
    Mix_VolumeMusic(128);

}
