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
    void setting_music();

    void setting_option(SDL_Renderer* renderer);
    bool handleEvent(SDL_Event& e);
    void render_menu(SDL_Renderer* renderer);
    void destroy_menu();
    bool return_wave_1();

private:
    Mix_Music* gameovermusic;
    SDL_Texture* gameOverTexture;
    SDL_Rect gameOverRect;
    bool gameovermusicPlayed = false;
    bool in_Wave1 =false;

    SDL_Texture* againTexture;
    SDL_Texture* menuTexture;
    SDL_Texture* quitTexture;

    SDL_Rect againButtonRect;
    SDL_Rect menuButtonRect;
    SDL_Rect quitButtonRect;

};

#endif // GAMEOVER_H_INCLUDED
