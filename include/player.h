#ifndef PLAYER_HEADER
#define PLAYER_HEADER
#include <stdbool.h>

#define MAX_GOAL 5   /// Nombre maximum de cibles.

/** 
* @file player.h
* @brief Header pour les joueurs.
* Dans ce fichier, a été définis la structure player et une énumeration des 
* des directions vers lesquelles le joueur se déplace. Le nom de la
* la fonction principale est movePlayer. 
*/

// Pour eviter le problème de dependance circulaire.
struct Grid;
enum CaseType;


/**
 * @struct Player
 * @brief Cette structure contient les informations.
 * liées à la position du joueur.
 */
typedef struct Player{
    int x;       /// Position x du joueur
    int y;       /// Position y du joueur
}player;

/**
 * @struct GoalCoordinates
 * @brief Cette structure contient les coordonnées de toutes les cibles
 * dans la grille.
 */
typedef struct GoalCoordinates{
    player array[MAX_GOAL];
    int length;
}goalCoordinates ;

/**
* @enum Direction player.h
* Définit le sens de direction d'une case.
*/
typedef enum Direction {
    Top,         ///< Haut
    Right,       ///< Droite
    Bottom,      ///< Bas
    Left         ///< Gauche
}Direction;

int isItemInGrid(struct Grid *theGrid, int itemX, int itemY);


char getItemAt(struct Grid *theGrid, Direction direction);


int isWall(char item);


int isBox(char item);


int isNone(char item);


int isGoal(char item);


player getCoordinatesAt(player thePlayer, Direction direction);


void setItemAt(struct Grid *theGrid, player coordinates, enum CaseType item);


void movePlayer(struct Grid *theGrid, Direction direction);

bool playerIsIn(player p, player array[], int length);

enum CaseType getItemAfterBox(struct Grid *theGrid, player coordAfterBox);

#endif