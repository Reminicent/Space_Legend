#ifndef GLOBAL_VARIABLE_H_INCLUDED
#define GLOBAL_VARIABLE_H_INCLUDED

extern int spaceship_x = 750,spaceship_y=660, spaceship_size=100, spaceship_HP , current_spaceship_HP;
extern int bullet_x = (2*spaceship_x+spaceship_size)/2, bullet_size = spaceship_size;   float bullet_y = (float)spaceship_y-spaceship_size/2, bullet_damage = 100;  float bullet_speed = 0.75;
extern int enemyshipX[27] ,enemyshipY[27], enemyshipSize = 120;
extern bool inMenu = true,ingame=false;
extern bool backgroundMusic2Played = false;
extern bool instruction_musicPlayed = false;
extern Mix_Music* backgroundmusic1;
extern Mix_Music* backgroundmusic2;
extern Mix_Music* instruction_music;
extern SDL_Rect enemyship_wave1_Rect[28];
extern int enemybullet_X[27],enemybullet_W[27],enemybullet_H[27];
extern float enemybullet_Y[27];
extern float enemybullet_speed;
extern int current_spaceship_HP_0;

extern int enemy_maxHealth[28],enemy_Health[28];
extern int enemy_initial_maxHealth;


#endif // GLOBAL_VARIABLE_H_INCLUDED
