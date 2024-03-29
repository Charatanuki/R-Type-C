#include <SDL.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <stdbool.h>
#include "PlayerValues.h"
#include "ScoreValues.h"

void freeRenderScore(SDL_Renderer* renderer, SDL_Rect* scoreRect) {
    SDL_RenderCopy(renderer, scoreTexture, NULL, *&scoreRect);
    SDL_DestroyTexture(scoreTexture);
    SDL_FreeSurface(scoreSurface);
}


int scoreDisplay(TTF_Font* font, SDL_Renderer* renderer, Player player) {
    sprintf_s(scoreText, sizeof(scoreText), 
        "Score: %d     Health: %d     Level: %d", 
        P1_Score, player.health, level);

    // Check if the font was loaded successfully
    if (font == NULL || renderer == NULL) {
        printf("Font or renderer is NULL\n");
        return -1;
    }

    // Surface for the score text
    scoreSurface = TTF_RenderText_Solid(font, 
        scoreText, textColor);
    if (scoreSurface == NULL) {
        printf("Surface not created");
        return -1;
    }

    // Create texture from surface
    scoreTexture = SDL_CreateTextureFromSurface(renderer, 
        scoreSurface);
    if (scoreTexture == NULL) {
        printf("Failed to create texture: %s\n", SDL_GetError());
        SDL_FreeSurface(scoreSurface); // Free the surface before returning
        return -1;
    }
    SDL_Rect scoreRect = { 50, 50, scoreSurface->w, scoreSurface->h }; // Position of the score text
    freeRenderScore(renderer, &scoreRect);
}

