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
int deplacementaleatoire(Playground*pg)
{
    int deplacement = rand() % 4;
    while(deplacement_possible(pg, J2, deplacement) == 0 )
    {
        deplacement = rand() % 4;
    }
    return deplacement;
}
enum OPTION actionIA2(Playground *pg) {
    char message[100];
    enum OPTION choix;
    int dir;
    int ligne = rand() % 10;
    int colonne = rand() % 10;

    /*enum OPTION last = pg->ia->lastaction;*/
    /*if (surface_joueur != 1){*/

    if (pg->ia->surface_joueur == 1 && pg->J2->energie == 4) {
        choix = MIS;
        ligne = pg->J1->S_M->ligne;
        colonne = pg->J1->S_M->colonne;
    } else if(pg->ia->surface_joueur == 1 && pg->J2->energie != 4) {
        choix = DEPLCMNT;
        if (deplacement_possible(pg, J2, gauche) == 0 && deplacement_possible(pg, J2, droite) == 0 &&
            deplacement_possible(pg, J2, haut) == 0 && deplacement_possible(pg, J2, bas) == 0) {
            choix = SURF;
            pg->ia->nbaction--;
        } else
        {
            if (dir == gauche && deplacement_possible(pg, J2, gauche) == 0) {
                dir = deplacementaleatoire(pg);
            }
            if (dir == droite && deplacement_possible(pg, J2, droite) == 0) {
                dir = deplacementaleatoire(pg);}
            if (dir == haut && deplacement_possible(pg, J2, haut) == 0) {
                dir = deplacementaleatoire(pg);}
            if (dir == bas && deplacement_possible(pg, J2, bas) == 0) {
                dir = deplacementaleatoire(pg);}
        }
    }
    else {
        if (pg->ia->nbaction < 6) {
            if ((pg->ia->nbaction % 3) < 2) {
                choix = DEPLCMNT;

                if (deplacement_possible(pg, J2, gauche) == 0 && deplacement_possible(pg, J2, droite) == 0 &&
                    deplacement_possible(pg, J2, haut) == 0 && deplacement_possible(pg, J2, bas) == 0) {
                    choix = SURF;
                    pg->ia->nbaction--;
                } else  {
                    if (dir == gauche && deplacement_possible(pg, J2, gauche) == 0)
                        dir = deplacementaleatoire(pg);
                    if (dir == droite && deplacement_possible(pg, J2, droite) == 0)
                        dir = deplacementaleatoire(pg);
                    if (dir == haut && deplacement_possible(pg, J2, haut) == 0)
                        dir = deplacementaleatoire(pg);
                    if (dir == bas && deplacement_possible(pg, J2, bas) == 0)
                        dir = deplacementaleatoire(pg);
                }
            } else {
                choix = SON;
            }
        }

        if (pg->ia->nbaction > 5 && pg->ia->nbaction < 19) {
            if (pg->ia->nbaction % 5 < 4) {
                choix = DEPLCMNT;
                if (deplacement_possible(pg, J2, gauche) == 0 && deplacement_possible(pg, J2, droite) == 0 &&
                    deplacement_possible(pg, J2, haut) == 0 && deplacement_possible(pg, J2, bas) == 0) {
                    choix = SURF;
                    pg->ia->nbaction--;
                } else if (deplacement_possible(pg, J2, gauche) == 1 || deplacement_possible(pg, J2, droite) == 1 ||
                           deplacement_possible(pg, J2, haut) == 1 || deplacement_possible(pg, J2, bas) == 1) {

                    if (dir == gauche && deplacement_possible(pg, J2, gauche) == 0)
                        dir = deplacementaleatoire(pg);
                    if (dir == droite && deplacement_possible(pg, J2, droite) == 0)
                        dir = deplacementaleatoire(pg);
                    if (dir == haut && deplacement_possible(pg, J2, haut) == 0)
                        dir = deplacementaleatoire(pg);
                    if (dir == bas && deplacement_possible(pg, J2, bas) == 0)
                        dir = deplacementaleatoire(pg);
                } else {
                    choix = MIS;
                    ligne = pg->J1->S_M->ligne + 1 - rand() % 3;
                    colonne = pg->J1->S_M->colonne + 1 - rand() % 3;
                }
            }
        }
        if (pg->ia->nbaction > 18) {
            if (pg->J2->energie != 4) {
                choix = DEPLCMNT;
                if (deplacement_possible(pg, J2, gauche) == 0 && deplacement_possible(pg, J2, droite) == 0 &&
                    deplacement_possible(pg, J2, haut) == 0 && deplacement_possible(pg, J2, bas) == 0) {
                    choix = SURF;
                    pg->ia->nbaction--;
                }
                else if (deplacement_possible(pg, J2, gauche) == 1 || deplacement_possible(pg, J2, droite) == 1 ||
                    deplacement_possible(pg, J2, haut) == 1 || deplacement_possible(pg, J2, bas) == 1) {
                    if (dir==gauche && deplacement_possible(pg, J2, gauche) == 0 )
                        dir =deplacementaleatoire(pg);
                    if (dir==droite && deplacement_possible(pg, J2, droite) == 0 )
                        dir =deplacementaleatoire(pg);
                    if (dir==haut && deplacement_possible(pg, J2, haut) == 0 )
                        dir =deplacementaleatoire(pg);
                    if (dir==bas && deplacement_possible(pg, J2, bas) == 0 )
                        dir =deplacementaleatoire(pg);
                }
            } else {
                choix = MIS;
                ligne = pg->J1->S_M->ligne + 1 - rand() % 3;
                colonne = pg->J1->S_M->colonne + 1 - rand() % 3;
            }
        }
    }
    action(pg, J2, choix, dir, ligne, colonne, message);
    pg->ia->nbaction++;
    return choix;

}


