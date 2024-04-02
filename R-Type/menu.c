#include "menu.h"

void Menu(SDL_Renderer* renderer)
{
    // Affiche le fond du menu principal
    SDL_RenderCopy(renderer, BgTexture, NULL, NULL);

    // Affiche le bouton "Start" au milieu de l'écran
    SDL_Rect btnRect;
    SDL_QueryTexture(StartBtnTexture, NULL, NULL, 
        &btnRect.w, &btnRect.h);
    btnRect.x = (800 - btnRect.w) / 2;
    btnRect.y = (600 - btnRect.h) / 3;
    SDL_RenderCopy(renderer, StartBtnTexture, NULL, &btnRect);

    // Affiche le bouton "Option" au milieu de l'écran
    SDL_Rect optionBtnRect;
    SDL_QueryTexture(OptionBtnTexture, NULL, NULL, 
        &optionBtnRect.w, &optionBtnRect.h);
    optionBtnRect.x = (800 - optionBtnRect.w) / 2;
    optionBtnRect.y = (600 - optionBtnRect.h) / 2;
    SDL_RenderCopy(renderer, OptionBtnTexture, NULL, &optionBtnRect);

    // Affiche le bouton "Quitter" en bas de l'écran
    SDL_Rect quitBtnRect;
    SDL_QueryTexture(QuitBtnTexture, NULL, NULL, 
        &quitBtnRect.w, &quitBtnRect.h);
    quitBtnRect.x = (800 - quitBtnRect.w) / 2;
    quitBtnRect.y = (600 - quitBtnRect.h) / 1.5;
    SDL_RenderCopy(renderer, QuitBtnTexture, NULL, &quitBtnRect);

    SDL_RenderPresent(renderer);
}

bool isInsideButton(SDL_Rect btnRect, int x, int y) {
    return (x >= btnRect.x && x <= btnRect.x + btnRect.w &&
        y >= btnRect.y && y <= btnRect.y + btnRect.h);
}

void initMenuTextures(SDL_Renderer* renderer) {
    // Charge les images du fond et du bouton "Start"
    BgTexture = loadTexture(renderer, "./images/bg/menus/menu_screen.png");
    StartBtnTexture = loadTexture(renderer, "./images/btn/play_btn.png");
    OptionBtnTexture = loadTexture(renderer, "./images/btn/settings_btn.png");
    QuitBtnTexture = loadTexture(renderer, "./images/btn/quit_btn.png");
}

int mouseClick(SDL_Event event, bool running) {
    if (event.button.button == SDL_BUTTON_LEFT) {
        int x = event.button.x;
        int y = event.button.y;
        SDL_Rect startBtnRect;
        SDL_QueryTexture(StartBtnTexture, NULL, NULL, 
            &startBtnRect.w, &startBtnRect.h);
        startBtnRect.x = (800 - startBtnRect.w) / 2;
        startBtnRect.y = (600 - startBtnRect.h) / 3;
        SDL_Rect quitBtnRect;
        SDL_QueryTexture(QuitBtnTexture, NULL, NULL, 
            &quitBtnRect.w, &quitBtnRect.h);
        quitBtnRect.x = (800 - quitBtnRect.w) / 2;
        quitBtnRect.y = (600 - quitBtnRect.h) / 1.5;
        SDL_Rect optionBtnRect;
        SDL_QueryTexture(OptionBtnTexture, NULL, NULL, 
            &optionBtnRect.w, &optionBtnRect.h);
        optionBtnRect.x = (800 - optionBtnRect.w) / 2;
        optionBtnRect.y = (600 - optionBtnRect.h) / 2;

        if (isInsideButton(startBtnRect, x, y)) {
            return PLAY;
        }
        else if (isInsideButton(quitBtnRect, x, y)) {
            return QUIT;
        }
        else if (isInsideButton(optionBtnRect, x, y)) {
            return OPTION;
        }
    }
}

int handleMainMenu(SDL_Renderer* renderer) {
    initMenuTextures(renderer);

    if (!BgTexture || !StartBtnTexture || !QuitBtnTexture) {
        printf("Erreur lors du chargement des images du menu principal.\n");
        return -1;
    }

    SDL_Event event;
    bool running = true;
    while (running) {
        while (SDL_PollEvent(&event)) {
            Menu(renderer);
            int clickResult = 0;
            switch (event.type) {
            case SDL_QUIT:
                running = false;
                break;
            case SDL_MOUSEBUTTONDOWN:
                clickResult = mouseClick(event, &running);
                break;
            }
            if (clickResult != 0) {
                return clickResult;
            }
        }
    }
    return QUIT;
}