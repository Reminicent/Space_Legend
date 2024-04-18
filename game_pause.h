#ifndef GAME_PAUSE_H_INCLUDED
#define GAME_PAUSE_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>

class PauseMenu {
public:
    PauseMenu();
    ~PauseMenu();

    void create_pausemenu(SDL_Renderer* renderer);
    void handleInput(SDL_Event& e);
    void update();
    void render();
    bool isGamePaused();
    bool backToMainMenu();
    void Destroy_pause();

private:
    bool gamePaused;
    SDL_Renderer* renderer;
    SDL_Texture* continueTexture;
    SDL_Texture* exitTexture;
    SDL_Rect exitButtonRect;
    SDL_Rect continueButtonRect;
    bool goToMainMenu;
};


#endif // GAME_PAUSE_H_INCLUDED

