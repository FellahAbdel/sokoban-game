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

/**
* @brief Teste s'il y a une entité au cordoonées itemX et itemY.
* @param itemX coordonées i.
* @param itemY coordonées j.
* @return 1 : si itemX ∈ [0, nombreLigne[ et itemY ∈ [0, nombreColonne[ sinon 0
*/
int isItemInGrid(struct Grid *theGrid, int itemX, int itemY);

/**
* @brief Permet de d'avoir l'entité à la direction d.
* @param direction Direction vers laquelle le joueur se deplace.
* @param theGrid Un pointeur vers la grille de jeux.
* @return '0' : S'il y a pas d'entité sinon l'entité.
*/
char getItem(struct Grid *theGrid, enum Direction direction);
#endif