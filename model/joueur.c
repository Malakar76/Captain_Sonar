#include "joueur.h"

int energie(SOUS_MARIN *S_M){
    int energie=0;
    if (S_M->d==0 || S_M->d==1 || S_M->d==1 || S_M->d==1){
        if (energie<4){
            energie=energie+1;
        }
        else energie=4;
    return energie;
    }
}

int Missile(int energie){
    if (energie!=4) return 0;
    else return 1;
}

char active_missile(int energie,int i, int j, CARTE *c, SOUS_MARIN S_M){
    if (Missile(energie)==1){
        if (S_M->i==i && S_M->j==j){
            C[i][j]='*';
        }
        else {
            c[i][j]='o';
        }
    }
    return c[i][j];
}

int  active_sonar(int energie,CARTE *c, SOUS_MARIN S_M) {
    if (Sonar(energie) == 1) return c->ligne = S_M->i || c->colonne = S_M->j;
    else return 0;
}

