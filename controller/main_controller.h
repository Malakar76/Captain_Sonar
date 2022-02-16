//
// Created by robin on 07/02/2022.
//
/**
 * \file main_controller.h
 * \brief Fonction principale du controller.
 *
 * Fonction principale pour la gestion du controller du projet
 */
#ifndef PROJET_C_MAIN_CONTROLLER_H
#define PROJET_C_MAIN_CONTROLLER_H

#include "../view/main_view.h"
#include "../model/main_model.h"

/**
 * \fn void controller(View_elements * app,Playground * pg)
 * \brief Permet de faire le pont entre la vue et le modèle.
 * Fonctionnalité :
 *      - Ferme la fenêtre si l'utilisateur clique sur la croix.
 *      - Ferme la fenêtre si l'utilisateur fait un clique gauche sur la fenêtre.
 * @param app Structure qui gère la vue
 * @param pg Strucutre qui gère le model
 */
void controller(View_elements * app,Playground * pg);

#endif //PROJET_C_MAIN_CONTROLLER_H
