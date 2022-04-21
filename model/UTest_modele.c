//
// Created by audrey on 21/04/22.
//
#include "main_model.h"
#include "carte.c"
#include "joueur.c"
#include "main_model.c"




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
    j->vie=0;



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

int main(void)
{

    const struct CMUnitTest tests_joueur[]=
            {
                    cmocka_unit_test_setup_teardown(test_energie_up, setup_joueur, teardown),

            };
    return cmocka_run_group_tests_name("Test joueur module",tests_joueur,NULL,NULL);
}