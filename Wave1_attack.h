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

   void get_static(int sx,int sy,int bx, int dam, float by, float speed, int health[],SDL_Rect enemyrect[]);
   void handleEvent(float by);
   void get_changed_static(int health[]);
   //int enemy_Health[28];
   //SDL_Rect enemyship_wave1_Rect[28];

private:
   int shipnum=27;
   int sx, sy, bx, dam;
   float by, speed;
   int health[28];
   SDL_Rect enemyrect[28];
};

#endif // WAVE1_ATTACK_H_INCLUDED

