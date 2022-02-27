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
#define NMAX 10

/**
 * \struct Case
 * Structure qui représente une case de la carte
 */
typedef struct {
    int accessible;/**< Permet de savoir si la case est accessible, 0 oui et 1 non */
    int sous_marin;/**< Permet de savoir si il y a un sous-marin sur la case 0 non et 1 oui*/
}Case;

/**
 * \struct CARTE
 * Carte de jeu
 * La carte va donc de 0 à 9 car elle à une taille de 10 par 10
 */
typedef  struct {
    Case carte[NMAX][NMAX];/**< Carte de 10 par 10 Case qui stocke les informations sur chaque case */
}CARTE;

/**
 * \enum DIRECTION
 * Permet de savoir dans quelle direction il faut déplacer le sous-marin
 */
enum DIRECTION{
    haut, /**< Haut*/
    bas, /**< BAS*/
    gauche, /**< GAUCHE*/
    droite /**< DROITE*/
};

/**
 * \enum OPTION
 * Permet de savoir quelle action le joueur fait
 */
enum OPTION{
    missile, /**< MISSILE*/
    surface, /**< SURFACE*/
    sonar, /**< SONAR*/
    silence, /**< SILENCE*/
    deplacemnt /**< DEPLACEMENT*/
};

/**
 * \struct SOUS-MARIN
 * Structure associée au sous-marin
 */
typedef struct {
    int ligne; /**< Position ligne du sous-marin*/
    int colonne; /**< Position colonne du sous-marin */
}SOUS_MARIN;

/**
 * \struct JOUEUR
 * Structure du joueur qui regroupe tous les éléments propres à chaque joueur
 */
typedef struct{
    SOUS_MARIN *S_M; /**< Structure sous-marin associée*/
    int energie; /**< Energie du joueur , entre 0 et 4 */
    int vie; /**< Points de vie du joueur 2 au début */
}JOUEUR;

/**
 * \struct Playground
 * \brief Structure principale du modèle
 * Structure qui regroupe tout les éléments nécessaires pour gérer le modèle du projet
 */
typedef struct {
    CARTE * map;/**< Carte de jeu */
    JOUEUR * J1;/**<Structure du joueur 1  */
    JOUEUR * J2; /**<Structure du joueur 2 */
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


//Gestion Carte

/**
 * \fn void init_Case(Case * c)
 * Initialise une case comme étant accessible et non occupée
 * @param c Structure Case a initialiser
 */
void init_Case(Case * c);

/**
 * \fn void set_Rocher(CARTE * carte,int ligne,int colonne)
 * Met la case désignée par ligne et colonne comme étant inaccessible
 * @param carte La carte de jeu
 * @param ligne La ligne où il faut mettre le rocher (de 0 à 9)
 * @param colonne la colonne où il faut mettre le rocher (de 0 à 9)
 */
void set_Rocher(CARTE * carte,int ligne,int colonne);

/**
 * \fn int est_occupe(Case * c)
 * \brief teste l'accessiblité d'une case
 * Vérifie si la case c est accessible
 * @param c case à tester
 * @return 1 si la case est occupé 0 sinon
 */
int est_occupe(Case * c);

/**
 * \fn void free_Carte(CARTE * carte)
 * Libère la mémoire associée à la carte
 * @param carte Carte de jeu
 */
void free_Carte(CARTE * carte);

/**
 *\fn void init_map (CARTE * carte)
 * Initialise la carte de jeu avec des cases vides et chaque case est accessible
 * et inoccupée
 * @param carte Carte de jeu
 */
void init_map (CARTE * carte);


//Gestion joueur

/**
 * \fn int init_joueur(JOUEUR *j)
 * Initialise la structure passée en paramètre et met tous les champs à 0
 * @param j Structure Joueur
 * @return EXIT_SUCCESS si tout va bien EXIT_FAILURE sinon
 */
int init_joueur(JOUEUR *j);

/**
 * \fn void free_joueur(JOUEUR *j)
 * Libère la structure joueur
 * @param j Structure Joueur
 */
void free_joueur(JOUEUR *j);

/**
 * \fn void energie_up(JOUEUR *j)
 * Augmente la réserve d'énergie du joueur passé en paramètre
 * @param j Joueur sélectionné
 */
void energie_up(JOUEUR *j);

/**
 * \fn deplacement(JOUEUR *j,CARTE * c,enum DIRECTION d)
 * \brief déplace un sous-marin
 * Déplace un sous-marin dans la direction indiquée et augmente son énergie
 * @param j joueur qui se déplace
 * @param c carte du jeu
 * @param d direction de déplacement
 * @return 0 si déplacement impossible 1 sinon
 */
int deplacement(JOUEUR *j,CARTE * c,enum DIRECTION d);

/**
 * \fn void start_Sous_Marin(JOUEUR *j,int ligne,int colonne)
 * Positionne le sous-marin du joueur j à la position indiqué par la ligne et la colonne
 * et met à jour la carte
 * @param j Joueur sélectionné
 * @param ligne Ligne
 * @param colonne Colonne
 * @param c carte de jeu
 */
void start_Sous_Marin(JOUEUR *j,int ligne,int colonne,CARTE * c);


//Création Carte

/**
 * \fn void Crea_Archipelago(CARTE * c)
 * Initialise les rochers sur la carte;
 * @param c carte de jeu
 */
void Crea_Archipelago(CARTE * c);
/**
 * \fn void Crea_Antartica(CARTE * c)
 * Initialise les rochers sur la carte
 * @param c carte de jeu
 */
void Crea_Antartica(CARTE * c);


#endif //PROJET_C_MAIN_MODEL_H
