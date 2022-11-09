#ifndef PLAYER_HEADER
#define PLAYER_HEADER


/** \file player.h
*    \brief A Documented file.
*    Details.
*/

#include "grid.h"

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
    Top,        /// Haut
    Right,      /// Droite
    Bottom,      /// Bas
    Left      /// Gauche
};

#endif