#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "grid.h"
#include "player.h"
#include "sdl2.h"

/**
 * \file main.c
*/


int main(void){
    
    sdl_init();


    grid gameGrid = initLevel("../level1.txt");

    displaySdl2(gameGrid);


	bool run = true;
    while(run){

        if(areGoalsCoveredByBox(gameGrid)){
            run = false ;
        }

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
                printf("None\n");
                break;
        }

        displaySdl2(gameGrid);
    }
    
    // Libération de la mémoire.
    free2DCaseType(gameGrid);
    free(gameGrid);

    sdl_quit();
    return 0;
}

