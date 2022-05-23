//
// Created by audrey on 21/04/22.
//
#include "UTest_modele.h"

extern int __wrap_rand(){
    return mock();
}

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



static int setup_case(void **state) {
    Case *c;
    c=(Case *)malloc (sizeof (Case));
    if(c==NULL){
        fprintf(stderr, "erreur allocation");
        return -1;
    }

    c->accessible=0;
    c->sous_marin=0;

    *state=c;
    return EXIT_SUCCESS;
}

static int setup_map(void **state) {
    CARTE *c;
    c=(CARTE *)malloc (sizeof (CARTE));
    if(c==NULL){
        fprintf(stderr, "erreur allocation");
        return -1;
    }

    int i,j;
    for (i=0;i<NMAX;i++) {
        for (j = 0; j <NMAX; j++) {
            init_Case(&c->carte[i][j]);

        }
    }

    *state=c;
    return EXIT_SUCCESS;
}

static int setup_playground(void **state) {
    Playground *pg;
    pg=(Playground *)malloc (sizeof (Playground));
    if(pg==NULL){
        fprintf(stderr, "erreur allocation");
        return -1;
    }


    pg->map= malloc(sizeof(CARTE));
    if(pg->map==NULL){
        return EXIT_FAILURE;
    }
    init_map(pg->map);
    pg->J1= malloc(sizeof (JOUEUR));
    pg->J2= malloc(sizeof(JOUEUR));
    pg->ia= malloc(sizeof(IA));
    if (pg->J2==NULL || pg->J1==NULL ||pg->ia==NULL){
        return EXIT_FAILURE;
    }
    if(init_joueur(pg->J1)==EXIT_FAILURE){
        return EXIT_FAILURE;
    }
    if(init_joueur(pg->J2)==EXIT_FAILURE){
        return EXIT_FAILURE;
    }
    pg->actif=J1;


    *state=pg;
    return EXIT_SUCCESS;
}


static int teardown(void **state){
    free(*state);
    return 0;
}




/***  TESTS initialisations ****/


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

/*static void test_init_calque_bis(void **state) { //test que 2 cases mais pb vec le fct originel on ya un _Noreturn
    JOUEUR *j = (JOUEUR *) *state;
    init_calque(j);
    assert_int_equal(j->calqueJ[0][0], 0);
    assert_int_equal(j->calqueJ[9][9], 0);
}*/

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

static void test_init_Case(void **state) {
    Case *c =(Case *)* state;
    init_Case(c);
    assert_int_equal(c->accessible, 0);
    assert_int_equal(c->sous_marin, 0);
}

static void test_init_map(void **state) {
    int i, j;
    CARTE *c =(CARTE *)* state;

    for (i = 0; i < NMAX; i++) {
        for (j = 0; j < NMAX; j++) {
            assert_int_equal(c->carte[i][j].accessible, 0);
            assert_int_equal(c->carte[i][j].sous_marin, 0);

        }
    }

}

static void test_init_model(void **state) {
    Playground *pg=(Playground *)* state;
    init_model(pg);

    /* assert_int_equal(pg->map, 0);
     assert_int_equal(pg->J1, 0);
     assert_int_equal(pg->J2, 0);
     assert_int_equal(pg->ia, 0);
     assert_int_equal(pg->actif, 0);*/

    assert_int_equal(init_model(pg), 0);

}




/***  TESTS carte.c ****/

static void test_set_Rocher(void **state){
    Playground *pg=(Playground *)* state;
    init_model(pg);
    start_Sous_Marin(pg->J1, 1,1, pg->map);
    set_Rocher(pg->map, 5,5); //creation rocher en 5x5

    assert_int_equal(pg->map->carte[5][5].accessible,1);
    assert_int_equal(pg->map->carte[0][0].accessible,0);
}

static void test_est_occupe(void **state) {
    Playground *pg = (Playground *) *state;
    init_model(pg);
    start_Sous_Marin(pg->J1, 1,1, pg->map);
    set_Rocher(pg->map, 5,5); //creation rocher en 5x5

    assert_int_equal(est_occupe(&pg->map->carte[5][5]),1);
    assert_int_equal(est_occupe(&pg->map->carte[0][0]),0);
}

