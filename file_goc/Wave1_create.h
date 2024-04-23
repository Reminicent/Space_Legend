#ifndef WAVE1_CREATE_H
#define WAVE1_CREATE_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#include <bits/stdc++.h>

class EnemyShip {

public:
    EnemyShip();
    void Destroy_EnemyShip();

    void Create_enemyship(SDL_Renderer* renderer, const std::string& imagePath1, const std::string& imagePath2);
    void update();

    void ship_render(SDL_Renderer* renderer);
    void bullet_render(SDL_Renderer* renderer);
    void create_enemyship_position();

    void get_ship(int shealth,int edam,float ebspeed);
    int left_HP_calculator(int hp,int dam);
    int update_current_health();

    void setting_initial_heath(int h);
    void create_HP_bar();
    void render_HP_bar();

    void create_enemybullet_position();
    void bullet_fire(int sx,int sy);

    void destroy_ship(int shipnum);
    void destroy_bullet(int shipnum);
    bool in_Wave1();


private:
    int shealth,edam;
    float ebspeed;
    int x, y, s;
    bool fire;
    SDL_Renderer* renderer;
    SDL_Rect bullet;
    SDL_Color barColor[28];
};

#endif
