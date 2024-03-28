#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include "PlayerScoreValues.h"
#include "ennemis.h"
#include "Background.h"
#include "HeaderFunction.h"

#define SCORE_REQ 3500 
#define MAX_BACKGROUND_TEXTURES 5

int level = 1;
int nextLevel = 2;
int levelCheck = 0;
int currentBackgroundId = -1;

void levelChange(int* numEnemies, Enemy enemies[], Background* background) {
	if (P1_Score >= levelCheck + SCORE_REQ && level != nextLevel) {
		level ++;
        nextLevel++;

        *numEnemies += 10;
        newSpeed += 1;

        levelCheck = P1_Score;
        background->backgroundId++;
        initEnemies(enemies, *numEnemies, 800, 500, newSpeed);
		printf("Level Up!\n");
        printf("%d", *numEnemies);
	}
}

SDL_Texture* currentBackgroundTexture = NULL;


void loadBackgroundTexture(SDL_Renderer* renderer, int backgroundId) {
    if (backgroundId != currentBackgroundId) {
        // Free the previously loaded texture, if any
        if (currentBackgroundTexture != NULL) {
            SDL_DestroyTexture(currentBackgroundTexture);
            currentBackgroundTexture = NULL;
        }

        int bgIdToLoad;
        // Load the new background texture
        if (backgroundId >= MAX_BACKGROUND_TEXTURES) {
            bgIdToLoad = MAX_BACKGROUND_TEXTURES;
        }
        else {
            bgIdToLoad = backgroundId;
        }
        char bgPath[64];
        sprintf_s(bgPath, sizeof(bgPath), "./bg/bg%d.png", backgroundId);
        currentBackgroundTexture = loadTexture(renderer, bgPath);
        currentBackgroundId = backgroundId;
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