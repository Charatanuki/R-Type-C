#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>
#include "menu.h"

SDL_Texture* BgTexture;
SDL_Texture* StartBtnTexture;
SDL_Texture* QuitBtnTexture;

// Fonction pour gérer les interactions du menu principal
int handleEnd(SDL_Renderer* renderer);
