#include "Background.h"
#include <SDL_image.h>
#include <iostream>

Background::Background(){}
void Background::create_background(SDL_Renderer* renderer, const std::string& imagePath) {
    this -> renderer = renderer;
    SDL_Surface* surface = IMG_Load(imagePath.c_str());
    if (!surface) {
        std::cerr << "Failed to load background image: " << IMG_GetError() << std::endl;
        texture = nullptr;
        return;
    }

    texture = SDL_CreateTextureFromSurface(renderer, surface);
    width = surface->w;
    height = surface->h;
    SDL_FreeSurface(surface);
}

Background::~Background() {
    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
    }
}

void Background::render() {
    if (texture != nullptr) {
        SDL_Rect rect = {0, 0, width, height};
        SDL_RenderCopy(renderer, texture, NULL, &rect);
    }
}

