//
// Created by robin on 08/05/2022.
//

/**
 * \file IA.c
 * \brief Fichier pour la gestion de l'IA.
 * Fichier pour la gestion de l'IA
 */
#include "main_model.h"

//IA
/* Rappel
MIS,  MISSILE interdit
SURF,  SURFACE
SON,  SONAR interdit
SIL, SILENCE interdit
DEPLCMNT  DEPLACEMENT
*/
enum OPTION actionIA(Playground * pg){
    char message[100];
    enum OPTION choix;
    int dir;
    choix =rand()%5;
    while (enough_energie(pg,J2,choix)!=1 || (choix==SIL) || ((choix==SURF)&&pg->ia->nbaction<10)){
        choix=rand()%5;
    }
    if (choix==DEPLCMNT){
        dir=rand()%4;
        while (deplacement_possible(pg,J2,dir)!=1){
            dir=rand()%4;
        }
    }
    if (choix==SURF){
        pg->ia->nbaction=0;
    }
    pg->ia->nbaction++;
    action(pg,J2,choix,dir,rand()%10,rand()%10,message);
    return choix;
}

enum OPTION actionIA2(Playground *pg) {
    char message[100];
    enum OPTION choix;
    int dir;
    /*enum OPTION last = pg->ia->lastaction;*/
    if (pg->ia->nbaction <= 20)
    {
        if (pg->ia->nbaction < 6)
        {
            if ((pg->ia->nbaction % 3) < 2)
            {
                choix = DEPLCMNT;
                dir = rand() % 4;
                while (deplacement_possible(pg, J2, dir) != 1)
                {
                    dir = rand() % 4;
                }
            }
            else
            {
                choix = SON;
                if (pg->ia->nbaction > 4)
                {
                    choix = DEPLCMNT;
                    dir = rand() % 4;
                    while (deplacement_possible(pg, J2, dir) != 1)
                    {
                        dir = rand() % 4;
                    }
                }
            }
            action(pg, J2, choix, dir, rand() % 10, rand() % 10, message);
            pg->ia->nbaction++;
        }
        if ((pg->ia->nbaction < 20 && pg->ia->nbaction % 5) != 0)
        {
            choix = DEPLCMNT;
            dir = rand() % 4;
            while (deplacement_possible(pg, J2, dir) != 1)
            {
                dir = rand() % 4;
            }
        }
        else
        {
            choix = SURF;
        }
    }
    action(pg, J2, choix, dir, rand() % 10, rand() % 10, message);
    pg->ia->nbaction++;
    if (pg->ia->nbaction > 20)
    {
        if (pg->J2->energie != 4)
        {
            choix = DEPLCMNT;
            dir = rand() % 4;
            while (deplacement_possible(pg, J2, dir) != 1)
            {
                dir = rand() % 4;
            }
            action(pg, J2, choix, dir, rand() % 10, rand() % 10, message);
            pg->ia->nbaction++;
        }
        else
        {
            choix = MIS;
            action(pg, J2, choix, dir, pg->J1->S_M->ligne, pg->J1->S_M->colonne, message);
            pg->ia->nbaction++;
        }
    }
    return choix;
}


