#include <SDL.h>
#include <stdio.h>
#include "HeaderFunction.h"
#include "PlayerValues.h";
#include "Projectile.h"

int isFiring = 0;

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

void handleKeyDown(Player *player, int keyDown) {
    switch (keyDown) {
    case(SDLK_UP):
        player->dy = movement(up);
        break;
    case(SDLK_DOWN):
        player->dy = movement(down);
        break;
    case(SDLK_LEFT):
        player->dx = movement(left);
        break;
    case(SDLK_RIGHT):
        player->dx = movement(right);
        break;
    case(SDLK_SPACE):
        isFiring = 1;
        break;
    }
}

void handleKeyUp(Player *player, int keyUp) {
    switch (keyUp) {
    case(SDLK_UP):
        player->dy = 0;
        break;
    case(SDLK_DOWN):
        player->dy = 0;
        break;
    case(SDLK_LEFT):
        player->dx = 0;
        break;
    case(SDLK_RIGHT):
        player->dx = 0;
        break;
    case(SDLK_SPACE):
        isFiring = 0;
        break;
    }
}



void handleKey(Player *player) {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        switch (event.type) {
        case SDL_KEYDOWN:
            handleKeyDown(player, event.key.keysym.sym);
            break;
        case SDL_KEYUP:
            handleKeyUp(player, event.key.keysym.sym);
            break;
        }
    }
}