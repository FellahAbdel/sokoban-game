#ifndef PLAYER_HEADER
#define PLAYER_HEADER

/** 
* @file player.h
* @brief Le joueur.
* Dans ce fichier, a été définis la structure player et une énumeration des 
* des directions vers lesquelles le joeur se déplace. Le nom de la
* la fonction principale est movePlyer. 
*/

// Pour eviter le problème de dependance circulaire.
struct Grid;
enum CaseType;


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
* Définit le sens de direction d'une case.
*/
typedef enum Direction {
    Top,         /// Haut
    Right,       /// Droite
    Bottom,      /// Bas
    Left         /// Gauche
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

#endif