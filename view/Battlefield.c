//
// Created by robin on 17/02/2022.
//

/**
 * \file Battlefield.c
 * \brief Fichier Choix de carte et Champ de bataille.
 *
 * Fichier qui gère l'affichage et la création du champ de bataille et du choix de carte
 */

#include "main_view.h"

int trace_deplacement(View_Battlefield *vb, View_elements *ve){

    int i, j; // on cree des mini rect sur la carte pour placer haut du rect pour le trait
    SDL_Rect recti={0,0,4,4};
    SDL_Rect tab [10][10];
    for (i = 0; i < 10; i++) {
        recti.y=78+i*66;
        for (j = 0;  j< 10; j++) {
            tab[i][j]= recti; //i ligne j colonne
            recti.x= 84+j*66;
        }
    }



    SDL_Rect rect;
    //on vient recuperer position joueur lettre et num a et b
    rect.x = tab[a][b].x;
    rect.y = tab[a][b].y;


    for (int i = 0; i < dernier_elt ; ++i) { //parcour tableau ou liste des historiques de deplacement et on vient chzrcher le dernier element
        //on recupere res qui dit dir (enum)
    }

    if (SDL_SetRenderTarget(ve->rRenderer, vb->Battlefield_current) != 0){
        SDL_Log("Erreur ciblage %s", SDL_GetError());
        SDL_Quit();
        return EXIT_FAILURE;
    }

    SDL_SetRenderDrawColor(ve->rRenderer, 255, 0, 0, SDL_ALPHA_OPAQUE); //modifie couleur trait

    switch (res) {

        case HAUT:
            rect.y=rect.y+66;
            rect.w=4;
            rect.h=66;
            if  (SDL_RenderFillRect(ve->rRenderer, &rect) != 0){
                SDL_Log("Erreur tracage deplacement %s", SDL_GetError());
                SDL_Quit();
                return EXIT_FAILURE;
            }
            break;

        case BAS:
            rect.w=4;
            rect.h=66;
            if  (SDL_RenderFillRect(ve->rRenderer, &rect) != 0){
                SDL_Log("Erreur tracage deplacement %s", SDL_GetError());
                SDL_Quit();
                return EXIT_FAILURE;
            }
            break;

        case DROITE:
            rect.w=66;
            rect.h=4;
            if  (SDL_RenderFillRect(ve->rRenderer, &rect) != 0){
                SDL_Log("Erreur tracage deplacement %s", SDL_GetError());
                SDL_Quit();
                return EXIT_FAILURE;
            }
            break;

        case GAUCHE:
            rect.x=rect.x+66;
            rect.w=66;
            rect.h=4;
            if  (SDL_RenderFillRect(ve->rRenderer, &rect) != 0){
                SDL_Log("Erreur tracage deplacement %s", SDL_GetError());
                SDL_Quit();
                return EXIT_FAILURE;
            }
            break;

        default:
            break;

    }
    return EXIT_SUCCESS;
}

int init_battlefield2(View_Battlefield *vb){
    int i, j;
    SDL_Rect rect;

    for (i = 0; i < 10; i++) {

        rect.x = 60;
        rect.y=55+i*66;
        rect.w = 52;
        rect.h = 52;

        for (j = 0;  j< 10; j++) {
            vb->Carte[i][j]= rect;
            rect.x= rect.x+66;
        }
    }

    SDL_Rect button={735,153,53,53};
    vb->Bbutton[0]=button; //fleche haut
    button.x=802;
    vb->Bbutton[1]=button; //fleche bas
    button.x=869;
    vb->Bbutton[2]=button; //fleche gauche
    button.x=932;
    button.y=156;
    vb->Bbutton[3]=button; //fleche droite

    button.x=745; button.y=221; button.w=217; button.h=43;
    vb->Bbutton[4]=button; //surface
    button.y=282;
    vb->Bbutton[5]=button; //sonar
    button.y=345;
    vb->Bbutton[6]=button; //silene
    button.y=406;
    vb->Bbutton[7]=button; //missile

    return EXIT_SUCCESS;
}

int init_view_battlefield(View_elements * app,enum Carte c){
    if(init_battlefield(app,c)!=EXIT_SUCCESS){
        return EXIT_FAILURE;
    }
    if(init_sousmarin(app)!=EXIT_SUCCESS){
        return EXIT_FAILURE;
    }
    SDL_SetRenderTarget(app->rRenderer, app->VBattlefield->Battlefield_current);
    SDL_RenderCopy(app->rRenderer, app->VBattlefield->Battlefield_blank, NULL, NULL);
    SDL_SetRenderTarget(app->rRenderer, NULL);
    //initialiser les boutons !
    return EXIT_SUCCESS;


}


