#include <SDL.h>
#include <SDL_image.h>
#include <bits/stdc++.h>
#include "spaceship_bullet_1.h"
#include "spaceship_moving.h"
#include "Wave1_create.h"

const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT = 900;

int spaceship_x = 800,spaceship_y=660, spaceship_size=100, spaceship_HP = 1000;
int bullet_x = (2*spaceship_x+spaceship_size)/2, bullet_size = spaceship_size;   float bullet_y = (float)spaceship_y-spaceship_size/2, bullet_damage = 100;  float bullet_speed = 0.5;


int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Spaceship_moving", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    IMG_Init(IMG_INIT_PNG);

    Spaceship spaceship(renderer, "Ship5.png",spaceship_x,spaceship_y, spaceship_size, spaceship_size, spaceship_HP);
    spaceship.setScreenSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    Bullet bullet1(renderer, "Bullet5.png", bullet_x, bullet_y ,bullet_size, bullet_size,bullet_damage, bullet_speed);
    EnemyShip enemyship1(renderer, "Ship3.png","Bullet3.png");
    enemyship1.setScreenSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    enemyship1.create_enemyship_position();

    bool quit = false;
    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            } else {
                spaceship.handleEvent(event);
            }
        }
        SDL_RenderClear(renderer);
        spaceship.render(renderer);

        spaceship_x=spaceship.updateX();    spaceship_y=spaceship.updateY();
        bullet1.get_spaceship_static(spaceship_x, spaceship_y);
        bullet1.handleEvent(event);
        bullet1.render(renderer);
        enemyship1.render(renderer);

        SDL_RenderPresent(renderer);
    }

    IMG_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