static void test_crea_archipelago(void **state) {
    Playground *pg = (Playground *) *state;
    init_model(pg);
    start_Sous_Marin(pg->J1, 0,0, pg->map);
    Crea_Archipelago(pg->map);

    assert_int_equal(pg->map->carte[1][6].accessible, 1);
    assert_int_equal(pg->map->carte[2][2].accessible, 1);
    assert_int_equal(pg->map->carte[2][7].accessible, 1);
    assert_int_equal(pg->map->carte[3][8].accessible, 1);
    assert_int_equal(pg->map->carte[4][3].accessible, 1);
    assert_int_equal(pg->map->carte[6][8].accessible, 1);
    assert_int_equal(pg->map->carte[7][1].accessible, 1);
    assert_int_equal(pg->map->carte[7][2].accessible, 1);
    assert_int_equal(pg->map->carte[7][5].accessible, 1);

    assert_int_equal(pg->map->carte[0][0].sous_marin, 1);

}


static void test_crea_antartica(void **state) {
    Playground *pg = (Playground *) *state;
    init_model(pg);
    start_Sous_Marin(pg->J1, 1,1, pg->map);
    Crea_Antartica(pg->map);

    assert_int_equal(pg->map->carte[2][3].accessible, 1);
    assert_int_equal(pg->map->carte[2][7].accessible, 1);
    assert_int_equal(pg->map->carte[4][8].accessible, 1);
    assert_int_equal(pg->map->carte[6][8].accessible, 1);
    assert_int_equal(pg->map->carte[7][2].accessible, 1);
    assert_int_equal(pg->map->carte[7][4].accessible, 1);
    assert_int_equal(pg->map->carte[8][3].accessible, 1);

    assert_int_equal(pg->map->carte[1][1].sous_marin, 1);

}

static void test_choix_carte_archipelago(void **state) {
    Playground *pg = (Playground *) *state;
    init_model(pg);
    start_Sous_Marin(pg->J1, 0,0, pg->map);
    choix_carte(pg, 0);

    assert_int_equal(pg->map->carte[1][6].accessible, 1);
    assert_int_equal(pg->map->carte[2][2].accessible, 1);
    assert_int_equal(pg->map->carte[2][7].accessible, 1);
    assert_int_equal(pg->map->carte[3][8].accessible, 1);
    assert_int_equal(pg->map->carte[4][3].accessible, 1);
    assert_int_equal(pg->map->carte[6][8].accessible, 1);
    assert_int_equal(pg->map->carte[7][1].accessible, 1);
    assert_int_equal(pg->map->carte[7][2].accessible, 1);
    assert_int_equal(pg->map->carte[7][5].accessible, 1);
}
static void test_choix_carte_antartica(void **state) {
    Playground *pg = (Playground *) *state;
    init_model(pg);
    start_Sous_Marin(pg->J1, 0,0, pg->map);
    choix_carte(pg, 1);

    assert_int_equal(pg->map->carte[2][3].accessible, 1);
    assert_int_equal(pg->map->carte[2][7].accessible, 1);
    assert_int_equal(pg->map->carte[4][8].accessible, 1);
    assert_int_equal(pg->map->carte[6][8].accessible, 1);
    assert_int_equal(pg->map->carte[7][2].accessible, 1);
    assert_int_equal(pg->map->carte[7][4].accessible, 1);
    assert_int_equal(pg->map->carte[8][3].accessible, 1);
}



/***  TESTS joueur.c ****/


static void test_energie_up(void **state){
    Playground *pg=(Playground *)* state;

    //JOUEUR *j =(JOUEUR *)* state;
    energie_up(pg->J1);
    assert_int_equal(pg->J1->energie, 1);
}

static void test_energie_down(void **state){
    Playground *pg=(Playground *)* state;

    //JOUEUR *j =(JOUEUR *)* state;
    energie_up(pg->J1);
    energie_up(pg->J1);
    energie_down(pg->J1,1);
    assert_int_equal(pg->J1->energie, 1);
}



