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
//#include "score.h"
#include "gameover.h"
#include "game_pause.h"
#include "explosion.h"
#include "Wave2_create.h"
#include "update_static.h"

const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT = 900;

int i,shipnum=27;
float enemybullet_speed = 0.04;
bool fire = true;
bool gameover_render;
bool checkGameOver = false;
bool W1 =false,W2 =false,W3 =false,W4 =false,W5 =false;
int spaceship_HP = 1000;
int current_spaceship_HP = 1000;
int loop;

int main(int argc, char* argv[])
{
    SDL_Init(SDL_INIT_VIDEO);
    TTF_Init();
    SDL_Window* window = SDL_CreateWindow("Chiến cơ huyền thoại", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    IMG_Init(IMG_INIT_PNG);
    if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 6, 4096) < 0)
    {
        std::cerr << "SDL_mixer could not initialize! SDL_Error: " << Mix_GetError() << std::endl;
        return 1;
    }

    Background background;
    background.create_background(renderer, "Background.png");

    BackgroundMusic backgroundMusic;
    Mix_Music* backgroundmusic1 = Mix_LoadMUS("background_music1.mp3");
    Mix_Music* backgroundmusic2 = Mix_LoadMUS("background_music2.mp3");
    Mix_Chunk* bulletsound = Mix_LoadWAV("bulletsound.wav");
    Mix_AllocateChannels(4);

    MainMenu mainmenu;
    mainmenu.Create_MainMenu(renderer);

    //Score Score;
    //Score.Score_create(renderer,20,720,40);

    Spaceship spaceship;
    spaceship.setScreenSize(SCREEN_WIDTH, SCREEN_HEIGHT);

    Bullet bullet1;
    EnemyShip Wave1;
    EnemyShip2 Wave2;
    SpaceshipHP spaceshiphp;
    PauseMenu pause;
    Static upstatic;

    //ExplosionEffect explosion;
    //explosion.init(renderer,500,500,1000);

    GameOver gameover;
    gameover.init(renderer);
    gameover.setting_option(renderer);

    bool quit = false;
    SDL_Event event;
    while (!quit)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
            {
                quit = true;
            }
            else if (checkGameOver)
            {
                if(gameover.handleEvent(event))
                {
                    inMenu=true;
                    backgroundmusic1Played = false;
                    backgroundMusic2Played = false;
                    Mix_HaltMusic();
                    gameover.setting_music();
                }
                if (gameover.return_wave_1())
                {
                    gameover.setting_music();
                    spaceship_HP = 1000;
                    current_spaceship_HP = 1000;
                    bullet_damage=100;
                    Wave1.Destroy_EnemyShip();
                    bullet1.Destroy_Bullet();
                    spaceship.Destroy_Spaceship();
                    spaceshiphp.Destroy_Spaceshiphp();
                    Mix_HaltMusic();
                    backgroundMusic2Played = false;
                    spaceship.Create_Spaceship(renderer, "Ship5.png",spaceship_x,spaceship_y, spaceship_size, spaceship_size, spaceship_HP);
                    bullet1.Create_Bullet(renderer, "Bullet5.png", bullet_x, bullet_y,bullet_size, bullet_size,bullet_damage, bullet_speed);
                    Wave1.Create_enemyship(renderer,"ship3.png","Bullet3.png");
                    Wave1.create_enemyship_position();
                    Wave1.create_enemybullet_position();
                    Wave1.setting_initial_heath(enemy_initial_maxHealth);
                    Wave1.create_HP_bar();
                    W1=true;

                }
                checkGameOver = false;
            }
            else if (inMenu)
            {
                loop = 0;
                upstatic.The_loop(loop);
                shipnum = 27;
                spaceship_HP = 1000;
                current_spaceship_HP = 1000;
                bullet_damage=100;
                enemy_initial_maxHealth = 300;
                enemybullet_speed = 0.04;
                enemy_damage = 50;
                spaceship.Create_Spaceship(renderer, "Ship5.png",spaceship_x,spaceship_y, spaceship_size, spaceship_size, spaceship_HP);
                bullet1.Create_Bullet(renderer, "Bullet5.png", bullet_x, bullet_y,bullet_size, bullet_size,bullet_damage, bullet_speed);
                Wave1.Create_enemyship(renderer,"ship3.png","Bullet3.png");
                Wave1.create_enemyship_position();
                Wave1.create_enemybullet_position();
                Wave1.setting_initial_heath(enemy_initial_maxHealth);
                Wave1.create_HP_bar();
                pause.create_pausemenu(renderer);

                mainmenu.Create_MainMenu(renderer);
                if (!backgroundmusic1Played)
                {
                    Mix_HaltMusic();
                    backgroundMusic.play(backgroundmusic1);
                    backgroundmusic1Played = true;
                }
                if(mainmenu.handleEvent(event))
                {
                    inMenu = false;
                    W1=true;
                    mainmenu.Destroy_MainMenu();
                }
            }
            else
            {
                if (!backgroundMusic2Played)
                {
                    Mix_HaltMusic();
                    backgroundMusic.play(backgroundmusic2);
                    backgroundMusic2Played = true;
                }
                spaceship.handleEvent(event);
            }
            pause.handleInput(event);
        }
        SDL_RenderClear(renderer);
        background.render();
        if (inMenu)
        {
            mainmenu.render(renderer);
        }
        else if(pause.isGamePaused())
        {
            pause.render();
            if (pause.backToMainMenu())
            {
                pause.Destroy_pause();
                if(W1)Wave1.Destroy_EnemyShip();
                if(W2)Wave2.Destroy_EnemyShip();
                //if(W3)Wave1.Destroy_EnemyShip();
                //if(W4)Wave1.Destroy_EnemyShip();
                //if(W5)Wave1.Destroy_EnemyShip();
                bullet1.Destroy_Bullet();
                spaceship.Destroy_Spaceship();
                spaceshiphp.Destroy_Spaceshiphp();
                Mix_HaltMusic();
                gameover.setting_music();
                backgroundmusic1Played = false;
                backgroundMusic2Played = false;
                inMenu=true;
                gameover_render = true;
                W1=false;
            }
        }
        else if(!pause.isGamePaused()&&W1)
        {
            spaceship.render(renderer);
            spaceship_x=spaceship.updateX();
            spaceship_y=spaceship.updateY();
            Wave1.get_ship(current_spaceship_HP,enemy_damage,enemybullet_speed);
            spaceshiphp.create_health_bar(renderer, spaceship_x, spaceship_y, spaceship_size, spaceship_HP);

            //Score.Score_create(renderer,20,720,40);
            bullet_y-=bullet_speed;
            if(bullet1.Check_bullet()&&fire)
            {
                Mix_PlayChannel(1,bulletsound,0);
                Mix_Volume(-1, MIX_MAX_VOLUME*0.6);
                fire=false;
            }
            for(int i=1; i<=9; i++)if(bullet1.Check_bullet())
                {
                    if(bullet_x>=enemyship_wave1_Rect[i].x&&bullet_x<=enemyship_wave1_Rect[i].x+80)
                        if(enemy_Health[18+i]>0)
                        {
                            if(bullet_y<=enemyship_wave1_Rect[18+i].y+70&&bullet_y>=enemyship_wave1_Rect[18+i].y+60)
                            {
                                if(enemy_Health[18+i]<=bullet_damage)enemy_Health[18+i]=0;
                                else enemy_Health[18+i]-=bullet_damage;
                                if(enemy_Health[18+i]==0)
                                {
                                    shipnum--;
                                    Wave1.destroy_ship(18+i);
                                    Wave1.destroy_bullet(18+i);
                                    //Score.increaseScore(your_score);
                                }
                                bullet_y = spaceship_y - spaceship_size/2;
                                bullet_x=(2*spaceship_x + spaceship_size)/2;
                                fire=true;
                            }
                        }
                        else if(enemy_Health[9+i]>0)
                        {
                            if(bullet_y<=enemyship_wave1_Rect[9+i].y+70&&bullet_y>=enemyship_wave1_Rect[9+i].y+60)
                            {
                                if(enemy_Health[9+i]<=bullet_damage)enemy_Health[9+i]=0;
                                else enemy_Health[9+i]-=bullet_damage;
                                if(enemy_Health[9+i]==0)
                                {
                                    shipnum--;
                                    Wave1.destroy_ship(9+i);
                                    Wave1.destroy_bullet(9+i);
                                    //Score.increaseScore(your_score);
                                }
                                bullet_y = spaceship_y - spaceship_size/2;
                                bullet_x=(2*spaceship_x + spaceship_size)/2;
                                fire=true;
                            }
                        }
                        else if(enemy_Health[i]>0)
                        {
                            if(bullet_y<=enemyship_wave1_Rect[i].y+70&&bullet_y>=enemyship_wave1_Rect[i].y+60)
                            {
                                if(enemy_Health[i]<=bullet_damage)enemy_Health[i]=0;
                                else enemy_Health[i]-=bullet_damage;
                                if(enemy_Health[i]==0)
                                {
                                    shipnum--;
                                    Wave1.destroy_ship(i);
                                    Wave1.destroy_bullet(i);
                                    //Score.increaseScore(your_score);
                                }
                                bullet_y = spaceship_y - spaceship_size/2;
                                bullet_x=(2*spaceship_x + spaceship_size)/2;
                                fire=true;

                            }
                        }
                    if (bullet_y<0)
                    {
                        bullet_y = spaceship_y - spaceship_size/2;
                        bullet_x=(2*spaceship_x + spaceship_size)/2;
                        fire=true;
                    }
                }

            bullet1.render(renderer,bullet_x,bullet_y,bullet_size,bullet_size);
            Wave1.render_HP_bar();
            Wave1.ship_render(renderer);
            Wave1.bullet_render(renderer);
            Wave1.bullet_fire(spaceship_x,spaceship_y);
            current_spaceship_HP = Wave1.update_current_health();
            if(current_spaceship_HP==0)
            {
                bullet1.Destroy_Bullet();
                gameover.render(renderer);
                gameover.load_gameovermusic();
                gameover.render_menu(renderer);
                checkGameOver=true;
            }
            spaceshiphp.render(renderer,current_spaceship_HP);
            if(shipnum==0)
            {
            //   Score.increaseScore(your_score*13);
            //   shipnum=-1;
                W1=false;     W2=true;   shipnum=18;
                upstatic.The_loop(loop);
                enemy_damage = upstatic.update_enemyship_dam(enemy_damage);
                enemy_initial_maxHealth = upstatic.update_enemyship_hp(enemy_initial_maxHealth);
                enemybullet_speed = upstatic.update_enemybullet_speed(enemybullet_speed);
                Wave2.Create_enemyship_1(renderer,"ship3.png","Bullet3.png");
                Wave2.create_enemyship_position();
                Wave2.create_enemybullet_position();
                Wave2.setting_initial_heath(enemy_initial_maxHealth);
                Wave2.create_HP_bar();
                if(current_spaceship_HP<50*spaceship_HP/100)current_spaceship_HP=50*spaceship_HP/100;
            }
            //Score.render(renderer);
        }
        else if(!pause.isGamePaused()&&W2)
        {
            Wave1.Destroy_EnemyShip();
            spaceship.render(renderer);
            spaceship_x=spaceship.updateX();
            spaceship_y=spaceship.updateY();
            Wave2.get_ship(current_spaceship_HP,enemy_damage,enemybullet_speed);
            spaceshiphp.create_health_bar(renderer, spaceship_x, spaceship_y, spaceship_size, spaceship_HP);

            //Score.Score_create(renderer,20,720,40);
            bullet_y-=bullet_speed;
            if(bullet1.Check_bullet()&&fire)
            {
                Mix_PlayChannel(1,bulletsound,0);
                Mix_Volume(-1, MIX_MAX_VOLUME*0.6);
                fire=false;
            }
            for(int i=1; i<=9; i++)if(bullet1.Check_bullet())
                {
                    if(bullet_x>=enemyship_wave2_Rect[i].x&&bullet_x<=enemyship_wave2_Rect[i].x+80)
                        if(enemy_Health_2[9+i]>0)
                        {
                            if(bullet_y<=enemyship_wave2_Rect[9+i].y+70&&bullet_y>=enemyship_wave2_Rect[9+i].y+60)
                            {
                                if(enemy_Health_2[9+i]<=bullet_damage)enemy_Health_2[9+i]=0;
                                else enemy_Health_2[9+i]-=bullet_damage;
                                if(enemy_Health_2[9+i]==0)
                                {
                                    shipnum--;
                                    Wave2.destroy_ship(9+i);
                                    Wave2.destroy_bullet(9+i);
                                    //Score.increaseScore(your_score);
                                }
                                bullet_y = spaceship_y - spaceship_size/2;
                                bullet_x=(2*spaceship_x + spaceship_size)/2;
                                fire=true;
                            }
                        }
                        else if(enemy_Health_2[i]>0)
                        {
                            if(bullet_y<=enemyship_wave2_Rect[i].y+70&&bullet_y>=enemyship_wave2_Rect[i].y+60)
                            {
                                if(enemy_Health_2[i]<=bullet_damage)enemy_Health_2[i]=0;
                                else enemy_Health_2[i]-=bullet_damage;
                                if(enemy_Health_2[i]==0)
                                {
                                    shipnum--;
                                    Wave2.destroy_ship(i);
                                    Wave2.destroy_bullet(i);
                                    //Score.increaseScore(your_score);
                                }
                                bullet_y = spaceship_y - spaceship_size/2;
                                bullet_x=(2*spaceship_x + spaceship_size)/2;
                                fire=true;

                            }
                        }
                    if (bullet_y<0)
                    {
                        bullet_y = spaceship_y - spaceship_size/2;
                        bullet_x=(2*spaceship_x + spaceship_size)/2;
                        fire=true;
                    }
                }
            if(shipnum==0)
            {
            //   Score.increaseScore(your_score*13);
                 shipnum=27;
                 W2=false;
                 W3=true;
            }

            bullet1.render(renderer,bullet_x,bullet_y,bullet_size,bullet_size);
            Wave2.render_HP_bar();
            Wave2.ship_render(renderer);
            Wave2.bullet_render(renderer);
            Wave2.bullet_fire(spaceship_x,spaceship_y);
            current_spaceship_HP = Wave2.update_current_health();
            if(current_spaceship_HP==0)
            {
                bullet1.Destroy_Bullet();
                gameover.render(renderer);
                gameover.load_gameovermusic();
                gameover.render_menu(renderer);
                checkGameOver=true;
            }
            spaceshiphp.render(renderer,current_spaceship_HP);
            //Score.render(renderer);
        }

