#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>
#include <stdbool.h>
#include "menu.h"
#include "HeaderFunction.h"

void Menu(SDL_Renderer* renderer,
    SDL_Texture* BgTexture,
    SDL_Texture* StartBtnTexture,
    SDL_Texture* OptionBtnTexture,
    SDL_Texture* QuitBtnTexture)
{
    // Affiche le fond du menu principal
    SDL_RenderCopy(renderer, BgTexture, NULL, NULL);

    // Affiche le bouton "Start" au milieu de l'écran
    SDL_Rect btnRect;
    SDL_QueryTexture(StartBtnTexture, NULL, NULL, &btnRect.w, &btnRect.h);
    btnRect.x = (800 - btnRect.w) / 2;
    btnRect.y = (600 - btnRect.h) / 3;
    SDL_RenderCopy(renderer, StartBtnTexture, NULL, &btnRect);

    // Affiche le bouton "Option" au milieu de l'écran
    SDL_Rect optionBtnRect;
    SDL_QueryTexture(OptionBtnTexture, NULL, NULL, &optionBtnRect.w, &optionBtnRect.h);
    optionBtnRect.x = (800 - optionBtnRect.w) / 2;
    optionBtnRect.y = (600 - optionBtnRect.h) / 2;
    SDL_RenderCopy(renderer, OptionBtnTexture, NULL, &optionBtnRect);

    // Affiche le bouton "Quitter" en bas de l'écran
    SDL_Rect quitBtnRect;
    SDL_QueryTexture(QuitBtnTexture, NULL, NULL, &quitBtnRect.w, &quitBtnRect.h);
    quitBtnRect.x = (800 - quitBtnRect.w) / 2;
    quitBtnRect.y = (600 - quitBtnRect.h) / 1.5;
    SDL_RenderCopy(renderer, QuitBtnTexture, NULL, &quitBtnRect);

    // Met à jour l'affichage
    SDL_RenderPresent(renderer);
}

bool isInsideButton(SDL_Rect btnRect, int x, int y) {
    return (x >= btnRect.x && x <= btnRect.x + btnRect.w &&
        y >= btnRect.y && y <= btnRect.y + btnRect.h);
}

int handleMainMenu(SDL_Renderer* renderer) {
    // Charge les images du fond et du bouton "Start"
    SDL_Texture* BgTexture = loadTexture(renderer, "./start_screen.png");
    SDL_Texture* StartBtnTexture = loadTexture(renderer, "./btn/play_btn.png");
    SDL_Texture* OptionBtnTexture = loadTexture(renderer, "./btn/optn_btn.png");
    SDL_Texture* QuitBtnTexture = loadTexture(renderer, "./btn/quit_btn.png");

    if (!BgTexture || !StartBtnTexture || !OptionBtnTexture || !QuitBtnTexture) {
        printf("Erreur lors du chargement des images du menu principal.\n");
        return -1;
    }

    SDL_Event event;
    bool running = true;
    SDL_Rect startBtnRect = { 0, 0, 0, 0 };
    SDL_QueryTexture(StartBtnTexture, NULL, NULL, &(startBtnRect.w), &(startBtnRect.h));
    startBtnRect.x = (800 - startBtnRect.w) / 2;
    startBtnRect.y = (600 - startBtnRect.h) / 3;

    SDL_Rect optionBtnRect;
    SDL_QueryTexture(OptionBtnTexture, NULL, NULL, &optionBtnRect.w, &optionBtnRect.h);
    optionBtnRect.x = (800 - optionBtnRect.w) / 2;
    optionBtnRect.y = (600 - optionBtnRect.h) / 2;

    SDL_Rect quitBtnRect;
    SDL_QueryTexture(QuitBtnTexture, NULL, NULL, &quitBtnRect.w, &quitBtnRect.h);
    quitBtnRect.x = (800 - quitBtnRect.w) / 2;
    quitBtnRect.y = (600 - quitBtnRect.h) / 1.5;
    while (running) {
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_MOUSEBUTTONDOWN:
                if (event.button.button == SDL_BUTTON_LEFT) {
                    int x = event.button.x;
                    int y = event.button.y;

                    // Affiche le menu principal
                    Menu(renderer, BgTexture,
                        StartBtnTexture, OptionBtnTexture, QuitBtnTexture);

                    if (isInsideButton(startBtnRect, x, y)) {
                        running = false; // Arrête le menu principal
                        // Retourne PLAYING pour démarrer le jeu
                        return PLAY;
                    }
                    else if (isInsideButton(optionBtnRect, x, y)) {
                        running = false; // option du jeu
                        return OPTION;
                    }
                    else if (isInsideButton(quitBtnRect, x, y)) {
                        running = false; // Quitte le jeu
                        return QUIT;
                    }
                }
                break;            
            case SDL_QUIT:
                running = false;
                break;
            }
        }
    }

    // Libère la mémoire utilisée par les textures
    SDL_DestroyTexture(BgTexture);
    SDL_DestroyTexture(StartBtnTexture);
    SDL_DestroyTexture(QuitBtnTexture);
    return 0;
}