static void test_deplacement_droite(void **state){
    Playground *pg=(Playground *)* state;

    deplacement(pg, J1, droite);

    assert_int_equal(pg->J1->S_M->ligne, 0);
    assert_int_equal(pg->J1->S_M->colonne, 1);
    assert_int_equal(pg->J1->nbpath,1);
    assert_int_equal(pg->J1->path[0],3);
    assert_int_equal(pg->J1->calqueJ[pg->J1->S_M->ligne][pg->J1->S_M->colonne],1);
    assert_int_equal(pg->J1->energie,1);
    energie_up(pg->J1);
    energie_up(pg->J1);
    energie_up(pg->J1);
    deplacement(pg, J1, droite);
    assert_int_equal(pg->J1->energie, 4); //test si energie deja a 4, ca bouge pas
}

static void test_deplacement_droite_rob(void **state){
    Playground  * pg ;
    JOUEUR *j =(JOUEUR *)* state;

    pg= malloc(sizeof (Playground));
    pg->map=malloc(sizeof(CARTE));
    init_map(pg->map);
    pg->J1=j;

    deplacement(pg, J1, droite);

    assert_int_equal(pg->J1->S_M->ligne, 0);
    assert_int_equal(pg->J1->S_M->colonne, 1);
    assert_int_equal(pg->J1->nbpath,1);
    assert_int_equal(pg->J1->path[0],3);
    assert_int_equal(pg->J1->calqueJ[pg->J1->S_M->ligne][pg->J1->S_M->colonne],1);
    assert_int_equal(pg->J1->energie,1);
    energie_up(pg->J1);
    deplacement(pg, J1, bas);
    assert_int_equal(pg->J1->energie, 3); //test si energie deja a 4, ca bouge pas
}

static void test_deplacement_haut(void **state){
    Playground *pg=(Playground *)* state;

    start_Sous_Marin(pg->J1, 1,1,pg->map);
    deplacement(pg, J1, haut);

    assert_int_equal(pg->J1->S_M->ligne, 0);
    assert_int_equal(pg->J1->S_M->colonne, 1);
    assert_int_equal(pg->J1->nbpath,1);
    assert_int_equal(pg->J1->path[0],0);//haut =0
    assert_int_equal(pg->J1->calqueJ[pg->J1->S_M->ligne][pg->J1->S_M->colonne],1);
    assert_int_equal(pg->J1->energie,1);
    energie_up(pg->J1);
    energie_up(pg->J1);
    energie_up(pg->J1);
    deplacement(pg, J1, droite);
    assert_int_equal(pg->J1->energie, 4); //test si energie deja a 4, ca bouge pas

}

static void test_deplacement_bas(void **state){
    Playground *pg=(Playground *)* state;

    start_Sous_Marin(pg->J1, 1,1,pg->map);
    deplacement(pg, J1, bas);

    assert_int_equal(pg->J1->S_M->ligne, 2);
    assert_int_equal(pg->J1->S_M->colonne, 1);
    assert_int_equal(pg->J1->nbpath,1);
    assert_int_equal(pg->J1->path[0],1);//bas =0
    assert_int_equal(pg->J1->calqueJ[pg->J1->S_M->ligne][pg->J1->S_M->colonne],1);
    assert_int_equal(pg->J1->energie,1);
    energie_up(pg->J1);
    energie_up(pg->J1);
    energie_up(pg->J1);
    deplacement(pg, J1, bas);
    assert_int_equal(pg->J1->energie, 4); //test si energie deja a 4, ca bouge pas

}

static void test_deplacement_gauche(void **state){
    Playground *pg=(Playground *)* state;

    start_Sous_Marin(pg->J1, 1,1,pg->map);
    deplacement(pg, J1, gauche);

    assert_int_equal(pg->J1->S_M->ligne, 1);
    assert_int_equal(pg->J1->S_M->colonne, 0);
    assert_int_equal(pg->J1->nbpath,1);
    assert_int_equal(pg->J1->path[0],2);//gauche =0
    assert_int_equal(pg->J1->calqueJ[pg->J1->S_M->ligne][pg->J1->S_M->colonne],1);
    assert_int_equal(pg->J1->energie,1);
    energie_up(pg->J1);
    energie_up(pg->J1);
    energie_up(pg->J1);
    deplacement(pg, J1, droite);
    assert_int_equal(pg->J1->energie, 4); //test si energie deja a 4, ca bouge pas

}


