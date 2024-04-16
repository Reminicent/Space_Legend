#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <SDL_ttf.h>
#include <bits/stdc++.h>
#include <vector>

#include "spaceship_bullet_1.h"
#include "spaceship_moving.h"
#include "Wave1_create.h"
#include "Background.h"
#include "Initial_Interface.h"
#include "Background_music.h"
#include "global_variable.h"
#include "spaceship_hp.h"
#include "score.h"
#include "gameover.h"
//#include "Wave1_attack.h"

const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT = 900;

int i,shipnum=27;
int spaceship_HP = 1000;     int current_spaceship_HP = 1000;

int main(int argc, char* argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    SDL_Window* window = SDL_CreateWindow("Chiến cơ huyền thoại", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    IMG_Init(IMG_INIT_PNG);

    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 4, 2048) < 0) {
       std::cerr << "SDL_mixer could not initialize! SDL_Error: " << Mix_GetError() << std::endl;
        return 1;
    }
    BackgroundMusic backgroundMusic;
    Mix_Music* backgroundmusic1 = Mix_LoadMUS("background_music1.flac");
    Mix_Music* backgroundmusic2 = Mix_LoadMUS("background_music2.mp3");
    backgroundMusic.play(backgroundmusic1);
    Background background(renderer, "Background.png");
    MainMenu mainmenu(renderer);
    //Score Score;

    Spaceship spaceship;
    spaceship.Create_Spaceship(renderer, "Ship5.png",spaceship_x,spaceship_y, spaceship_size, spaceship_size, spaceship_HP);
    spaceship.setScreenSize(SCREEN_WIDTH, SCREEN_HEIGHT);

    Bullet bullet1;
    bullet1.Create_Bullet(renderer, "Bullet5.png", bullet_x, bullet_y ,bullet_size, bullet_size,bullet_damage, bullet_speed);

    EnemyShip Wave1;
    Wave1.Create_enemyship(renderer,"ship3.png","Bullet3.png");
    Wave1.create_enemyship_position();
    Wave1.create_enemybullet_position();
    Wave1.setting_initial_heath(enemy_initial_maxHealth);
    Wave1.create_HP_bar();

    SpaceshipHP spaceshiphp;

    GameOver gameover;
    gameover.init(renderer);

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
                      backgroundMusic.stop(backgroundmusic1);
                      backgroundMusic.play(backgroundmusic2);
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
        Wave1.get_ship(current_spaceship_HP,enemy_damage);
        spaceshiphp.create_health_bar(renderer, spaceship_x, spaceship_y, spaceship_size, spaceship_HP);

        //Score.Score_create(renderer,20,720,40);
        bullet_y-=bullet_speed;
        for(int i=1;i<=9;i++)
        {
         if(bullet_x>=enemyship_wave1_Rect[i].x&&bullet_x<=enemyship_wave1_Rect[i].x+80)
            if(enemy_Health[18+i]>0)
            {
                if(bullet_y<=enemyship_wave1_Rect[18+i].y+70&&bullet_y>=enemyship_wave1_Rect[18+i].y+60)
                {
                        if(enemy_Health[18+i]<=bullet_damage)enemy_Health[18+i]=0; else enemy_Health[18+i]-=bullet_damage;
                        if(enemy_Health[18+i]==0){shipnum--;    Wave1.destroy_ship(18+i); Wave1.destroy_bullet(18+i);}//   Score.increaseScore(your_score);}
                        bullet_y = spaceship_y - spaceship_size/2;     bullet_x=(2*spaceship_x + spaceship_size)/2;
                }
            }
            else if(enemy_Health[9+i]>0)
            {
                if(bullet_y<=enemyship_wave1_Rect[9+i].y+70&&bullet_y>=enemyship_wave1_Rect[9+i].y+60)
                {
                        if(enemy_Health[9+i]<=bullet_damage)enemy_Health[9+i]=0; else enemy_Health[9+i]-=bullet_damage;
                        if(enemy_Health[9+i]==0){shipnum--;    Wave1.destroy_ship(9+i);   Wave1.destroy_bullet(9+i);}// Score.increaseScore(your_score);}
                        bullet_y = spaceship_y - spaceship_size/2;     bullet_x=(2*spaceship_x + spaceship_size)/2;
                }
            }
            else if(enemy_Health[i]>0)
            {
                if(bullet_y<=enemyship_wave1_Rect[i].y+70&&bullet_y>=enemyship_wave1_Rect[i].y+60)
                {
                        if(enemy_Health[i]<=bullet_damage)enemy_Health[i]=0; else enemy_Health[i]-=bullet_damage;
                        if(enemy_Health[i]==0){shipnum--;    Wave1.destroy_ship(i);    Wave1.destroy_bullet(i);}//   Score.increaseScore(your_score);}
                        bullet_y = spaceship_y - spaceship_size/2;     bullet_x=(2*spaceship_x + spaceship_size)/2;

                }
            }
       if (bullet_y<0){bullet_y = spaceship_y - spaceship_size/2;     bullet_x=(2*spaceship_x + spaceship_size)/2;}
       }
        //if(shipnum==0){Score.increaseScore(your_score*13); shipnum=-1;}

        bullet1.render(renderer,bullet_x,bullet_y,bullet_size,bullet_size);
        Wave1.render_HP_bar();
        Wave1.ship_render(renderer);
        Wave1.bullet_render(renderer);
        Wave1.bullet_fire(spaceship_x,spaceship_y);
        current_spaceship_HP = Wave1.update_current_health();
        if(current_spaceship_HP==0){gameover.render(renderer);}
        spaceshiphp.render(renderer,current_spaceship_HP);
        //Score.render(renderer);
        }
        SDL_RenderPresent(renderer);
    }

    Mix_CloseAudio();
    IMG_Quit();
    TTF_Quit();
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
