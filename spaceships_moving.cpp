#include "spaceship_moving.h"
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

Spaceship::Spaceship(){}
void Spaceship::Create_Spaceship(SDL_Renderer* renderer, const std::string& imagePath, int x, int y, int s,int s1,int HP) {
    SDL_Surface* surface = IMG_Load(imagePath.c_str());
    if (!surface) {
        std::cerr << "Failed to load spaceship image: " << IMG_GetError() << std::endl;
    }
    spaceship_texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    this->x = x;
    this->newX = newX;
    this->screen_height = screen_height;
    this->y = y;
    this->newY = newY;
    this->screen_width = screen_width;
    this->s = s;     this->s1 = s1;    this ->HP = HP;
    mousePressed = false;
}
void Spaceship::setScreenSize(int width, int height) {
    screen_width = width;
    screen_height = height;
}
Spaceship::~Spaceship() {
    SDL_DestroyTexture(spaceship_texture);
}

void Spaceship::handleEvent(SDL_Event& event) {
    if (event.type == SDL_MOUSEBUTTONDOWN) {
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);
        if (mouseX >= x && mouseX <= x + s &&
            mouseY >= y && mouseY <= y + s) {
            mousePressed = true;
        }
    } else if (event.type == SDL_MOUSEBUTTONUP) {
        mousePressed = false;
    } else if (event.type == SDL_MOUSEMOTION && mousePressed) {
        int mouseX, mouseY;
        SDL_GetMouseState(&mouseX, &mouseY);
        newX = mouseX - s/2;
        newY = mouseY - s/2;
    }
      if (newX >= 0 && newY >= 0 && newX + s <= screen_width && newY + s <= screen_height&& newY >= screen_height/2)
           if(newX - s < x&&newY - s < y && x - s < newX&&y - s < newY){
                    x = newX;          y = newY;
                }
}

int Spaceship::updateX() {return x;}
int Spaceship::updateY() {return y;}

void Spaceship::render(SDL_Renderer* renderer) {
    SDL_Rect spaceship_rect = {x, y, s, s1};
    SDL_RenderCopy(renderer, spaceship_texture, NULL, &spaceship_rect);
}
