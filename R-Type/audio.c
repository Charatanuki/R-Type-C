#include <SDL.h>
#include <stdio.h>
#include <stdlib.h>
#include <SDL_mixer.h>
#include "audio.h"

//Permet de manipuler la musique
Mix_Music* music = NULL;

//msg d'erreur pour l'init de l'audio
void initAudio() {
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
    {
        printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
    }
}
void loadbgmusic() {
    music = Mix_LoadMUS("/music.mp3");
    if (music = NULL) {
        printf("Failed to load background musicSDL_mixer Error: %s\n", Mix_GetError());
    }
}
void playbgmusic() {
    if (Mix_PlayingMusic() == 0 && music != NULL) {
        Mix_PlayMusic(music, -1);
    }
}
void stopbgmusic() {
    Mix_HaltMusic();
}
void cleanupAudio() {
    Mix_FreeMusic(music);
    Mix_CloseAudio();
}