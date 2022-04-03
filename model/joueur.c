/**
 * \file joueur.c
 * \brief Fichier pour la gestion du joueur.
 *
 * Fichier pour la gestion du joueur
 */
#include "main_model.h"

void energie_up(JOUEUR *j){
        if (j->energie<4){
            j->energie++;
        }
    }

void energie_down(JOUEUR *j,int nb){
    j->energie=j->energie-nb;
}

void deplacement(Playground * pg,enum Actif actif,enum DIRECTION d){
    JOUEUR * j;
    if (actif==J1) {
       j =pg->J1;
    }
    else {
        j =pg->J2;
    }
    switch(d){

        case haut:
        {
            pg->map->carte[j->S_M->ligne][j->S_M->colonne].sous_marin=0;
            j->S_M->ligne--;
            energie_up(j);
            pg->map->carte[j->S_M->ligne][j->S_M->colonne].sous_marin=1;
            j->calqueJ[j->S_M->ligne][j->S_M->colonne]=1;
            break;
        }

        case bas:
        {
            pg->map->carte[j->S_M->ligne][j->S_M->colonne].sous_marin=0;
            j->S_M->ligne++;
            energie_up(j);
            pg->map->carte[j->S_M->ligne][j->S_M->colonne].sous_marin=1;
            j->calqueJ[j->S_M->ligne][j->S_M->colonne]=1;
            break;
        }

        case droite:
        {
            pg->map->carte[j->S_M->ligne][j->S_M->colonne].sous_marin=0;
            j->S_M->colonne++;
            energie_up(j);
            pg->map->carte[j->S_M->ligne][j->S_M->colonne].sous_marin=1;
            j->calqueJ[j->S_M->ligne][j->S_M->colonne]=1;
            break;
        }

        case gauche:
        {
            pg->map->carte[j->S_M->ligne][j->S_M->colonne].sous_marin=0;
            j->S_M->colonne--;
            energie_up(j);
            pg->map->carte[j->S_M->ligne][j->S_M->colonne].sous_marin=1;
            j->calqueJ[j->S_M->ligne][j->S_M->colonne]=1;
            break;
        }
    }
}

int deplacement_possible(Playground * pg,enum Actif actif, enum DIRECTION d){
    JOUEUR * j;
    if (actif==J1) {
        j =pg->J1;
    }
    else {
        j =pg->J2;
    }
    switch(d){
        case haut:
        {
                if (j->S_M->ligne>0){
                if ((est_occupe(&pg->map->carte[j->S_M->ligne-1][j->S_M->colonne])==0) && (j->calqueJ[j->S_M->ligne-1][j->S_M->colonne]==0)){
                    return 1;
                }
            }
            break;
        }
        case bas:
        {
            if (j->S_M->ligne<9){
                if ((est_occupe(&pg->map->carte[j->S_M->ligne+1][j->S_M->colonne])==0)&&(j->calqueJ[j->S_M->ligne+1][j->S_M->colonne]==0)){
                return 1;
                }
            }
            break;
        }

        case droite:
        {
            if (j->S_M->colonne<9){
                if ((est_occupe(&pg->map->carte[j->S_M->ligne][j->S_M->colonne+1])==0)&&(j->calqueJ[j->S_M->ligne][j->S_M->colonne+1]==0)){
                    return 1;
                }
            }
            break;
        }

        case gauche:
        {
            if (j->S_M->colonne>0){
                if ((est_occupe(&pg->map->carte[j->S_M->ligne][j->S_M->colonne-1])==0)&&(j->calqueJ[j->S_M->ligne][j->S_M->colonne-1]==0)){
                    return 1;
                }
            }
            break;
        }
    }
    return 0;
}

int init_joueur(JOUEUR *j){
    j->S_M= malloc(sizeof (SOUS_MARIN));
    if(j->S_M==NULL){
        return EXIT_FAILURE;
    }
    init_calque(j);
    j->energie=0;
    j->vie=2;
    j->S_M->ligne=0;
    j->S_M->colonne=0;
    j->S_M->start[0]=0;
    j->S_M->start[1]=0;
    return EXIT_SUCCESS;
}

void init_calque(JOUEUR * joueur){
    int i,j;
    for (i=0;i<NMAX;i++) {
        for (j = 0; j <NMAX; j++) {
            joueur->calqueJ[i][j]=0;

        }
    }
}

void free_joueur(JOUEUR * j){
    free(j->S_M);
    free(j);
}

void start_Sous_Marin(JOUEUR *j,int ligne,int colonne,CARTE * c){
    j->S_M->ligne=ligne;
    j->S_M->colonne=colonne;
    c->carte[ligne][colonne].sous_marin=1;
    j->S_M->start[0]=j->S_M->ligne;
    j->S_M->start[1]=j->S_M->colonne;
    j->calqueJ[ligne][colonne]=1;
}

int enough_energie(Playground *pg, enum Actif actif, enum OPTION option) {
    JOUEUR *j;
    if (actif == J1) {
        j = pg->J1;
    } else {
        j = pg->J2;
    }
    switch (option) {
        case MIS: {
            if (j->energie == 4) {
                return 1;
            }
            break;
        }
        case SURF: {
            return 1;
        }
        case SON: {
            if (j->energie >= 2) {
                return 1;
            }
            break;
        }
        case SIL: {
            if (j->energie >= 3) {
                return 1;
            }
            break;
        }
        case DEPLCMNT: {
            return 1;
        }
    }
    return 0;
}

