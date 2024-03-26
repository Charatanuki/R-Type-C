#include <stdio.h>;
#include <SDL.h>;
#include <SDL_image.h>;
#include "PlayerValues.h";
#include "HeaderFunction.h";
#include "Projectile.h"

void initPlayer(Player *player) 
{
    player->pX = 250;
    player->pY = 250;
    player->pSize = 50;
    player->dx = 0;
    player->dy = 0;
}


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

void renderPlayer(SDL_Renderer* renderer, Player *player) {
    SDL_Texture* playerTexture = loadTexture(renderer);
    SDL_Rect playerRect = { player->pX, player->pY, player->pSize, player->pSize };
    if (playerTexture != NULL) {
        SDL_RenderCopy(renderer, playerTexture, NULL, &playerRect);
    }
    else {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderFillRect(renderer, &playerRect);
    }
}


void updatePosPlayer(Player *player) {
    if (player->pY > 0 && player->pY < 600 - player->pSize) {
        player->pY += player->dy;
    }
    else if (player->pY <= 0 && player->dy == 5) {
        player->pY += player->dy;
    }
    else if (player->pY >= 600 - player->pSize && player->dy == -5) {
        player->pY += player->dy;
    }

    if (player->pX > 0 && player->pX < 800 - player->pSize) {
        player->pX += player->dx;
    }
    else if (player->pX <= 0 && player->dx == 5) {
        player->pX += player->dx;
    }
    else if (player->pX >= 800 - player->pSize && player->dx == -5) {
        player->pX += player->dx;
    }
}

void handlePlayer(SDL_Renderer* renderer, Player *player) {
    renderPlayer(renderer, player);
    handleKey(player);
    //updateMovement(&y, &y1, dy, dv, sizey);
    updatePosPlayer(player);
}