int init_battlefield(View_elements * app,enum Carte c){
    SDL_Texture * tmp=NULL;
    SDL_Surface * surface=NULL;
    if (c==Antartica){
        surface=IMG_Load("Ressources/Mission_AntarticaMod.jpg");
    }
    else if (c==Archipelago){
        surface=IMG_Load("Ressources/Mission_Archipelagotest.jpg");
    }
    else {
        return EXIT_FAILURE;
    }
    if (surface==NULL){
        fprintf(stderr, "Erreur SDL_CreateSurface : %s", SDL_GetError());
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(tmp);
        return EXIT_FAILURE;
    }
    tmp=SDL_CreateTextureFromSurface(app->rRenderer,surface);
    if (tmp==NULL){
        fprintf(stderr, "Erreur SDL_CreateTexture: %s", SDL_GetError());
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(tmp);
        return EXIT_FAILURE;
    }
    SDL_SetRenderTarget(app->rRenderer, app->VBattlefield->Battlefield_blank);
    SDL_Rect rect ={0,0,1600,900};
    SDL_RenderCopy(app->rRenderer, tmp, NULL, &rect);
    SDL_DestroyTexture(tmp);
    SDL_FreeSurface(surface);
    SDL_SetRenderTarget(app->rRenderer, NULL);
    return EXIT_SUCCESS;

}

int init_sousmarin(View_elements * app){
    SDL_Texture * tmp=NULL;
    SDL_Surface * surface=NULL;
    surface=IMG_Load("Ressources/Mission_AntarticaMod.jpg"); //mettre sous marin
    if (surface==NULL){
        fprintf(stderr, "Erreur SDL_CreateSurface : %s", SDL_GetError());
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(tmp);
        return EXIT_FAILURE;
    }
    tmp=SDL_CreateTextureFromSurface(app->rRenderer,surface);
    if (tmp==NULL){
        fprintf(stderr, "Erreur SDL_CreateTexture: %s", SDL_GetError());
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(tmp);
        return EXIT_FAILURE;
    }
    SDL_SetRenderTarget(app->rRenderer, app->VBattlefield->Sous_marin);
    SDL_Rect rect ={0,0,1600,900};
    SDL_RenderCopy(app->rRenderer, tmp, NULL, &rect);
    SDL_DestroyTexture(tmp);
    SDL_FreeSurface(surface);
    SDL_SetRenderTarget(app->rRenderer, NULL);
    return EXIT_SUCCESS;
}

void show_battlefield(View_elements *app){
    SDL_RenderCopy(app->rRenderer,app->VBattlefield->Battlefield_current,NULL,NULL);
    SDL_RenderPresent(app->rRenderer);
    app->window=Battlefield;
}

int init_choix_carte(View_elements * app){
    SDL_Texture * tmp=NULL;
    SDL_Surface * surface=NULL;
    surface=IMG_Load("Ressources/Choix_carte.jpg");
    if (surface==NULL){
        fprintf(stderr, "Erreur SDL_CreateSurface : %s", SDL_GetError());
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(tmp);
        return EXIT_FAILURE;
    }
    tmp=SDL_CreateTextureFromSurface(app->rRenderer,surface);
    if (tmp==NULL){
        fprintf(stderr, "Erreur SDL_CreateTexture: %s", SDL_GetError());
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(tmp);
        return EXIT_FAILURE;
    }
    SDL_SetRenderTarget(app->rRenderer, app->cCarte);
    SDL_Rect rect ={0,0,1600,900};
    SDL_RenderCopy(app->rRenderer, tmp, &rect, &rect);
    SDL_DestroyTexture(tmp);
    SDL_FreeSurface(surface);
    SDL_SetRenderTarget(app->rRenderer, NULL);
    SDL_Rect rect1={190,430,300,90};
    SDL_Rect rect2={950,430,300,90};
    app->CCarte[0]=rect1;
    app->CCarte[1]=rect2;
    return EXIT_SUCCESS;

}

void show_choix_carte(View_elements *app){
    SDL_RenderCopy(app->rRenderer,app->cCarte,NULL,NULL);
    SDL_RenderPresent(app->rRenderer);
    app->window=Choix_Carte;
}
