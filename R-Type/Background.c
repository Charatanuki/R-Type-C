#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include "PlayerScoreValues.h"
#include "ennemis.h"
#include "Background.h"
#include "HeaderFunction.h"


#define MAX_BACKGROUND_TEXTURES 4

int currentBackgroundId = -1;

SDL_Texture* currentBackgroundTexture = NULL;


void loadBackgroundTexture(SDL_Renderer* renderer, int backgroundId) {
    if (backgroundId > MAX_BACKGROUND_TEXTURES) {
        backgroundId = 4;
    }
    if (backgroundId != currentBackgroundId) {
        // Free the previously loaded texture, if any
        if (currentBackgroundTexture != NULL) {
            SDL_DestroyTexture(currentBackgroundTexture);
            currentBackgroundTexture = NULL;
        }


        char bgPath[64];

        sprintf_s(bgPath, sizeof(bgPath), "./bg/bg%d.png", backgroundId);
        currentBackgroundId = backgroundId;
        currentBackgroundTexture = loadTexture(renderer, bgPath);
    }
}

void initBackground(Background *background, int backgroundId)
{
    background->bX = 0;
    background->bY = 0;
    background->bdx = 5;
    background->backgroundId = backgroundId;
}

void renderBackground(SDL_Renderer* renderer, Background* background) {
    // Load the background texture if it's not already loaded
    loadBackgroundTexture(renderer, background->backgroundId);

    // Render the background texture
    SDL_Rect bgRect = { background->bX, background->bY, 6000, 600 };
    if (currentBackgroundTexture != NULL) {
        SDL_RenderCopy(renderer, currentBackgroundTexture, NULL, &bgRect);
    }
    else {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderFillRect(renderer, &bgRect);
    }
}



void updatePosBackground(Background* background) {
    if (background->bX <= -5400) {
        background->bX = 0;
    }
    background->bX -= background->bdx;
}

void handleBackground(SDL_Renderer* renderer, Background* background) {
    loadBackgroundTexture(renderer, background -> backgroundId);
    renderBackground(renderer, background);
    updatePosBackground(background);
}