//
// Created by robin on 07/02/2022.
//

/**
 * \file main_view.c
 * \brief Fichier principal de la vue.
 *
 * Fichier principal pour la gestion de la vue du projet
 */

#include "main_view.h"

int init_view(View_elements * app) {
    SDL_Surface * icone =NULL;
    int Resolution_x =1600;
    int Resolution_y=900;
    int statut = EXIT_FAILURE;
    if (IMG_Init(IMG_INIT_JPG|IMG_INIT_PNG)==0){
        fprintf(stderr, "Erreur IMG_Init : %s", SDL_GetError());
        return statut;
    }
    if (TTF_Init()!=0){
        fprintf(stderr, "Erreur TTF_Init : %s", SDL_GetError());
        return statut;
    }
    init_font(app);
    app->VBattlefield=(malloc(sizeof(View_Battlefield)));

    if (0 != SDL_Init(SDL_INIT_VIDEO)) {
        fprintf(stderr, "Erreur SDL_Init : %s", SDL_GetError());
        return statut;
    }
    if (0 != SDL_CreateWindowAndRenderer(Resolution_x, Resolution_y, SDL_WINDOW_SHOWN, &app->wwindow, &app->rRenderer)) {
        fprintf(stderr, "Erreur SDL_CreateWindowAndRenderer : %s", SDL_GetError());
        return statut;
    }
    icone=IMG_Load("Ressources/sonar_family.jpg");
    if (icone==NULL) {
        fprintf(stderr, "Erreur SDL_CreateSurface : %s", SDL_GetError());
        SDL_FreeSurface(icone);
        return EXIT_FAILURE;
    }
    SDL_SetWindowTitle(app->wwindow,"Sonar family");
    SDL_SetWindowIcon(app->wwindow,icone);
    SDL_FreeSurface(icone);
    app->mMenu= SDL_CreateTexture(app->rRenderer,SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET,Resolution_x,Resolution_y);
    if(NULL == app->mMenu) {
        fprintf(stderr, "Erreur SDL_CreateTexture : %s", SDL_GetError());
        return statut;
    }
    app->rRegles= SDL_CreateTexture(app->rRenderer,SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET,Resolution_x,Resolution_y);
    if(NULL == app->rRegles) {
        fprintf(stderr, "Erreur SDL_CreateTexture : %s", SDL_GetError());
        return statut;
    }
    app->cCredit= SDL_CreateTexture(app->rRenderer,SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET,Resolution_x,Resolution_y);
    if(NULL == app->cCredit) {
        fprintf(stderr, "Erreur SDL_CreateTexture : %s", SDL_GetError());
        return statut;
    }
    app->cCarte= SDL_CreateTexture(app->rRenderer,SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET,Resolution_x,Resolution_y);
    if(NULL == app->cCarte) {
        fprintf(stderr, "Erreur SDL_CreateTexture : %s", SDL_GetError());
        return statut;
    }
    app->valide= SDL_CreateTexture(app->rRenderer,SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET,Resolution_x,Resolution_y);
    if(NULL == app->valide) {
        fprintf(stderr, "Erreur SDL_CreateTexture : %s", SDL_GetError());
        return statut;
    }
    app->VBattlefield->Battlefield_blank =SDL_CreateTexture(app->rRenderer,SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET,Resolution_x,Resolution_y);
    if(NULL == app->VBattlefield->Battlefield_blank) {
        fprintf(stderr, "Erreur SDL_CreateTexture : %s", SDL_GetError());
        return statut;
    }
    app->VBattlefield->Battlefield_current =SDL_CreateTexture(app->rRenderer,SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET,Resolution_x,Resolution_y);
    if(NULL == app->VBattlefield->Battlefield_current) {
            fprintf(stderr, "Erreur SDL_CreateTexture : %s", SDL_GetError());
            return statut;
    }
    app->VBattlefield->Sous_marin =SDL_CreateTexture(app->rRenderer,SDL_PIXELFORMAT_RGBA8888,SDL_TEXTUREACCESS_TARGET,Resolution_x,Resolution_y);
    if(NULL == app->VBattlefield->Sous_marin) {
                fprintf(stderr, "Erreur SDL_CreateTexture : %s", SDL_GetError());
                return statut;
    }
    statut=EXIT_SUCCESS;
    return statut;

}

void free_view(View_elements *app){
    SDL_DestroyRenderer(app->rRenderer);
    SDL_DestroyWindow(app->wwindow);
    SDL_DestroyTexture(app->mMenu);
    SDL_DestroyTexture(app->rRegles);
    SDL_DestroyTexture(app->cCredit);
    SDL_DestroyTexture(app->cCarte);
    SDL_DestroyTexture(app->valide);
    SDL_DestroyTexture(app->VBattlefield->Sous_marin);
    SDL_DestroyTexture(app->VBattlefield->Battlefield_current);
    SDL_DestroyTexture(app->VBattlefield->Battlefield_blank);
    IMG_Quit();
    TTF_Quit();
    while (Mix_Init(0)){
        Mix_Quit();
    }
}



int init_all_view(View_elements *app){
    if(init_menu(app)!=EXIT_SUCCESS){
        return EXIT_FAILURE;
    }
    if(init_choix_carte(app) !=EXIT_SUCCESS){
        return EXIT_FAILURE;
    }
    if(init_rules(app) !=EXIT_SUCCESS){
        return EXIT_FAILURE;
    }
    if(init_credit(app) !=EXIT_SUCCESS){
        return EXIT_FAILURE;
    }
    if(init_coche_case(app)!=EXIT_SUCCESS){
        return EXIT_FAILURE;
    }
    init_rbutton(app);
    return EXIT_SUCCESS;
}

void init_font(View_elements * app){
    app->ttf=TTF_OpenFont("Ressources/SmoochSans-Medium.ttf",50);
}


