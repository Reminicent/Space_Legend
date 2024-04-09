#include "Background_music.h"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

BackgroundMusic::BackgroundMusic() {
    music = nullptr;
}

BackgroundMusic::~BackgroundMusic() {
    if (music) {
        Mix_FreeMusic(music);
        music = nullptr;
    }
}

bool BackgroundMusic::loadMusic(const char* path) {
    music = Mix_LoadMUS(path);
    if (!music) {
        return false;
    }
    return true;
}

void BackgroundMusic::play(Mix_Music* music) {
    Mix_PlayMusic(music, -1);
}

void BackgroundMusic::stop(Mix_Music* music) {
    Mix_HaltMusic();
}

