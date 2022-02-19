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
#include "SDL2/SDL_image.h"

enum Window {
    Menu,Battlefield,Choix_Carte,Rules,Credits
};

/**
 * \struct View_elements
 * \brief Elements de la vue
 *
 * Structure qui regroupe tout les éléments nécessaires pour gérer la vue du projet
 */
typedef struct {
    SDL_Window *wwindow; /**< Fenêtre principale SDl */
    SDL_Renderer *rRenderer; /**<Renderer associé à la fenêtre principale */
    SDL_Texture *tBattlefield;/**< Texture qui garde l'aperçu de la fenêtre de jeu */
    SDL_Rect  Bbutton[7] ;/** < Tableau qui stocke l'emplacement des boutons du champ de bataille*/
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
int init_all_view(View_elements *app);


// Fonctions pour le champ de bataille
int init_battlefield(View_elements * app);
void show_battlefield(View_elements *app);
int init_choix_carte(View_elements * app);
void show_choix_carte(View_elements *app);

// Fonctions pour le Menu
void init_menu(View_elements *app);
void show_menu(View_elements *app);


//Fonctions pour les Règles
void init_rules(View_elements *app);
void show_rules(View_elements *app);

//Fonctions pour les Crédits
void init_credit(View_elements *app);
void show_credit(View_elements *app);

void init_rbutton(View_elements *app,SDL_Rect rect);

#endif //PROJET_C_MAIN_VIEW_H
