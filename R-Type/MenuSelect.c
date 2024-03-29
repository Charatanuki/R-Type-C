#include "menu.h"
#include "HeaderFunction.h"
#include <SDL.h>

int titleMenu(SDL_Renderer* renderer) {
    int menuResult = handleMainMenu(renderer);
    switch (menuResult)
    {
    case PLAY:
        mainLoop(renderer);
        return (1);
        break;
    case OPTION:
        return(0);
        break;
    default:
        return(0);
        break;
    }
}