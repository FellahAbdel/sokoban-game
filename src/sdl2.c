#include "sdl2.h"

SDLContext context; /// Une variable globale.
SDL_Palette *palette ;

void sdl_init() {
    int const width = 700;
    int const height = 600;

    context = (SDLContext){NULL, NULL, .width = 0, .height = 0};

    if (SDL_Init(SDL_INIT_VIDEO)) {
        return;
    }

    SDL_Window *window =
        SDL_CreateWindow("Sokoban", SDL_WINDOWPOS_CENTERED,
            SDL_WINDOWPOS_CENTERED, 700, 600, SDL_WINDOW_SHOWN);

    if (!window) {
        return;
    }

    SDL_Renderer *renderer =
        SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    context = (SDLContext){
        .window = window, .renderer = renderer, .width = width, .height = height};
}

void sdl_quit() {

    SDL_DestroyWindow(context.window);
    SDL_DestroyRenderer(context.renderer);
    context.window = NULL;
    context.renderer = NULL;
    
    SDL_Quit();
}

void displaySdl2(struct Grid *theGrid){
    colorPalette();
    SDL_SetRenderDrawColor(context.renderer, 126, 126, 126, 255); // couleur grise
    SDL_RenderClear(context.renderer); // On dessine toute la fenêtre en gris
    
    // On calcule la taille en pixel des cases.
    int screenWidth = context.width ;
    int screenHeight = context.height ;


    int rowNumber = theGrid->row_number;
    int colNumber = theGrid->column_number;

    int cellWidth = screenWidth / colNumber ;
    int cellHeight = screenHeight / rowNumber ;



    printf("screenWidth = %d screenHeight = %d\n", screenWidth, screenHeight);
    printf("rowNumber = %d colNumber = %d\n", rowNumber, colNumber);
    printf("cellWidth = %d cellHeight = %d\n", cellWidth, cellHeight);

    SDL_Rect cell = {
        .x = 0,
        .y = 0,
        .h = cellHeight,
        .w = cellWidth
    };

    SDL_Color rectColor = {
        .r = 255,
        .g = 0,
        .b = 0,
        .a = 255
    };

    // sdlDrawRect(cell, rectColor);
    // cell.x = cellHeight ;
    // cell.y = cellWidth ;
    int newX = 0 ;
    int newY = 0 ;

    for(int i = 0 ; i < rowNumber ; i++){
        for(int j = 0 ; j < colNumber ; j++){
            newX = j*cellWidth ;
            newY = i*cellHeight ;
            cell.x = newX ;
            cell.y = newY ;
            sdlDrawRect(cell, rectColor);
        }
    }

    SDL_RenderPresent(context.renderer); // On affiche tout
    return ;
}

void sdlDrawRect(SDL_Rect rect, SDL_Color rectColor){
    
    // SDL_SetRenderDrawColor(context.renderer, 126, 126, 126, 255); // couleur grise
    // SDL_RenderClear(context.renderer); // On dessine toute la fenêtre en gris

    int r = rectColor.r;
    int g = rectColor.g;
    int b = rectColor.b;
    int a = rectColor.a;
     
    SDL_SetRenderDrawColor(context.renderer, r, g, b, a); // on choisit la couleur rouge
    SDL_RenderFillRect(context.renderer, &rect); // On dessine le rectangle

    // SDL_RenderPresent(context.renderer); // On affiche tout
}

void colorPalette(){
    palette = SDL_AllocPalette(5);

    if(palette == NULL){
        return;
    }
    // palette->ncolors  = 5;
    SDL_Color navy = {
        .r = 36,
        .g = 55,
        .b = 99
    };

    SDL_Color orange = {
        .r = 255,
        .g = 110,
        .b = 49
    };

    SDL_Color yellow = {
        .r = 255,
        .g = 235,
        .b = 183
    };

    SDL_Color brown = {
        .r = 173,
        .g = 142,
        .b = 112
    };

    SDL_Color teal = {
        .r = 134,
        .g = 200,
        .b = 188 
    };

    SDL_Color arrayColors[5] = {navy, orange, yellow, brown, teal};
    // palette->colors = arrayColors ;

    if(SDL_SetPaletteColors(palette, arrayColors, 0, 5) != 0){
        SDL_Log("Erreur : Setting colors > %s", SDL_GetError());
        exit(EXIT_FAILURE);
    };
}


