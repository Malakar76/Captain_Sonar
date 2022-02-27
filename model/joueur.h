
#ifndef MODEL_JOUEUR_H
#define MODEL_JOUEUR_H
#include "carte.h"
enum {haut, bas, gauche, droite}DIRECTION;

enum {missile, surface, sonar, silence}OPTION;

enum {DESACTIVATED, ACTIVATED}CHOIX;

typedef struct {
    DIRECTION *d;
    int j;
    int i;
}SOUS_MARIN;

typedef struct{
    OPTION *o;
    SOUS_MARIN *S_M;
    unsigned int energie;
    unsigned int vie;
    CHOIX *c;
    }JOUEUR;



int energie(SOUS_MARIN *S_M);
int Missile(int energie);
char active_missile(int energie,int i, int j, CARTE *c, SOUS_MARIN S_M);
int  active_sonar(int energie,CARTE *c, SOUS_MARIN S_M);
#endif
