#ifndef WAVE1_ATTACK_H_INCLUDED
#define WAVE1_ATTACK_H_INCLUDED

#include <SDL.h>
#include "spaceship_bullet_1.h"
#include "spaceship_moving.h"
#include "spaceship_hp.h"
#include "Wave1_create.h"

class Wave1Attack {
public:
   Wave1Attack();
    ~Wave1Attack();

   void handleEvent(SDL_Event& event);
   int spaceship_x,spaceship_y,bullet_x;
   float bullet_y,spped;

private:
   int shipnum=27;

#endif // WAVE1_ATTACK_H_INCLUDED
