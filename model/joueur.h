//
// Created by eii on 15/02/2022.
//

#ifndef MODEL_JOUEUR_H
#define MODEL_JOUEUR_H
#endif //MODEL_JOUEUR_H
#define length 10
//actions

typedef enum{haut,bas,droite,gauche} Direction;
typedef  struct{Direction d;unsigned int i;unsigned int j}Sousmarin;

//Functions
void afficherSousmarin(Sousmarin m);
int avancer(Sousmarin * p_m);
