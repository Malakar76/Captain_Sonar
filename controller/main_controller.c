//
// Created by robin on 07/02/2022.
//
/**
 * \file main_controller.c
 * \brief Fichier principal du controller.
 *
 * Fichier principal pour la gestion du controller du projet
 */
#include "main_controller.h"

void controller(View_elements *app,Playground * pg){
    SDL_Event event;
    SDL_Point point= {-1,-1};
    show_menu(app);
    int run =1;
    while (run ==1){
        SDL_WaitEvent(&event);
        switch(event.type){
            case SDL_QUIT:
                run =0;
                break;
            case SDL_MOUSEBUTTONDOWN:
                if ((event.button.button==SDL_BUTTON_LEFT) && (event.button.windowID== SDL_GetWindowID(app->wwindow))){
                    point.x=event.button.x;
                    point.y=event.button.y;
                    switch (app->window) {
                        case Menu:
                            if (SDL_PointInRect(&point,&app->Mbutton[0])){
                                show_choix_carte(app);
                            }
                            else if (SDL_PointInRect(&point,&app->Mbutton[1])){
                                show_rules(app);
                            }
                            else if (SDL_PointInRect(&point,&app->Mbutton[2])){
                                show_credit(app);
                            }
                            else if (SDL_PointInRect(&point,&app->Mbutton[3])){
                                run =0;
                            }
                            break;
                        case Choix_Carte:
                            if (SDL_PointInRect(&point,&app->Rbutton)){
                                show_menu(app);
                            }
                            else if (SDL_PointInRect(&point,&app->CCarte[0])){
                                controller_battlefield(app,pg,Archipelago);
                                show_menu(app);
                            }
                            else if (SDL_PointInRect(&point,&app->CCarte[1])){
                                controller_battlefield(app,pg,Antartica);
                                show_menu(app);
                            }
                            break;
                        case Rules:
                            if (SDL_PointInRect(&point,&app->Rbutton)){
                                show_menu(app);
                            }
                            break;
                        case Credits:
                            if (SDL_PointInRect(&point,&app->Rbutton)){
                                show_menu(app);
                            }
                            break;
                    }
                }
                break;




        }
    }
}

void controller_battlefield(View_elements * app,Playground * pg,enum Carte choix){
    int start=0;
    char message [100];
    SDL_Event event;
    SDL_Point point= {-1,-1};
    init_view_battlefield(app,choix);
    show_battlefield(app);
    choix_carte(pg,choix);
    int run=1;
    while (run==1){
        SDL_WaitEvent(&event);
        switch(event.type){
            case SDL_QUIT:
                run =0;
                break;
            case SDL_MOUSEBUTTONDOWN:
                point.x=event.button.x;
                point.y=event.button.y;
                if ((event.button.button==SDL_BUTTON_LEFT) && (event.button.windowID== SDL_GetWindowID(app->wwindow))) {
                    if (SDL_PointInRect(&point,&app->VBattlefield->Bbutton[10])){
                      run=0;
                    }
                    else if ((start==0) && (SDL_PointInRect(&point,&app->VBattlefield->Bbutton[11]))){
                        int tab[2];
                        case_choisie(app,point,tab);
                        if (est_occupe(&pg->map->carte[tab[0]][tab[1]])!=1){
                            fprintf(stderr,"%d %d",tab[0],tab[1]);
                            start_Sous_Marin(pg->J1,tab[0],tab[1],pg->map);
                            show_SM(app,pg->J1->S_M->ligne,pg->J1->S_M->colonne);
                            if (tab[0]!=-1){
                                fprintf(stderr,"Vous avez choisie votre case \n");
                                start=1;
                                print_message(app,"Vous avez choisi votre case");
                            }
                        }else{
                            fprintf(stderr,"case inaccessible\n");
                        }

                    }
                    else if (SDL_PointInRect(&point,&app->VBattlefield->Bbutton[9])){
                        //couper ou remettre le son
                    }
                    else if (SDL_PointInRect(&point,&app->VBattlefield->Bbutton[8])){
                        //clean map
                    }
                    else if (SDL_PointInRect(&point,&app->VBattlefield->Bbutton[7]) && start==1){
                        //missile
                    }
                    else if (SDL_PointInRect(&point,&app->VBattlefield->Bbutton[6]) && start==1){
                        //silence
                    }
                    else if (SDL_PointInRect(&point,&app->VBattlefield->Bbutton[5]) && start==1){
                        //sonar
                    }
                    else if (SDL_PointInRect(&point,&app->VBattlefield->Bbutton[4]) && start==1){
                        //surface
                    }
                    else if (SDL_PointInRect(&point,&app->VBattlefield->Bbutton[3]) && start==1){
                        //droite
                        if(deplacement_possible(pg,pg->actif,droite)){
                            result_deplacement(pg,pg->actif,droite,message);
                            show_SM(app,pg->J1->S_M->ligne,pg->J1->S_M->colonne);

                        }else{
                            //déplacement impossible
                            print_message(app,"Deplacement a droite impossible");

                        }
                    }
                    else if (SDL_PointInRect(&point,&app->VBattlefield->Bbutton[2]) && start==1){
                        //gauche
                        if(deplacement_possible(pg,pg->actif,gauche)){

                        }else{
                            //déplacement impossible
                            print_message(app,"Deplacement a gauche impossible");
                        }
                    }
                    else if (SDL_PointInRect(&point,&app->VBattlefield->Bbutton[1]) && start==1){
                        //bas
                        if(deplacement_possible(pg,pg->actif,bas)){

                        }else{
                            //déplacement impossible
                            print_message(app,"Deplacement en bas impossible");
                        }
                    }
                    else if (SDL_PointInRect(&point,&app->VBattlefield->Bbutton[0]) && start==1){
                        //haut
                        if(deplacement_possible(pg,pg->actif,haut)){

                        }else{
                            //déplacement impossible
                            print_message(app,"Deplacement en haut impossible");
                        }
                    }
                    else if (SDL_PointInRect(&point,&app->VBattlefield->Bbutton[11]) && start==1){
                        //sur la carte affichage calque
                    }

                }
        }
    }
}
