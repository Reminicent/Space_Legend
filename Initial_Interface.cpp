#include "Initial_Interface.h"
#include "instructions_music.h"

SDL_Texture* creditTexture;
SDL_Texture* highscoreTexture;
Mix_Music* instruction_music;
Mix_Music* credit_music ;
Mix_Music* highscore_music;
InstructionsMusic instructionsmusic;
SDL_Point clickPoint;

MainMenu::MainMenu(){}
void MainMenu::Create_MainMenu(SDL_Renderer* renderer){
    SDL_Surface* play_surface = IMG_Load("play_button.png");
    playTexture = SDL_CreateTextureFromSurface(renderer, play_surface);
    SDL_FreeSurface(play_surface);

    SDL_Surface* instructions_surface = IMG_Load("instructions_button.png");
    instructionsTexture = SDL_CreateTextureFromSurface(renderer, instructions_surface);
    SDL_FreeSurface(instructions_surface);

    SDL_Surface* quit_surface = IMG_Load("quit_button.png");
    quitTexture = SDL_CreateTextureFromSurface(renderer, quit_surface);
    SDL_FreeSurface(quit_surface);

    SDL_Surface* credit_surface= IMG_Load("credit_button.png");
    creditTexture = SDL_CreateTextureFromSurface(renderer, credit_surface);
    SDL_FreeSurface(credit_surface);

    credit_surface = IMG_Load("highscore_button.png");
    highscoreTexture = SDL_CreateTextureFromSurface(renderer, credit_surface);
    SDL_FreeSurface(credit_surface);

    instruction_music = Mix_LoadMUS("instructions_music.mp3");
    credit_music = Mix_LoadMUS("credit_music.mp3");
    highscore_music = Mix_LoadMUS("highscore_music.mp3");
}

void MainMenu::Destroy_MainMenu() {
    SDL_DestroyTexture(playTexture);
    SDL_DestroyTexture(instructionsTexture);
    SDL_DestroyTexture(quitTexture);
    SDL_DestroyTexture(creditTexture);
    SDL_DestroyTexture(highscoreTexture);

    instruction_music = nullptr;
    credit_music = nullptr;
    highscore_music = nullptr;
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
    SDL_RenderCopy(renderer, highscoreTexture, NULL, &highscoreButtonRect);

}

bool MainMenu::handleEvent(SDL_Event& e) {
    if (e.type == SDL_MOUSEBUTTONDOWN) {
        int x, y;
        SDL_GetMouseState(&x, &y);
        if (x>=700&&x<=900&&y>=400&&y<=500) {
            return true;
        } else if (x>=700&&x<=900&&y>=550&&y<=650) {
            bool instruction_musicPlayed ;
            if (!instruction_musicPlayed) {
                      Mix_HaltMusic();
                      instructionsmusic.play(instruction_music);
                      instruction_musicPlayed = true;
            }
        } else if (x>=700&&x<=900&&y>=700&&y<=800) {SDL_Quit();    return 0;
        } else if (x>=450&&x<=650&&y>=550&&y<=650){
            bool credit_musicPlayed = false;
            if (!credit_musicPlayed) {
                      Mix_HaltMusic();
                      Mix_PlayMusic(credit_music,-1);
                      credit_musicPlayed = true;
            }
        }else if (x>=950&&x<=1150&&y>=550&&y<=650){
            bool highscore_musicPlayed = false;
            if (!highscore_musicPlayed) {
                      Mix_HaltMusic();
                      Mix_PlayMusic(highscore_music,-1);
                      highscore_musicPlayed = true;
            }
        }
    }
    return false;
}
