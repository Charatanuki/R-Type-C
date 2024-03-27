#pragma once
#include <SDL_ttf.h>

int P1_Lives = 3;
extern int P1_Score = 0;
int Hi_Score = 174500;
// Color for the text
SDL_Color textColor = { 255, 255, 255, 255 }; // White color

// Surface for the score text
SDL_Surface* scoreSurface = NULL;

// Texture for the score text
SDL_Texture* scoreTexture = NULL;