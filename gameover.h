#ifndef GAMEOVER_H_INCLUDED
#define GAMEOVER_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

class GameOver {
public:
    GameOver();
    ~GameOver();

    void init(SDL_Renderer* renderer);
    void render(SDL_Renderer* renderer);
    void load_gameovermusic();

private:
    Mix_Music* gameovermusic;
    SDL_Texture* gameOverTexture;
    SDL_Rect gameOverRect;
};

#endif // GAMEOVER_H_INCLUDED
