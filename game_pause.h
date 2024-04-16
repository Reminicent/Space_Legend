#ifndef GAME_PAUSE_H_INCLUDED
#define GAME_PAUSE_H_INCLUDED

#include <SDL.h>

class PauseMenu {
public:
    PauseMenu(SDL_Renderer* renderer);
    ~PauseMenu();

    void handleInput(SDL_Event& e);
    void update();
    void render();
    bool isGamePaused();
    bool backToMainMenu();

private:
    SDL_Renderer* renderer;
    SDL_Rect continueButtonRect;
    SDL_Rect mainMenuButtonRect;
    bool gamePaused;
    bool goToMainMenu;
};


#endif // GAME_PAUSE_H_INCLUDED
