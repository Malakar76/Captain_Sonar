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
#include "time.h"
#include "string.h"
#include "stdio.h"
#include "math.h"

/**
 * \def NMAX
 * définie la largeur et longeur max de la carte
 */
#define NMAX 10

/**
 * \enum Actif
 * Permet de savoir qui est le joueur actif du tour
 */
 enum Actif{
    J1, /**< Le joueur actif est le J1 */
    J2  /**< Le joueur actif est le J2 */
};

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
    MIS, /**< MISSILE*/
    SURF, /**< SURFACE*/
    SON, /**< SONAR*/
    SIL, /**< SILENCE*/
    DEPLCMNT /**< DEPLACEMENT*/
};

/**
 * \struct SOUS-MARIN
 * Structure associée au sous-marin
 */
typedef struct {
    int ligne; /**< Position ligne du sous-marin*/
    int colonne; /**< Position colonne du sous-marin */
    int start[2]; /**< Position de départ du sous-marin */
}SOUS_MARIN;

/**
 * \struct JOUEUR
 * Structure du joueur qui regroupe tous les éléments propres à chaque joueur
 */
typedef struct{
    SOUS_MARIN *S_M; /**< Structure sous-marin associée*/
    int energie; /**< Energie du joueur , entre 0 et 4 */
    int vie; /**< Points de vie du joueur 2 au début */
    int calqueJ[NMAX][NMAX];/**< Carte de 10 par 10 Case qui stocke les informations des cases qui ont été occupée par le joueur vaut 1 si le joueur est passé par là 0 sinon */
    enum DIRECTION path[NMAX*NMAX]; /** < Tableau qui stocke les différentes directions empruntées par le sous-marin */
    int nbpath; /** < Stocke le nombre de déplacement du sous-marin */

}JOUEUR;

/**
 * \struct IA
 * Structure qui permet de stocker des informations relatives à l'IA
 */
typedef struct {
   enum OPTION lastaction; /**< Dernière action effectuée par l'IA */
   int  nbaction ; /**< Nombre d'actions depuis la dernière surface */
}IA;

/**
 * \struct Playground
 * \brief Structure principale du modèle
 * Structure qui regroupe tout les éléments nécessaires pour gérer le modèle du projet
 */
