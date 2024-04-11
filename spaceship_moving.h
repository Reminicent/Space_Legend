#ifndef SPACESHIP_MOVING_H_INCLUDED
#define SPACESHIP_MOVING_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class Spaceship {
public:
    Spaceship();
    ~Spaceship();
    void Create_Spaceship(SDL_Renderer* renderer, const std::string& imagePath, int x, int y, int s,int s1, int HP);
    void setScreenSize(int width, int height);
    void handleEvent(SDL_Event& event);
    int updateX();         int updateY();
    void render(SDL_Renderer* renderer);
private:
    SDL_Renderer* renderer;
    SDL_Texture* spaceship_texture;
    int x,y,newX,newY;
    int s,s1,HP;
    int screen_width, screen_height;
    bool mousePressed;
};

#endif // SPACESHIP_MOVING_H

