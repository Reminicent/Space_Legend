#include "spaceship_hp.h"
#include "Wave1_create.h"
#include <SDL.h>
#include <SDL_image.h>
#include <bits/stdc++.h>

EnemyShip Wave1;
SpaceshipHP::SpaceshipHP(){}
void SpaceshipHP::create_health_bar(SDL_Renderer* renderer, int x, int y, int width, int maxHealth) {
    healthbar_w = width*5/4;
    healthbar_x = (2*x + width)/2 - healthbar_w/2 + 5 ;
    healthbar_y = y + width - 5 ;
    healthbar_h = healthbar_w/10;
    barRect = { healthbar_x, healthbar_y, healthbar_w, healthbar_h };
    this->maxHealth = maxHealth;
}

void SpaceshipHP::Destroy_Spaceshiphp() {current_shealth=0;}

void SpaceshipHP::render(SDL_Renderer* renderer,int current_shealth) {
     if(current_shealth>0)
     {
     current_healthbar_x = healthbar_x;
     current_healthbar_y = healthbar_y;
     current_healthbar_w = static_cast<int>((static_cast<double>( current_shealth) / maxHealth) * healthbar_w);
     current_healthbar_h = healthbar_h;

     current_barRect = {current_healthbar_x,current_healthbar_y,current_healthbar_w,current_healthbar_h};

     if (current_shealth >= 70 * maxHealth / 100) {
        barColor = {0, 255, 0, 255};
    } else if (current_shealth >= 40 * maxHealth / 100) {
        barColor = {255, 255, 0, 255};
    } else {
        barColor = {255, 0, 0, 255};
    }

    left_healthbar_x = healthbar_x + static_cast<int>((static_cast<double>( current_shealth) / maxHealth) * healthbar_w);
    left_healthbar_y = healthbar_y;
    left_healthbar_w = healthbar_w - current_healthbar_w;
    left_healthbar_h = healthbar_h;
    SDL_Rect left_barRect = { left_healthbar_x,left_healthbar_y,left_healthbar_w,left_healthbar_h };

    SDL_SetRenderDrawColor(renderer, barColor.r, barColor.g, barColor.b, barColor.a);
    SDL_RenderFillRect(renderer, &current_barRect);

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderDrawRect(renderer, &barRect);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &left_barRect);
    }
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
