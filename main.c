//
// Created by robin on 07/02/2022.
//

#include "controller/main_controller.h"

int main (int argc, char *argv[]){
    View_elements app;
    init_view(&app);
    SDL_Delay(3000);
    free_view(&app);
}

