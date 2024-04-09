#ifndef BACKGROUND_H_INCLUDED
#define BACKGROUND_H_INCLUDED

#include <SDL.h>
#include <string>

class Background {
public:
    Background(SDL_Renderer* renderer, const std::string& imagePath);
    ~Background();

    void render();

private:
    SDL_Renderer* renderer;
    SDL_Texture* texture;
    int width;
    int height;
};

#endif // BACKGROUND_H_INCLUDED
