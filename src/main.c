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
        switch(event()){
            case Quit :
                run = false ;
                break;
            case Up:
                printf("Up\n");
                break ;
            case Down:
                printf("Down\n");
                break ;
            case LeftArr:
                printf("Left arr\n");
                break ;
            case RightArr:
                printf("Right arr\n");
                break ;
            case None:
                printf("None\n");
                break;
        }
    }
    
    goto there;
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
    there:
    // Libération de la mémoire.
    free2DCaseType(gameGrid);
    free(gameGrid);

    sdl_quit();
    return 0;
}

