#ifndef INSTRUCTIONS_MUSIC_H_INCLUDED
#define INSTRUCTIONS_MUSIC_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

class InstructionsMusic {
public:
    InstructionsMusic();
    ~InstructionsMusic();

    bool loadMusic(const char* path);
    void play(Mix_Music* music);
    void stop(Mix_Music* music);

private:
    Mix_Music* music;
};

#endif // INSTRUCTIONS_MUSIC_H_INCLUDED
