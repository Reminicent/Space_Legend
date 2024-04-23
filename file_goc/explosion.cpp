#include "explosion.h"

ExplosionEffect::ExplosionEffect() : texture(nullptr), frameCount(0), finished(false) {}

ExplosionEffect::~ExplosionEffect() {
    SDL_DestroyTexture(texture);
}

void ExplosionEffect::init(SDL_Renderer* renderer, int x, int y, int size) {
    // Load explosion texture
    SDL_Surface* surface = IMG_Load("spaceship_explosion.png"); // Example: replace "explosion.bmp" with your explosion image file
    if (!surface) {
        // Handle error
        finished = true;
        return;
    }

    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    // Set position and size of explosion
    position.x = x;
    position.y = y;
    position.w = size;
    position.h = size;
}

void ExplosionEffect::update() {
    // Update animation frame count
    frameCount++;
    if (frameCount > 30) { // Adjust frame count as needed
        finished = true; // End explosion animation after 30 frames (adjust as needed)
    }
}

void ExplosionEffect::render(SDL_Renderer* renderer) {
    if (!finished && texture) {
        SDL_RenderCopy(renderer, texture, nullptr, &position);
    }
}

bool ExplosionEffect::isFinished() {
    return finished;
}
