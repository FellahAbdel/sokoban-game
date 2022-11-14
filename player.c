#include <stdio.h>
#include "grid.h"
#include "player.h"

/**
 * @file player.c
*/


/**
* @brief Teste s'il y a une entité au cordoonées itemX et itemY.
* @param itemX coordonées i.
* @param itemY coordonées j.
* @return 1 : si itemX ∈ [0, nombreLigne[ et itemY ∈ [0, nombreColonne[ sinon 0
*/
int isItemInGrid(struct Grid *theGrid, int itemX, int itemY){
    int numberRow = theGrid->row_number;
    int numberCol = theGrid->column_number;

    if( (itemX >= 0 && itemX < numberRow) && ( itemY >= 0 && itemY < numberCol)){
        return 1;
    }
    return 0;
}

/**
 * @brief Coordonées du joeur à la direction d.
 * @param thePlayer Le joueur.
 * @return Les nouvelles coordonées du joeur à la direction d.
*/
player getCoordinatesAt(player thePlayer, Direction direction){
    if( direction == Top){
        thePlayer.x--;
    }else if (direction == Right){
        thePlayer.y++;
    }else if( direction == Bottom){
        thePlayer.x++;
    }else {
        thePlayer.y--;
    }

    return thePlayer;
}

/**
* @brief Permet de d'avoir l'entité à la direction d.
* @param direction Direction vers laquelle le joueur se deplace.
* @param theGrid Un pointeur vers la grille de jeux.
* @return '0' : S'il y a pas d'entité sinon l'entité.
*/
char getItemAt(struct Grid *theGrid, Direction direction){
    int i, j;
    player playerCoordinatesAt;
    char item = '0' ;  // Au cas où, on sort de la grille

    playerCoordinatesAt = getCoordinatesAt(theGrid->aPlayer, direction);

    i = playerCoordinatesAt.x ;
    j = playerCoordinatesAt.y ;
    
    if( isItemInGrid(theGrid, i, j)){
        item = theGrid->game_grid[i][j];
    }

    return item;
}

/**
 * @brief Est-ce que c'est un mur.
 * @param item Une entité.
 * @return 1 si oui 0 sinon
*/
int isWall(char item){
    return item == WALL;
}

/**
 * @brief Est-ce que c'est un carton.
 * @param item Une entité.
 * @return 1 si oui 0 sinon
*/
int isBox(char item){
    return item == BOX;
}

/**
 * @brief Est-ce que c'est un néant.
 * @param item Une entité.
 * @return 1 si oui 0 sinon
*/
int isNone(char item){
    return item == NONE;
}

/**
 * @brief Est-ce que c'est une cible.
 * @param item Une entité.
 * @return 1 si oui 0 sinon
*/
int isGoal(char item){
    return item == GOAL;
}

/**
 * @brief On y met au cordonnées en entré notre entité. 
 * @param theGrid Un pointeur vers la grille de jeux.
 * @param coordinates Coordonnées de la case où l'on met l'entité.
 * @param item Entité à mettre. 
 * @return Rien (On modifie la grille).
*/
void setItemAt(struct Grid *theGrid, player coordinates, enum CaseType item){
    int i = coordinates.x;
    int j = coordinates.y;

    theGrid->game_grid[i][j] = item;
    return;
}

/**
* @brief Déplacement d'un joueur dans la grille.
* @param direction Direction vers laquelle le joueur se deplace.
*/
void movePlayer(struct Grid *theGrid, Direction direction){
    CaseType item = getItemAt(theGrid, direction);
    player thePlayer = theGrid->aPlayer;
    player thePlayerNewPosition;

    if(item != '0'){
        // Nous sommes toujours dans la grille de jeux.
        if(!isWall(item) && !isBox(item)){
            // Ce n'est ni un mûr, ni un carton.
            // Donc c'est soit le néant ou une cible.
            if(isNone(item) || isGoal(item)){
                // Si c'est le néant. 
                // On deplace le joueur tranquillement.

                // A la position (i, j) on met None
                setItemAt(theGrid, thePlayer, NONE);

                // A la position (i + dx, j + dx) on met le joueur.
                thePlayerNewPosition = getCoordinatesAt(thePlayer, direction);
                setItemAt(theGrid, thePlayerNewPosition, PLAYER);

                // On change la position du joueur, après le deplacement
                theGrid->aPlayer = thePlayerNewPosition;
            }
        }
    }
}