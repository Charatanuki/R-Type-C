#include <SDL.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <stdbool.h>
#include "PlayerValues.h"
#include "ScoreValues.h"




int scoreDisplay(TTF_Font* font, SDL_Renderer* renderer, Player player) {
    // Render text for the scores
    char scoreText[64]; // Assuming the score won't exceed 64 characters
    sprintf_s(scoreText, sizeof(scoreText), "Score: %d     Health: %d     Level: %d", P1_Score, player.health, level);

    // Check if the font was loaded successfully
    if (font == NULL || renderer == NULL) {
        printf("Font or renderer is NULL\n");
        return -1;
    }

    // Surface for the score text
    SDL_Surface* scoreSurface = TTF_RenderText_Solid(font, scoreText, textColor);
    if (scoreSurface == NULL) {
        printf("Surface not created");
        return -1;
    }

    // Create texture from surface
    SDL_Texture* scoreTexture = SDL_CreateTextureFromSurface(renderer, scoreSurface);
    if (scoreTexture == NULL) {
        printf("Failed to create texture: %s\n", SDL_GetError());
        SDL_FreeSurface(scoreSurface); // Free the surface before returning
        return -1;
    }
    SDL_Rect scoreRect = { 50, 50, scoreSurface->w, scoreSurface->h }; // Position of the score text
    SDL_RenderCopy(renderer, scoreTexture, NULL, &scoreRect);

    SDL_DestroyTexture(scoreTexture);

    SDL_FreeSurface(scoreSurface);
}
