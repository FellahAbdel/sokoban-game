/*! \file grid.c
    \brief A Documented file.
    
    Details.
*/

#include <stdio.h>
#include <stdlib.h>
#include "grid.h"

grid initLevel(const char* filePath){
    // Création de la grille
    grid gridInit = ((strGrid*)malloc(sizeof(strGrid)));
    if(!gridInit){
		fprintf(stderr, "Error: Allocation échouée! ");
		exit(-1);
    }

	// ouverture du fichier en mode lecture
	FILE* file = fopen(filePath, "r");
	if(!file){
		fprintf(stderr, "Error %s not found", filePath);
        printf("erreur\n");
		exit(-1);
	}
	char line[100] = {0};
	int number_column = 0; // nombre de colonne
	int number_row = 0; /// nombre de ligne
	int number_goals = 0;


	// on lit la première ligne du fichier
	fgets(line, 100, file);
	sscanf(line, "%d %d %d", &number_column, &number_row, &number_goals);
    
    // On initialise le nombre de ligne et de colonne dans 
    // notre grille de jeux
    gridInit->column_number = number_column;
    gridInit->row_number = number_row;

    
    gridInit->game_grid = (enum CaseType**)malloc(number_row * (sizeof(enum CaseType*)));
    for(int i = 0; i < number_row ; i++)
        gridInit->game_grid[i] = (enum CaseType*)malloc(number_column * sizeof(enum CaseType));

	int current_row = 0;
	int current_goal = 0;

	// On lit le fichier ligne par ligne jusqu'à la fin du fichier
	while(fgets(line, 100, file) != NULL){
		char* buffer = line;
		int current_column = 0;
		while(*buffer && *buffer != '\n'){
            /// On remplit en même temps, la grille du jeux
            gridInit->game_grid[current_row][current_column] = *buffer;

            // On recupère les coordonnées du joueur
            if(*buffer == '@'){
                gridInit->aPlayer.x = current_row;
                gridInit->aPlayer.y = current_column;
            }

			current_column += 1;
			buffer += 1;
		}		
		current_row += 1;
	}
	// fermeture du fichier
	fclose(file);
    return gridInit;
}

void display(grid theGrid){
    int numberRow = theGrid->row_number;
    int numberColumn = theGrid->column_number;

    for(int i = 0 ; i  < numberRow; i++){
        for(int j = 0 ; j < numberColumn; j++){
            printf("%c", theGrid->game_grid[i][j]);
        }
        printf("\n");
    }
}