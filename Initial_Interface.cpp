#include "Initial_Interface.h"
#include "instructions_music.h"
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <bits/stdc++.h>

MainMenu::MainMenu(){}
void MainMenu::Create_MainMenu(SDL_Renderer* renderer){
    SDL_Surface* play_surface = IMG_Load("play_button.png");
    playTexture = SDL_CreateTextureFromSurface(renderer, play_surface);
    SDL_FreeSurface(play_surface);
    //play_surface=nullptr;

    SDL_Surface* instructions_surface = IMG_Load("instructions_button.png");
    instructionsTexture = SDL_CreateTextureFromSurface(renderer, instructions_surface);
    SDL_FreeSurface(instructions_surface);
    //instructions_surface = NULL;

    SDL_Surface* quit_surface = IMG_Load("quit_button.png");
    quitTexture = SDL_CreateTextureFromSurface(renderer, quit_surface);
    SDL_FreeSurface(quit_surface);

    SDL_Surface* credit_surface= IMG_Load("credit_button.png");
    creditTexture = SDL_CreateTextureFromSurface(renderer, credit_surface);
    SDL_FreeSurface(credit_surface);

    //credit_surface = IMG_Load("highscore_button.png");
    //creditTexture[2] = SDL_CreateTextureFromSurface(renderer, credit_surface);
    //SDL_FreeSurface(credit_surface);

}

void MainMenu::Destroy_MainMenu() {
    SDL_DestroyTexture(playTexture);
    SDL_DestroyTexture(instructionsTexture);
    SDL_DestroyTexture(quitTexture);
    SDL_DestroyTexture(creditTexture);
    //SDL_DestroyTexture(creditTexture[2]);
    //SDL_DestroyTexture(highscoreTexture);
}


void MainMenu::render(SDL_Renderer* renderer) {

    playButtonRect = { 700, 400, 200, 100 };

    instructionsButtonRect = { 700, 550, 200, 100 };
    creditButtonRect = { 450, 550, 200, 100 };
    highscoreButtonRect = { 950, 550, 200, 100 };

    quitButtonRect = { 700, 700, 200, 100 };

    SDL_RenderCopy(renderer, playTexture, NULL, &playButtonRect);
    SDL_RenderCopy(renderer, instructionsTexture, NULL, &instructionsButtonRect);
    SDL_RenderCopy(renderer, quitTexture, NULL, &quitButtonRect);
    SDL_RenderCopy(renderer, creditTexture, NULL, &creditButtonRect);
    //SDL_RenderCopy(renderer, creditTexture[2], NULL, &highscoreButtonRect);
    //SDL_RenderCopy(renderer, highscoreTexture, NULL, &highscoreButtonRect);

}

bool MainMenu::handleEvent(SDL_Event& e) {
    if (e.type == SDL_MOUSEBUTTONDOWN) {
        int x, y;
        SDL_GetMouseState(&x, &y);
        SDL_Point clickPoint = {x, y};
        if (SDL_PointInRect(&clickPoint, &playButtonRect)) {
            return true;
        } else if (SDL_PointInRect(&clickPoint, &instructionsButtonRect)) {
            bool instruction_musicPlayed ;    Mix_Music* instruction_music;
            InstructionsMusic instructionsmusic;
            instruction_music = Mix_LoadMUS("instructions_music.mp3");
            if (!instruction_musicPlayed) {
                      instructionsmusic.play(instruction_music);
                      instruction_musicPlayed = true;
            }
        } else if (SDL_PointInRect(&clickPoint, &quitButtonRect)) {SDL_Quit();    return 0;
        } else if (SDL_PointInRect(&clickPoint, &creditButtonRect)){
            bool credit_musicPlayed = false;    Mix_Music* credit_music ;
            credit_music = Mix_LoadMUS("credit_music.flac");
            if (!credit_musicPlayed) {
                      Mix_PlayMusic(credit_music,-1);
                      credit_musicPlayed = true;
            }
        }else if (SDL_PointInRect(&clickPoint, &highscoreButtonRect)){
            bool highscore_musicPlayed = false;    Mix_Music* highscore_music;
            highscore_music = Mix_LoadMUS("highscore_music.mp3");
            if (!highscore_musicPlayed) {
                      Mix_HaltMusic();
                      Mix_PlayMusic(highscore_music,-1);
                      highscore_musicPlayed = true;
            }
        }
    }
    return false;
}
