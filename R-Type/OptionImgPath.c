#include "option.h"

char* getPath(int optionType, int value) {
    if (optionType == 0) {
        if (value == 0)
            return "./images/btn/Music_OFF_btn.png";
        return "./images/btn/Music_ON_btn.png";
    }
    if (value == 0)
        return "./images/btn/SFX_OFF_btn.png";
    return "./images/btn/SFX_ON_btn.png";
}

void destroyOptText() {
    SDL_DestroyTexture(SFXTexture);
    SDL_DestroyTexture(musicTexture);
    SDL_DestroyTexture(returnTexture);
}