static void test_deplacement_possible(void **state){ //dplcmnt possible fin carte + rocher + deja passé + si j2 y est deja (c possible)
    Playground *pg=(Playground *)* state;
    init_model(pg);
    start_Sous_Marin(pg->J1, 0, 0, pg->map);
    start_Sous_Marin(pg->J2, 1, 1, pg->map);

    set_Rocher(pg->map, 0, 2);

    assert_int_equal(deplacement_possible(pg, J1, haut), 0); //impossible car bord de la carte
    deplacement(pg, J1, droite);
    assert_int_equal(deplacement_possible(pg, J1, gauche), 0); //impossible car deja passe
    assert_int_equal(deplacement_possible(pg, J1, droite), 0); //impossible car presence de rocher
    assert_int_equal(deplacement_possible(pg, J1, bas), 1); //il doit pouvoir aller en bas
    assert_int_equal(deplacement_possible(pg, J1, bas), 1); //il doit pouvoir aller la ou est j2

}



static void test_enough_energie_missile(void **state){
    Playground *pg=(Playground *)* state;

    energie_up(pg->J1);
    energie_up(pg->J1);
    assert_int_equal(enough_energie(pg, J1, MIS), 0);
    energie_up(pg->J1);
    energie_up(pg->J1);
    assert_int_equal(enough_energie(pg, J1, MIS), 1);

}

static void test_enough_energie_surface(void **state){
    Playground *pg=(Playground *)* state;

    assert_int_equal(enough_energie(pg, J1, SURF), 1);
}


static void test_enough_energie_sonar(void **state){
    Playground *pg=(Playground *)* state;
    energie_up(pg->J1);
    assert_int_equal(enough_energie(pg, J1, SON), 0);
    energie_up(pg->J1);
    assert_int_equal(enough_energie(pg, J1, SON), 1);
}

static void test_enough_energie_silence(void **state){
    Playground *pg=(Playground *)* state;
    energie_up(pg->J1);
    energie_up(pg->J1);
    assert_int_equal(enough_energie(pg, J1, SIL), 0);
    energie_up(pg->J1);
    assert_int_equal(enough_energie(pg, J1, SIL), 1);

}

static void test_enough_energie_dplcmt(void **state){
    Playground *pg=(Playground *)* state;
    assert_int_equal(enough_energie(pg, J1, DEPLCMNT), 1);
}



static void test_missile(void **state){ // si j1 tire sur rien , sur j2 et sur lui meme et idem pour j2
    Playground *pg=(Playground *)* state;
    init_model(pg);
    start_Sous_Marin(pg->J1, 0,0, pg->map); //on a placé le j1 à la pos 0x0
    start_Sous_Marin(pg->J2, 1,1, pg->map); //on a placé le j2 à la pos 1x1

    missile(pg, J1, 1, 1); //j1 tire sur J2
    assert_int_equal(pg->J1->vie, 2); //j1 garde ses 2 vies
    assert_int_equal(pg->J2->vie, 1); //j2 a ete touché il a perdu 1 vie

    missile(pg, J1, 0, 0); //j1 tire sur lui meme
    assert_int_equal(pg->J1->vie, 1); //j1 perd une vie

    missile(pg, J1, 3, 3); //j1 tire sur rien
    assert_int_equal(pg->J1->vie, 1); //j1 n a pas ete touche
    assert_int_equal(pg->J2->vie, 1); //j2 n a pas ete touche

    missile(pg, J2, 3, 3); //j2 tire sur rien
    assert_int_equal(pg->J1->vie, 1); //j1 n a pas ete touche
    assert_int_equal(pg->J2->vie, 1); //j2 n a pas ete touche

    missile(pg, J2, 1, 1); //j2 tire sur lui meme
    assert_int_equal(pg->J1->vie, 1); //j1 n a pas ete touche
    assert_int_equal(pg->J2->vie, 0); //j2 a ete touche
}

