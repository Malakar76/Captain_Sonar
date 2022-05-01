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
    //initialiser les boutons
    int i, j;
    SDL_Rect rect={0,0,52,52};

    for (i = 0; i < 10; i++) {
        rect.y=55+i*66;
        for (j = 0;  j< 10; j++) {
            rect.x=60+j*66;
            app->VBattlefield->Carte[i][j]= rect;

        }
    }

    SDL_Rect button={735,153,53,53};
    app->VBattlefield->Bbutton[0]=button; //fleche haut
    button.x=802;
    app->VBattlefield->Bbutton[1]=button; //fleche bas
    button.x=869;
    app->VBattlefield->Bbutton[2]=button; //fleche gauche
    button.x=932;
    button.y=156;
    app->VBattlefield->Bbutton[3]=button; //fleche droite

    button.x=745; button.y=221; button.w=217; button.h=43;
    app->VBattlefield->Bbutton[4]=button; //surface
    button.y=282;
    app->VBattlefield->Bbutton[5]=button; //sonar
    button.y=345;
    app->VBattlefield->Bbutton[6]=button; //silence
    button.y=406;
    app->VBattlefield->Bbutton[7]=button; //missile
    SDL_Rect button2={990,10,245,90};
    app->VBattlefield->Bbutton[8]=button2; //clean map
    SDL_Rect button3={1287,0,125,115};
    app->VBattlefield->Bbutton[9]=button3; //son
    SDL_Rect button4={1480,0,120,115};
    app->VBattlefield->Bbutton[10]=button4; //retour menu
    SDL_Rect button5={57,53,660,658};
    app->VBattlefield->Bbutton[11]=button5; //sur la carte
    SDL_Rect button6={0,0,100,100};
    app->VBattlefield->Bbutton[12]=button6; //bouton fin partie

    return EXIT_SUCCESS;
}

