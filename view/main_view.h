//
// Created by robin on 07/02/2022.
//
/**
 * \file main_view.h
 * \brief Fichier principal de la vue.
 *
 * Fichier principal pour la gestion de la vue du projet
 */

#ifndef PROJET_C_MAIN_VIEW_H
#define PROJET_C_MAIN_VIEW_H

#include "SDL2/SDL.h"
#include "SDL2/SDL_image.h"
#include "SDL2/SDL_mixer.h"

/**
 * \enum Window
 * \brief Permet de savoir quelle fenêtre est affichée
 *
 * Enumération qui permet de savoir quelle est la fenêtre affichée
 */
enum Window {
    Menu, /**< Fenêtre du menu */
    Battlefield, /**< Fenêtre du champ de bataille */
    Choix_Carte, /**< fenêtre du choix de la carte */
    Rules, /**< Fenêtre des règles */
    Credits /**< Fenêtre des Crédits */
};

/**
 * \enum Carte
 * \brief Permet de savoir quelle carte a été choisie par le joueur
 *
 * Enumération qui permet de savoir quelle est la carte sélectionnée par le joueur
 */
enum Carte {
    Archipelago, /**< Carte 1 */
    Antartica /**< Carte 2 */
};

/**
 * \struct View_Battlefield
 * \brief Elements de la vue du Battlefield
 *
 * Structure qui regroupe tout les éléments nécessaires pour gérer la vue du champ de bataille
 */
typedef struct {
    SDL_Texture *Battlefield_current;/**< Texture qui garde l'aperçu de la fenêtre de jeu affiché */
    SDL_Texture *Battlefield_blank;/**< Texture qui garde l'aperçu de la fenêtre de jeu clean*/
    SDL_Texture *Sous_marin;/**< Texture qui garde l'aperçu du sous_marin */
    SDL_Rect  Bbutton[7] ;/** < Tableau qui stocke l'emplacement des boutons du champ de bataille*/
    SDL_Rect Carte[10][10];/**< Tableau qui stocke l'emplacement des cases du champ de bataille */
}View_Battlefield;

/**
 * \struct View_elements
 * \brief Elements de la vue
 *
 * Structure qui regroupe tout les éléments nécessaires pour gérer la vue du projet
 */
typedef struct {
    SDL_Window *wwindow; /**< Fenêtre principale SDl */
    SDL_Renderer *rRenderer; /**<Renderer associé à la fenêtre principale */
    View_Battlefield * VBattlefield ;/**< Structure qui stocke les inforamtions de la vue du champ de bataille */
    SDL_Texture *mMenu;/** < Texture qui garde l'aperçu du menu principal */
    SDL_Rect  Mbutton[4] ;/** < Tableau qui stocke l'emplacement des boutons du menu */
    SDL_Rect  Rbutton;  /** < Rectangle qui stocke l'emplacement du bouton retour */
    SDL_Texture *rRegles;/** <Texture qui garde l'aperçu des règles */
    SDL_Texture *cCredit;/** <Texture qui garde l'aperçu des crédits */
    SDL_Texture *cCarte; /** <Texture qui garde l'aperçu du choix des cartes */
    SDL_Rect  CCarte[4] ;/** < Tableau qui stocke l'emplacement des boutons du choix des cartes */
    enum Window window;/** <Permet de savoir qu'elle est la fenêtre actuellement utilisée */

}View_elements;



//Fonction Globale

/**
 * \fn int init_view(View_elements * app)
 * \brief initialise la vue et le renderer de la structure passée.
 * Initialise toutes les textures de la structure passée, le renderer et la fenêtre
 * Mais initialise aussi le module qui permet d'ouvrir les images JPG
 * @param app Structure qui gère la vue
 * @return EXIT_SUCCES si tout va bien, EXIT_FAILURE sinon.
 */
int init_view(View_elements * app);
/**
 * \fn void free_view(View_elements * app)
 * \brief libère la fenêtre,le renderer et les textures de la structure passée.
 * @param app Structure qui gère la vue
 */
void free_view(View_elements * app);
/**
 * \fn int init_all_view(View_elements *app)
 * \brief Remplit toutes les textures de la structure.
 * Remplit chaque fenêtre les unes après les autres avec la bonne texture
 * @param app Structure qui gère la vue
 * @return EXIT_SUCCES si tout va bien, EXIT_FAILURE sinon.
 */
