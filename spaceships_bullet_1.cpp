#include "spaceship_bullet_1.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

Bullet::Bullet(){}
void Bullet::Create_Bullet(SDL_Renderer* renderer, const std::string& imagePath, int x, float y, int s,int s1,int damage, float speed) {
    SDL_Surface* surface = IMG_Load(imagePath.c_str());
    if (!surface) {
        std::cerr << "Failed to load bullet image: " << IMG_GetError() << std::endl;
    }

    bullet_texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    this->x = x;    this->y = y;     this->x1 = x1;
    this->s = s;    this->s1 =s1;    this->y1 = y1;
    this->speed = speed;    this -> damage = damage;
}

Bullet::~Bullet() {
    SDL_DestroyTexture(bullet_texture);
}
void Bullet::get_spaceship_static(int x,float y)
{
    x1=x;      y1=y;
}
void Bullet::handleEvent(SDL_Event& event) {
    y-=speed;
    if (y<0){y = y1-s/2;  x=(2*x1+s)/2;}
}
void Bullet::update() {}
void Bullet::render(SDL_Renderer* renderer) {
    SDL_Rect bullet_rect = { x, y, s/6, s1 };
    SDL_RenderCopy(renderer, bullet_texture, NULL, &bullet_rect);
}
