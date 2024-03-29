#include "option.h"

void initOption(Option* option)
{
    option->musicVolume = 32;
    option->soundVolume = 32;
}

/*void setting(SDL_Renderer* renderer) {
	
	SDL_RenderCopy(renderer, SFXTexture, NULL, NULL);
    
    // Affiche le bouton "Music" au milieu de l'écran
    SDL_Rect musicRect;
    SDL_QueryTexture(musicTexture, NULL, NULL, &musicRect.w, &musicRect.h);
    musicRect.x = (800 - musicRect.w) / 2;
    musicRect.y = (600 - musicRect.h) / 3;
    SDL_RenderCopy(renderer, musicTexture, NULL, &musicRect);

    // Affiche le bouton "Option" au milieu de l'écran
    SDL_Rect SFXRect;
    SDL_QueryTexture(SFXTexture, NULL, NULL, &SFXRect.w, &SFXRect.h);
    SFXRect.x = (800 - SFXRect.w) / 2;
    SFXRect.y = (600 - SFXRect.h) / 1.5;
    SDL_RenderCopy(renderer, SFXTexture, NULL, &SFXRect);

    // Met à jour l'affichage
    SDL_RenderPresent(renderer);
}*/