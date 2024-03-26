#include <stdio.h>;
#include <SDL.h>;
#include <SDL_image.h>;
#include "PlayerValues.h";
#include "HeaderFunction.h";
#include "Projectile.h"

int pX = 250;
int pY = 250;
int pSize = 50;

int dx = 0;
int dy = 0;

SDL_Texture* loadTexture(SDL_Renderer* renderer) {
    SDL_Texture* playerTexture = NULL;

    // Load player image
    SDL_Surface* playerSurface = IMG_Load("spaceship.png");
    if (playerSurface == NULL) {
        printf("Failed to load player image: %s\n", IMG_GetError());
        return -1;
        // Handle error
    }
    else {
        // Create texture from surface
        playerTexture = SDL_CreateTextureFromSurface(renderer, playerSurface);
        if (playerTexture == NULL) {
            printf("Failed to create texture from player surface: %s\n", SDL_GetError());
            return -1;
            // Handle error
        }
        SDL_FreeSurface(playerSurface); // Free the surface once the texture is created
        return(playerTexture);
    }

}

void Player(SDL_Renderer* renderer) {
    SDL_Texture* playerTexture = loadTexture(renderer);
    SDL_Rect player = { pX, pY, pSize, pSize };
    if (playerTexture != NULL) {
        SDL_RenderCopy(renderer, playerTexture, NULL, &player);
    }
    else {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderFillRect(renderer, &player);
    }
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

