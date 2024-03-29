#include <SDL.h>
#include <SDL_ttf.h>
#include "EndDisplay.h"
#include "HeaderFunction.h"

void freeEndDisplay() {
    SDL_DestroyTexture(killsTexture);
    SDL_DestroyTexture(sscoreTexture);
    SDL_DestroyTexture(levelTexture);

    SDL_FreeSurface(killsSurface);
    SDL_FreeSurface(sscoreSurface);
    SDL_FreeSurface(levelSurface);
}

int endScoreDisplay(TTF_Font* font, SDL_Renderer* renderer) {
    // Render text for the scores
    sprintf_s(killsText, sizeof(killsText), "%d", P1_Score / 200);
    sprintf_s(sscoreText, sizeof(sscoreText), "%d", P1_Score);
    sprintf_s(levelText, sizeof(levelText), "%d", level);

    killsSurface = TTF_RenderText_Solid(font, killsText, endTextColor);
    sscoreSurface = TTF_RenderText_Solid(font, sscoreText, endTextColor);
    levelSurface = TTF_RenderText_Solid(font, levelText, endTextColor);
    if (killsSurface == NULL || sscoreSurface == NULL || levelSurface == NULL) {
        printf("Surface not created");
        return -1;
    }

    killsTexture = SDL_CreateTextureFromSurface(renderer, killsSurface);
    sscoreTexture = SDL_CreateTextureFromSurface(renderer, sscoreSurface);
    levelTexture = SDL_CreateTextureFromSurface(renderer, levelSurface);

    SDL_Rect killsRect = { 300, 400, killsSurface->w, killsSurface->h }; 
    SDL_Rect sscoreRect = { 300, 460, sscoreSurface->w, sscoreSurface->h }; 
    SDL_Rect levelRect = { 300, 530, levelSurface->w, levelSurface->h }; 

    SDL_RenderCopy(renderer, killsTexture, NULL, &killsRect);
    SDL_RenderCopy(renderer, sscoreTexture, NULL, &sscoreRect);
    SDL_RenderCopy(renderer, levelTexture, NULL, &levelRect);

    freeEndDisplay();
}


