#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "grid.h"
#include "player.h"

/**
 * \file main.c
*/


int main(void){
    
    grid gameGrid = initLevel("../level1.txt");
    // player p;
    // for(int i = 0 ; i < gameGrid->arrayGoal.taille ; i++){
    //     p = gameGrid->arrayGoal.tab[i];
    //     printf("(%d, %d)  ", p.x, p.y);
    // }
    // printf("\n");

	bool run = true;
	while(run){
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

    return 0;
}

