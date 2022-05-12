//
// Created by audrey on 21/04/22.
//
#include "main_model.h"

#include <stdio.h>

#include <stdarg.h>
#include <stddef.h>
#include <setjmp.h>
#include <cmocka.h>
#include <stdlib.h>


static int setup_joueur(void **state){



    JOUEUR *j;
    j=(JOUEUR *)malloc (sizeof (JOUEUR));
    if(j==NULL){
        fprintf(stderr, "erreur allocation");
        return -1;
    }


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
    j->nbpath=0;




    *state=j;
    return EXIT_SUCCESS;
}




static int teardown(void **state){

    //  free((JOUEUR *)*state)->energie);
    free(*state);
    return 0;

}

static void test_energie_up(void **state){
    JOUEUR *j =(JOUEUR *)* state;
    energie_up(j);
    assert_int_equal(j->energie, 1);
}

static void test_energie_down(void **state){
    JOUEUR *j =(JOUEUR *)* state;
    energie_up(j);
    energie_up(j);
    energie_down(j,1);
    assert_int_equal(j->energie, 1);
}

static void test_deplacement_droite(void **state){
    Playground  *pg ;


    pg= malloc(sizeof (Playground));

    init_model(pg);

    JOUEUR *j =(JOUEUR *)* state;
    pg->J1=j;
    deplacement(pg, J1, droite);

    assert_int_equal(j->S_M->ligne, 0);


    // assert_int_equal(j->S_M->colonne, 1);
    // assert_int_equal(j->nbpath,1);
    assert_string_equal(j->path, haut);
    assert_int_equal(j->calqueJ[j->S_M->ligne][j->S_M->colonne],1);

    assert_int_equal(j->energie, 3);
    energie_up(j);
    deplacement(pg, J1, haut);
    assert_int_equal(j->energie, 4); //test si energie deja a 4, ca bouge pas
}

