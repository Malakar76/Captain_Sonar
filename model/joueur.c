//
// Created by eii on 15/02/2022.
//

#include "joueur.h"
#include<stdio.h>

void afficherSousmarin(Sousmarin m)
{
    printf("Le sous marin est en (%d,%d)\n", m.i,m.j);
}

int avancer(Sousmarin *p_m)
{
    switch(p_m->d)
    {
        case haut:
        {
            if(p_m->i>0)
                p_m->i --;
            else return 0;
            break;
        }
        case bas:
        {
            if(p_m->i<(length-1))
                p_m->i ++;
            else return 0;
            break;
        }

        case droite:
        {
            if(p_m->j<(length-1))
                p_m->j ++;
            else return 0;
            break;
        }

        case gauche:
        {
            if(p_m->j<0)
                p_m->i --;
            else return 0;
            break;
        }
    }
    return 1;
}
