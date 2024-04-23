#ifndef CREDIT_H_INCLUDED
#define CREDIT_H_INCLUDED

#include <SDL.h>
#include <string>

class Credit {
public:
    Credit();

    void create_Credit(SDL_Renderer* renderer, const std::string& imagePath);
    void Destroy_Banner();
    void render();

private:
    SDL_Renderer* renderer;
    SDL_Texture* texture;
    int width;
    int height;
};


#endif // CREDIT_H_INCLUDED
