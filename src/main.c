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

    SDL_Rect rect = {
        .x = 0,
        .y = 0,
        .w = 50,
        .h = 50
    };

    SDL_Rect rect1 = {
        .x = 50,
        .y = 0,
        .w = 50,
        .h = 50
    };

    SDL_Color rectColor = {
        .r = 255,
        .g = 0,
        .b = 0,
        .a = 255
    };

    // sdlDrawRect(rect , rectColor);
    // sdlDrawRect(rect1 , rectColor);

    grid gameGrid = initLevel("../level1.txt");

    displaySdl2(gameGrid);


	bool run = true;
	while(run){
        if(areGoalsCoveredByBox(gameGrid)){
            run = false ;
        }

        // system("clear");
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

