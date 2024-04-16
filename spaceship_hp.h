#ifndef SPACESHIP_HP_H_INCLUDED
#define SPACESHIP_HP_H_INCLUDED

#include <SDL.h>

class SpaceshipHP {
public:
    SpaceshipHP();
    ~SpaceshipHP();

    void create_health_bar(SDL_Renderer* renderer, int x, int y, int width, int maxHealth);
    void render(SDL_Renderer* renderer,int current_shealth);
    void setHealth(int health);
    int current_spaceship_HP;

private:
    SDL_Rect barRect, current_barRect;
    SDL_Color barColor;
    int currentHealth;
    int maxHealth,current_shealth;
    int healthbar_h,healthbar_x,healthbar_y,healthbar_w;
    int current_healthbar_h,current_healthbar_x,current_healthbar_y,current_healthbar_w;
    int left_healthbar_h,left_healthbar_x,left_healthbar_y,left_healthbar_w;
};

#endif // SPACESHIP_HP_H_INCLUDED

