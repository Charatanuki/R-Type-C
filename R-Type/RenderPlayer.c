#include <stdio.h>;
#include <SDL.h>;
#include "PlayerValues.h";
#include "HeaderFunction.h";
#include "Projectile.h"

int pX = 250;
int pY = 250;
int pSize = 50;

int dx = 0;
int dy = 0;

void Player(SDL_Renderer* renderer) {
    SDL_Rect rightPlayer = { pX, pY, pSize, pSize };
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    SDL_RenderFillRect(renderer, &rightPlayer);
}


void updatePosPlayer(a, ba, win) {
    if (pY > 0 && pY < 600 - pSize) {
        pY += dy;
    }
    else if (pY <= 0 && dy == 5) {
        pY += dy;
    }
    else if (pY >= 600 - pSize && dy == -5) {
        pY += dy;
    }

    if (pX > 0 && pX < 800 - pSize) {
        pX += dx;
    }
    else if (pX <= 0 && dx == 5) {
        pX += dx;
    }
    else if (pX >= 800 - pSize && dx == -5) {
        pX += dx;
    }
}

void handlePlayer(SDL_Renderer* renderer) {
    Player(renderer);

    handleKey(&dx, &dy);


    //updateMovement(&y, &y1, dy, dv, sizey);
    updatePosPlayer();
}

