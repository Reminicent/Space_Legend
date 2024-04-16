#include "game_pause.h"

PauseMenu::PauseMenu(SDL_Renderer* renderer) : renderer(renderer), gamePaused(false), goToMainMenu(false) {
    continueButtonRect = { 100, 100, 200, 50 };
    mainMenuButtonRect = { 100, 200, 200, 50 };
}

PauseMenu::~PauseMenu() {}

void PauseMenu::handleInput(SDL_Event& e) {
    if (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE) {
        gamePaused = !gamePaused;
    }
    if (e.type == SDL_MOUSEBUTTONDOWN) {
        int x, y;
        SDL_GetMouseState(&x, &y);
        if (x >= continueButtonRect.x && x <= continueButtonRect.x + continueButtonRect.w &&
            y >= continueButtonRect.y && y <= continueButtonRect.y + continueButtonRect.h) {
            gamePaused = false;
        } else if (x >= mainMenuButtonRect.x && x <= mainMenuButtonRect.x + mainMenuButtonRect.w &&
                   y >= mainMenuButtonRect.y && y <= mainMenuButtonRect.y + mainMenuButtonRect.h) {
            goToMainMenu = true;
        }
    }
}

void PauseMenu::update() {
}

void PauseMenu::render() {
    if (gamePaused) {
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderFillRect(renderer, &continueButtonRect);
        SDL_RenderFillRect(renderer, &mainMenuButtonRect);
    }
}

bool PauseMenu::isGamePaused() {
    return gamePaused;
}

bool PauseMenu::backToMainMenu() {
    return goToMainMenu;
}
