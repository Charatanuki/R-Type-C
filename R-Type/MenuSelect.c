#include "menuSelect.h"

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
            gameState = handleEnd(renderer);
            break;
        default:
            break;
        }
    }
}