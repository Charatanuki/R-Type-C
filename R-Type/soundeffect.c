#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL_mixer.h>
#include "soundeffect.h"

//Permet de manipuler les sounds effects
Mix_Chunk* boom = NULL; //explosion
Mix_Chunk* pew = NULL; //tirs


void loadshootsound() {
    pew = Mix_LoadWAV("../pew.mp3");
    if (pew == NULL) {
        printf("Failed to load ship shoot sound! SDL_mixer Error: %s\n", Mix_GetError());
    }
}
void playshootsound() {
    if (pew != NULL) {
        Mix_PlayChannel(-1, pew, 0);
    }
}
void loaddestroysound() {
    boom = Mix_LoadWAV("boom.mp3");
    if (boom == NULL) {
        printf("Failed to load enemy destroy sound! SDL_mixer Error: %s\n", Mix_GetError());
    }
}
void playdestroysound() {
    if (boom != NULL) {
        Mix_PlayChannel(-1, boom, 0);
    }
}
void cleanupSoundeffect() {
	Mix_FreeChunk(pew);
	Mix_FreeChunk(boom);
}