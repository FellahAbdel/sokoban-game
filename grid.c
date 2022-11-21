#include <stdio.h>
#include <stdlib.h>
#include "grid.h"

/** 
* @file grid.c
* @brief Code pour la grille. 
* @author DIALLO Abdoul Aziz.
*/


/**
* @relatesalso Grid
* @brief Alloue un tableau à 2D pour les entités du jeux.
* @param numberOfRow Nombre de ligne de la grille
* @param numberOfColumn Nombre de colonne de la grillej 
*/
CaseType** malloc2DCaseType(int numberOfRow, int numberOfColumn){
    CaseType** tabCaseType;

    tabCaseType = (CaseType**)malloc(numberOfRow * (sizeof(CaseType*)));
    for(int i = 0; i < numberOfRow ; i++)
        tabCaseType[i] = (CaseType*)malloc(numberOfColumn * sizeof(CaseType));

    return tabCaseType;
}

/**
* @relatesalso Grid
* @brief Initiatialisation du niveau de jeux.
* @param file_path le chemin du fichier.
*/
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

    gridInit->game_grid = malloc2DCaseType(number_row, number_column);

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
            if(*buffer == PLAYER){
                gridInit->aPlayer.x = current_row;
                gridInit->aPlayer.y = current_column;
            }

            if(*buffer == GOAL){
                current_goal++;
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

/**
 * @relatesalso Grid
 * @brief Affichage de la grille
 * @param theGrid Un pointeur vers la grille.
*/
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

/**
 * @relatesalso Grid
 * @brief Libération de la mémoire
 * @param theGrid Un pointeur vers la grille.
*/
void free2DCaseType(grid theGrid){

    for( int i = 0 ; i < theGrid->row_number ; i++){
        free(theGrid->game_grid[i]);
    }

    free(theGrid->game_grid);
    return;
}