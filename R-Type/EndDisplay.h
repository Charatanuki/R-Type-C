#pragma once
#include <SDL_ttf.h>
#include "PlayerScoreValues.h"

extern int P1_Score;

extern int level;


// Color for the text
SDL_Color endTextColor = { 255, 255, 255, 255 }; // White color

// Surface for the score text
SDL_Surface* killsSurface = NULL;
SDL_Surface* sscoreSurface = NULL;
SDL_Surface* levelSurface = NULL;

// Texture for the score text
SDL_Texture* killsTexture = NULL;
SDL_Texture* sscoreTexture = NULL;
SDL_Texture* levelTexture = NULL;