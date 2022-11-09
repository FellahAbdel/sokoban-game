#include <stdio.h>
#include "grid.h"
#include "player.h"


int isItemInGrid(struct Grid *theGrid, int itemX, int itemY){
    int numberRow = theGrid->row_number;
    int numberCol = theGrid->column_number;

    if( (itemX >= 0 && itemX < numberRow) && ( itemY >= 0 && itemY < numberCol)){
        return 1;
    }
    return 0;
}

char getItem(struct Grid *theGrid, enum Direction direction){
    int i, j;
    char item = '0' ;
    i = theGrid->aPlayer.x;
    j = theGrid->aPlayer.y;
    

    if( direction == Top){
        i--;
    }else if (direction == Right){
        j++;
    }else if( direction == Bottom){
        i++;
    }else {
        j--;
    }

    // Il y aura un bug si i < 0 ou i > numbLigne
    // ou j < 0 ou j > nombreCol
    if( isItemInGrid(theGrid, i, j)){
        item = theGrid->game_grid[i][j];
    }
    
    return item;
}
void movePlayer(struct Grid *theGrid, enum Direction direction){

}