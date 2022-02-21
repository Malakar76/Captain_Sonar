//
// Created by eii on 21/02/2022.
//

#ifndef PROJET_POINT_H
#define PROJET_POINT_H

#endif //PROJET_POINT_H

typedef struct
{
    int x;
    int y;
    int accesible;
    int occupe;
    int couleur;
    int couleur_precedent;
} Point;

int init_Point(Point);
int Rocher(Point);
int est_occupe(Point);
int freePoint(Point);
