#ifndef GRID_HEADER
#define GRID_HEADER
#include "player.h"

/** 
* \file grid.h
* \brief A Documented file.
* Details.
*/

/**
* @enum CaseType grid.h
* Définit le type d'une case 
*/

enum CaseType{
	WALL = '#',    /// un mur
	BOX = '$',     /// un carton
	PLAYER = '@',  /// un joueur
	GOAL = '.',    /// une cible
	NONE = ' '     /// néant
};

typedef enum CaseType CaseType;

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

/**
* @brief Initiatialisation du niveau de jeux.
* @param file_path le chemin du fichier.
*/
grid initLevel(const char* filePath);

/**
* @brief Alloue un tableau à 2D pour les entités du jeux.
* @param numberOfRow Nombre de ligne de la grille
* @param numberOfColumn Nombre de colonne de la grillej 
*/
enum CaseType** malloc2DCaseType(int numberOfRow, int numberOfColumn);

/**
 * @brief Affichage de la grille
 * @param theGrid Un pointeur vers la grille.
*/
void display(grid theGrid);

/**
* @brief Déplacement d'un joueur dans la grille.
* @param direction Direction vers laquelle le joueur se deplace.
*/
#endif
