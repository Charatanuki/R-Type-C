#include "option.h"

void initOption(Option* option)
{
    option->musicVolume = 32;
    option->soundVolume = 32;
}

char* getPath(int optionType, int value) {
    if (optionType == 0) {
        if (value == 0)
            return "./btn/Music_OFF_btn.png";
        return "./btn/Music_ON_btn.png";
    }
    if (value == 0)
        return "./btn/SFX_OFF_btn.png";
    return "./btn/SFX_ON_btn.png";
}

void setting(SDL_Renderer* renderer, Option *option) {
    SFXTexture = loadTexture(renderer, getPath(1, option->soundVolume));
    musicTexture = loadTexture(renderer, getPath(0, option->musicVolume));

	SDL_RenderCopy(renderer, SettingBgTexture, NULL, NULL);

    // Affiche le bouton "Music" au milieu de l'écran
    SDL_Rect musicRect;
    SDL_QueryTexture(musicTexture, NULL, NULL, 
        &musicRect.w, &musicRect.h);
    musicRect.x = (800 - musicRect.w) / 2;
    musicRect.y = (600 - musicRect.h) / 3;
    SDL_RenderCopy(renderer, musicTexture, NULL, &musicRect);
    // Affiche le bouton "SFX" au milieu de l'écran
    SDL_Rect SFXRect;
    SDL_QueryTexture(SFXTexture, NULL, NULL, 
        &SFXRect.w, &SFXRect.h);
    SFXRect.x = (800 - SFXRect.w) / 2;
    SFXRect.y = (600 - SFXRect.h) / 2;
    SDL_RenderCopy(renderer, SFXTexture, NULL, &SFXRect);
    // Affiche le bouton "Quitter" en bas de l'écran
    SDL_Rect returnBtnRect;
    SDL_QueryTexture(returnTexture, NULL, NULL, 
        &returnBtnRect.w, &returnBtnRect.h);
    returnBtnRect.x = (800 - returnBtnRect.w) / 2;
    returnBtnRect.y = (600 - returnBtnRect.h) / 1.5;
    SDL_RenderCopy(renderer, returnTexture, NULL, &returnBtnRect);
    // Met à jour l'affichage
    SDL_RenderPresent(renderer);
}





int mouseClickOption(SDL_Event event, Option *option) {
    if (event.button.button == SDL_BUTTON_LEFT) {
        int x = event.button.x;
        int y = event.button.y;
        SDL_Rect musicBtnRect;
        SDL_QueryTexture(StartBtnTexture, NULL, NULL, &musicBtnRect.w, &musicBtnRect.h);
        musicBtnRect.x = (800 - musicBtnRect.w) / 2;
        musicBtnRect.y = (600 - musicBtnRect.h) / 3;
        SDL_Rect returnBtnRect;
        SDL_QueryTexture(returnTexture, NULL, NULL, &returnBtnRect.w, &returnBtnRect.h);
        returnBtnRect.x = (800 - returnBtnRect.w) / 2;
        returnBtnRect.y = (600 - returnBtnRect.h) / 1.5;
        SDL_Rect SFXBtnRect;
        SDL_QueryTexture(OptionBtnTexture, NULL, NULL, &SFXBtnRect.w, &SFXBtnRect.h);
        SFXBtnRect.x = (800 - SFXBtnRect.w) / 2;
        SFXBtnRect.y = (600 - SFXBtnRect.h) / 2;

        if (isInsideButton(musicBtnRect, x, y)) {
            musicVolumeOpt(option);
            return OPTION;
        }
        else if (isInsideButton(returnBtnRect, x, y)) {
            return MENU;
        }
        else if (isInsideButton(SFXBtnRect, x, y)) {
            soundVolumeOpt(option);
            return OPTION;
        }
    }
}

int handleOptionMenu(SDL_Renderer* renderer, Option *option) {
    SettingBgTexture = loadTexture(renderer, "./settings_screen.png");
    SFXTexture = loadTexture(renderer, getPath(1, option->soundVolume));
    musicTexture = loadTexture(renderer, getPath(0, option->musicVolume));
    returnTexture = loadTexture(renderer, "./btn/menu_btn.png"); 

    if (!SFXTexture || !musicTexture || !returnTexture) {
        printf("Erreur lors du chargement des images du menu principal.\n");
        return ERROR;
    }

    SDL_Event event;
    bool running = true;
    int clickResult = OPTION;
    while (running) {
        while (SDL_PollEvent(&event)) {
            setting(renderer, option);
            switch (event.type) {
            case SDL_QUIT:
                running = false;
                break;
            case SDL_MOUSEBUTTONDOWN:
                clickResult = mouseClickOption(event, option);
                break;
            }
            if (clickResult != OPTION) {
                running = false;
            }
        }
    }
    SDL_DestroyTexture(SFXTexture);
    SDL_DestroyTexture(musicTexture);
    SDL_DestroyTexture(returnTexture);
    return clickResult;
}