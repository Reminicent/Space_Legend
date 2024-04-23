#include <SDL.h>
#include "spaceship_bullet_1.h"
#include "spaceship_moving.h"
#include "spaceship_hp.h"
#include "Wave1_create.h"
#include "Wave1_attack.h"

//int spaceship_x,spaceship_y,bullet_x;
//float bullet_y,speed;
Bullet bullet1;
EnemyShip Wave1Create;

Wave1Attack::Wave1Attack(){}
Wave1Attack::~Wave1Attack(){}
void Wave1Attack::get_static(int sx,int sy,int bx, int dam, float by, float speed, int health[],SDL_Rect enemyrect[])
{
    this->sx = sx;
    this->sy = sy;
    this->bx = bx;
    this->by = by;
    this->dam = dam;
    this->speed = speed;
    //for(int i=19;i<=27;i++)std::cout<<enemy_Health[i]<<' ';     std::cout<<std::endl;
    for(int i=1;i<=27;i++)this -> health[i] = health[i];
    for(int i=1;i<=27;i++){this ->enemyrect[i].x = enemyrect[i].x;  this ->enemyrect[i].w = enemyrect[i].w;  this ->enemyrect[i].y = enemyrect[i].y;  this ->enemyrect[i].h = enemyrect[i].h;}
    //std::cout<<enemyrect[23].y;     std::cout<<std::endl;
    //for(int i=19;i<=27;i++)std::cout<<health[i]<<' ';     std::cout<<std::endl;
}
void Wave1Attack::get_changed_static(int health[])
{
    for(int i=1;i<=27;i++)this -> health[i] = health[i];
}
void Wave1Attack::handleEvent(float by,SDL_Rect enemyrect[]) {
    //while(shipnum>0)
    //{
       //by-=speed;
       //bullet1.handleEvent(by,speed);
       //std::cout<<by<<' ';     std::cout<<std::endl;
       for(int i=1;i<=27;i++)
       {
         if(bx>=enemyrect[i].x&&bx<=enemyrect[i].x+120)
            if(health[2*9+i]>0)
            {
                if(by==enemyrect[18+i].y+120)
                {
                        if(health[18+i]<=dam)health[18+i]=0; else; health[18+i]-=dam;
                        if(health[18+i]==0){shipnum--;    Wave1Create.destroy_ship(18+i);}
                        bullet1.get_spaceship_static(sx, sy);
                        by = sy - 50;     bx=(2*sx + 100)/2;
                }
            }
            else if(health[9+i]>0)
            {
                if(by==enemyrect[9+i].y+120)
                {
                        if(health[9+i]<=dam)health[18+i]=0; else; health[9+i]-=dam;
                        if(health[9+i]==0){shipnum--;    Wave1Create.destroy_ship(9+i);}
                        bullet1.get_spaceship_static(sx, sy);
                        by = sy - 50;     bx=(2*sx + 100)/2;
                }
            }
            else if(health[i]>0)
            {
                if(by==enemyrect[i].y+120)
                {
                        if(health[9+i]<=dam)health[18+i]=0; else; health[9+i]-=dam;
                        if(health[i]==0){shipnum--;    Wave1Create.destroy_ship(i);}
                        bullet1.get_spaceship_static(sx, sy);
                        by = sy - 50;     bx=(2*sx + 100)/2;
                }
            }
       //}
       //for(int i=19;i<=27;i++)std::cout<<health[i]<<' ';     std::cout<<std::endl;
       //std::cout<<enemyrect[23].y;     std::cout<<std::endl;
       if (by<0){    by = sy - 50;     bx=(2*sx + 100)/2;}
    }
}

