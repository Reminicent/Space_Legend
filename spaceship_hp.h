#ifndef SPACESHIP_HP_H_INCLUDED
#define SPACESHIP_HP_H_INCLUDED

#include <SDL.h>

class SpaceshipHP {
public:
    SpaceshipHP(SDL_Renderer* renderer, int x, int y, int width, int maxHealth);
    ~SpaceshipHP();

    void render(SDL_Renderer* renderer);
    void setHealth(int health);
    int current_spaceship_HP;

private:
    SDL_Rect barRect;
    SDL_Color barColor;
    int currentHealth;
    int maxHealth;
    int healthbar_h,healthbar_x,healthbar_y,healthbar_w;
};

#endif // SPACESHIP_HP_H_INCLUDED

