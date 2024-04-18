#ifndef EXPLOSION_H_INCLUDED
#define EXPLOSION_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>

class ExplosionEffect {
public:
    ExplosionEffect();
    ~ExplosionEffect();

    void init(SDL_Renderer* renderer, int x, int y, int size);
    void update();
    void render(SDL_Renderer* renderer);
    bool isFinished();

private:
    SDL_Texture* texture;
    SDL_Rect position;
    int frameCount;
    bool finished;
};

#endif // EXPLOSION_H_INCLUDED
