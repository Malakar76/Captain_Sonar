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
                                controller_battlefield(app,pg,Archipelago,app->IA);
                                show_menu(app);
                            }
                            else if (SDL_PointInRect(&point,&app->CCarte[1])){
                                controller_battlefield(app,pg,Antartica,app->IA);
                                show_menu(app);
                            }
                            else if (SDL_PointInRect(&point,&app->CCarte[4])){
                                coche_case(app);
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
