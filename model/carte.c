#include "carte.h"
include <string.h>
#include <stdlib.h>
#include <time.h>

void init_map(int colonne, int ligne,){
    int i, int j;
    TABLEAU* c[]={(TABLEAU*)malloc(sizeof(TABLEAU)*colonne),(TABLEAU*)malloc(sizeof(TABLEAU)*colonne)};
    for (i=0;i<colonne;i++) {
        for (j = 0; j < ligne; j++) {
            c[i][j]=".";
        }
        printf("\n");
    }
    if (i==5 && j==5 || i==6 && j==5 || i==5 && j==6 || i==6 && j==6) {
        c[i][j]='X';
    }
}

char acces (CARTE *c){
    switch (c->note) {
        case '.':
            return "ACCES AUTORISE";
        case 'X':
            return "ACCES INTERDIT, ROCHERS";
        case 's':
            return "PRESENCE DU SOUS_MARIN";
        case '*':
            return "le missile à touché le sous marin"
        case 'o':
            return "le missile à rien touché"
        case 'a':
            return "le sous-marin est à la surface"
    }
}

