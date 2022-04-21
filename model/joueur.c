/**
 * \file joueur.c
 * \brief Fichier pour la gestion du joueur.
 *
 * Fichier pour la gestion du joueur
 */
<<<<<<< HEAD
=======


>>>>>>> c88329c34942d9c48eea04a49168ce4fee91af04
#include "main_model.h"

void energie_up(JOUEUR *j){
        if (j->energie<4){
            j->energie++;
        }
    }

void deplacement(Playground * pg,enum Actif actif,enum DIRECTION d){
    JOUEUR * j;
    if (actif==J1) {
       j =pg->J1;
    }
    else {
        j =pg->J2;
    }
    switch(d){

        case haut:
        {
            pg->map->carte[j->S_M->ligne][j->S_M->colonne].sous_marin=0;
            j->S_M->ligne--;
            energie_up(j);
            pg->map->carte[j->S_M->ligne][j->S_M->colonne].sous_marin=1;
            break;
        }

        case bas:
        {
            pg->map->carte[j->S_M->ligne][j->S_M->colonne].sous_marin=0;
            j->S_M->ligne++;
            energie_up(j);
            pg->map->carte[j->S_M->ligne][j->S_M->colonne].sous_marin=1;
            break;
        }

        case droite:
        {
            pg->map->carte[j->S_M->ligne][j->S_M->colonne].sous_marin=0;
            j->S_M->colonne++;
            energie_up(j);
            pg->map->carte[j->S_M->ligne][j->S_M->colonne].sous_marin=1;
            break;
        }

        case gauche:
        {
            pg->map->carte[j->S_M->ligne][j->S_M->colonne].sous_marin=0;
            j->S_M->colonne--;
            energie_up(j);
            pg->map->carte[j->S_M->ligne][j->S_M->colonne].sous_marin=1;
            break;
        }
    }
}

int deplacement_possible(Playground * pg,enum Actif actif, enum DIRECTION d){
    JOUEUR * j;
    if (actif==J1) {
        j =pg->J1;
    }
    else {
        j =pg->J2;
    }
    switch(d){
        case haut:
        {
                if (j->S_M->ligne>0){
                if (est_occupe(&pg->map->carte[j->S_M->ligne-1][j->S_M->colonne])==0){
                    return 1;
                }
            }
            break;
        }
        case bas:
        {
            if (j->S_M->ligne<9){
                if (est_occupe(&pg->map->carte[j->S_M->ligne+1][j->S_M->colonne])==0){
                return 1;
                }
            }
            break;
        }

        case droite:
        {
            if (j->S_M->colonne<9){
                if (est_occupe(&pg->map->carte[j->S_M->ligne][j->S_M->colonne+1])==0){
                    return 1;
                }
            }
            break;
        }

        case gauche:
        {
            if (j->S_M->colonne>0){
                if (est_occupe(&pg->map->carte[j->S_M->ligne][j->S_M->colonne-1])==0){
                    return 1;
                }
            }
            break;
        }
    }
    return 0;
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

<<<<<<< HEAD
int missile(Playground *pg,enum Actif actif,int ligne,int colonne) {
    if (actif = J1) {
        j = pg->J1;
        if (pg->J1->S_M->colonne = colonne && pg->J1->S_M->ligne == ligne)
            return -1;
        if (g->J2->S_M->colonne = colonne && pg->J2->S_M->ligne == ligne)
            return 1;
        else return 0;
    } else {
        j = pg->J2;
        if (pg->J1->S_M->colonne = colonne && pg->J1->S_M->ligne == ligne)
            return 1;
        if (g->J2->S_M->colonne = colonne && pg->J2->S_M->ligne == ligne)
            return -1;
        else return 0;
    }
}

void result_missile(Playground *pg,enum Actif actif,int ligne,int colonne, char message);
    if (missile(pg,Actif actif, ligne, colonne)==0)
        strcpy(message,"Zut, vous n\'avez rien touché");
    if (missile(pg,Actif actif, ligne, colonne)==-1)
        strcpy(message,"Mince alors, vous vous êtes touché vous même!");
    if (missile(pg,Actif actif, ligne, colonne)==-1)
        strcpy(message,"Bravo vous avez touché l'adversaire");



void sonar(Playground * pg, enum Actif actif, char message){
    if (pg->actif==J1) {
       strcpy(message,pg->J2->S_M->ligne || pg->J2->S_M->colonne);
    }
    if (pg->actif==J2){
        strcpy(message,pg->J1->S_M->ligne || pg->J1->S_M->colonne);
    }
}
=======


int enough_energie(Playground *pg,enum Actif actif,enum OPTION option)
{
    JOUEUR*j;
    switch(option)
    {
        case MIS:
        {
            if(j->energie==4)
            {
                return 1;
            }
            else
            {
                return 0;
            }
            break;
        }
        case SURF:
        {
            if(j->energie>=1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
            break;
        }


        case SON:
        {
            if(j->energie>=2)
            {
                return 1;
            }
            else
            {
                return 0;
            }
            break;

        }

        case SIL:
        {
            if(j->energie>=3)
            {
                return 1;
            }
            else
            {
                return 0;
            }
            break;
        }

        case DEPLCMNT:
        {
            if(j->energie>=1)
            {
                return 1;
            }
            else
            {
                return 0;
            }
            break;
        }

    }

    if (actif==J1)
    {
        j =pg->J1;
        return (int) j;
    }
    else
    {
        j = pg->J2;
        return (int) j;
    }



}

char * action(Playground *pg,enum Actif actif,enum OPTION option,enum DIRECTION d)
{
    Playground * a;




}

char * result_deplacement(Playground *pg,enum Actif actif,enum DIRECTION d)
{
    JOUEUR * j;

    switch(d)
    {
        case haut:
        {
            char *ptr = "haut";
            return ptr;

        }
            break;
        case bas:
        {
            char *ptr = "Bas";
            return ptr;

        }
            break;

        case gauche:
        {
            char *ptr = "Gauche";
            return ptr;

        }
            break;

        case droite:
        {
            char *ptr = "Droite";
            return ptr;
        }
            break;
    }


    if (actif==J1)
    {
        j =pg->J1;
        return (char*) j;
    }
    else
    {
        j = pg->J2;
        return (char*) j;
    }
    
}






>>>>>>> c88329c34942d9c48eea04a49168ce4fee91af04