int init_battlefield(View_elements * app,enum Carte c){
    SDL_Texture * tmp=NULL;
    SDL_Surface * surface=NULL;
    if (c==Antartica){
        surface=IMG_Load("Ressources/Mission_Antartica.jpg");
    }
    else if (c==Archipelago){
        surface=IMG_Load("Ressources/Mission_Archipelago.jpg");
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
    SDL_SetRenderTarget(app->rRenderer, NULL);
    SDL_DestroyTexture(tmp);
    SDL_FreeSurface(surface);


    surface=IMG_Load("Ressources/niveau_energie.png");
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
    SDL_SetRenderTarget(app->rRenderer, app->VBattlefield->Energie);
    SDL_Rect rect1={0,0,1000,900};
    SDL_RenderCopy(app->rRenderer, tmp, NULL, &rect1);
    SDL_SetRenderTarget(app->rRenderer, NULL);


    SDL_DestroyTexture(tmp);
    SDL_FreeSurface(surface);

    return EXIT_SUCCESS;

}

int init_sousmarin(View_elements * app){
    SDL_Texture * tmp=NULL;
    SDL_Surface * surface=NULL;
    surface=IMG_Load("Ressources/sous_marin.png"); //mettre sous marin
    if (surface==NULL){
        fprintf(stderr, "Erreur SDL_CreateSurface : %s", SDL_GetError());
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(tmp);
        return EXIT_FAILURE;
    }
    Uint32 colorkey = SDL_MapRGB(surface->format,255,255,255);
    SDL_SetColorKey(surface,SDL_TRUE,colorkey);
    tmp=SDL_CreateTextureFromSurface(app->rRenderer,surface);
    if (tmp==NULL){
        fprintf(stderr, "Erreur SDL_CreateTexture: %s", SDL_GetError());
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(tmp);
        return EXIT_FAILURE;
    }
    SDL_SetRenderTarget(app->rRenderer, app->VBattlefield->Sous_marin);
    SDL_RenderCopy(app->rRenderer, tmp, NULL, NULL);
    SDL_DestroyTexture(tmp);
    SDL_FreeSurface(surface);
    SDL_SetTextureBlendMode(app->VBattlefield->Sous_marin,SDL_BLENDMODE_BLEND);
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
    SDL_Rect rect5={1295,20,78,78};
    app->CCarte[0]=rect1;
    app->CCarte[1]=rect2;
    app->CCarte[4]=rect5;
    return EXIT_SUCCESS;

}

void show_choix_carte(View_elements *app){
    SDL_RenderCopy(app->rRenderer,app->cCarte,NULL,NULL);
    SDL_RenderPresent(app->rRenderer);
    app->window=Choix_Carte;
}

void print_message(View_elements *app,char * message){
    SDL_SetRenderDrawColor(app->rRenderer,57,143,70,255);
    SDL_Rect rect ={25,760,695,100}; // zone où afficher le message
    SDL_SetRenderTarget(app->rRenderer,app->VBattlefield->Battlefield_current);
    SDL_RenderFillRect(app->rRenderer,&rect);
    SDL_Texture * tmp=NULL;
    SDL_Surface * surface=NULL;
    SDL_Color color={0,0,0,255};
    surface=TTF_RenderText_Solid(app->ttf,message,color);
    tmp=SDL_CreateTextureFromSurface(app->rRenderer,surface);
    SDL_Rect rect2={25,760,surface->w,surface->h};
    SDL_RenderCopy(app->rRenderer, tmp, NULL, &rect2);
    SDL_DestroyTexture(tmp);
    SDL_FreeSurface(surface);
    SDL_SetRenderTarget(app->rRenderer,NULL);
    SDL_RenderCopy(app->rRenderer,app->VBattlefield->Battlefield_current,NULL,NULL);
    SDL_RenderPresent(app->rRenderer);
}

void print_message_adversaire(View_elements *app,char * message){
    SDL_SetRenderDrawColor(app->rRenderer,57,143,70,255);
    SDL_Rect rect ={770,760,831,100}; // zone où afficher le message
    SDL_SetRenderTarget(app->rRenderer,app->VBattlefield->Battlefield_current);
    SDL_RenderFillRect(app->rRenderer,&rect);
    SDL_Texture * tmp=NULL;
    SDL_Surface * surface=NULL;
    SDL_Color color={0,0,0,255};
    surface=TTF_RenderText_Solid(app->ttf,message,color);
    tmp=SDL_CreateTextureFromSurface(app->rRenderer,surface);
    SDL_Rect rect2={770,760,surface->w,surface->h};
    SDL_RenderCopy(app->rRenderer, tmp, NULL, &rect2);
    SDL_DestroyTexture(tmp);
    SDL_FreeSurface(surface);
    SDL_SetRenderTarget(app->rRenderer,NULL);
    SDL_RenderCopy(app->rRenderer,app->VBattlefield->Battlefield_current,NULL,NULL);
    SDL_RenderPresent(app->rRenderer);
}

void  case_choisie(View_elements * app, SDL_Point point,int tab[]){
    for (int i=0;i<10;i++){
        for (int j=0;j<10;j++){
            if (SDL_PointInRect(&point,&app->VBattlefield->Carte[i][j])){
                tab[0]=i;
                tab[1]=j;
            }
        }
    }
}

void show_SM(View_elements * app,int ligne,int colonne){
    SDL_RenderClear(app->rRenderer);
    SDL_RenderCopy(app->rRenderer,app->VBattlefield->Battlefield_current,NULL,NULL);
    SDL_Rect rect=app->VBattlefield->Carte[ligne][colonne];
    SDL_RenderCopy(app->rRenderer,app->VBattlefield->Sous_marin,NULL,&rect);
    SDL_RenderPresent(app->rRenderer);
}

void coche_case(View_elements * app){
    if (app->IA==0){
        app->IA=1;
        SDL_RenderCopy(app->rRenderer,app->valide,NULL,NULL);
    }else{
        app->IA=0;
        SDL_RenderClear(app->rRenderer);
        SDL_RenderCopy(app->rRenderer,app->cCarte,NULL,NULL);
    }
    SDL_RenderPresent(app->rRenderer);
}

int init_coche_case(View_elements * app){
    app->IA=0;
    SDL_Texture * tmp=NULL;
    SDL_Surface * surface=NULL;
    surface=IMG_Load("Ressources/Valide.png");
    if (surface==NULL){
        fprintf(stderr, "Erreur SDL_CreateSurface : %s", SDL_GetError());
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(tmp);
        return EXIT_FAILURE;
    }
    Uint32 colorkey = SDL_MapRGB(surface->format,255,255,255);
    SDL_SetColorKey(surface,SDL_TRUE,colorkey);
    tmp=SDL_CreateTextureFromSurface(app->rRenderer,surface);
    if (tmp==NULL){
        fprintf(stderr, "Erreur SDL_CreateTexture: %s", SDL_GetError());
        SDL_FreeSurface(surface);
        SDL_DestroyTexture(tmp);
        return EXIT_FAILURE;
    }
    SDL_SetRenderTarget(app->rRenderer, app->valide);
    SDL_RenderCopy(app->rRenderer, tmp, NULL, &app->CCarte[4]);
    SDL_DestroyTexture(tmp);
    SDL_FreeSurface(surface);
    SDL_SetTextureBlendMode(app->valide,SDL_BLENDMODE_BLEND);
    SDL_SetRenderTarget(app->rRenderer, NULL);
    return EXIT_SUCCESS;
}


void trace_deplacement(View_elements * app, int direction, int pos_joueur_ligne, int pos_joueur_colonne){

    int i, j; // on cree des mini rect sur la carte pour placer haut du rect pour le trait
    SDL_Rect recti={0,0,4,4};
    SDL_Rect tab [10][10];
    for (i = 0; i < 10; i++) {
        recti.y=78+i*66;
        for (j = 0;  j< 10; j++) {
            recti.x= 84+j*66;
            tab[i][j]= recti; //i ligne j colonne
        }
    }


    SDL_Rect rect;    //on vient recuperer position joueur
    rect.x=(tab[pos_joueur_ligne][pos_joueur_colonne]).x;
    rect.y=(tab[pos_joueur_ligne][pos_joueur_colonne]).y;


    SDL_SetRenderTarget(app->rRenderer, app->VBattlefield->Battlefield_current);
    SDL_SetRenderDrawColor(app->rRenderer, 255, 0, 0, SDL_ALPHA_OPAQUE); //modifie couleur trait


    switch (direction) {

        case 0: //haut
            rect.w=4;
            rect.h=66;
            SDL_RenderFillRect(app->rRenderer, &rect);
            break;

        case 1: //bas
            rect.y=rect.y-66;
            rect.w=4;
            rect.h=66;
            SDL_RenderFillRect(app->rRenderer, &rect);
            break;



        case 2: //gauche
            rect.w=66;
            rect.h=4;
            SDL_RenderFillRect(app->rRenderer, &rect);
            break;

        case 3: //droite
            rect.x=rect.x-66;
            rect.w=66;
            rect.h=4;
            SDL_RenderFillRect(app->rRenderer, &rect);
            break;

        default:
            break;

    }
    SDL_SetRenderTarget(app->rRenderer,NULL);
    SDL_RenderCopy(app->rRenderer,app->VBattlefield->Battlefield_current,NULL,NULL);
    SDL_RenderPresent(app->rRenderer);
}

void clean_map(View_elements * app){
    SDL_SetRenderTarget(app->rRenderer,app->VBattlefield->Battlefield_current);
    SDL_RenderCopy(app->rRenderer,app->VBattlefield->Battlefield_blank,NULL,NULL);
    SDL_SetRenderTarget(app->rRenderer,NULL);
    SDL_RenderCopy(app->rRenderer,app->VBattlefield->Battlefield_current,NULL,NULL);
    SDL_RenderPresent(app->rRenderer);

}

void trace_deplacement_total(View_elements * app, int direction[],int nbdir,int pos_depart[]){
    int ligne=pos_depart[0];
    int colonne=pos_depart[1];
    for (int i=0;i<nbdir;i++){
        trace_deplacement(app,direction[i],ligne,colonne);
        switch (direction[i]){
            case 0: //haut
                ligne--;
                break;
            case 1: //bas
                ligne++;
                break;
            case 2: //gauche
                colonne--;
                break;
            case 3: //droite
                colonne++;
                break;
        }
    }
}

void trace_deplacement_calque(View_elements * app, int direction, int pos_joueur_ligne, int pos_joueur_colonne){
    int i, j;
    SDL_Rect recti={0,0,4,4}; //à vérifier
    SDL_Rect tab [19][19];
    for (i = 0; i < 19; i++) {
        recti.y=124+i*32; //à vérifier
        for (j = 0;  j< 19; j++) {
            recti.x= 992+j*32; //à vérifier
            tab[i][j]= recti; //i ligne j colonne
        }
    }


    SDL_Rect rect;    //on vient recuperer position joueur
    rect.x=(tab[pos_joueur_ligne][pos_joueur_colonne]).x;
    rect.y=(tab[pos_joueur_ligne][pos_joueur_colonne]).y;


    SDL_SetRenderTarget(app->rRenderer, app->VBattlefield->Battlefield_current);
    SDL_SetRenderDrawColor(app->rRenderer, 255, 0, 0, SDL_ALPHA_OPAQUE); //modifie couleur trait


    switch (direction) {

        case 0: //haut
            rect.w=4;
            rect.h=32;
            SDL_RenderFillRect(app->rRenderer, &rect);
            break;

        case 1: //bas
            rect.y=rect.y-32;
            rect.w=4;
            rect.h=32;
            SDL_RenderFillRect(app->rRenderer, &rect);
            break;



        case 2: //gauche
            rect.w=32;
            rect.h=4;
            SDL_RenderFillRect(app->rRenderer, &rect);
            break;

        case 3: //droite
            rect.x=rect.x-32;
            rect.w=32;
            rect.h=4;
            SDL_RenderFillRect(app->rRenderer, &rect);
            break;

        default:
            break;

    }
    SDL_SetRenderTarget(app->rRenderer,NULL);
    SDL_RenderCopy(app->rRenderer,app->VBattlefield->Battlefield_current,NULL,NULL);
    SDL_RenderPresent(app->rRenderer);
}
void trace_deplacement_total_calque(View_elements * app, int direction[],int nbdir){
    int ligne=9;
    int colonne=9;
    fprintf(stderr,"%d\n",nbdir);
    for (int i=0;i<nbdir;i++){
        trace_deplacement_calque(app,direction[i],ligne,colonne);
        switch (direction[i]){
            case 0: //haut
                ligne--;
                break;
            case 1: //bas
                ligne++;
                break;
            case 2: //gauche
                colonne--;
                break;
            case 3: //droite
                colonne++;
                break;
        }
    }
}

void clean_calque(View_elements * app){
    SDL_Rect src={987,115,611,617};
    SDL_SetRenderTarget(app->rRenderer,app->VBattlefield->Battlefield_current);
    SDL_RenderCopy(app->rRenderer,app->VBattlefield->Battlefield_blank,&src,&src);
    SDL_SetRenderTarget(app->rRenderer,NULL);
    SDL_RenderCopy(app->rRenderer,app->VBattlefield->Battlefield_current,NULL,NULL);
    SDL_RenderPresent(app->rRenderer);
}

void show_energie(View_elements * app,int energie){
    SDL_Rect rect={720,455,270,190};
    SDL_Rect rect4={0,0,270,190};
    SDL_Rect rect3={270,0,270,190};
    SDL_Rect rect2={540,0,270,190};
    SDL_Rect rect1={0,190,270,190};
    SDL_SetRenderTarget(app->rRenderer,app->VBattlefield->Battlefield_current);
    switch (energie) {
        case 0:
            SDL_RenderCopy(app->rRenderer,app->VBattlefield->Battlefield_blank,&rect,&rect);
            break;
        case 1:
            SDL_RenderCopy(app->rRenderer,app->VBattlefield->Energie,&rect1,&rect);
            break;
        case 2:
            SDL_RenderCopy(app->rRenderer,app->VBattlefield->Energie,&rect2,&rect);
            break;
        case 3:
            SDL_RenderCopy(app->rRenderer,app->VBattlefield->Energie,&rect3,&rect);
            break;
        case 4:
            SDL_RenderCopy(app->rRenderer,app->VBattlefield->Energie,&rect4,&rect);
            break;
    }
    SDL_SetRenderTarget(app->rRenderer,NULL);
    SDL_RenderCopy(app->rRenderer,app->VBattlefield->Battlefield_current,NULL,NULL);
    SDL_RenderPresent(app->rRenderer);
}

void show_vie(View_elements * app, int vieA,int vieNA){
    SDL_Rect P2V={0,508,226,64};
    SDL_Rect P1V={0,380,226,64};
    SDL_Rect P0V={0,444,226,64};
    SDL_Rect Pos1={741,78,226,64};
    SDL_Rect Pos2={741,645,226,64};
    SDL_SetRenderTarget(app->rRenderer,app->VBattlefield->Battlefield_current);
    switch (vieA) {
        case 0:
            SDL_RenderCopy(app->rRenderer,app->VBattlefield->Energie,&P0V,&Pos2);
            break;
        case 1:
            SDL_RenderCopy(app->rRenderer,app->VBattlefield->Energie,&P1V,&Pos2);
            break;

        case 2:
            SDL_RenderCopy(app->rRenderer,app->VBattlefield->Energie,&P2V,&Pos2);
            break;


    }
    switch (vieNA) {
        case 0:
            SDL_RenderCopy(app->rRenderer,app->VBattlefield->Energie,&P0V,&Pos1);
            break;
        case 1:
            SDL_RenderCopy(app->rRenderer,app->VBattlefield->Energie,&P1V,&Pos1);
            break;

        case 2:
            SDL_RenderCopy(app->rRenderer,app->VBattlefield->Energie,&P2V,&Pos1);
            break;

    }
    SDL_SetRenderTarget(app->rRenderer,NULL);
    SDL_RenderCopy(app->rRenderer,app->VBattlefield->Battlefield_current,NULL,NULL);
    SDL_RenderPresent(app->rRenderer);
}



