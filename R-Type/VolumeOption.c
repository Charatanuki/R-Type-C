#include "option.h"


int musicVolumeOpt(Option* option) {
    if (option->musicVolume == 0) {
        option->musicVolume = 32;
    }
    else option->musicVolume = 0;
}

int soundVolumeOpt(Option* option) {
    if (option->soundVolume == 0) {
        option->soundVolume = 32;
    }
    else option->soundVolume = 0;
}