#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>
#include "HeaderFunction.h"

SDL_Texture* BgTexture;
SDL_Texture* StartBtnTexture;
SDL_Texture* OptionBtnTexture;
SDL_Texture* QuitBtnTexture;

enum State {
    MENU,
    PLAY,
    OPTION,
    QUIT,
    ENDSCREEN,
    ERROR = -1
};

// Fonction pour afficher le menu principal
void Menu(SDL_Renderer* renderer);

// Fonction pour gérer les interactions du menu principal
int handleMainMenu(SDL_Renderer* renderer);
bool isInsideButton(SDL_Rect btnRect, int x, int y);

