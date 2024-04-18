#include "game_pause.h"

PauseMenu::PauseMenu(){}
void PauseMenu::create_pausemenu(SDL_Renderer* renderer) {
    SDL_Surface* continue_surface = IMG_Load("continue_button.png");
    SDL_Surface* exit_surface = IMG_Load("exit_button.png");

    continueTexture = SDL_CreateTextureFromSurface(renderer, continue_surface);
    SDL_FreeSurface(continue_surface);
    exitTexture = SDL_CreateTextureFromSurface(renderer, exit_surface);
    SDL_FreeSurface(exit_surface);

    continueButtonRect = { 700, 400, 200, 100 };
    exitButtonRect = { 700, 550, 200, 100 };

    this -> renderer = renderer;
    gamePaused = false;
    goToMainMenu = false;
}

PauseMenu::~PauseMenu() {}

void PauseMenu::handleInput(SDL_Event& e) {
    if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) {
        gamePaused = true;
    }
    if (e.type == SDL_MOUSEBUTTONDOWN) {
        int x, y;
        SDL_GetMouseState(&x, &y);
        if (x >= continueButtonRect.x && x <= continueButtonRect.x + continueButtonRect.w &&
            y >= continueButtonRect.y && y <= continueButtonRect.y + continueButtonRect.h) {
            gamePaused = false;
        } else if (x >= exitButtonRect.x && x <= exitButtonRect.x + exitButtonRect.w &&
                   y >= exitButtonRect.y && y <= exitButtonRect.y + exitButtonRect.h) {
            goToMainMenu = true;
        }
    }
}

void PauseMenu::update() {
}
void PauseMenu::render() {
    if (gamePaused) {
        SDL_RenderCopy(renderer, continueTexture, NULL, &continueButtonRect);
        SDL_RenderCopy(renderer, exitTexture, NULL, &exitButtonRect);
    }
}

bool PauseMenu::isGamePaused() {
    return gamePaused;
}

bool PauseMenu::backToMainMenu() {
    bool goToMainMenu1 = goToMainMenu;
    goToMainMenu = false;
    return goToMainMenu1;
}
void PauseMenu::Destroy_pause()
{
    SDL_DestroyTexture(continueTexture);
    continueTexture = nullptr;
    SDL_DestroyTexture(exitTexture);
    exitTexture = nullptr;
}
