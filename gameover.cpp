#include "gameover.h"
#include <bits/stdc++.h>

GameOver::GameOver() : gameOverTexture(nullptr) {}

GameOver::~GameOver() {
    if (gameOverTexture != nullptr) {
        SDL_DestroyTexture(gameOverTexture);
        gameOverTexture = nullptr;
    }
}

void GameOver::init(SDL_Renderer* renderer) {
    SDL_Surface* gameOverSurface = IMG_Load("gameover.png");
    if (!gameOverSurface) {
        std::cerr << "Failed to load game over image: " << IMG_GetError() << std::endl;
        return;
    }

    gameOverTexture = SDL_CreateTextureFromSurface(renderer, gameOverSurface);
    SDL_FreeSurface(gameOverSurface);

    if (!gameOverTexture) {
        std::cerr << "Failed to create texture from game over surface: " << SDL_GetError() << std::endl;
        return;
    }

    gameOverRect.x = 0;
    gameOverRect.y = 0;
    gameOverRect.w = 1600;
    gameOverRect.h = 900;
}
void GameOver::load_gameovermusic()
{
      Mix_HaltMusic();
      gameovermusic = Mix_LoadMUS("gameovermusic.mp3");
      Mix_PlayMusic(gameovermusic, -1);
}

void GameOver::render(SDL_Renderer* renderer) {
    if (gameOverTexture) {
        SDL_RenderCopy(renderer, gameOverTexture, nullptr, &gameOverRect);
    }
}
