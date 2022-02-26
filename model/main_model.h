//
// Created by robin on 07/02/2022.
//
/**
 * \file main_model.h
 * \brief Fichier principal du model.
 *
 * Fichier principal pour la gestion du model du projet
 */
#ifndef PROJET_C_MAIN_MODEL_H
#define PROJET_C_MAIN_MODEL_H

#include "stdlib.h"

/**
 * \struct Playground
 * \brief Elements du modèle
 *
 * Structure qui regroupe tout les éléments nécessaires pour gérer le modèle du projet
 */
typedef struct {
  //   Carte * map;/**< Carte de jeu */
    // Joueur * J1;/**<Structure du joueur 1  */
    // Joueur * J2; /**<Structure du joueur 2 */
    int test;
}Playground;

/**
 * \fn int init_model(Playground * pg)
 * \brief initialise le modèle de la structure passé.
 * @param pg Structure qui gère le modèle
 * @return EXIT_SUCCES si tout va bien, EXIT_FAILURE sinon.
 */
int init_model(Playground * pg);

/**
 * \fn void free_model(Playground * pg)
 * \brief libère le modèle de la structure passée.
 * @param pg Structure qui gère le modèle
 */
void free_model(Playground * pg);

#endif //PROJET_C_MAIN_MODEL_H
