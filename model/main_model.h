#ifndef PROJET_C_MAIN_MODEL_H
#define PROJET_C_MAIN_MODEL_H

#include "stdlib.h"
#include "joueur.h"
#include "carte.h"
/**
 * \struct PLAYGROUND
 * \brief Elements du modèle
 * Structure qui regroupe tout les éléments nécessaires pour gérer le modèle du projet
 */
typedef struct {
    CARTE * map;/**<Structure Carte de jeu */
    JOUEUR * J1;/**<Structure du joueur 1  */
    JOUEUR * J2; /**<Structure du joueur 2 */
}PLAYGROUND;

/**
 * \fn int init_model(Playground * pg)
 * \brief initialise le modèle de la structure passé.
 * @param pg Structure qui gère le modèle
 * @return EXIT_SUCCES si tout va bien, EXIT_FAILURE sinon.
 */
int init_model(PLAYGROUND * pg);

/**
 * \fn void free_model(Playground * pg)
 * \brief libère le modèle de la structure passée.
 * @param pg Structure qui gère le modèle
 */
void free_model(PLAYGROUND * pg);


#endif
