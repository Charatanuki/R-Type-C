#include <SDL.h>
#include <stdio.h>
#include "HeaderFunction.h"

int up = SDLK_UP;
int down = SDLK_DOWN;
int left = SDLK_LEFT;
int right = SDLK_RIGHT;


int movement(int dir) {
    int baseSpeedV = 5;
    int baseSpeedH = 5;

    if (dir == up) {
        return -baseSpeedV;
    }
    else if (dir == down) {
        return baseSpeedV;
    }
    else if (dir == left) {
        return -baseSpeedV;
    }
    else if (dir == right) {
        return baseSpeedV;
    }
}

void handleKeyDown(int* dx, int* dy, int keyDown) {
    switch (keyDown) {
    case(SDLK_UP):
        *dy = movement(up);
        break;
    case(SDLK_DOWN):
        *dy = movement(down);
        break;
    case(SDLK_LEFT):
        *dx = movement(left);
        break;
    case(SDLK_RIGHT):
        *dx = movement(right);
        break;
    }
}

void handleKeyUp(int* dx, int* dy, int keyUp) {

    switch (keyUp) {
    case(SDLK_UP):
        *dy = 0;
        break;
    case(SDLK_DOWN):
        *dy = 0;
        break;
    case(SDLK_LEFT):
        *dx = 0;
        break;
    case(SDLK_RIGHT):
        *dx = 0;
        break;
    }


}



void handleKey(int *dx, int *dy) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_KEYDOWN:
            handleKeyDown(*&dx, *&dy, event.key.keysym.sym);
            break;
        case SDL_KEYUP:
            handleKeyUp(*&dx, *&dy, event.key.keysym.sym);
            break;
        }
    }
}