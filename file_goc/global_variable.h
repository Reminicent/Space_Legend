#ifndef GLOBAL_VARIABLE_H_INCLUDED
#define GLOBAL_VARIABLE_H_INCLUDED

extern int spaceship_x = 750,spaceship_y=660, spaceship_size=100, spaceship_HP , current_spaceship_HP;
extern int bullet_x = (2*spaceship_x+spaceship_size)/2, bullet_size = spaceship_size;   float bullet_y = (float)spaceship_y-spaceship_size/2;  float bullet_speed = 0.75;

extern int enemyshipSize = 120, enemy_damage = 50, bullet_damage = 100;

extern int enemyshipX[27] ,enemyshipY[27] ;
extern int enemybullet_X[27],enemybullet_W[27],enemybullet_H[27];
extern float enemybullet_Y[27];
extern SDL_Rect enemyship_wave1_Rect[28];
extern int enemy_maxHealth[28],enemy_Health[28];

extern int enemyshipX_2[18] ,enemyshipY_2[18] ;
extern int enemybullet_X_2[18],enemybullet_W_2[18],enemybullet_H_2[18];
extern float enemybullet_Y_2[18];
extern SDL_Rect enemyship_wave2_Rect[19];
extern int enemy_maxHealth_2[19],enemy_Health_2[19];
extern SDL_Rect enemyship2_wave2_Rect[3];
extern SDL_Rect current_healthbar2_rect_2[3];
extern SDL_Rect left_healthbar2_rect_2[3];
extern SDL_Rect healthbar2_rect_2[3];
extern int enemy2_maxHealth_2[3],enemy2_Health_2[3];
extern int enemybullet2_X_2[10],enemybullet2_W_2[10],enemybullet2_H_2[10];
extern float enemybullet2_Y_2[10];

extern int enemyshipX_3[27] ,enemyshipY_3[27];
extern int enemybullet_X_3[27],enemybullet_W_3[27],enemybullet_H_3[27];
extern float enemybullet_Y_3[27];
extern SDL_Rect enemyship_wave3_Rect[28];
extern int enemy_maxHealth_3[28],enemy_Health_3[28];

extern int enemyshipX_4[18] ,enemyshipY_4[18] ;
extern int enemybullet_X_4[18],enemybullet_W_4[18],enemybullet_H_4[18];
extern float enemybullet_Y_4[18];
extern SDL_Rect enemyship_wave4_Rect[19];
extern int enemy_maxHealth_4[19],enemy_Health_4[19];
extern SDL_Rect enemyship2_wave4_Rect[3];
extern SDL_Rect current_healthbar2_rect_4[3];
extern SDL_Rect left_healthbar2_rect_4[3];
extern SDL_Rect healthbar2_rect_4[3];
extern int enemy2_maxHealth_4[3],enemy2_Health_4[3];
extern int enemybullet2_X_4[10],enemybullet2_W_4[10],enemybullet2_H_4[10];
extern float enemybullet2_Y_4[10];



extern bool inMenu = true,ingame=false,gamePaused=false;

extern bool backgroundmusic1Played = false;
extern bool backgroundMusic2Played = false;
extern bool instruction_musicPlayed = false;

extern Mix_Music* backgroundmusic1;
extern Mix_Music* backgroundmusic2;
extern Mix_Music* instruction_music;

extern int enemy_initial_maxHealth = 300;
extern int your_score=300, total_score = 0;


#endif // GLOBAL_VARIABLE_H_INCLUDED