int init_all_view(View_elements *app);


// Fonctions pour le champ de bataille

/**
 * \fn int init_view_battlefield(View_elements * app,enum Carte c)
 * \brief Initialise la Structure VBattlefield.
 * Applique la bonne texture au différentes textures de la structure
 * Crée les différents boutons
 * @param app Structure qui gère la vue
 * @param c Permet de savoir la carte choisie
 * @return EXIT_SUCCES si tout va bien, EXIT_FAILURE sinon.
 */
int init_view_battlefield(View_elements * app,enum Carte c);
/**
 * \fn int init_battlefield_blank(View_elements * app,enum Carte c)
 * \brief Initialise la texture du champ de bataille
 * Applique la bonne texture
 * @param app Structure qui gère la vue
 * @param c Permet de savoir la carte choisie
 * @return EXIT_SUCCES si tout va bien, EXIT_FAILURE sinon.
 */
int init_battlefield(View_elements * app,enum Carte c);
/**
 * \fn int init_sousmarin(View_elements * app)
 * \brief Initialise la texture du sous-marin
 * Applique la bonne texture
 * @param app Structure qui gère la vue
 * @return EXIT_SUCCES si tout va bien, EXIT_FAILURE sinon.
 */
int init_sousmarin(View_elements * app);

/**
 * \fn void show_battlefield(View_elements *app)
 * \brief Affiche le battlefield.
 * Remplace la fenêtre précédente par la texture du champ de bataille
 * @param app Structure qui gère la vue
 */
void show_battlefield(View_elements *app);
/**
 * \fn int init_choix_carte(View_elements * app)
 * \brief Initialise le choix de carte.
 * Applique la bonne texture au choix de carte
 * @param app Structure qui gère la vue
 * @return EXIT_SUCCES si tout va bien, EXIT_FAILURE sinon.
 */
int init_choix_carte(View_elements * app);
/**
 * \fn void show_choix_carte(View_elements *app)
 * \brief Affiche le choix de carte
 * Remplace la fenêtre précédente par la texture du choix de la carte
 * @param app Structure qui gère la vue
 */
void show_choix_carte(View_elements *app);


// Fonctions pour le Menu

/**
 * \fn int init_menu(View_elements *app)
 * \brief Initialise le Menu.
 * Applique la bonne texture au menu
 * @param app Structure qui gère la vue
 * @return EXIT_SUCCES si tout va bien, EXIT_FAILURE sinon.
 */
int init_menu(View_elements *app);
/**
 * \fn void show_menu(View_elements *app)
 * \brief Affiche le menu
 * Remplace la fenêtre précédente par la texture du menu
 * @param app Structure qui gère la vue
 */
void show_menu(View_elements *app);


//Fonctions pour les Règles

/**
 * \fn int init_rules(View_elements *app)
 * \brief Initialise les règles
 * Applique la bonne texture au règles
 * @param app Structure qui gère la vue
 * @return EXIT_SUCCES si tout va bien, EXIT_FAILURE sinon.
 */
int init_rules(View_elements *app);
/**
 * \fn void show_rules(View_elements *app)
 * \brief Affiche les règles
 * Remplace la fenêtre précédente par la texture des règles
 * @param app Structure qui gère la vue
 */
void show_rules(View_elements *app);


//Fonctions pour les Crédits

/**
 * \fn int init_credit(View_elements *app)
 * \brief Initialise les crédits.
 * Applique la bonne texture aux crédits
 * @param app Structure qui gère la vue
 * @return EXIT_SUCCES si tout va bien, EXIT_FAILURE sinon.
 */
int init_credit(View_elements *app);
/**
 * \fn void show_credit(View_elements *app)
 * \brief Affiche les crédits
 * Remplace la fenêtre précédente par la texture des crédits
 * @param app Structure qui gère la vue
 */
void show_credit(View_elements *app);


//Bouton commun au choix de carte, crédits et règles

/**
 * \fn void init_rbutton(View_elements *app)
 * \brief initialise la position du bouton retour
 * Initialise dans la structure passée la valeur du bouton de retour
 * aka la position du bouton sur l'image
 * @param app Structure qui gère la vue
 */
void init_rbutton(View_elements *app);


//Fonction pour le son

/**
 * \fn void start_music()
 * \brief lance la musique
 * Lance la musique de fond du menu
 */
void start_music();

#endif //PROJET_C_MAIN_VIEW_H
