#include <stdio.h>
#include "grid.h"
#include "player.h"

/**
 * @file player.c
*/


/**
* @relatesalso Player
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
 * @relatesalso Player
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
 * @relatesalso Player
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

enum CaseType getItemAfterBox(struct Grid *theGrid, player coordAfterBox){
    int i = coordAfterBox.x;
    int j = coordAfterBox.y;

    return theGrid->game_grid[i][j];
}

/**
 * @relatesalso Player
 * @brief Est-ce que c'est un mur.
 * @param item Une entité.
 * @return 1 si oui 0 sinon
*/
int isWall(char item){
    return item == WALL;
}

/**
 * @relatesalso Player
 * @brief Est-ce que c'est un carton.
 * @param item Une entité.
 * @return 1 si oui 0 sinon
*/
int isBox(char item){
    return item == BOX;
}

/**
 * @relatesalso Player
 * @brief Est-ce que c'est un néant.
 * @param item Une entité.
 * @return 1 si oui 0 sinon
*/
int isNone(char item){
    return item == NONE;
}

/**
 * @relatesalso Player
 * @brief Est-ce que c'est une cible.
 * @param item Une entité.
 * @return 1 si oui 0 sinon
*/
int isGoal(char item){
    return item == GOAL;
}

/**
 * @relatesalso Player
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
 * @relatesalso Player
* @brief Déplacement d'un joueur dans la grille.
* @param direction Direction vers laquelle le joueur se deplace.
*/
void movePlayer(struct Grid *theGrid, Direction direction){
    CaseType item = getItemAt(theGrid, direction);
    player thePlayer = theGrid->aPlayer;
    player *arrayOfGoals = theGrid->arrayGoal.array;
    int length = theGrid->arrayGoal.length;
    player thePlayerNewPosition;

    if(item != '0'){
        // Nous sommes toujours dans la grille de jeux.
        if(!isWall(item)){
            // Ce n'est pas un mûr.
            // Donc c'est soit le néant, une cible ou un carton.
            if(isNone(item) || isGoal(item)){
                // Si c'est le néant. 
                // On deplace le joueur tranquillement.

                // A la position (i, j) on met None ou Goal selon que (i,j)
                // est la coordonnée du goal ou pas.

                // si thePlayer est dans le tableau des coordonnées alors
                // on met GOAL à la position (i, j).
                if(playerIsIn(thePlayer, arrayOfGoals, length)){
                    setItemAt(theGrid, thePlayer, GOAL);
                }else{
                    // sinon on met NONE.
                    setItemAt(theGrid, thePlayer, NONE);
                }

                // A la position (i + dx, j + dx) on met le joueur.
                thePlayerNewPosition = getCoordinatesAt(thePlayer, direction);
                setItemAt(theGrid, thePlayerNewPosition, PLAYER);

                // On change la position du joueur, après le deplacement
                theGrid->aPlayer = thePlayerNewPosition;
            } else if(isBox(item)){
                // Si c'est un carton, il faut vérifier qu'il y a un pos-
                // sible deplacement à la direction (d + dx, d + dy) pour
                // le carton. (cad qu'on reste toujours dans la grille et 
                // qu'il y a le néant ou une cible à la direction d du carton)

                // En gros, voici ce qu'il faut faire :
                // On cherche l'item à la direction d après le carton.
                player boxCoord = getCoordinatesAt(thePlayer, direction);
                player coordAfterBox = getCoordinatesAt(boxCoord, direction);
                CaseType itemAfterBox = getItemAfterBox(theGrid, coordAfterBox);
                // si itemAfterBox n'est pas un mur alors on pousse le carton.
                if(!isWall(itemAfterBox)){
                    // Et si itemAfterBox est une cible, qu'est-ce qu'il faut
                    // faire ?
                    setItemAt(theGrid, coordAfterBox, BOX);
                    setItemAt(theGrid, boxCoord, PLAYER);

                    if(playerIsIn(thePlayer, arrayOfGoals, length)){
                        setItemAt(theGrid, thePlayer, GOAL);
                    }else{
                        // sinon on met NONE.
                        setItemAt(theGrid, thePlayer, NONE);
                    }

                    // On change la nouvelle position du joueur
                    theGrid->aPlayer = boxCoord;
                }
                // sinon on fait rien
             }
        }
    }
}

/**
 * @relatesalso Player
* @brief Test si le joeur est déjà sur l'une des positions des cibles.
* @param p Le joueur.
* @param array Le tableau contenant les coordonnées des cibles.
* @param length Le nombre de cible.
* @return Un boolean.
*/
bool playerIsIn(player p, player array[], int length){
    bool found = false;
    player playerInArr;

    for(int i = 0 ; i < length && !found; i++){
        playerInArr = array[i];
        if(playerInArr.x == p.x && playerInArr.y == p.y){
            found = true;
        }
    }

    return found;
}