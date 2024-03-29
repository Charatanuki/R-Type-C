#include "menuSelect.h"
#include <SDL_ttf.h>

void selectMenu(SDL_Renderer* renderer) {
    int gameState = handleMainMenu(renderer);
    Option option;
    initOption(&option);
    while (gameState != ERROR && gameState != QUIT)
    {
        switch (gameState)
        {
        case PLAY:
            gameState = mainLoop(renderer, option);
            break;
        case OPTION:
            gameState = handleOptionMenu(renderer, &option);
            break;
        case MENU:
            gameState = handleMainMenu(renderer);
            break;
        case ENDSCREEN:
            TTF_Font* font = TTF_OpenFont("sans.ttf", 24);
            if (font == NULL) {
                printf("Error loading font for end screen");
                return -1;
            }
            gameState = handleEnd(renderer, font);
            break;
        default:
            break;
        }
    }
}