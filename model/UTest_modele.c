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
    j->energie=0;
    j->vie=2;
    j->S_M->ligne=5;
    j->S_M->colonne=5;



    *state=j;
    return 0;
}


static int teardown(void **state){
    {
      //  free((JOUEUR *)*state)->energie);
        free(*state);
        return 0;
    }
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

static void test_deplacement_haut(void **state){
    JOUEUR *j =(JOUEUR *)* state;
    deplacement(, J1, haut);
    assert_int_equal(j->S_M->ligne, 4);
    assert_int_equal(j->S_M->colonne, 5);

}

static void test_deplacement_bas(void **state){
    JOUEUR *j =(JOUEUR *)* state;
    deplacement(, J1, bas);
    assert_int_equal(j->S_M->ligne, 6);
    assert_int_equal(j->S_M->colonne, 5);
}
static void test_deplacement_droite(void **state){
    JOUEUR *j =(JOUEUR *)* state;
    deplacement(, J1, droite);
    assert_int_equal(j->S_M->ligne, 5);
    assert_int_equal(j->S_M->colonne, 6);
}
static void test_deplacement_gauche(void **state){
    JOUEUR *j =(JOUEUR *)* state;
    deplacement(, J1, droite);
    assert_int_equal(j->S_M->ligne, 5);
    assert_int_equal(j->S_M->colonne, 4);
}
//dplcmnt possible fin carte + rocher

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

int main(void)
{

    const struct CMUnitTest tests_joueur[]=
            {
                    cmocka_unit_test_setup_teardown(test_energie_up, setup_joueur, teardown),
                    cmocka_unit_test_setup_teardown(test_energie_down, setup_joueur, teardown),
                    cmocka_unit_test_setup_teardown(test_deplacement_haut, setup_joueur, teardown),
                    cmocka_unit_test_setup_teardown(test_deplacement_bas, setup_joueur, teardown),
                    cmocka_unit_test_setup_teardown(test_deplacement_gauche, setup_joueur, teardown),
                    cmocka_unit_test_setup_teardown(test_deplacement_droite, setup_joueur, teardown),
                    cmocka_unit_test_setup_teardown(enough_energie_missile, setup_joueur, teardown),
                    cmocka_unit_test_setup_teardown(not_enough_energie_missile, setup_joueur, teardown),
                    cmocka_unit_test_setup_teardown(enough_energie_surface, setup_joueur, teardown),
                    cmocka_unit_test_setup_teardown(enough_energie_sonar, setup_joueur, teardown),
                    cmocka_unit_test_setup_teardown(not_enough_energie_sonar, setup_joueur, teardown),
                    cmocka_unit_test_setup_teardown(enough_energie_dplcmt, setup_joueur, teardown),


            };
    return cmocka_run_group_tests_name("Test joueur module", tests_joueur, NULL, NULL);
}
