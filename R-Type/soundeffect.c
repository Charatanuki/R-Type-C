#include "soundeffect.h"


//Permet de manipuler les sounds effects
Mix_Chunk* boom = NULL; //explosion
Mix_Chunk* pew = NULL; //tirs


void loadshootsound() {
    pew = Mix_LoadWAV("./sfx/pew.wav");
    if (pew == NULL) {
        printf("Failed to load shoot sound! SDL_mixer Error: %s\n", 
            Mix_GetError());
    }
}

void playshootsound(Option option) {
    if (pew != NULL) {
        Mix_VolumeChunk(pew, option.soundVolume);
        Mix_PlayChannel(-1, pew, 0); 
        //0 sert à jouer 1x le son (ne loop pas)
    }
}

void loaddestroysound() {
    boom = Mix_LoadWAV("./sfx/boom.wav");
    if (boom == NULL) {
        printf("Failed to load enemy destroy sound! SDL_mixer Error: %s\n", 
            Mix_GetError());
    }
}

void playdestroysound(Option option) {
    if (boom != NULL) {
        Mix_VolumeChunk(boom, option.soundVolume * 3);
        Mix_PlayChannel(-1, boom, 0);
    }
}

void cleanupSoundeffect() {
	Mix_FreeChunk(pew);
	Mix_FreeChunk(boom);
}