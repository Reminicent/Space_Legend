#ifndef BACKGROUND_MUSIC_H_INCLUDED
#define BACKGROUND_MUSIC_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

class BackgroundMusic {
public:
    BackgroundMusic();
    ~BackgroundMusic();

    bool loadMusic(const char* path);
    void play(Mix_Music* music);
    void stop(Mix_Music* music);

private:
    Mix_Music* music;
};


#endif // BACKGROUND_MUSIC_H_INCLUDED