static void test_result_missile(void **state) { /****  manque si touche adversaire ET soi meme en meme temps  ***/
    char mes[50];
    Playground *pg = (Playground *) *state;
    init_model(pg);
    start_Sous_Marin(pg->J1, 0, 0, pg->map); //on a placé le j1 à la pos 0x0
    start_Sous_Marin(pg->J2, 1, 1, pg->map); //on a placé le j2 à la pos 1x1

    result_missile(pg, J1, 2,2, mes); //renvoie 0 car rien touche
    assert_string_equal(mes, "Zut, vous n'avez rien touche");

    result_missile(pg, J1, 1,1, mes); //renvoie 1 car touche adversaire
    assert_string_equal(mes, "Bravo vous avez touche l'adversaire");

    result_missile(pg, J1, 0,0, mes); //renvoie 1 car touche lui meme
    assert_string_equal(mes, "Mince alors, vous vous etes touche vous meme!");
}

static void test_surface(void **state) {
    char mes[50];
    Playground *pg = (Playground *) *state;
    init_model(pg);
    start_Sous_Marin(pg->J1, 1, 1, pg->map); //on a placé le j1 à la pos 1x1
    deplacement(pg, J1, droite);
    deplacement(pg, J1, droite); //j1 est en 0x2
    surface(pg, J1, mes);

    assert_string_equal(mes, "Nous faisons surface");
    assert_int_equal(pg->J1->vie, 2);
    assert_int_equal(pg->J1->energie, 2); //j1 s est deplace 2 fois
    assert_int_equal(pg->J1->nbpath, 0); //remise a zero
    assert_int_equal(pg->J1->S_M->start[0], pg->J1->S_M->ligne);
    assert_int_equal(pg->J1->S_M->start[1], pg->J1->S_M->colonne);
    assert_int_equal(pg->J1->calqueJ[pg->J1->S_M->ligne][pg->J1->S_M->colonne], 1);
    assert_int_equal(pg->J1->calqueJ[0][0], 0); //verifier qu ele calque est bien vider la ou le SM est passer avnt de faire surface
    assert_int_equal(pg->J1->calqueJ[0][1], 0);
}








static void test_action(void **state) { //sonar pas complété
    char mes[50];
    Playground *pg = (Playground *) *state;
    init_model(pg);
    start_Sous_Marin(pg->J1, 0,0, pg->map);

    /*** missile ***/

    action(pg, J1, MIS, haut, 1,1, mes);
    assert_string_equal(mes, "Pas assez d'energie pour missille");
    assert_int_equal(pg->J1->energie, 0);

    energie_up(pg->J1);
    energie_up(pg->J1);
    energie_up(pg->J1);
    energie_up(pg->J1);
    action(pg, J1, MIS, haut, 1,1, mes);
    assert_int_equal(pg->J1->energie, 0);
    assert_string_equal(mes,  "Zut, vous n'avez rien touche");



    /*** surface ***/
    assert_int_equal(action(pg, J1, SURF, haut, 1,1, mes), 1);
    assert_string_equal(mes,  "Nous faisons surface");

    /*** sonar ***/
    action(pg, J1, SON, haut, 1,1, mes);
    assert_string_equal(mes, "Pas d'energie pour sonar");
    assert_int_equal(pg->J1->energie, 0);


    energie_up(pg->J1);
    energie_up(pg->J1);
    will_return (__wrap_rand,0);

    action(pg, J1, SON, haut, 1,1, mes);
    assert_int_equal(pg->J1->energie,0);

    /*** dplcmnt ***/

    action(pg, J1, DEPLCMNT, haut, 1,1, mes); //ideme pour dplcmnt ailleurs
    assert_string_equal(mes, "Impossible de se deplacer en haut");
    assert_int_equal(pg->J1->energie, 0);

    action(pg, J1, DEPLCMNT, bas, 1,1, mes);
    assert_string_equal(mes, "Deplacement en bas");
    assert_int_equal(pg->J1->energie, 1);
}



static void test_sonar(void **state) {
    char mesa[50];
    Playground *pg = (Playground *) *state;
    init_model(pg);
    start_Sous_Marin(pg->J1, 0,0, pg->map);
    start_Sous_Marin(pg->J2, 1,1, pg->map);

    energie_up(pg->J1);
    energie_up(pg->J1);
    will_return (__wrap_rand,0);
    sonar(pg, J1, mesa);
    assert_string_equal(mesa, "L'ennemi se trouve dans la ligne 2");

    energie_up(pg->J1);
    energie_up(pg->J1);
    will_return (__wrap_rand,1);
    sonar(pg, J1, mesa);
    assert_string_equal(mesa, "L'ennemi se trouve dans la colonne B");
}


