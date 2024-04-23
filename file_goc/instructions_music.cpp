#include "instructions_music.h"

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

InstructionsMusic::InstructionsMusic() {
    music = nullptr;
}

InstructionsMusic::~InstructionsMusic() {
    if (music) {
        Mix_FreeMusic(music);
        music = nullptr;
    }
}

bool InstructionsMusic::loadMusic(const char* path) {
    music = Mix_LoadMUS(path);
    if (!music) {
        return false;
    }
    return true;
}

void InstructionsMusic::play(Mix_Music* music) {
    Mix_PlayMusic(music, -1);
}

void InstructionsMusic::stop(Mix_Music* music) {
    Mix_HaltMusic();
}
