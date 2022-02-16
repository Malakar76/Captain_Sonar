//
// Created by robin on 07/02/2022.
//

#include "controller/main_controller.h"

int main (int argc, char *argv[]){
    View_elements app;
    Playground pg;
    if((init_view(&app)&& init_model(&pg)) !=EXIT_SUCCESS){
        free_view(&app);
        free_model(&pg);
        return EXIT_FAILURE;
    }
    controller(&app,&pg);
    free_view(&app);
    free_model(&pg);
    return EXIT_SUCCESS;
}

