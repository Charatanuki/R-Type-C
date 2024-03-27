#pragma once
#include <SDL_ttf.h>
#include "PlayerScoreValues.h"

extern int P1_Score;


// Color for the text
SDL_Color textColor = { 255, 255, 255, 255 }; // White color

// Surface for the score text
SDL_Surface* scoreSurface = NULL;

// Texture for the score text
SDL_Texture* scoreTexture = NULL;

