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
#include "SDL2/SDL_ttf.h"


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
 * Structure qui regroupe tous les éléments nécessaires pour gérer la vue du champ de bataille
 */
typedef struct {
    SDL_Texture *Battlefield_current;/**< Texture qui garde l'aperçu de la fenêtre de jeu affiché */
    SDL_Texture *Battlefield_blank;/**< Texture qui garde l'aperçu de la fenêtre de jeu clean */
    SDL_Texture *Sous_marin;/**< Texture qui garde l'aperçu du sous_marin */
    SDL_Texture *Energie; /**< Texture qui garde les niveaux d'énergie */
    SDL_Texture *FinSon; /**< Texture qui stocke le bouton du son et de la fin de partie */
    SDL_Rect  Bbutton[13] ;/**< Tableau qui stocke l'emplacement des boutons du champ de bataille */
    SDL_Rect Carte[10][10];/**< Tableau qui stocke l'emplacement des cases du champ de bataille */
}View_Battlefield;

/**
 * \struct View_elements
 * \brief Elements de la vue
 *
 * Structure qui regroupe tous les éléments nécessaires pour gérer la vue du projet
 */
typedef struct {
    SDL_Window *wwindow; /**< Fenêtre principale SDl */
    SDL_Renderer *rRenderer; /**< Renderer associé à la fenêtre principale */
    View_Battlefield * VBattlefield ;/**< Structure qui stocke les inforamtions de la vue du champ de bataille */
    SDL_Texture *mMenu;/**< Texture qui garde l'aperçu du menu principal */
    SDL_Rect  Mbutton[4] ;/** < Tableau qui stocke l'emplacement des boutons du menu */
    SDL_Rect  Rbutton;  /** < Rectangle qui stocke l'emplacement du bouton retour */
    SDL_Texture *rRegles;/** < Texture qui garde l'aperçu des règles */
    SDL_Texture *cCredit;/** < Texture qui garde l'aperçu des crédits */
    SDL_Texture *cCarte; /** < Texture qui garde l'aperçu du choix des cartes */
    SDL_Texture *valide; /**< Texture qui garde l'apeçu du bouton validé pour joueur ou IA */
    SDL_Rect  CCarte[5] ;/** < Tableau qui stocke l'emplacement des boutons du choix des cartes */
    enum Window window;/** < Permet de savoir qu'elle est la fenêtre actuellement utilisée */
    TTF_Font * ttf;/** < Structure qui permet de régler la police d'écriture des messages */
    Mix_Music * music ; /** < Musique à jouer */
    int state; /** < Vaut 0 (musique en pause) ou 1 (musique en cours) */
    int IA ; /** < Permet de savoir si l'on va jouer contre une IA ou un vrai joueur (0=Joueur , 1=IA) */

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

/**
 * \fn void init_font(View_elements *app)
 * Initialise la police d'écriture et sa taille
 * @param app Structure qui gère la vue
 */
void init_font(View_elements *app);


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
 * \fn int init_battlefield(View_elements * app,enum Carte c)
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
 * \fn int init_BoutonSonEtFinPartie(View_elements *app)
 * Initialise la texture pour les boutons du son et l'écran de défaite
 * @param app Structure qui gère la vue
 * @return EXIT_SUCCES si tout va bien, EXIT_FAILURE sinon.
 */
int init_BoutonSonEtFinPartie(View_elements *app);

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

/**
 * \fn void print_message(View_elements *app,char * message)
 * Affiche le message passé en parmètre avec la typo initialisé dans la structure app. Le message est affiché dans l'interface utilisateur
 * dans la zone action allié
 * @param app Structure qui gère la vue
 * @param message message à afficher
 */
void print_message(View_elements *app,char * message);

/**
 * \fn void print_message_adversaire(View_elements *app,char * message)
 * Affiche le message passé en parmètre avec la typo initialisé dans la structure app. Le message est affiché dans l'interface utilisateur
 * dans la zone action de l'adversaire
 * @param app Structure qui gère la vue
 * @param message message à afficher
 */
void print_message_adversaire(View_elements *app,char * message);

/**
 * \fn void case_choisie(View_elements * app, SDL_Point point,int tab[])
 * Fonction qui stocke la ligne et la colonne où l'utilisateur vient de cliquer dans un tableau
 * @param app Structure qui gère la vue
 * @param point Point où l'utilisateur vient de cliquer
 * @param tab tableau où stocker la position x et y de la case
 */
void case_choisie(View_elements * app, SDL_Point point,int tab[]);

/**
 * \fn void show_SM(View_elements * app,int ligne,int colonne)
 * Affiche le sous-marin et actualise sa position sur la vue
 * @param app Structure qui gère la vue
 * @param ligne Position actuelle du sous-marin
 * @param colonne Position actuelle du sous-marin
 */
void show_SM(View_elements * app,int ligne,int colonne);

/**
 * \fn int init_coche_case(View_elements * app)
 * initialise la texture qui stocke la case cochée
 * @param app Structure qui gère la vue
 * @return EXIT_SUCCES si tout va bien, EXIT_FAILURE sinon.
 */
int init_coche_case(View_elements * app);

/**
 * \fn void coche_case(View_elements * app)
 * met à jour la tecture de la case cochée sur la vue.
 * @param app Structure qui gère la vue
 */
void coche_case(View_elements * app);

/**
 * \fn void trace_deplacement(View_elements * app, int direction, int pos_joueur_ligne, int pos_joueur_colonne,int color)
 * Trace le dernier déplacement du joueur sur la carte
 * @param app Structure qui gère la vue
 * @param direction Direction du dernier déplacement
 * @param pos_joueur_ligne Nouvelle position du joueur
 * @param color Permet de choisir la couleur entre rouge (0) et vert (1)
 * @param pos_joueur_colonne Nouvelle position du joueur
 */
void trace_deplacement(View_elements * app, int direction, int pos_joueur_ligne, int pos_joueur_colonne,int color);

/**
 * \fn void clean_map(View_elements * app)
 * Permet de retirer le tracé du déplacement lorsque le joueur fait surface.
 * @param app Structure qui gère la vue
 */
void clean_map(View_elements * app);

/**
 * \fn void trace_deplacement_total(View_elements * app, int direction[],int nbdir,int pos_depart[],int color)
 * permet de retracer tout les déplacements d'un joueur
 * @param app Structure qui gère la vue
 * @param direction tableau de toutes les directions à tracer
 * @param nbdir nombre de direction à tracer
 * @param color Permet de choisir la couleur entre rouge (0) et vert (1)
 * @param pos_depart position de départ du joueur
 */
void trace_deplacement_total(View_elements * app, int direction[],int nbdir,int pos_depart[],int color);

/**
 * \fn void trace_deplacement_calque(View_elements * app, int direction, int pos_joueur_ligne, int pos_joueur_colonne)
 * Trace le dernier déplacement du joueur adverse sur le calque
 * @param app Structure qui gère la vue
 * @param direction Direction du dernier déplacement
 * @param pos_joueur_ligne Nouvelle position du joueur
 * @param pos_joueur_colonne Nouvelle position du joueur
 */
void trace_deplacement_calque(View_elements * app, int direction, int pos_joueur_ligne, int pos_joueur_colonne);

/**
 * \fn void trace_deplacement_total_calque(View_elements * app, int direction[],int nbdir)
 * permet de retracer tout les déplacements d'un joueur sur le calque
 * @param app Structure qui gère la vue
 * @param direction tableau de toutes les directions à tracer
 * @param nbdir nombre de direction à tracer
 */
void trace_deplacement_total_calque(View_elements * app, int direction[],int nbdir);

/**
 * \fn void clean_calque(View_elements * app)
 * Permet de retirer le tracé du déplacement sur le calque lorsque le joueur fait surface.
 * @param app Structure qui gère la vue
 */
void clean_calque(View_elements * app);

/**
 * \fn void show_energie(View_elements * app,int energie)
 * met à jour le niveau d'énergie affiché
 * @param app Structure qui gère la vue
 * @param energie niveau d'énergie
 */
void show_energie(View_elements * app,int energie);

/**
 * \fn void show_vie(View_elements * app, int vieJ1,int vieJ2)
 * met à jour le niveau de vie affiché
 * @param app Structure qui gère la vue
 * @param vieA Points de vie du Joueur Actif
 * @param vieNA Points de vie du Joueur Non-Actif
 */
void show_vie(View_elements * app, int vieA,int vieNA);

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
 * \fn void start_music(Mix_Music * music)
 * \brief lance la musique
 * Lance la musique de fond du menu
 * @param music Strucure de la musique à jouer
 * @return retourne 1
 */
int start_music(Mix_Music * music);

/**
 * \fn void resume_music(View_elements * app)
 * joue la musique après une pause et met à jour le logo du son
 * @param app Structure qui gère la vue
 * @return retourne 1
 */
int resume_music(View_elements * app);

/**
 * \fn void pause_music(View_elements * app)
 * Met en pause la musique et met à jour le logo du son
 * @param app Structure qui gère la vue
 * @return retourne 0
 */
int pause_music(View_elements * app);

#endif //PROJET_C_MAIN_VIEW_H
