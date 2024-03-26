#pragma once
#include <stdbool.h>


// Init functions
int initSDL();
SDL_Renderer* createRenderer(SDL_Window* window);
void freeAll(SDL_Window* window, SDL_Renderer* renderer);



// Movement player function 
void handleKey(int* dx, int* dy);
void handlePlayer(SDL_Renderer* renderer);
int mainLoop(SDL_Renderer* renderer);