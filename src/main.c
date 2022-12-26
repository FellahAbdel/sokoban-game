#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "grid.h"
#include "player.h"
#include "sdl2.h"

/**
 * \file main.c
*/


int main(int argc, char** argv){
    // Est-ce en mode sdl2 ?
    bool modeSdl2 = argc > 1 && strcmp(argv[1], "--sdl2") == 0 ;

    if(modeSdl2){
        sdl_init();
    }

    // Les pointeurs de fonctions
    Event (*handleEvent)() = modeSdl2 ? eventSdl2 : event ;
    void (*handleDisplay)(grid gameGrid) = modeSdl2 ? displaySdl2 : display ;

    // Initialisation du niveau
    grid gameGrid = initLevel("../level1.txt");

    // Affichage du niveau
    handleDisplay(gameGrid);

	bool run = true;
    while(run){
        run = run && !areGoalsCoveredByBox(gameGrid); 
        switch(handleEvent()){
            case Quit :
                run = false ;
                break;
            case Up:
                // printf("Up\n");
                movePlayer(gameGrid, Top);
                break ;
            case Down:
                // printf("Down\n");
                movePlayer(gameGrid, Bottom);
                break ;
            case LeftArr:
                // printf("Left arr\n");
                movePlayer(gameGrid, Left);
                break ;
            case RightArr:
                // printf("Right arr\n");
                movePlayer(gameGrid, Right);
                break ;
            case None:
                break;
        }

        handleDisplay(gameGrid);
    }
    
    // Libération de la mémoire.
    free2DCaseType(gameGrid);
    free(gameGrid);

    if(modeSdl2)  
        sdl_quit();
    return 0;
}

