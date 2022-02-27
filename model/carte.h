#ifndef MODEL_CARTE_H
#define MODEL_CARTE_H

#define NMAX 10
#define NB_obs 1
/**
 * \struct Playground
 * \brief Elements du modèle
 * Structure qui regroupe tout les éléments nécessaires pour gérer le modèle du projet
 */
typedef  struct CARTE{
    int ligne;
    int colonne;
    char caractere;
    unsigned int i;
    unsigned int j;

}CARTE;

void init_map (int colonne, int ligne);

char acces (CARTE *C);

#endif
