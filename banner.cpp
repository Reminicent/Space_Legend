#include "banner.h"
#include <SDL_image.h>
#include <iostream>

Banner::Banner(){}
void Banner::create_Banner(SDL_Renderer* renderer, const std::string& imagePath) {
    this -> renderer = renderer;
    SDL_Surface* surface = IMG_Load(imagePath.c_str());
    if (!surface) {
        std::cerr << "Failed to load background image: " << IMG_GetError() << std::endl;
        texture = nullptr;
        return;
    }

    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);
}

void Banner::Destroy_Banner() {
    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
    }
}

void Banner::render() {
    if (texture != nullptr) {
        SDL_Rect rect = {400, 100, 800, 250};
        SDL_RenderCopy(renderer, texture, NULL, &rect);
    }
}

