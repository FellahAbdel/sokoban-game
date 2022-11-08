/**
 * \file main.c
*/

#include <stdio.h>
#include "grid.h"
#include <stdbool.h>

int main(void){
    
    grid gameGrid = initLevel("./level1.txt");
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

