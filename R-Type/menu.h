#pragma once
#include <SDL.h>

SDL_Texture* BgTexture;
SDL_Texture* StartBtnTexture;
SDL_Texture* OptionBtnTexture;
SDL_Texture* QuitBtnTexture;

enum game {
    MENU,
    PLAY,
    OPTION,
    QUIT
};

// Fonction pour afficher le menu principal
void Menu(SDL_Renderer* renderer,
    SDL_Texture* BgTexture,
    SDL_Texture* StartBtnTexture,
    SDL_Texture* OptionBtnTexture,
    SDL_Texture* QuitBtnTexture);

// Fonction pour gérer les interactions du menu principal
int handleMainMenu(SDL_Renderer* renderer);