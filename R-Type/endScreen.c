#include "endScreen.h"





void endScreen(SDL_Renderer* renderer, TTF_Font* font)
{
    // Affiche le fond du menu principal
    SDL_RenderCopy(renderer, BgTexture, NULL, NULL);

    // Affiche le bouton "Start" au milieu de l'écran
    SDL_Rect btnRect;
    SDL_QueryTexture(StartBtnTexture, NULL, NULL, 
        &btnRect.w, &btnRect.h);
    btnRect.x = (800 - btnRect.w) / 2;
    btnRect.y = (600 - btnRect.h) / 4;
    SDL_RenderCopy(renderer, StartBtnTexture, NULL, &btnRect);

    // Affiche le bouton "Quitter" en bas de l'écran
    SDL_Rect quitBtnRect;
    SDL_QueryTexture(QuitBtnTexture, NULL, NULL, 
        &quitBtnRect.w, &quitBtnRect.h);
    quitBtnRect.x = (800 - quitBtnRect.w) / 2;
    quitBtnRect.y = (600 - quitBtnRect.h) / 3;
    SDL_RenderCopy(renderer, QuitBtnTexture, NULL, &quitBtnRect);

    endScoreDisplay(font, renderer);

    SDL_RenderPresent(renderer);
}

bool isInsideButtonEnd(SDL_Rect btnRect, int x, int y) {
    return (x >= btnRect.x && x <= btnRect.x + btnRect.w &&
        y >= btnRect.y && y <= btnRect.y + btnRect.h);
}

void initEndTextures(SDL_Renderer* renderer) {
    // Charge les images du fond et du bouton "Start"
    BgTexture = loadTexture(renderer, "./images/bg/menus/Endgame_bg_box.png");
    StartBtnTexture = loadTexture(renderer, "./images/btn/play_again_btn.png");
    QuitBtnTexture = loadTexture(renderer, "./images/btn/quit_btn.png");
}

int mouseClickEnd(SDL_Event event, bool running) {
    if (event.button.button == SDL_BUTTON_LEFT) {
        int x = event.button.x;
        int y = event.button.y;
        SDL_Rect startBtnRect;
        SDL_QueryTexture(StartBtnTexture, NULL, NULL, 
            &startBtnRect.w, &startBtnRect.h);
        startBtnRect.x = (800 - startBtnRect.w) / 2;
        startBtnRect.y = (600 - startBtnRect.h) / 4;
        SDL_Rect quitBtnRect;
        SDL_QueryTexture(QuitBtnTexture, NULL, NULL, 
            &quitBtnRect.w, &quitBtnRect.h);
        quitBtnRect.x = (800 - quitBtnRect.w) / 2;
        quitBtnRect.y = (600 - quitBtnRect.h) / 3;
        SDL_Rect optionBtnRect;

        if (isInsideButtonEnd(startBtnRect, x, y)) {
            running = false; // Arrête le menu principal
            return PLAY;
        }
        else if (isInsideButtonEnd(quitBtnRect, x, y)) {
            running = false; // Quitte le jeu
            return QUIT;
        }
    }
}

int handleEnd(SDL_Renderer* renderer, TTF_Font* font) {
    initEndTextures(renderer);

    if (!BgTexture || !StartBtnTexture || !QuitBtnTexture) {
        printf("Erreur lors du chargement des images du menu principal.\n");
        return ERROR;
    }

    SDL_Event event;
    bool running = true;
    while (running) {
        while (SDL_PollEvent(&event)) {
            endScreen(renderer, font);
            int clickResult = 0;
            switch (event.type) {
            case SDL_QUIT:
                clickResult = QUIT;
                break;
            case SDL_MOUSEBUTTONDOWN:
                clickResult = mouseClickEnd(event, &running);
                break;
            }
            if (clickResult != 0) {
                return clickResult;
            }
        }
    }

    freeEndDisplay();
    return 0;
}