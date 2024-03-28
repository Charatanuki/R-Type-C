#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include "PlayerScoreValues.h"
#include "Background.h"
#include "HeaderFunction.h"

int level = 1;

void levelChange() {
	if (P1_Score > 2000 && level != 2) {
		level += 1;
		printf("Level Up!\n");
	}
}



void initBackground(Background *background, int backgroundId)
{
    background->bX = 0;
    background->bY = 0;
    background->bdx = 1;
    background->backgroundId = backgroundId;
}

void renderBackground(SDL_Renderer* renderer, Background* background) {
    char bgPath[64];
    sprintf_s(bgPath, sizeof(bgPath), "./bg/bg%d.png", background->backgroundId);

    SDL_Texture* bgTexture = loadTexture(renderer, bgPath);
    SDL_Rect bgRect = { background->bX, background->bY, 6000, 600 };
    if (bgTexture != NULL) {
        SDL_RenderCopy(renderer, bgTexture, NULL, &bgRect);
        SDL_DestroyTexture(bgTexture); // Free the texture after rendering
    }
    else {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
        SDL_RenderFillRect(renderer, &bgRect);
    }
}



void updatePosBackground(Background* background) {
    background->bX -= background->bdx;
}

void handleBackground(SDL_Renderer* renderer, Background* background) {
    renderBackground(renderer, background);
    updatePosBackground(background);
}