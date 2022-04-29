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
#include "test.h"

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

<<<<<<< HEAD

=======
int test_unitaire (){
    Playground *pg;

    // test unitaire deplacement_posssible
    ligne=pg->J1->S_M->ligne;
    colonne=pg->J1->S_M->colonne;
    display_test_int("test deplacement possible à haut du joueur 2\n", deplacement_possible(Playground * pg, 0,0 ),1);
    display_test_int("test deplacement possible à bas du joueur 2\n", deplacement_possible(Playground * pg, 0,1 ),1);
    display_test_int("test deplacement possible à guache du joueur 2\n", deplacement_possible(Playground * pg, 0,2),1);
    display_test_int("test deplacement possible à droite du joueur 2\n", deplacement_possible(Playground * pg, 0,3 ),1);
    display_test_int("test deplacement possible à haut du joueur 2\n", deplacement_possible(Playground * pg,1,0 ),1);
    display_test_int("test deplacement possible à bas du joueur 2\n", deplacement_possible(Playground * pg,1,1 ),1);
    display_test_int("test deplacement possible à guache du joueur 2\n", deplacement_possible(Playground * pg,1,2),1);
    display_test_int("test deplacement possible à droite du joueur 2\n", deplacement_possible(Playground * pg,1,3 ),1);

    // test unitaire init_joueur
    display_test_int("test initialisation du joueur 1\n", init_joueur(Joueur *j),EXIT_SUCCESS);
    display_test_int("test initialisation du joueur 2\n", init_joueur(Joueur *j),EXIT_SUCCESS);


    //test unitaire missile
    display_test_int("test missile sur son sous-marin\n", missile(Playground *pg,0,ligne,colonne),-1);
    display_test_int("test missile sur le sous-marin adverse, avec J2 actif\n", missile(Playground *pg,1,ligne,colonne),1);
    ligne=pg->J2->S_M->ligne;
    colonne=pg->J2->S_M->colonne;
    display_test_int("test missile sur son sous-marin\n", missile(Playground *pg,1,ligne,colonne),-1);
    display_test_int("test missile sur le sous-marin adverse, avec J1 actif\n", missile(Playground *pg,0,ligne,colonne),1);
    ligne= 5;
    colonne=5;
    display_test_int("test missile sur une ligne et colonne differente de la position du sous-marin J2\n", missile(Playground *pg,0,ligne,colonne),0);
    display_test_int("test missile sur une ligne et colonne differente de la position du sous-marin J1\n", missile(Playground *pg,1,ligne,colonne),0);

    //test unitaire de enough_energie
    pg->J1->energie=0;
    pg->J2->energie=0;
    display_test_int("test de enough_energie pour le missile\n",enough_energie(Playground *pg,0,0),0);
    display_test_int("test de enough_energie pour le missile\n",enough_energie(Playground *pg,1,0),0);
    display_test_int("test de enough_energie pour la surface\n",enough_energie(Playground *pg,0,2),0);
    display_test_int("test de enough_energie pour la surface\n",enough_energie(Playground *pg,1,2),0);
    display_test_int("test de enough_energie pour le sonar\n",enough_energie(Playground *pg,0,2),0);
    display_test_int("test de enough_energie pour le sonar\n",enough_energie(Playground *pg,1,2),0);
    display_test_int("test de enough_energie pour le silence\n",enough_energie(Playground *pg,0,3),0);
    display_test_int("test de enough_energie pour le silence\n",enough_energie(Playground *pg,1,3),0);
    pg->J1->energie=1;
    pg->J2->energie=1;
    display_test_int("test de enough_energie pour le missile\n",enough_energie(Playground *pg,0,0),0);
    display_test_int("test de enough_energie pour le missile\n",enough_energie(Playground *pg,1,0),0);
    display_test_int("test de enough_energie pour la surface\n",enough_energie(Playground *pg,0,1),1);
    display_test_int("test de enough_energie pour le sonar\n",enough_energie(Playground *pg,1,1),1);
    display_test_int("test de enough_energie pour le sonar\n",enough_energie(Playground *pg,0,2),0);
    display_test_int("test de enough_energie pour le sonar\n",enough_energie(Playground *pg,1,2),0);
    display_test_int("test de enough_energie pour le silence\n",enough_energie(Playground *pg,0,0),0);
    display_test_int("test de enough_energie pour le silence\n",enough_energie(Playground *pg,1,0),0);
    pg->J1->energie=2;
    pg->J2->energie=2;
    display_test_int("test de enough_energie pour le missile\n",enough_energie(Playground *pg,0,0),0);
    display_test_int("test de enough_energie pour le missile\n",enough_energie(Playground *pg,1,0),0);
    display_test_int("test de enough_energie pour la surface\n",enough_energie(Playground *pg,0,1),1);
    display_test_int("test de enough_energie pour la surface\n",enough_energie(Playground *pg,1,1),1);
    display_test_int("test de enough_energie pour le sonar\n",enough_energie(Playground *pg,0,2),1);
    display_test_int("test de enough_energie pour le sonar\n",enough_energie(Playground *pg,1,2),1);
    display_test_int("test de enough_energie pour le silence\n",enough_energie(Playground *pg,0,3),0);
    display_test_int("test de enough_energie pour le silence\n",enough_energie(Playground *pg,1,3),0);

    pg->J1->energie=3;
    pg->J2->energie=3;
    display_test_int("test de enough_energie pour le missile\n",enough_energie(Playground *pg,0,0),0);
    display_test_int("test de enough_energie pour le missile\n",enough_energie(Playground *pg,1,0),0);
    display_test_int("test de enough_energie pour la surface\n",enough_energie(Playground *pg,0,1),1);
    display_test_int("test de enough_energie pour la surface\n",enough_energie(Playground *pg,1,1),1);
    display_test_int("test de enough_energie pour le sonar\n",enough_energie(Playground *pg,0,2),1);
    display_test_int("test de enough_energie pour le sonar\n",enough_energie(Playground *pg,1,2),1);
    display_test_int("test de enough_energie pour le silence\n",enough_energie(Playground *pg,0,3),1);
    display_test_int("test de enough_energie pour le silence\n",enough_energie(Playground *pg,1,3),1);

    pg->J1->energie=4;
    pg->J2->energie=4;
    display_test_int("test de enough_energie pour le missile\n",enough_energie(Playground *pg,0,0),1);
    display_test_int("test de enough_energie pour le missile\n",enough_energie(Playground *pg,1,0),1);
    display_test_int("test de enough_energie pour la surface\n",enough_energie(Playground *pg,0,1),1);
    display_test_int("test de enough_energie pour le sonar\n",enough_energie(Playground *pg,1,1),1);
    display_test_int("test de enough_energie pour le sonar\n",enough_energie(Playground *pg,0,2),1);
    display_test_int("test de enough_energie pour le sonar\n",enough_energie(Playground *pg,1,2),1);
    display_test_int("test de enough_energie pour le silence\n",enough_energie(Playground *pg,0,0),1);
    display_test_int("test de enough_energie pour le silence\n",enough_energie(Playground *pg,1,0),1);

    display_test_string("test result haut\n",result_deplacement(Playground *pg,0,0),"Haut");
    display_test_string("test result haut\n",result_deplacement(Playground *pg,1,0),"Haut");
    display_test_string("test result bas\n",result_deplacement(Playground *pg,0,1),"Bas");
    display_test_string("test result bas\n",result_deplacement(Playground *pg,1,1),"Bas");
    display_test_string("test result gauche\n",result_deplacement(Playground *pg,0,2),"Gauche");
    display_test_string("test result gauche\n",result_deplacement(Playground *pg,1,2),"Gauche");
    display_test_string("test result droite\n",result_deplacement(Playground *pg,0,3),"Droite");
    display_test_string("test result droite\n",result_deplacement(Playground *pg,1,3),"Droite");

}
>>>>>>> b6eaf27f77578ef7d7f17db53ece4ea93b74268f
