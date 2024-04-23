#ifndef SPACESHIP_BULLET_1_H_INCLUDED
#define SPACESHIP_BULLET_1_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class Bullet {
public:
    Bullet();
    void Destroy_Bullet();
    void Create_Bullet(SDL_Renderer* renderer, const std::string& imagePath, int x, float y, int s, int s1,int damage, float speed);
    void get_spaceship_static(int x,float y);
    int handleEvent1();
    void handleEvent2();
    void update();
    void render(SDL_Renderer* renderer,int x, int ,int s,int s1);
    bool Check_bullet();
private:
    SDL_Renderer* renderer;
    SDL_Texture* bullet_texture;
    int x,x1,s,s1,damage;
    float y,y1,speed;
};

#endif //SPACESHIP_BULLET_1_H