static void test_deplacement_droite2(void **state){
    Playground *pg= (Playground *)* state;

    init_model(pg);

    deplacement(pg, J1, droite);

    assert_int_equal(pg->J1->S_M->ligne, 0);
    // assert_int_equal(j->S_M->colonne, 1);
    // assert_int_equal(j->nbpath,1);
    assert_string_equal(pg->J1->path, haut);
    assert_int_equal(pg->J1->calqueJ[pg->J1->S_M->ligne][pg->J1->S_M->colonne],1);

    assert_int_equal(pg->J1->energie, 3);
    energie_up(pg->J1);
    deplacement(pg, J1, haut);
    assert_int_equal(pg->J1->energie, 4); //test si energie deja a 4, ca bouge pas
}
/*static void test_deplacement_haut(void **state){
    JOUEUR *j =(JOUEUR *)* state;
    init_calque(j);
    deplacement(, J1, haut);
    assert_int_equal(j->S_M->ligne, 4);
    assert_int_equal(j->S_M->colonne, 5);
    assert_int_equal(j->nbpath,1);
    assert_string_equal(j->path, haut);
    assert_int_equal(j->calqueJ[j->S_M->ligne][j->S_M->colonne],1);

    assert_int_equal(j->energie, 3);
    energie_up(j);
    deplacement(, J1, haut);
    assert_int_equal(j->energie, 4); //test si energie deja a 4, ca bouge pas


}

static void test_deplacement_bas(void **state){
    JOUEUR *j =(JOUEUR *)* state;
    init_calque(j);
    deplacement(, J1, bas);
    assert_int_equal(j->S_M->ligne, 6);
    assert_int_equal(j->S_M->colonne, 5);
    assert_int_equal(j->nbpath,1);
    assert_string_equal(j->path, haut);
    assert_int_equal(j->calqueJ[j->S_M->ligne][j->S_M->colonne],1);

    assert_int_equal(j->energie, 3);
    energie_up(j);
    deplacement(, J1, haut);
    assert_int_equal(j->energie, 4);
}

static void test_deplacement_gauche(void **state){
    JOUEUR *j =(JOUEUR *)* state;
    init_calque(j);
    deplacement(, J1, gauche);
    assert_int_equal(j->S_M->ligne, 5);
    assert_int_equal(j->S_M->colonne, 4);
    assert_int_equal(j->nbpath,1);
    assert_string_equal(j->path, haut);
    assert_int_equal(j->calqueJ[j->S_M->ligne][j->S_M->colonne],1);

    assert_int_equal(j->energie, 3);
    energie_up(j);
    deplacement(, J1, haut);
    assert_int_equal(j->energie, 4);
}

static void not_deplacement_possible_haut(void **state){ //idemn pour les autres directions
    JOUEUR *j =(JOUEUR *)* state;
    deplacement(, J1, haut);
    deplacement(, J1, haut);
    deplacement(, J1, haut);
    deplacement(, J1, haut); //arrivé en haut de la carte
    assert_int_equal(deplacement_possible(, J1, haut), 0); //impossible car carte fini
    assert_int_equal(deplacement_possible(, J1, haut), 0); //impossible car deja passe
}
//dplcmnt possible fin carte + rocher + deja passé

static void enough_energie_missile(void **state){
    JOUEUR *j =(JOUEUR *)* state;
    energie_up(j);
    energie_up(j);
    assert_int_equal(enough_energie(, J1, MIS), 1);
}

static void not_enough_energie_missile(void **state){
    JOUEUR *j =(JOUEUR *)* state;
    assert_int_equal(enough_energie(, J1, MIS), 0);
}

static void enough_energie_surface(void **state){
    JOUEUR *j =(JOUEUR *)* state;
    assert_int_equal(enough_energie(, J1, SURF), 1);
}

static void enough_energie_sonar(void **state){
    JOUEUR *j =(JOUEUR *)* state;
    energie_up(j);
    assert_int_equal(enough_energie(, J1, SON), 1);
}

static void not_enough_energie_sonar(void **state){
    JOUEUR *j =(JOUEUR *)* state;
    energie_down(j);
    assert_int_equal(enough_energie(, J1, SON), 0);
}

static void enough_energie_silence(void **state){
    JOUEUR *j =(JOUEUR *)* state;
    energie_up(j);
    assert_int_equal(enough_energie(, J1, SIL), 1);
}

static void not_enough_energie_silence(void **state){
    JOUEUR *j =(JOUEUR *)* state;
    assert_int_equal(enough_energie(, J1, SIL), 0);
}

static void enough_energie_dplcmt(void **state){
    JOUEUR *j =(JOUEUR *)* state;
    energie_down(j,2);
    assert_int_equal(enough_energie(, J1, DEPLCMNT), 1);
}



*/
static void test_init_joueur(void **state){
    JOUEUR *j =(JOUEUR *)* state;
    init_joueur(j);
    assert_int_equal(j->energie, 0);
    assert_int_equal(j->vie, 2);
    assert_int_equal(j->S_M->ligne, 0);
    assert_int_equal(j->S_M->colonne, 0);
    assert_int_equal(j->S_M->start[0], 0);
    assert_int_equal(j->S_M->start[1], 0);
    assert_int_equal(j->nbpath, 0);
}

_Noreturn static void test_init_calque(void **state) {
    int i,k;
    JOUEUR *j = (JOUEUR *) *state;
    init_calque(j);
    for (i = 0; i < 10; i++) {
        for (k = 0; k < 10; k++) {
            assert_int_equal(j->calqueJ[i][k], 0);
        }
    }
}
static void test_init_calque_bis(void **state) { //test que 2 cases mais pb vec le fct originel on ya un _Noreturn
    JOUEUR *j = (JOUEUR *) *state;
    init_calque(j);
    assert_int_equal(j->calqueJ[0][0], 0);
    assert_int_equal(j->calqueJ[9][9], 0);
}

