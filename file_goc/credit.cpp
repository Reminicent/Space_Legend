#include "credit.h"
#include <SDL_image.h>
#include <iostream>

Credit::Credit(){}
void Credit::create_Credit(SDL_Renderer* renderer, const std::string& imagePath) {
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

void Credit::Destroy_Banner() {
    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
    }
}

void Credit::render() {
    if (texture != nullptr) {
        SDL_Rect rect = {700, 150, 400, 600};
        SDL_RenderCopy(renderer, texture, NULL, &rect);
    }
}

