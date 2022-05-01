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
 * @param pg Strucutre qui gère le modèle
 */
void controller(View_elements * app,Playground * pg);
/**
 * \fn controller_battlefield(View_elements * app,Playground * pg,enum Carte choix)
 * \brief Permet de faire le pont entre la vue et le modèle pour le champ de bataille.
 * Fonctionnalité :
 *      -gère le champ de bataille
 * @param app Structure qui gère la vue
 * @param pg Strucutre qui gère le modèle
 * @param IA Entier valant 0 (joueur) ou 1 (IA) qui permet de savoir si l'on joue contre une IA ou un autre joueur
 * @param choix
 */
void controller_battlefield(View_elements * app,Playground * pg,enum Carte choix,int IA);

/**
 * \fn void controller_battlefield_IA(View_elements * app,Playground * pg,enum Carte choix)
 * Lance le controller dédié aux parties contre l'IA
 * @param app Structure qui gère la vue
 * @param pg Strucutre qui gère le modèle
 * @param choix Choix de la carte à lancer
 */
void controller_battlefield_IA(View_elements * app,Playground * pg,enum Carte choix);

/**
 * \fn void controller_battlefield_Joueur(View_elements * app,Playground * pg,enum Carte choix)
 * Lance le controlleur dédié aux parties JCJ
 * @param app Structure qui gère la vue
 * @param pg Strucutre qui gère le modèle
 * @param choix Choix de la carte à lancer
 */
void controller_battlefield_Joueur(View_elements * app,Playground * pg,enum Carte choix);

/**
 * \fn void actionIA_ctrl(View_elements * app,Playground * pg)
 * Gère l'affichage de l'action de l'IA et ses conséquences dans la vue
 * @param app Structure qui gère la vue
 * @param pg Strucutre qui gère le modèle
 * @param message message de retour éventuel
 */
void actionIA_ctrl(View_elements * app,Playground * pg,char message []);

/**
 * \fn int fin_partie(View_elements * app,Playground * pg)
 * Déclenche la fin de partie si l'un des deux joueurs à perdu et affiche l'écran de fin
 * @param app Structure qui gère la vue
 * @param pg Strucutre qui gère le modèle
 * @return Renvoi 1 si l'un des deux joueurs à perdu et 0 sinon
 */
int fin_partie(View_elements * app,Playground * pg);

#endif //PROJET_C_MAIN_CONTROLLER_H
