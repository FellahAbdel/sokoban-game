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
    display(gameGrid);

    // movePlayer(gameGrid, Bottom);
    
    // display(gameGrid);

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
                // display(gameGrid);
                break;
            }
            case 'l' : {
                movePlayer(gameGrid, Right);
                // display(gameGrid);
                break;
            }
            case 'j' : {
                movePlayer(gameGrid, Bottom);
                // display(gameGrid);
                break;
            }
            case 'h' : {
                movePlayer(gameGrid, Left);
                // display(gameGrid);
                break;
            }
		}
	}
}