void result_deplacement(Playground *pg,enum Actif actif,enum DIRECTION d,char message []){
    switch (d) {
        case haut: {
            deplacement(pg,actif,d);
            strcpy(message,"Deplacement en haut");
            break;

        }

        case bas: {
            deplacement(pg,actif,d);
            strcpy(message,"Deplacement en bas");
            break;
        }

        case gauche: {
            deplacement(pg,actif,d);
            strcpy(message,"Deplacement a gauche");
            break;
        }

        case droite: {
            deplacement(pg,actif,d);
            strcpy(message,"Deplacement a droite");
            break;
        }
    }
}

int missile(Playground *pg,enum Actif actif,int ligne,int colonne) {
    if (actif == J1) {
        if (pg->J1->S_M->colonne == colonne && pg->J1->S_M->ligne == ligne) {
            pg->J1->vie--;
            return -1;
        }
        else if (pg->J2->S_M->colonne == colonne && pg->J2->S_M->ligne == ligne) {
            pg->J2->vie--;
            return 1;
        }
        else{
          return 0;
        }
    } else {
        if (pg->J1->S_M->colonne == colonne && pg->J1->S_M->ligne == ligne) {
            pg->J1->vie--;
            return 1;
        }
        else if (pg->J2->S_M->colonne == colonne && pg->J2->S_M->ligne == ligne) {
            pg->J2->vie--;
            return -1;
        }
        else {
            return 0;
        }
    }
}

int result_missile(Playground *pg,enum Actif actif,int ligne,int colonne, char  message[]) {
    switch (missile(pg, actif, ligne, colonne)) {
        case 0:
            strcpy(message, "Zut, vous n'avez rien touché");
            return 0;

        case 1:
            strcpy(message, "Bravo vous avez touché l'adversaire");
            return 1;

        case -1:
            strcpy(message, "Mince alors, vous vous êtes touché vous même!");
            return -1;

    }
}

void sonar(Playground * pg, enum Actif actif, char message[]){
    int val= rand();
    char valeur;
    if (actif==J1) {
        if (val%2==1){

            //valeur=pg->J2->S_M->colonne+'0';
            valeur = '5';
            fprintf(stderr,"%c",valeur);
            strcpy(message,"L'ennemi se trouve dans la colonne ");
            strcat(message,&valeur);
        }else{
            //valeur=pg->J2->S_M->ligne+'0';
            valeur = '5';
            fprintf(stderr,"%c",valeur);
            strcpy(message,"L'ennemi se trouve dans la ligne ");
            strcat(message,&valeur);
        }
    }
    else if (pg->actif==J2){
        if (val%2==1){
            valeur=pg->J1->S_M->colonne;
            strcpy(message,"L'ennemi se trouve dans la colonne ");
            strcat(message,&valeur);
        }else{
            valeur=pg->J1->S_M->ligne;
            strcpy(message,"L'ennemi se trouve dans la ligne ");
            strcat(message,&valeur);
        }
    }
}

void action(Playground *pg,enum Actif actif,enum OPTION option,enum DIRECTION d,int ligne,int colonne,char message []){
    JOUEUR * j;
    if (pg->actif==J1){
        j=pg->J1;
    }else{
        j=pg->J2;
    }
    switch (option) {
        case MIS: {

            if (enough_energie(pg, actif, MIS)) {
                result_missile(pg, actif, ligne, colonne, message);
                energie_down(j,4);
            } else {
                printf("Pas assez d'energie pour missille");
            }
            break;
        }

        case SURF: {
            surface(pg,actif,message);
            break;
        }


        case SON: {
            if (enough_energie(pg, actif, SON)) {
                sonar(pg, actif, message);
                energie_down(j,2);
            } else {
                strcpy(message, "Pas d'energie pour sonar");
            }
            break;
        }


        case SIL: {
            if (enough_energie(pg, actif, SIL)) {
                energie_down(j,3);
            } else {
                strcpy(message, "Pas d'energie pour silence");
            }
            break;
        }


        case DEPLCMNT: {

            switch (d) {
                case haut: {
                    if (deplacement_possible(pg, actif, d)) {
                        result_deplacement(pg, actif, d, message);
                    }else {
                        strcpy(message, "Impossible de se deplacer en haut");
                    }
                    break;
                }


                case bas: {

                    if (deplacement_possible(pg, actif, d)) {
                        result_deplacement(pg, actif, d, message);
                    } else {
                        strcpy(message, "Impossible de se deplacer en bas");
                    }
                    break;
                }


                case droite: {
                    if (deplacement_possible(pg, actif, d)) {
                        result_deplacement(pg, actif, d, message);
                    } else {
                        strcpy(message, "Impossible de se deplacer à droite");
                    }
                    break;
                }



                case gauche: {
                    if (deplacement_possible(pg, actif, d)) {
                        result_deplacement(pg, actif, d, message);
                    } else {
                        strcpy(message, "Impossible de se deplacer à gauche");
                    }
                    break;
                }

            }
            break;
        }


    }
}

void surface(Playground *pg,enum Actif actif,char message[]){

}


