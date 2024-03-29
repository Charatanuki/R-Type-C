#include <stdio.h>
#include <SDL.h>
#include <SDL_image.h>
#include "PlayerValues.h"
#include "HeaderFunction.h"
#include "Projectile.h"
#include "PTextureManager.h"

int P1_Health = 3;
char spaceship[64] = "./spaceship.png";
char invisinsibility[64] = "./Shield-ship.png";



void renderPlayer(SDL_Renderer* renderer, Player *player) {
    SDL_Texture* playerTexture;
    if (player->immortal == 1) {
        playerTexture = playerTextureInvincible;
    }
    else {
        playerTexture = playerTextureNormal;
    }
    SDL_Rect playerRect = { player->pX, player->pY, 
        player->pSize, player->pSize };
    if (playerTexture != NULL) {
        SDL_RenderCopy(renderer, playerTexture, NULL, &playerRect);
    }
    else {
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
        SDL_RenderFillRect(renderer, &playerRect);
        SDL_DestroyTexture(playerTexture);
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

void playerImmortality(Player* player) {
    if (player->immortal && SDL_GetTicks() - player->hurtTime >= 3000) {
        player->immortal = 0;
    }
}

void handlePlayer(SDL_Renderer* renderer, Player *player) {
    renderPlayer(renderer, player);
    handleKey(player);
    //updateMovement(&y, &y1, dy, dv, sizey);
    updatePosPlayer(player);
    playerImmortality(player);
}

void playerHurt(Player *player) {
    player->pX = 250;
    player->pY = 250;
    player->health -= 1;
    player->immortal = 1;
    player->hurtTime = SDL_GetTicks();
}

