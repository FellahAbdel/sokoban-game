#include <stdio.h>
#include <stdbool.h>
#include "grid.h"
#include "player.h"

/**
 * \file main.c
*/


int main(void){
    
    grid gameGrid = initLevel("./level1.txt");
    printf("Player (x, y) = (%d, %d)\n", gameGrid->aPlayer.x, gameGrid->aPlayer.y);
    display(gameGrid);
	bool run = true;
	while(run){
		char entry = fgetc(stdin);
		switch(entry){
			case 'q' :{
				run = false;
				break;
			}
		}
	}
}

