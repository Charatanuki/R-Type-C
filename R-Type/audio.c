#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL_mixer.h>
#include "audio.h"

//Permet de manipuler la musique
Mix_Chunk* music = NULL;
int musicPlaying = 0;

//msg d'erreur pour l'init de l'audio
void initAudio() {
    if (Mix_OpenAudio(44100, AUDIO_F32SYS, 2, 2048) < 0)
    {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
    }
}

void loadbgmusic() {
    music = Mix_LoadWAV("./music.wav");
    if (music == NULL) {
        printf("Failed to load background musicSDL_mixer Error: %s\n", Mix_GetError());
    }
}

void playbgmusic() {
    if (music != NULL && musicPlaying == 0) {
        Mix_VolumeChunk(music, 32);
        Mix_PlayChannel(-1, music, -1);
        musicPlaying = 1;
    }
}

void stopbgmusic() {
    Mix_HaltMusic();
}

void cleanupAudio() {
    Mix_FreeChunk(music);
    Mix_CloseAudio();
}