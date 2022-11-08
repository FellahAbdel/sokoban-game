#ifndef GRID_HEADER
#define GRID_HEADER

/*! \file grid.h
    \brief A Documented file.
    
    Details.
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

/**
 * @struct Grid grid.h
 * @brief Cette structure contient les informations 
 * concernant la grille du jeu et son contenu
 */

struct Grid{
	enum CaseType** game_grid; ///< Tableau contenant les entités présents dans le jeu
	int column_number; ///< Nombre de colonne de game_grid
	int row_number; ///< Nombre de ligne de game_grid
};

/**
* @brief Initiatialisation du niveau de jeux.
* @param file_path le chemin du fichier.
*/
void init_level(const char* file_path);

#endif
