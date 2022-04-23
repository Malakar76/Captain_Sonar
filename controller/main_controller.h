//
// Created by robin on 07/02/2022.
//
/**
 * \file main_controller.h
 * \brief Fichier principal du controller.
 *
 * Fichier principal pour la gestion du controller du projet
 */
#ifndef PROJET_C_MAIN_CONTROLLER_H
#define PROJET_C_MAIN_CONTROLLER_H

#include "../view/main_view.h"
#include "../model/main_model.h"

/**
 * \fn void controller(View_elements * app,Playground * pg)
 * \brief Permet de faire le pont entre la vue et le modèle.
 * Fonctionnalité :
 *      -gère le menu,
 *      -le choix de carte,
 *      -les crédits,
 *      -les règles
 * Passe la main à controller_battlefield pour la gestion de la partie
 * @param app Structure qui gère la vue
 * @param pg Strucutre qui gère le model
 */
void controller(View_elements * app,Playground * pg);
/**
 * \fn controller_battlefield(View_elements * app,Playground * pg,enum Carte choix)
 * \brief Permet de faire le pont entre la vue et le modèle pour le champ de bataille.
 * Fonctionnalité :
 *      -gère le champ de bataille
 * @param app Structure qui gère la vue
 * @param pg Strucutre qui gère le model
 */
void controller_battlefield(View_elements * app,Playground * pg,enum Carte choix);

#endif //PROJET_C_MAIN_CONTROLLER_H
