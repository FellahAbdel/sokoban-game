#include "sdl2.h"

/**
 * @file sdl2.c
*/

SDLContext context; /// Une variable globale.
SDL_Palette *palette ; /// Une variable globale

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

/**
 * @relatesalso Grid
 * @brief Affiche du niveau de jeu sur la SDL.
 * @param theGrid La grille de jeux.
 * @return Rien
 */
void displaySdl2(struct Grid *theGrid){
    // Initialisation de palette de couleur
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

    SDL_Rect cell = {
        .x = 0,
        .y = 0,
        .h = cellHeight,
        .w = cellWidth
    };

    SDL_Color rectColor;
    int newX = 0 ;
    int newY = 0 ;
    char item ;
    for(int i = 0 ; i < rowNumber ; i++){
        for(int j = 0 ; j < colNumber ; j++){
            newX = j*cellWidth ;
            newY = i*cellHeight ;
            cell.x = newX ;
            cell.y = newY ;

            item = theGrid->game_grid[i][j];
            if(isBox(item)){
                rectColor = palette->colors[0];
            } else if( isGoal(item)){
                rectColor = palette->colors[1] ;
            } else if(isNone(item)){
                rectColor = palette->colors[3] ;
            }else if(isWall(item)){
                rectColor = palette->colors[2] ;
            }else {
                rectColor = palette->colors[4] ;
            }

            sdlDrawRect(cell, rectColor);
        }
    }

    SDL_RenderPresent(context.renderer); // On affiche tout
    SDL_FreePalette(palette);  // On n'ettoie la palette
    return ;
}

/**
 * @relatesalso Grid
 * @brief On dessine juste un rectangle.
 * @param rect Le rectangle. 
 * @param rectColor La couleur du rectangle à dessiner. 
 * @return Rien
 */
void sdlDrawRect(SDL_Rect rect, SDL_Color rectColor){
    
    // SDL_SetRenderDrawColor(context.renderer, 126, 126, 126, 255); // couleur grise
    // SDL_RenderClear(context.renderer); // On dessine toute la fenêtre en gris

    int r = rectColor.r;
    int g = rectColor.g;
    int b = rectColor.b;
    int a = rectColor.a;
     
    SDL_SetRenderDrawColor(context.renderer, r, g, b, a); // on choisit la couleur rouge
    SDL_RenderFillRect(context.renderer, &rect); // On dessine le rectangle
}

/**
 * @brief Gestion de cinqs couleur pour le jeux.
 * @return Rien
 */
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

    if(SDL_SetPaletteColors(palette, arrayColors, 0, 5) != 0){
        SDL_Log("Erreur : Setting colors > %s", SDL_GetError());
        exit(EXIT_FAILURE);
    };
}

Event eventSdl2(){
    Event eventType ;

    SDL_Event ev;
    SDL_WaitEvent(&ev);
    switch(ev.type){
        case SDL_QUIT :
            eventType = Quit;
            break;
        case SDL_KEYUP :
            switch(ev.key.keysym.sym){
                case SDLK_UP :
                    eventType = Up ;
                    break;
                case SDLK_DOWN :
                    eventType = Down;
                    break;
                case SDLK_LEFT :
                    eventType = LeftArr;
                    break;
                case SDLK_RIGHT :
                    eventType = RightArr ;
                default :
                    break;
            }
        default :
            // eventType = None ;
            break;
    }

    return eventType ;
}


