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
    gameOverRect.h = 700;
}
void GameOver::load_gameovermusic()
{
      if(!gameovermusicPlayed)
      {
      Mix_HaltMusic();
      gameovermusic = Mix_LoadMUS("gameovermusic.mp3");
      Mix_PlayMusic(gameovermusic, -1);
      gameovermusicPlayed = true;
      }
}
void GameOver::setting_music()
{
    gameovermusicPlayed = false;
}
void GameOver::setting_option(SDL_Renderer* renderer)
{
    SDL_Surface* again_surface = IMG_Load("again_button.png");
    againTexture = SDL_CreateTextureFromSurface(renderer, again_surface);
    SDL_FreeSurface(again_surface);

    SDL_Surface* menu_surface = IMG_Load("menu_button.png");
    menuTexture = SDL_CreateTextureFromSurface(renderer, menu_surface);
    SDL_FreeSurface(again_surface);

    SDL_Surface* quit_surface = IMG_Load("quit_button.png");
    quitTexture = SDL_CreateTextureFromSurface(renderer, quit_surface);
    SDL_FreeSurface(quit_surface);

}
void GameOver::destroy_menu()
{
     SDL_DestroyTexture(againTexture);
     SDL_DestroyTexture(menuTexture);
     SDL_DestroyTexture(quitTexture);
}
void GameOver::render_menu(SDL_Renderer* renderer)
{
    againButtonRect = { 450, 750, 200, 100 };
    menuButtonRect = { 700, 750, 200, 100 };
    quitButtonRect = { 950, 750, 200, 100 };

    SDL_RenderCopy(renderer, againTexture, NULL, &againButtonRect);
    SDL_RenderCopy(renderer, menuTexture, NULL, &menuButtonRect);
    SDL_RenderCopy(renderer, quitTexture, NULL, &quitButtonRect);
}
bool GameOver::handleEvent(SDL_Event& e) {
    in_Wave1=false;
    if (e.type == SDL_MOUSEBUTTONDOWN) {
        int x,y;
        SDL_GetMouseState(&x, &y);
        if (x>=450&&x<=650&&y>=750&&y<=850) {
            in_Wave1=true;
        } else if (x>=700&&x<=900&&y>=750&&y<=850) {
            return true;
        } else if (x>=950&&x<=1150&&y>=750&&y<=850) {SDL_Quit();    return 0;
        }
    }
    return false;
}

void GameOver::render(SDL_Renderer* renderer) {
    if (gameOverTexture) {
        SDL_RenderCopy(renderer, gameOverTexture, nullptr, &gameOverRect);
    }
}

bool GameOver::return_wave_1()
{
    return in_Wave1;
}
