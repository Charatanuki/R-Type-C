#pragma once


// Init functions
int initSDL();

int createRenderer(SDL_Window* window);



void freeAll(SDL_Window* window, SDL_Renderer* renderer);