//
// Created by robin on 03/04/2022.
//


/**
 * \file control_battlefield.c
 * \brief gestion du controller du champ de bataille.
 *
 * Fichier qui permet de gérer le corps pur du jeu avec la gestion du champ de bataille
 */
#include "main_controller.h"

void controller_battlefield(View_elements * app,Playground * pg,enum Carte choix,int IA){
    if (IA==0){
        controller_battlefield_Joueur(app,pg,choix);
    }else if (IA==1){
        controller_battlefield_IA(app,pg,choix);
    }
}

void controller_battlefield_IA(View_elements * app,Playground * pg,enum Carte choix) {
    int start = 0;
    char message[100];
    int tab[2];
    int tir=0;
    SDL_Event event;
    SDL_Point point = {-1, -1};
    init_view_battlefield(app, choix);
    show_battlefield(app);
    choix_carte(pg, choix);
    init_calque(pg->J1);
    init_calque(pg->J2);
    int run = 1;
    while (run == 1) {
        SDL_WaitEvent(&event);
        switch (event.type) {
            case SDL_QUIT:
                run = 0;
                break;
            case SDL_MOUSEBUTTONDOWN:
                point.x = event.button.x;
                point.y = event.button.y;
                if ((event.button.button == SDL_BUTTON_LEFT) &&
                    (event.button.windowID == SDL_GetWindowID(app->wwindow))) {
                    if (SDL_PointInRect(&point, &app->VBattlefield->Bbutton[10])) {
                        run = 0;
                    } else if ((start == 0) && (SDL_PointInRect(&point, &app->VBattlefield->Bbutton[11]))) {

                        case_choisie(app, point, tab);
                        if (est_occupe(&pg->map->carte[tab[0]][tab[1]]) != 1) {
                            start_Sous_Marin(pg->J1, tab[0], tab[1], pg->map);
                            start_Sous_Marin(pg->J2, 5, 5, pg->map); //mettre une valeur quelconque pour l'IA
                            show_SM(app, pg->J1->S_M->ligne, pg->J1->S_M->colonne);
                            if (tab[0] != -1) {
                                start = 1;
                                print_message(app, "Vous avez choisi votre case");
                            }
                        } else {
                            print_message(app, "Case inaccessible");
                        }

                    } else if (SDL_PointInRect(&point, &app->VBattlefield->Bbutton[9])) {
                        //couper ou remettre le son
                    } else if (SDL_PointInRect(&point, &app->VBattlefield->Bbutton[8])) {
                        //clean map
                    } else if (SDL_PointInRect(&point, &app->VBattlefield->Bbutton[7]) && start == 1) {
                        //missile
                        if (enough_energie(pg, pg->actif, MIS)) {
                            print_message(app, "choississez la case ou tirer");
                            tir=1;
                            while (tir==1){
                                SDL_WaitEvent(&event);
                                switch (event.type) {
                                    case SDL_QUIT:
                                        run = 0;
                                        tir=0;
                                        break;
                                    case SDL_MOUSEBUTTONDOWN:
                                        point.x = event.button.x;
                                        point.y = event.button.y;
                                        if ((event.button.button == SDL_BUTTON_LEFT) &&
                                            (event.button.windowID == SDL_GetWindowID(app->wwindow))) {
                                            if (SDL_PointInRect(&point, &app->VBattlefield->Bbutton[10])) {
                                                run = 0;
                                                tir=0;
                                            } else if (SDL_PointInRect(&point, &app->VBattlefield->Bbutton[11])) {
                                                case_choisie(app, point, tab);
                                                action(pg, pg->actif, MIS, 0, tab[0], tab[1], message);
                                                print_message(app,message);
                                                tir=0;
                                            }

                                        }
                                }
                            }
                            actionIA(pg);
                        } else {
                            print_message(app, "Pas assez d'energie pour missille");
                        }
                    } else if (SDL_PointInRect(&point, &app->VBattlefield->Bbutton[6]) && start == 1) {
                        //silence
                        action(pg, pg->actif, SIL, 0, 0, 0, message);
                        print_message(app, message);
                    } else if (SDL_PointInRect(&point, &app->VBattlefield->Bbutton[5]) && start == 1) {
                        //sonar
                        if (action(pg, pg->actif, SON, 0, 0, 0, message)) {
                            actionIA(pg);
                        }
                        print_message(app, message);
                    } else if (SDL_PointInRect(&point, &app->VBattlefield->Bbutton[4]) && start == 1) {
                        //surface
                        if (action(pg, pg->actif, SURF, 0, 0, 0, message)) {
                            clean_map(app);
                            show_SM(app,pg->J1->S_M->ligne, pg->J1->S_M->colonne);
                        }
                        print_message(app, message);
                        actionIA(pg);
                    } else if (SDL_PointInRect(&point, &app->VBattlefield->Bbutton[3]) && start == 1) {
                        //droite
                        if (action(pg, pg->actif, DEPLCMNT, droite, 0, 0, message)) {
                            trace_deplacement(app,droite,pg->J1->S_M->ligne,pg->J1->S_M->colonne);
                            show_SM(app, pg->J1->S_M->ligne, pg->J1->S_M->colonne);
                            actionIA(pg);
                        }
                        print_message(app, message);
                    } else if (SDL_PointInRect(&point, &app->VBattlefield->Bbutton[2]) && start == 1) {
                        //gauche
                        if (action(pg, pg->actif, DEPLCMNT, gauche, 0, 0, message)) {
                            trace_deplacement(app,gauche,pg->J1->S_M->ligne,pg->J1->S_M->colonne);
                            show_SM(app, pg->J1->S_M->ligne, pg->J1->S_M->colonne);
                            actionIA(pg);
                        }
                        print_message(app, message);
                    } else if (SDL_PointInRect(&point, &app->VBattlefield->Bbutton[1]) && start == 1) {
                        //bas
                        if (action(pg, pg->actif, DEPLCMNT, bas, 0, 0, message)) {
                            trace_deplacement(app,bas,pg->J1->S_M->ligne,pg->J1->S_M->colonne);
                            show_SM(app, pg->J1->S_M->ligne, pg->J1->S_M->colonne);
                            actionIA(pg);
                        }
                        print_message(app, message);
                    } else if (SDL_PointInRect(&point, &app->VBattlefield->Bbutton[0]) && start == 1) {
                        //haut
                        if (action(pg, pg->actif, DEPLCMNT, haut, 0, 0, message)) {
                            trace_deplacement(app,haut,pg->J1->S_M->ligne,pg->J1->S_M->colonne);
                            show_SM(app, pg->J1->S_M->ligne, pg->J1->S_M->colonne);
                            actionIA(pg);
                        }
                        print_message(app, message);
                    } else if (SDL_PointInRect(&point, &app->VBattlefield->Bbutton[11]) && start == 1) {
                        //sur la carte affichage calque
                    }

                }
                show_energie(app,pg->J1->energie);
                show_SM(app, pg->J1->S_M->ligne, pg->J1->S_M->colonne);
                break;
        }
    }
}
void controller_battlefield_Joueur(View_elements * app,Playground * pg,enum Carte choix){

}
