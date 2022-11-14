#ifndef GRID_HEADER
#define GRID_HEADER
#include "player.h"

/** 
* \file grid.h
* \brief Les fonctions de gestion de la grille.
* Dans ce fichier, nous avons toutes les fonctions permettant
* de d'initier un niveau et d'afficher la grille de jeux. 
*/

/**
* @enum CaseType grid.h
* Définit le type d'une case 
*/

typedef enum CaseType{
	WALL = '#',    /// un mur
	BOX = '$',     /// un carton
	PLAYER = '@',  /// un joueur
	GOAL = '.',    /// une cible
	NONE = ' '     /// néant
}CaseType;

/**
 * @struct Grid grid.h
 * @brief Cette structure contient les informations 
 * concernant la grille du jeu et son contenu
 */
typedef struct Grid{
	enum CaseType** game_grid; ///< Tableau contenant les entités présents dans le jeu
	int column_number; ///< Nombre de colonne de game_grid
	int row_number; ///< Nombre de ligne de game_grid
    player aPlayer;
}strGrid, *grid;


grid initLevel(const char* filePath);

CaseType** malloc2DCaseType(int numberOfRow, int numberOfColumn);

void display(grid theGrid);

#endif
