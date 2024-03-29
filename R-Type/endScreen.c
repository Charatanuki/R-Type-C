#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>
#include "endScreen.h"
#include "HeaderFunction.h"
#include "menu.h"


void endScreen(SDL_Renderer* renderer)
{
    // Affiche le fond du menu principal
    SDL_RenderCopy(renderer, BgTexture, NULL, NULL);

    // Affiche le bouton "Start" au milieu de l'écran
    SDL_Rect btnRect;
    SDL_QueryTexture(StartBtnTexture, NULL, NULL, &btnRect.w, &btnRect.h);
    btnRect.x = (800 - btnRect.w) / 2;
    btnRect.y = (600 - btnRect.h) / 3.5;
    SDL_RenderCopy(renderer, StartBtnTexture, NULL, &btnRect);

    // Affiche le bouton "Quitter" en bas de l'écran
    SDL_Rect quitBtnRect;
    SDL_QueryTexture(QuitBtnTexture, NULL, NULL, &quitBtnRect.w, &quitBtnRect.h);
    quitBtnRect.x = (800 - quitBtnRect.w) / 2;
    quitBtnRect.y = (600 - quitBtnRect.h) / 2.25;
    SDL_RenderCopy(renderer, QuitBtnTexture, NULL, &quitBtnRect);

    // Met à jour l'affichage
    SDL_RenderPresent(renderer);
}

bool isInsideButtonEnd(SDL_Rect btnRect, int x, int y) {
    return (x >= btnRect.x && x <= btnRect.x + btnRect.w &&
        y >= btnRect.y && y <= btnRect.y + btnRect.h);
}

void initEndTextures(SDL_Renderer* renderer) {
    // Charge les images du fond et du bouton "Start"
    BgTexture = loadTexture(renderer, "./Endgame_bg.png");
    StartBtnTexture = loadTexture(renderer, "./btn/play_again_btn.png");
    QuitBtnTexture = loadTexture(renderer, "./btn/quit_btn.png");
}

int mouseClickEnd(SDL_Event event, bool running) {
    if (event.button.button == SDL_BUTTON_LEFT) {
        int x = event.button.x;
        int y = event.button.y;
        SDL_Rect startBtnRect;
        SDL_QueryTexture(StartBtnTexture, NULL, NULL, &startBtnRect.w, &startBtnRect.h);
        startBtnRect.x = (800 - startBtnRect.w) / 2;
        startBtnRect.y = (600 - startBtnRect.h) / 3.5;
        SDL_Rect quitBtnRect;
        SDL_QueryTexture(QuitBtnTexture, NULL, NULL, &quitBtnRect.w, &quitBtnRect.h);
        quitBtnRect.x = (800 - quitBtnRect.w) / 2;
        quitBtnRect.y = (600 - quitBtnRect.h) / 2.25;
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

int handleEnd(SDL_Renderer* renderer) {
    initEndTextures(renderer);

    if (!BgTexture || !StartBtnTexture || !QuitBtnTexture) {
        printf("Erreur lors du chargement des images du menu principal.\n");
        return -1;
    }

    SDL_Event event;
    bool running = true;
    while (running) {
        while (SDL_PollEvent(&event)) {
            endScreen(renderer);
            int clickResult = 0;
            switch (event.type) {
            case SDL_QUIT:
                running = false;
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

    SDL_DestroyTexture(BgTexture);
    SDL_DestroyTexture(StartBtnTexture);
    SDL_DestroyTexture(QuitBtnTexture);
    return 0;
}
