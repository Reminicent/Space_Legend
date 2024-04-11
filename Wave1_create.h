#ifndef WAVE1_CREATE_H
#define WAVE1_CREATE_H

#include <SDL.h>
#include <SDL_image.h>
#include <bits/stdc++.h>

class EnemyShip {

public:
    EnemyShip();
    ~EnemyShip();

    void Create_enemyship(SDL_Renderer* renderer, const std::string& imagePath1, const std::string& imagePath2);
    void update();
    void ship_render(SDL_Renderer* renderer);
    void bullet_render(SDL_Renderer* renderer);
    void create_enemyship_position();

    void setting_initial_heath(int h);
    void create_HP_bar();
    void render_HP_bar();

    void create_enemybullet_position();
    void bullet_fire();

private:
    SDL_Texture* ship_texture;
    SDL_Texture* bullet_texture;
    int x, y, s;
    SDL_Renderer* renderer;
    SDL_Rect bullet;
    SDL_Color barColor[28];
};

#endif
