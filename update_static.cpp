#include "update_static.h"

Static::Static(){}
void Static::The_loop(int loop)
{
    this -> loop = loop;
    if(loop1<loop)checkloop=true; else checkloop=false;
    loop1=loop;
}

int Static::update_enemyship_hp(int hp)
{
    return hp+75+(25*loop);
}

int Static::update_enemyship_dam(int dam)
{
    return dam+10+(5*loop);
}

float Static::update_enemybullet_speed(float speed)
{
    if(speed<=0.4)
    {
        if(checkloop)return speed+0.015; else return speed+0.005;
    }
    else return speed;
}

int Static::update_hp(int hp)
{
    if(checkloop)return hp+400+(100*loop); else return hp;
}
int Static::update_dam(int dam)
{
    if(checkloop)return dam+40+(10*loop); else return dam;
}

float Static::update_bullet_speed(float speed)
{
    if(speed<=1.5)
    {
        if(checkloop)return speed+0.15;
    }
    else return speed;
}
