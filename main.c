//
// Created by robin on 07/02/2022.
//
/**
 * \file main.c
 * \brief Fichier principal du projet.
 *
 * Fichier principal qui appelle les différentes fonctions pour initialiser le modèle et la vue puis donne la main au controleur.
 */
#include "controller/main_controller.h"

int main (){
    View_elements app;
    Playground pg;
    if((init_view(&app)&& init_model(&pg)) !=EXIT_SUCCESS){
        free_view(&app);
        free_model(&pg);
        return EXIT_FAILURE;
    }
    if(init_all_view(&app) !=EXIT_SUCCESS){
        free_view(&app);
        free_model(&pg);
        return EXIT_FAILURE;
    }
    controller(&app,&pg);
    free_view(&app);
    free_model(&pg);
    return EXIT_SUCCESS;
}