/***  TESTS main_model.c ****/

static void test_free_model(void **state) {
    Playground *pg = (Playground *) *state;
    init_model(pg);
    free_model(pg);
    assert_non_null(pg->map);
    assert_null(pg->J1->S_M);
    assert_non_null(pg->J1);
}

static void test_free_Carte(void **state) {
    Playground *pg = (Playground *) *state;
    init_model(pg);
    free_Carte(pg->map);
    assert_non_null(pg->map);
}

static void test_free_joueur(void **state){
    Playground *pg=(Playground *)* state;
    init_model(pg);
    free_joueur(pg->J1);
    assert_null(pg->J1->S_M);
    assert_non_null(pg->J1);
}



int main(void)
{

    const struct CMUnitTest tests_joueur[]=
            {
                    cmocka_unit_test_setup_teardown(test_init_joueur, setup_joueur, teardown),
                    cmocka_unit_test_setup_teardown(test_init_calque, setup_joueur, teardown),
                    cmocka_unit_test_setup_teardown(test_init_reset, setup_joueur, teardown),
                    cmocka_unit_test_setup_teardown(test_start_Sous_Marin, setup_joueur, teardown),
                    cmocka_unit_test_setup_teardown(test_init_Case, setup_case, teardown),
                    cmocka_unit_test_setup_teardown(test_init_map, setup_map, teardown),
                    cmocka_unit_test_setup_teardown(test_init_model, setup_playground, teardown),

                    cmocka_unit_test_setup_teardown(test_energie_up, setup_playground, teardown),
                    cmocka_unit_test_setup_teardown(test_energie_down, setup_playground, teardown),

                    cmocka_unit_test_setup_teardown(test_deplacement_droite, setup_playground, teardown),
                    cmocka_unit_test_setup_teardown(test_deplacement_haut, setup_playground, teardown),
                    cmocka_unit_test_setup_teardown(test_deplacement_bas, setup_playground, teardown),
                    cmocka_unit_test_setup_teardown(test_deplacement_gauche, setup_playground, teardown),

                    cmocka_unit_test_setup_teardown(test_deplacement_possible, setup_playground, teardown),

                    cmocka_unit_test_setup_teardown(test_enough_energie_missile, setup_playground, teardown),
                    cmocka_unit_test_setup_teardown(test_enough_energie_surface, setup_playground, teardown),
                    cmocka_unit_test_setup_teardown(test_enough_energie_sonar, setup_playground, teardown),
                    cmocka_unit_test_setup_teardown(test_enough_energie_sonar, setup_playground, teardown),
                    cmocka_unit_test_setup_teardown(test_enough_energie_dplcmt, setup_playground, teardown),

                    cmocka_unit_test_setup_teardown(test_set_Rocher, setup_playground, teardown),
                    cmocka_unit_test_setup_teardown(test_est_occupe, setup_playground, teardown),
                    cmocka_unit_test_setup_teardown(test_crea_antartica, setup_playground, teardown),
                    cmocka_unit_test_setup_teardown(test_crea_archipelago, setup_playground, teardown),
                    cmocka_unit_test_setup_teardown(test_choix_carte_antartica, setup_playground, teardown),
                    cmocka_unit_test_setup_teardown(test_choix_carte_archipelago, setup_playground, teardown),

                    cmocka_unit_test_setup_teardown(test_missile, setup_playground, teardown),
                    cmocka_unit_test_setup_teardown(test_result_missile, setup_playground, teardown),
                    cmocka_unit_test_setup_teardown(test_surface, setup_playground, teardown),
                    cmocka_unit_test_setup_teardown(test_sonar, setup_playground, teardown),


                    cmocka_unit_test_setup_teardown(test_action, setup_playground, teardown),


                    cmocka_unit_test_setup_teardown(test_free_Carte, setup_playground, teardown),
                    cmocka_unit_test_setup_teardown(test_free_joueur, setup_playground, teardown),
                    cmocka_unit_test_setup_teardown(test_free_model, setup_playground, teardown),


            };
    return cmocka_run_group_tests_name("Test joueur module", tests_joueur, NULL, NULL);
}

