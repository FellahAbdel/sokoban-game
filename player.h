#ifndef PLAYER_HEADER
#define PLAYER_HEADER

struct Grid;
enum CaseType;

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
typedef enum Direction {
    Top,         /// Haut
    Right,       /// Droite
    Bottom,      /// Bas
    Left         /// Gauche
}Direction;


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
char getItemAt(struct Grid *theGrid, Direction direction);

/**
 * @brief Est-ce que c'est un mur.
 * @param item Une entité.
 * @return 1 si oui 0 sinon
*/
int isWall(char item);

/**
 * @brief Est-ce que c'est un carton.
 * @param item Une entité.
 * @return 1 si oui 0 sinon
*/
int isBox(char item);

/**
 * @brief Est-ce que c'est un néant.
 * @param item Une entité.
 * @return 1 si oui 0 sinon
*/
int isNone(char item);

/**
 * @brief Est-ce que c'est une cible.
 * @param item Une entité.
 * @return 1 si oui 0 sinon
*/
int isGoal(char item);


/**
 * @brief Coordonées du joeur à la direction d.
 * @param thePlayer Le joeur.
 * @return Les nouvelles coordonées du joeur à la direction d.
*/
player getCoordinatesAt(player thePlayer, Direction direction);

/**
 * @brief 
 * @param theGrid Un pointeur vers la grille de jeux.
 * @param coordinates Coordonnées de la case où l'on met l'entité.
 * @param item Entité à mettre. 
 * @return Rien (On modifie la grille).
*/
void setItemAt(struct Grid *theGrid, player coordinates, enum CaseType item);

/**
* @brief Déplacement d'un joueur dans la grille.
* @param direction Direction vers laquelle le joueur se deplace.
*/
void movePlayer(struct Grid *theGrid, Direction direction);
#endif