typedef struct {
    CARTE * map;/**< Carte de jeu */
    JOUEUR * J1;/**<Structure du joueur 1  */
    JOUEUR * J2; /**<Structure du joueur 2 */
    enum Actif actif;/**< Joueur actif du tour */
    IA * ia; /**< Structure pour l'IA */
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

/**
 * \fn init_calque(JOUEUR * joueur)
 * @param joueur Joueur dont il faut réinitialiser le calque
 * Initialise ou remet à 0 le calque du joueur j
 */
void init_calque(JOUEUR * joueur);

/**
 * \fn void choix_carte(Playground * pg,int a)
 * Initialise la carte de jeu correctement en fonction de la carte choisie
 * @param pg Structure du modèle
 * @param a Entier qui permet de déterminer la carte à charger
 */
void choix_carte(Playground * pg,int a);


//Gestion joueur

/**
 * \fn int init_joueur(JOUEUR *j)
 * Initialise la structure passée en paramètre et met tous les champs à 0
 * @param j Structure Joueur
 * @return EXIT_SUCCESS si tout va bien EXIT_FAILURE sinon
 */
int init_joueur(JOUEUR *j);

/**
 * \fn void reset_joueur(JOUEUR * j)
 * Reinitialise le joueur
 * @param j Structure Joueur
 */
void reset_joueur(JOUEUR * j);

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
 * \fn void energie_down(JOUEUR *j,int nb)
 * @param j Joueur sélectionné
 * @param nb valeur d'énergie à retirer
 */
void energie_down(JOUEUR *j,int nb);

/**
 * \fn void deplacement(Playground * pg,enum Actif actif,enum DIRECTION d)
 * \brief déplace un sous-marin
 * Déplace le sous-marin du joueur actif dans la direction indiquée et augmente son énergie
 * @param pg Structure du modèle
 * @param actif permet de savoir le joueur qui est en train de jouer
 * @param d direction de déplacement
 */
void deplacement(Playground * pg,enum Actif actif,enum DIRECTION d);

/**
 * \fn int deplacement_possible(Playground * pg,enum Actif actif, enum DIRECTION d)
 * Permet de savoir si le joueur actif peut déplacer son sous-marin dans la direction indiquée
 * @param pg Structure du modèle
 * @param actif permet de savoir le joueur qui est en train de jouer
 * @param d Direction dans laquelle se déplacer
 * @return 1 si déplacement dans la direction possible 0 sinon
 */
int deplacement_possible(Playground * pg,enum Actif actif, enum DIRECTION d);

/**
 * \fn void result_deplacement(Playground *pg,enum Actif actif,enum DIRECTION d,char message [])
 * Fonction qui renvoie une chaîne de caractère contenant un message indiquant le déplacement effectué
 * et utilisant la fonction deplacement
 * @param pg Structure du modèle
 * @param actif permet de savoir le joueur qui est en train de jouer
 * @param d Direction dans laquelle se déplacer
 * @param message Chaîne de caractère qui contient le message retour
 */
void result_deplacement(Playground *pg,enum Actif actif,enum DIRECTION d,char message []);

/**
 * \fn void start_Sous_Marin(JOUEUR *j,int ligne,int colonne,CARTE * c)
 * Positionne le sous-marin du joueur j à la position indiqué par la ligne et la colonne
 * et met à jour la carte
 * @param j Joueur sélectionné
 * @param ligne Ligne
 * @param colonne Colonne
 * @param c carte de jeu
 */
void start_Sous_Marin(JOUEUR *j,int ligne,int colonne,CARTE * c);

/**
 * \fn void sonar(Playground * pg,enum Actif actif,char message [])
 * La fonction prend en paramètre le joueur actif et stocke la position (soit ligne ou colonne de son adversaire) dans message
 * ex : L'ennemi se trouve dans la colonne B
 * ex : L'ennemi se trouve dans la ligne 3
 * @param pg Structure du modèle
 * @param actif permet de savoir le joueur qui est en train de jouer
 * @param message Stocke le message de retour
 */
void sonar(Playground * pg,enum Actif actif,char message[]);

/**
 * \fn int missile(Playground *pg,enum Actif actif,int ligne,int colonne)
 * La fonction permet au joueur de tirer un missile sur une case choisie à l'avance.
 * Si le tir ne touche rien, la fonction renvoie 0;
 * Si le joueur actif se touche lui-même la fonction renvoie -1;
 * Si le joueur touche l'adversaire la fonction renvoie 1;
 *
 * Si un tir touche l'un des deux joueurs ou les deux, chaque joueur perd 1 point de vie
 * @param pg Structure du modèle
 * @param actif permet de savoir le joueur qui est en train de jouer
 * @param ligne Ligne choisie par le joueur
 * @param colonne Colonne choisie par le joueur
 * @return -1,0 ou 1
 */
int missile(Playground *pg,enum Actif actif,int ligne,int colonne);

/**
 * \fn void surface(Playground *pg,enum Actif actif,char message[])
 * @param pg Structure du modèle
 * @param actif permet de savoir le joueur qui est en train de jouer
 * @param message Stocke le message de retour
 * Fonction qui permet au joueur de faire surface, cette action ne coûte pas d'énergie,
 * La fonction stocke dans la variable message un message type : "Nous avons fait surface"
 * L'ennemi sait précisément où le joueur est !
 * Remet à zéro le calque du joueur qui fait surface!
 */
void surface(Playground *pg,enum Actif actif,char message[]);

/**
 * \fn void result_missile(Playground *pg,enum Actif actif,int ligne,int colonne,char message [])
 * La fonction stocke un message qui indique si le joueur actif a réussi à toucher son adversaire dans le tableau message.
 * La fonction est basée sur le résultat de la fonction missile.
 * Résultat possible :
 * "Zut, vous n'avez rien touché"
 * "Mince alors, vous vous êtes touché vous même!"
 * "Bravo vous avez touché l'adversaire"
 * @param pg Structure du modèle
 * @param actif permet de savoir le joueur qui est en train de jouer
 * @param ligne Ligne choisie par le joueur
 * @param colonne Colonne choisie par le joueur
 * @param message Stocke le message de retour
 * @return Renvoie la valeur de la fonction missile (-1,1,0)
 */
int result_missile(Playground *pg,enum Actif actif,int ligne,int colonne,char message[]);

/**
 * \fn int enough_energie(Playground *pg,enum Actif actif,enum OPTION option)
 * Fonction qui permet de savoir si le joueur actif a assez d'énergie pour effectuer l'action
 * passée en paramètre.
 * @param pg Structure du modèle
 * @param actif permet de savoir le joueur qui est en train de jouer
 * @param option Permet de savoir l'action que le jouer veut faire
 * @return 1 si l'action peut être faite 0 sinon
 */
int enough_energie(Playground *pg,enum Actif actif,enum OPTION option);

/**
 * \fn int action(Playground *pg,enum Actif actif,enum OPTION option,enum DIRECTION d,int ligne,int colonne,char message [])
 * Réalise l'option passé en paramètre en appelant les fonction précédentes
 * ex : result missile
 * Et retourne une chaîne de caractère qui correspond à l'action éffectuée
 * @param pg Structure du modèle
 * @param actif permet de savoir le joueur qui est en train de jouer
 * @param option Permet de savoir l'action que le jouer veut faire
 * @param d Direction dans laquelle se déplacer
 * @param ligne ligne sélectionné par le joueur pour le missile
 * @param colonne colonne sélectionné par le joueur pour le missile
 * @param message Stocke le message de retour
 * @return Renvoi 1 si une action a bien été effectuée, 0 sinon
 */
int action(Playground *pg,enum Actif actif,enum OPTION option,enum DIRECTION d,int ligne,int colonne,char message []);

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

//IA

/**
 * \fn void actionIA(Playground * pg)
 * choisi une action pour l'IA
 * @param pg Structure du modèle
 * @return renvoi un entier qui contient l'action
 */
enum OPTION actionIA(Playground * pg);

/**
 * \fn enum OPTION actionIA2(Playground * pg);
 * IA avancée
 * @param pg Structure du modèle
 * @return renvoi un entier qui contient l'action
 */
enum OPTION actionIA2(Playground * pg);

#endif //PROJET_C_MAIN_MODEL_H
