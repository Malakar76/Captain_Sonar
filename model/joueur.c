//
// Created by eii on 15/02/2022.
//

#include "joueur.h"
#include<stdio.h>
#include <stdlib.h>

void afficherSousmarin(Sousmarin * m)
{
    printf("Le sous marin est en (%d,%d)\n", m->i,m->j);
}

int avancer(Sousmarin *p_m,DIRECTION d)
{
    switch(d)
    {
        case haut:
        {
            if(p_m->i>0 && p_m->i<=length)
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
            if(p_m->j<0 && p_m->j<=length)
            {

                p_m->i --;
            }
            else
            {
                return 0;
            }
            break;
        }
    }
    return 1;
}

int initjoueur(JOUEUR *jo,unsigned int i, unsigned int j)
{
    JOUEUR *NJ= (JOUEUR *) malloc(sizeof (JOUEUR));
    NJ->energie=0;
    NJ->vie=2;
    NJ->S_M->i=i;
    NJ->S_M->j=j;
    return NJ;
}
