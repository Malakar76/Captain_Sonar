/**
 * \file joueur.c
 * \brief Fichier pour la gestion du joueur.
 *
 * Fichier pour la gestion du joueur
 */
#include "main_model.h"

void energie_up(JOUEUR *j){
        if (j->energie<4){
            j->energie++;
        }
    }

int deplacement(JOUEUR * j,CARTE * c,enum DIRECTION d){
    switch(d)
    {
        case haut:
        {
            if (j->S_M->ligne>0){
                if (est_occupe(&c->carte[j->S_M->ligne-1][j->S_M->colonne])==0){
                    c->carte[j->S_M->ligne][j->S_M->colonne].sous_marin=0;
                    j->S_M->ligne--;
                    energie_up(j);
                    c->carte[j->S_M->ligne][j->S_M->colonne].sous_marin=1;
                    return EXIT_SUCCESS;
                }
            }
            break;
        }
        case bas:
        {
            if (j->S_M->ligne<9){
                if (est_occupe(&c->carte[j->S_M->ligne+1][j->S_M->colonne])==0){
                    c->carte[j->S_M->ligne][j->S_M->colonne].sous_marin=0;
                    j->S_M->ligne++;
                    energie_up(j);
                    c->carte[j->S_M->ligne][j->S_M->colonne].sous_marin=1;
                    return EXIT_SUCCESS;
                }
            }
            break;

        }

        case droite:
        {
            if (j->S_M->colonne<9){
                if (est_occupe(&c->carte[j->S_M->ligne][j->S_M->colonne+1])==0){
                    c->carte[j->S_M->ligne][j->S_M->colonne].sous_marin=0;
                    j->S_M->colonne++;
                    energie_up(j);
                    c->carte[j->S_M->ligne][j->S_M->colonne].sous_marin=1;
                    return EXIT_SUCCESS;
                }
            }
            break;
        }

        case gauche:
        {
            if (j->S_M->colonne>0){
                if (est_occupe(&c->carte[j->S_M->ligne][j->S_M->colonne-1])==0){
                    c->carte[j->S_M->ligne][j->S_M->colonne].sous_marin=0;
                    j->S_M->colonne--;
                    energie_up(j);
                    c->carte[j->S_M->ligne][j->S_M->colonne].sous_marin=1;
                    return EXIT_SUCCESS;
                }
            }
            break;
        }
    }
    return EXIT_FAILURE;
}

int init_joueur(JOUEUR *j){
    j=malloc(sizeof (JOUEUR));
    j->S_M= malloc(sizeof (SOUS_MARIN));
    if((j==NULL) || (j->S_M==NULL)){
        return EXIT_FAILURE;
    }
    j->energie=0;
    j->vie=2;
    j->S_M->ligne=0;
    j->S_M->colonne=0;
    return EXIT_SUCCESS;
}

void free_joueur(JOUEUR * j){
    free(j->S_M);
    free(j);
}

void start_Sous_Marin(JOUEUR *j,int ligne,int colonne,CARTE * c){
    j->S_M->ligne=ligne;
    j->S_M->colonne=colonne;
    c->carte[ligne][colonne].sous_marin=1;
}
