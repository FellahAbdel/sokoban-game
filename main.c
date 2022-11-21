#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "grid.h"
#include "player.h"

/**
 * \file main.c
*/


int main(void){
    
    grid gameGrid = initLevel("./level1.txt");

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
    free2DCaseType(gameGrid);
    free(gameGrid);

    return 0;
}

