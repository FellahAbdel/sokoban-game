#include "sdl2.h"

SDLContext context; /// Une variable globale.

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
    
}

void sdlDrawRect(SDL_Rect rect, SDL_Color rectColor){
    
    SDL_SetRenderDrawColor(context.renderer, 126, 126, 126, 255); // couleur grise
    SDL_RenderClear(context.renderer); // On dessine toute la fenêtre en gris

    int r = rectColor.r;
    int g = rectColor.g;
    int b = rectColor.b;
    int a = rectColor.a;
     
    SDL_SetRenderDrawColor(context.renderer, r, g, b, a); // on choisit la couleur rouge
    SDL_RenderFillRect(context.renderer, &rect); // On dessine le rectangle
    SDL_RenderPresent(context.renderer); // On affiche tout

    SDL_Delay(1000);
}


