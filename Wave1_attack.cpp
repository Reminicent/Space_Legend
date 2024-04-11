#include <SDL.h>
#include "spaceship_bullet_1.h"
#include "spaceship_moving.h"
#include "spaceship_hp.h"
#include "Wave1_create.h"
#include "Wave1_attack.h"

int enemy_Health[28];
SDL_Rect enemyship_wave1_Rect[28];

Wave1Attack::Wave1Attack(){}
Wave1Attack::~Wave1Attack(){}
void Wave1Attack::handleEvent(SDL_Event& event) {
    Bullet bullet1;
    while(shipnum>0)
    {
       bullet_y-=speed;
       for(int i=1;i<=9;i++)
       {
         if(bullet_x>=enemyship_wave1_Rect[i].x&&bullet_x<=enemyship_wave1_Rect[i].x+120)
            if(enemy_Health[2*9+i]>0)
            {
                if(bullet_Y==enemyship_wave1_Rect[i].y+120)
                {
                        if(enemy_Health[18+i]>enemy_damage)enemy_Health[18+i]-=enemy_damage;
                        if(enemy_Health[18+i]==0)shipnum--;
                        bullet1.get_spaceship_static(spaceship_x, spaceship_y);
                        bullet_y = spaceship_y - 50;     bullet_x=(2*spaceship_x + 100)/2;
                }
            }
            else if enemy_Health[9+i]>0)
            {
                if(bullet_Y==enemyship_wave1_Rect[9+i].y+120)
                {
                        if(enemy_Health[9+i]>enemy_damage)enemy_Health[9+i]-=enemy_damage;
                        if(enemy_Health[9+i]==0)shipnum--;
                        bullet1.get_spaceship_static(spaceship_x, spaceship_y);
                        bullet_y = spaceship_y - 50;     bullet_x=(2*spaceship_x + 100)/2;
                }
            }
            else if enemy_Health[i]>0)
            {
                if(bullet_Y==enemyship_wave1_Rect[i].y+120)
                {
                        if(enemy_Health[i]>enemy_damage)enemy_Health[i]-=enemy_damage;
                        if(enemy_Health[i]==0)shipnum--;
                        bullet1.get_spaceship_static(spaceship_x, spaceship_y);
                        bullet_y = spaceship_y - 50;     bullet_x=(2*spaceship_x + 100)/2;
                }
            }
       }
       if (bullet_Y<0){bullet_y = spaceship_y - 50;     bullet_x=(2*spaceship_x + 100)/2;}
    }
}

