//
// Created by eii on 15/02/2022.
//

#ifndef MODEL_JOUEUR_H
#define MODEL_JOUEUR_H
#endif //MODEL_JOUEUR_H
#define length 10 //size of one side of the tableaux
#define nbcharacters
//actions
/*typedef struct
{
    int loc;      /*Saisie de ma location N°1 pour jouer*/
/* int ptdevie;      /*Saisie de ma location N°2 pour jouer*/
/*}Sousmarin;*/

typedef enum{haut,bas,droite,gauche} DIRECTION;


typedef  struct
{
    unsigned int i;
    unsigned int j;
}Sousmarin;


typedef enum
{           missile,
    suface,
    sonar,
    silence
}OPTION;


typedef struct
{
    OPTION o;
    Sousmarin * S_M;
    unsigned int energie;
    unsigned vie;
}JOUEUR;


typedef struct
{
    unsigned int ligne;
    unsigned int cologne;
    char caractere;
}CARTE;

typedef struct
{
    unsigned int ligne;
    unsigned int cologne;
    char caractere;
}CALQUE;




void afficherSousmarin(Sousmarin * m);
int avancer(Sousmarin * p_m,DIRECTION d);
int initjoueur(JOUEUR *jo,unsigned int i, unsigned int j);
