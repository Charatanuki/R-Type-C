#include "audio.h"

//Permet de manipuler la musique
Mix_Chunk* music = NULL;

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

void playbgmusic(Option option) {
    if (music != NULL) {
        Mix_VolumeChunk(music, option.musicVolume);
        Mix_PlayChannel(-1, music, -1); //-1 sert à prendre le 1er canal dispo pour jouer
        //le 2eme -1 sert à repeat infini tant que ça stop pas manuellement
    }
}

void stopbgmusic() {
    Mix_HaltMusic();
}

void cleanupAudio() {
    Mix_FreeChunk(music);
    Mix_CloseAudio();
}