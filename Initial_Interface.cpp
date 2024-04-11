#include "Initial_Interface.h"
#include "instructions_music.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <bits/stdc++.h>


MainMenu::MainMenu(SDL_Renderer* renderer) : renderer(renderer) {
    SDL_Surface* play_surface = IMG_Load("play_button.png");
    SDL_Surface* instructions_surface = IMG_Load("instructions_button.png");
    SDL_Surface* quit_surface = IMG_Load("quit_button.png");

    playTexture = SDL_CreateTextureFromSurface(renderer, play_surface);
    SDL_FreeSurface(play_surface);
    instructionsTexture = SDL_CreateTextureFromSurface(renderer, instructions_surface);
    SDL_FreeSurface(instructions_surface);
    quitTexture = SDL_CreateTextureFromSurface(renderer, quit_surface);
    SDL_FreeSurface(quit_surface);

}

MainMenu::~MainMenu() {
    SDL_DestroyTexture(playTexture);
    SDL_DestroyTexture(instructionsTexture);
    SDL_DestroyTexture(quitTexture);
}


void MainMenu::render(SDL_Renderer* renderer) {

    playButtonRect = { 700, 400, 200, 100 };
    instructionsButtonRect = { 700, 550, 200, 100 };
    quitButtonRect = { 700, 700, 200, 100 };

    SDL_RenderCopy(renderer, playTexture, NULL, &playButtonRect);
    SDL_RenderCopy(renderer, instructionsTexture, NULL, &instructionsButtonRect);
    SDL_RenderCopy(renderer, quitTexture, NULL, &quitButtonRect);

}

bool MainMenu::handleEvent(SDL_Event& e) {
    if (e.type == SDL_MOUSEBUTTONDOWN) {
        int x, y;
        SDL_GetMouseState(&x, &y);
        SDL_Point clickPoint = {x, y};
        if (SDL_PointInRect(&clickPoint, &playButtonRect)) {
            return true;
        } else if (SDL_PointInRect(&clickPoint, &instructionsButtonRect)) {
            Mix_Music* backgroundmusic1;    bool instruction_musicPlayed ;    Mix_Music* instruction_music;
            //bool instruction_musicPlayed;
            InstructionsMusic instructionsmusic;
            instruction_music = Mix_LoadMUS("instructions_music.mp3");
            if (!instruction_musicPlayed) {
                      instructionsmusic.stop(backgroundmusic1);
                      instructionsmusic.play(instruction_music);
                      instruction_musicPlayed = true;
            }
        } else if (SDL_PointInRect(&clickPoint, &quitButtonRect)) {SDL_Quit();    return 0;
        }
    }
    return false;
}
