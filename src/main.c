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
    sdlDrawRect();
    grid gameGrid = initLevel("../level1.txt");


	bool run = true;
	while(run){
        if(areGoalsCoveredByBox(gameGrid)){
            run = false ;
        }

        system("clear");
        display(gameGrid);
		char entry = fgetc(stdin);
		switch(entry){
			case 'q' :{
				run = false;
				break;
			}
            case 'k' :{
                movePlayer(gameGrid, Top);
                getchar();
                break;
            }
            case 'l' : {
                movePlayer(gameGrid, Right);
                break;
            }
            case 'j' : {
                movePlayer(gameGrid, Bottom);
                break;
            }
            case 'h' : {
                movePlayer(gameGrid, Left);
                break;
            }
		}

	}

    // Libération de la mémoire.
    free2DCaseType(gameGrid);
    free(gameGrid);

    sdl_quit();
    return 0;
}

