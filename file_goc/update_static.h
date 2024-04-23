#ifndef UPDATE_STATIC_H_INCLUDED
#define UPDATE_STATIC_H_INCLUDED

#include <SDL.h>

class Static{

public:
       Static();

       void The_loop(int loop);
       int update_enemyship_hp(int hp);
       int update_enemyship_dam(int dam);
       float update_enemybullet_speed(float speed);
       int update_hp(int hp);
       int update_dam(int dam);
       float update_bullet_speed(float speed);

private:
       int loop,loop1;
       bool checkloop;
};

#endif // UPDATE_STATIC_H_INCLUDED
