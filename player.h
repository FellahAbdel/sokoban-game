#ifndef PLAYER_HEADER
#define PLAYER_HEADER

struct Grid;

/** 
* @file player.h
* @brief A Documented file.
* Details.
*/


/**
 * @struct Player player.h
 * @brief Cette structure contient les informations 
 * concernant liées à la position du joueur
 */
typedef struct Player{
    int x;
    int y;
}player;

/**
* @enum Direction player.h
* Définit le sens de direction d'une case 
*/
enum Direction {
    Top,         /// Haut
    Right,       /// Droite
    Bottom,      /// Bas
    Left         /// Gauche
};

/**
* @brief Déplacement d'un joueur dans la grille.
* @param direction Direction vers laquelle le joueur se deplace.
*/

void movePlayer(struct Grid *theGrid, enum Direction direction);

#endif