#pragma once
#include <SDL2/SDL.h>
#include "grid.h"
#include "player.h"

/** 
* @file sdl2.h
* @brief Header pour la SDL2.
* Dans ce fichier, a été définis la structure SDLContext contenant la fenêtre,
* le rendu, la hauteur et la largeur de l'écran. 
*/

typedef struct SDLContext {
  SDL_Window *window;
  SDL_Renderer *renderer;
  int width;
  int height;
} SDLContext;


/* @brief 
 * Initialise une variable global `context` de type SDLContext
 *
 * Si il y a erreur pendant l'intialisation:
 *  context.window = NULL
 *  ou 
 *  context.renderer = NULL
 *
 * Les deux cas sont à testé !
 * 
 */
void sdl_init();

/**
 * nettoie la variable global context 
 */
void sdl_quit();

void displaySdl2(struct Grid *theGrid);

void colorPalette();

void sdlDrawRect(SDL_Rect rect, SDL_Color rectColor);
