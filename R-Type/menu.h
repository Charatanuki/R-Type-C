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
    QUIT,
    ENDSCREEN
};

// Fonction pour afficher le menu principal
void Menu(SDL_Renderer* renderer,
    SDL_Texture* BgTexture,
    SDL_Texture* StartBtnTexture,
    SDL_Texture* OptionBtnTexture,
    SDL_Texture* QuitBtnTexture);

// Fonction pour afficher le menu de fin
void EndScreen(SDL_Renderer* renderer,
    SDL_Texture* BgTexture,
    SDL_Texture* StartBtnTexture,
    SDL_Texture* OptionBtnTexture,
    SDL_Texture* QuitBtnTexture);


// Fonction pour g�rer les interactions du menu principal
int handleMainMenu(SDL_Renderer* renderer);

// Fonction pour g�rer les interactions du menu de fin
int handleEndScreen(SDL_Renderer* renderer);