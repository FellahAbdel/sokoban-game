/**
 * \file main.c
*/

#include <stdio.h>
#include "grid.h"
#include <stdbool.h>
int main(void){
    
    init_level("./level1.txt");
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