/**        else if(!pause.isGamePaused()&&W3)
        {
            Wave1.Destroy_EnemyShip();
            spaceship.render(renderer);
            spaceship_x=spaceship.updateX();
            spaceship_y=spaceship.updateY();
            Wave2.get_ship(current_spaceship_HP,enemy_damage,enemybullet_speed);
            spaceshiphp.create_health_bar(renderer, spaceship_x, spaceship_y, spaceship_size, spaceship_HP);

            //Score.Score_create(renderer,20,720,40);
            bullet_y-=bullet_speed;
            if(bullet1.Check_bullet()&&fire)
            {
                Mix_PlayChannel(1,bulletsound,0);
                Mix_Volume(-1, MIX_MAX_VOLUME*0.6);
                fire=false;
            }
            for(int i=1; i<=9; i++)if(bullet1.Check_bullet())
                {
                    if(bullet_x>=enemyship_wave2_Rect[i].x&&bullet_x<=enemyship_wave2_Rect[i].x+80)
                        if(enemy_Health_2[18+i]>0)
                        {
                            if(bullet_y<=enemyship_wave2_Rect[18+i].y+70&&bullet_y>=enemyship_wave2_Rect[18+i].y+60)
                            {
                                if(enemy_Health_2[18+i]<=bullet_damage)enemy_Health_2[18+i]=0;
                                else enemy_Health_2[18+i]-=bullet_damage;
                                if(enemy_Health_2[18+i]==0)
                                {
                                    shipnum--;
                                    Wave2.destroy_ship(18+i);
                                    Wave2.destroy_bullet(18+i);
                                    //Score.increaseScore(your_score);
                                }
                                bullet_y = spaceship_y - spaceship_size/2;
                                bullet_x=(2*spaceship_x + spaceship_size)/2;
                                fire=true;
                            }
                        }
                        else if(enemy_Health_2[9+i]>0)
                        {
                            if(bullet_y<=enemyship_wave2_Rect[9+i].y+70&&bullet_y>=enemyship_wave2_Rect[9+i].y+60)
                            {
                                if(enemy_Health_2[9+i]<=bullet_damage)enemy_Health_2[9+i]=0;
                                else enemy_Health_2[9+i]-=bullet_damage;
                                if(enemy_Health_2[9+i]==0)
                                {
                                    shipnum--;
                                    Wave2.destroy_ship(9+i);
                                    Wave2.destroy_bullet(9+i);
                                    //Score.increaseScore(your_score);
                                }
                                bullet_y = spaceship_y - spaceship_size/2;
                                bullet_x=(2*spaceship_x + spaceship_size)/2;
                                fire=true;
                            }
                        }
                        else if(enemy_Health_2[i]>0)
                        {
                            if(bullet_y<=enemyship_wave2_Rect[i].y+70&&bullet_y>=enemyship_wave2_Rect[i].y+60)
                            {
                                if(enemy_Health_2[i]<=bullet_damage)enemy_Health_2[i]=0;
                                else enemy_Health_2[i]-=bullet_damage;
                                if(enemy_Health_2[i]==0)
                                {
                                    shipnum--;
                                    Wave2.destroy_ship(i);
                                    Wave2.destroy_bullet(i);
                                    //Score.increaseScore(your_score);
                                }
                                bullet_y = spaceship_y - spaceship_size/2;
                                bullet_x=(2*spaceship_x + spaceship_size)/2;
                                fire=true;

                            }
                        }
                    if (bullet_y<0)
                    {
                        bullet_y = spaceship_y - spaceship_size/2;
                        bullet_x=(2*spaceship_x + spaceship_size)/2;
                        fire=true;
                    }
                }
            //if(shipnum==0)
            //{
            //   Score.increaseScore(your_score*13);
            //   shipnum=-1;    W1=false;     W2=true;
            //}

            bullet1.render(renderer,bullet_x,bullet_y,bullet_size,bullet_size);
            Wave2.render_HP_bar();
            Wave2.ship_render(renderer);
            Wave2.bullet_render(renderer);
            Wave2.bullet_fire(spaceship_x,spaceship_y);
            current_spaceship_HP = Wave2.update_current_health();
            if(current_spaceship_HP==0)
            {
                bullet1.Destroy_Bullet();
                gameover.render(renderer);
                gameover.load_gameovermusic();
                gameover.render_menu(renderer);
                checkGameOver=true;
            }
            spaceshiphp.render(renderer,current_spaceship_HP);
            //Score.render(renderer);
        }
**/
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
