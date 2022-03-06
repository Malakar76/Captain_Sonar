/**
 * \file carte.c
 * \brief Fichier pour la gestion de la carte.
 *
 * Fichier pour la gestion de la carte
 */
#include "main_model.h"

void init_Case(Case * c){
    c->accessible=0;
    c->sous_marin=0;
}

void set_Rocher(CARTE * carte,int ligne,int colonne){
    carte->carte[ligne][colonne].accessible=1;
}

int est_occupe(Case * c){
    return c->accessible;
}

void free_Carte(CARTE * carte){
    free(carte);
}

void init_map(CARTE * c){
    int i,j;
    for (i=0;i<NMAX;i++) {
        for (j = 0; j <NMAX; j++) {
            init_Case(&c->carte[i][j]);
        }
    }
}

void Crea_Archipelago(CARTE * c){
    set_Rocher(c,1,6);
    set_Rocher(c,2,2);
    set_Rocher(c,2,7);
    set_Rocher(c,3,8);
    set_Rocher(c,4,3);
    set_Rocher(c,6,8);
    set_Rocher(c,7,1);
    set_Rocher(c,7,2);
    set_Rocher(c,7,5);
}
void Crea_Antartica(CARTE * c){
    set_Rocher(c,2,3);
    set_Rocher(c,2,7);
    set_Rocher(c,4,8);
    set_Rocher(c,6,8);
    set_Rocher(c,7,2);
    set_Rocher(c,7,4);
    set_Rocher(c,8,3);
}

void choix_carte(Playground * pg,int a){
    if (a==0) {
        Crea_Archipelago(pg->map);
    }
    else if (a==1){
        Crea_Antartica(pg->map);
    }
}



