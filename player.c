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

int isBox(char item){
    return item == BOX;
}

int isNone(char item){
    return item == NONE;
}

int isGoal(char item){
    return item == GOAL;
}


void movePlayer(struct Grid *theGrid, Direction direction){
    char item = getItemAt(theGrid, direction);
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
                int i = thePlayer.x;
                int j = thePlayer.y;
                theGrid->game_grid[i][j] = NONE ;

                // A la position (i + dx, j + dx) on met le joueur.
                thePlayerNewPosition = getCoordinatesAt(thePlayer, direction);

                i = thePlayerNewPosition.x;
                j = thePlayerNewPosition.y;

                theGrid->game_grid[i][j] = PLAYER;

                // On change la position du joeur, après le deplacement
                theGrid->aPlayer = thePlayerNewPosition;
            }
        }
    }
}