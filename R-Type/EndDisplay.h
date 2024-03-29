#pragma once
#include <SDL_ttf.h>
#include "PlayerScoreValues.h"

extern int P1_Score;

extern int level;


// Color for the text
SDL_Color endTextColor = { 255, 255, 255, 255 }; // White color

// Surface for the end values
SDL_Surface* killsSurface = NULL;
SDL_Surface* sscoreSurface = NULL;
SDL_Surface* levelSurface = NULL;

// Texture for the end values
SDL_Texture* killsTexture = NULL;
SDL_Texture* sscoreTexture = NULL;
SDL_Texture* levelTexture = NULL;



// String for each end value
char killsText[64]; 
char sscoreText[64]; 
char levelText[64]; 