static void test_init_reset(void **state){
    JOUEUR *j =(JOUEUR *)* state;
    reset_joueur(j);

    assert_int_equal(j->energie, 0);
    assert_int_equal(j->vie, 2);
    assert_int_equal(j->S_M->ligne, 0);
    assert_int_equal(j->S_M->colonne, 0);
    assert_int_equal(j->S_M->start[0], 0);
    assert_int_equal(j->S_M->start[1], 0);
    assert_int_equal(j->nbpath, 0);


}

static void test_start_Sous_Marin(void **state) {
    JOUEUR *j = (JOUEUR *) *state;
    CARTE *c= malloc(sizeof (CARTE));
    start_Sous_Marin(j,5,7,c);

    assert_int_equal(j->S_M->ligne, 5);
    assert_int_equal(j->S_M->colonne, 7);
    assert_int_equal(j->S_M->start[0],j->S_M->ligne);
    assert_int_equal(j->S_M->start[1],j->S_M->colonne);
    assert_int_equal(j->calqueJ[5][7],1);
    assert_int_equal(c->carte[5][7].sous_marin,1);
}

static void test_missile(void **state){
    JOUEUR *j1 =(JOUEUR *)* state;
    pg->J1=j;
    JOUEUR *j2 =(JOUEUR *)* state;
    pg->J2=j2;
    deplacement(pg, J2, droite);
    deplacement(pg, J2, bas); //on a placé le j2 à la pos 1x1
    missile(, J1, 1, 1); //j1 tire sur J2

    assert_int_equal(j1->vie, 2); //j1 garde ses 2 vies
    assert_int_equal(j2->vie, 1); //j2 a ete touché il a perdu 1 vie

    missile(pg, J1, 0, 0); //j1 tire sur lui meme

    assert_int_equal(j1->vie, 1); //j1 perd une vie

    missile(pg, J1, 0, 0); //j1 tire sur rien

    assert_int_equal(j1->vie, 1); //j1 n a pas ete touche
    assert_int_equal(j2->vie, 1); //j2 n a pas ete touche
}


int main(void)
{

    const struct CMUnitTest tests_joueur[]=
            {
                    cmocka_unit_test_setup_teardown(test_energie_up, setup_joueur, teardown),
                    cmocka_unit_test_setup_teardown(test_energie_down, setup_joueur, teardown),
                        /*cmocka_unit_test_setup_teardown(test_deplacement_droite, setup_joueur, teardown),

                 cmocka_unit_test_setup_teardown(test_deplacement_haut, setup_joueur, teardown),
                     cmocka_unit_test_setup_teardown(test_deplacement_bas, setup_joueur, teardown),
                     cmocka_unit_test_setup_teardown(test_deplacement_gauche, setup_joueur, teardown),
                     cmocka_unit_test_setup_teardown(enough_energie_missile, setup_joueur, teardown),
                     cmocka_unit_test_setup_teardown(not_enough_energie_missile, setup_joueur, teardown),
                     cmocka_unit_test_setup_teardown(enough_energie_surface, setup_joueur, teardown),
                     cmocka_unit_test_setup_teardown(enough_energie_sonar, setup_joueur, teardown),
                     cmocka_unit_test_setup_teardown(not_enough_energie_sonar, setup_joueur, teardown),
                     cmocka_unit_test_setup_teardown(enough_energie_dplcmt, setup_joueur, teardown),
                     cmocka_unit_test_setup_teardown(test_missile, setup_joueur, teardown),*/
                     cmocka_unit_test_setup_teardown(test_init_joueur, setup_joueur, teardown),
                     cmocka_unit_test_setup_teardown(test_init_calque, setup_joueur, teardown),
                    cmocka_unit_test_setup_teardown(test_init_reset, setup_joueur, teardown),
                    cmocka_unit_test_setup_teardown(test_start_Sous_Marin, setup_joueur, teardown),


            };
    return cmocka_run_group_tests_name("Test joueur module", tests_joueur, NULL, NULL);
}

