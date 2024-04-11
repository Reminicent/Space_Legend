#include "spaceship_hp.h"
#include <SDL.h>
#include <SDL_image.h>
#include <bits/stdc++.h>

SpaceshipHP::SpaceshipHP(SDL_Renderer* renderer, int x, int y, int width, int maxHealth) {
    healthbar_w = width*5/4;
    healthbar_x = (2*x + width)/2 - healthbar_w/2 + 5 ;
    healthbar_y = y + width - 5 ;
    healthbar_h = healthbar_w/10;
    barRect = { healthbar_x, healthbar_y, healthbar_w, healthbar_h };
    this->maxHealth = maxHealth;
}

SpaceshipHP::~SpaceshipHP() {}

void SpaceshipHP::render(SDL_Renderer* renderer) {
    //int barWidth = static_cast<int>((static_cast<double>(currentHealth) / maxHealth) * barRect.w);

     if (current_spaceship_HP >= 50 * maxHealth / 100) {
        barColor = {0, 255, 0, 255};
    } else if (current_spaceship_HP >= 25 * maxHealth / 100) {
        barColor = {255, 255, 0, 255};
    } else {
        barColor = {255, 0, 0, 255};
    }

    SDL_SetRenderDrawColor(renderer, barColor.r, barColor.g, barColor.b, barColor.a);
    SDL_RenderFillRect(renderer, &barRect);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawRect(renderer, &barRect);
}

void SpaceshipHP::setHealth(int health) {
    if (health < 0) {
        currentHealth = 0;
    } else if (health > maxHealth) {
        currentHealth = maxHealth;
    } else {
        currentHealth = health;
    }
}
