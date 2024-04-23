#ifndef BACKGROUND_H_INCLUDED
#define BACKGROUND_H_INCLUDED

#include <SDL.h>
#include <string>

class Background {
public:
    Background();
    ~Background();

    void create_background(SDL_Renderer* renderer, const std::string& imagePath);
    void render();

private:
    SDL_Renderer* renderer;
    SDL_Texture* texture;
    int width;
    int height;
};

#endif // BACKGROUND_H_INCLUDED
