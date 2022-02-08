//
// Created by robin on 07/02/2022.
//

#include "controller/main_controller.h"

int main (int argc, char *argv[]){
    View_elements app;
    if(init_view(&app) !=EXIT_SUCCESS){
        free_view(&app);
        return EXIT_FAILURE;
    }
    controller(&app);
    free_view(&app);
    return EXIT_SUCCESS;
}

