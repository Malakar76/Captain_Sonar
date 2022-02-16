//
// Created by robin on 07/02/2022.
//
/**
 * \file main_view.h
 * \brief Fonction principale de la vue.
 *
 * Fonction principale pour la gestion de la vue du projet
 */

#ifndef PROJET_C_MAIN_VIEW_H
#define PROJET_C_MAIN_VIEW_H

#include "SDL2/SDL.h"

/**
 * \struct View_elements
 * \brief Elements de la vue
 *
 * Structure qui regroupe tout les éléments nécessaires pour gérer la vue du projet
 */
typedef struct {
    SDL_Window *pwindow; /**< Fenêtre principale SDl */
    SDL_Renderer *pRenderer; /**<Renderer associé à la fenêtre principale */
}View_elements;

/**
 * \fn int init_view(View_elements * app)
 * \brief initialise la vue et le renderer de la structure passée.
 * @param app Structure qui gère la vue
 * @return EXIT_SUCCES si tout va bien, EXIT_FAILURE sinon.
 */
int init_view(View_elements * app);
/**
 * \fn void free_view(View_elements * app)
 * \brief libère la vue et le renderer de la structure passée.
 * @param app Structure qui gère la vue
 */
void free_view(View_elements * app);



#endif //PROJET_C_MAIN_VIEW_H
