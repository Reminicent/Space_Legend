#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <bits/stdc++.h>
#include <vector>

#include "spaceship_bullet_1.h"
#include "spaceship_moving.h"
#include "Wave1_create.h"
#include "Background.h"
#include "Inital_Interface.h"
#include "Background_music.h"
#include "instructions_music.h"
#include "global_variable.h"

const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT = 900;

//int spaceship_x = 800,spaceship_y=660, spaceship_size=100, spaceship_HP = 1000;
//int bullet_x = (2*spaceship_x+spaceship_size)/2, bullet_size = spaceship_size;   float bullet_y = (float)spaceship_y-spaceship_size/2, bullet_damage = 100;  float bullet_speed = 0.5;
int enemyshipX[27] ,enemyshipY[27]; //enemyshipSize = 120, enemyship_HP = 1000;
//std::vector<EnemyShip> Wave1ship;
int i;
//bool inMenu = true,ingame=false;
//bool backgroundMusic2Played = false;

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Chiến cơ huyền thoại", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    IMG_Init(IMG_INIT_PNG);

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 4, 2048) < 0) {
       std::cerr << "SDL_mixer could not initialize! SDL_Error: " << Mix_GetError() << std::endl;
        return 1;
    }
    BackgroundMusic backgroundMusic;
    Mix_Music* backgroundnusic1 = Mix_LoadMUS("background_music1.flac");
    Mix_Music* backgroundnusic2 = Mix_LoadMUS("background_music2.mp3");
    backgroundMusic.play(backgroundnusic1);
    Background background(renderer, "Background.png");
    MainMenu mainmenu(renderer);
    Spaceship spaceship(renderer, "Ship5.png",spaceship_x,spaceship_y, spaceship_size, spaceship_size, spaceship_HP);
    spaceship.setScreenSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    Bullet bullet1(renderer, "Bullet5.png", bullet_x, bullet_y ,bullet_size, bullet_size,bullet_damage, bullet_speed);

    for(i=1;i<=9;i++){
    enemyshipX[i]=30+180*(i-1);     enemyshipY[i]=15;
    EnemyShip::create_enemyship_position(renderer, "Ship3.png",enemyshipX[i],enemyshipY[i],enemyshipSize);
    }

    bool quit = false;
    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
             if (event.type == SDL_QUIT) {
                  quit = true;
            } else if (inMenu) {
                if(mainmenu.handleEvent(event)) {
                    inMenu = false;
               }
             } else {
               if (!backgroundMusic2Played) {
                      backgroundMusic.stop(backgroundnusic1);
                      backgroundMusic.play(backgroundnusic2);
                      backgroundMusic2Played = true;
              }
               spaceship.handleEvent(event);
             }
        }
        SDL_RenderClear(renderer);
        background.render();
        if (inMenu) {
        mainmenu.render(renderer);
        } else {
        spaceship.render(renderer);
        spaceship_x=spaceship.updateX();    spaceship_y=spaceship.updateY();
        bullet1.get_spaceship_static(spaceship_x, spaceship_y);
        bullet1.handleEvent(event);
        bullet1.render(renderer);
        for (auto& Wave1s : Wave1ship) {
            Wave1s.update();
            Wave1s.render(renderer);
        }
        }
        SDL_RenderPresent(renderer);
    }

    Mix_CloseAudio();
    IMG_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
