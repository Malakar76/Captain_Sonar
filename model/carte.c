#include "carte.h"
include <string.h>
#include <stdlib.h>
#include <time.h>

int crea_tableau (int colonne, int ligne){
    int i, int j;
    TABLEAU* t[]={(TABLEAU*)malloc(sizeof(TABLEAU)*colonne),(TABLEAU*)malloc(sizeof(TABLEAU)*colonne)};
    for (i=0;i<colonne;i++){
        for (j=0;j<ligne;j++){
            t[i][j]=rand () % 256;
            printf("%d ", t[i][j]);
        }
        printf("\n");
    }


}