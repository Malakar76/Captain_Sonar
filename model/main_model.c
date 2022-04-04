//
// Created by robin on 07/02/2022.
//
/**
 * \file main_model.c
 * \brief Fichier principal du model.
 *
 * Fichier principal pour la gestion du model du projet
 */

#include "main_model.h"

int init_model(Playground * pg)
{
    int statut = EXIT_FAILURE;
    pg->map= malloc(sizeof(CARTE));
    if(pg->map==NULL){
        return statut;
    }
    init_map(pg->map);
    pg->J1= malloc(sizeof (JOUEUR));
    pg->J2= malloc(sizeof(JOUEUR));
    if (pg->J2==NULL || pg->J1==NULL){
        return statut;
    }
    if(init_joueur(pg->J1)==EXIT_FAILURE){
        return statut;
    }
    if(init_joueur(pg->J2)==EXIT_FAILURE){
        return statut;
    }
    pg->actif=J1;
    statut=EXIT_SUCCESS;
    return statut;
}

void free_model(Playground * pg){
    free_Carte(pg->map);
    free_joueur(pg->J1);
    free_joueur(pg->J2);
}


