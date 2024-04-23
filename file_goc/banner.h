#ifndef BANNER_H_INCLUDED
#define BANNER_H_INCLUDED

#include <SDL.h>
#include <string>

class Banner {
public:
    Banner();

    void create_Banner(SDL_Renderer* renderer, const std::string& imagePath);
    void Destroy_Banner();
    void render();

private:
    SDL_Renderer* renderer;
    SDL_Texture* texture;
    int width;
    int height;
};


#endif // BANNER_H_INCLUDED
