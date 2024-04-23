/**#include "Wave3_create.h"
#include "gameover.h"
#include <bits/stdc++.h>

SDL_Rect enemyship_wave2_Rect[28];
SDL_Rect current_healthbar_rect_2[28];
SDL_Rect left_healthbar_rect_2[28];
SDL_Rect healthbar_rect_2[28];
int enemy_maxHealth_2[28],enemy_Health_2[28];
int enemybullet_X_2[27],enemybullet_W_2[27],enemybullet_H_2[27];
float enemybullet_Y_2[27];
SDL_Texture* ship_texture_2[28];
SDL_Texture* bullet_texture_2[28];

//GameOver gameover;
EnemyShip2::EnemyShip2(){}
void EnemyShip2::get_ship(int shealth, int edam,float ebspeed)
{
    this -> shealth = shealth;
    this -> edam = edam;
    this -> ebspeed = ebspeed;
}
void EnemyShip2::Create_enemyship(SDL_Renderer* renderer, const std::string& imagePath1,const std::string& imagePath2) {
    this->renderer = renderer;
    SDL_Surface* ship_surface = IMG_Load(imagePath1.c_str());
    if (!ship_surface) {
        std::cerr << "Failed to load enemy ship image: " << IMG_GetError() << std::endl;
    }

    SDL_Surface* bullet_surface = IMG_Load(imagePath2.c_str());
    if (!bullet_surface) {
        std::cerr << "Failed to load enemy bullet image: " << IMG_GetError() << std::endl;
    }

    for(int i=1;i<=27;i++)
    {
    ship_texture_2[i] = SDL_CreateTextureFromSurface(renderer, ship_surface);
    bullet_texture_2[i] = SDL_CreateTextureFromSurface(renderer, bullet_surface);
    }
    SDL_FreeSurface(ship_surface);
    SDL_FreeSurface(bullet_surface);
}

void EnemyShip2::update() {}
void EnemyShip2::create_enemyship_position()
{
     for(int i=1;i<=9;i++)
     {
     enemyship_wave2_Rect[i].x=30+180*(i-1);      enemyship_wave2_Rect[i].y=15;
     enemyship_wave2_Rect[i].w=120;               enemyship_wave2_Rect[i].h=120;
     }
     for(int i=10;i<=18;i++)
     {
     enemyship_wave2_Rect[i].x=30+180*(i-10);     enemyship_wave2_Rect[i].y=120;
     enemyship_wave2_Rect[i].w=120;               enemyship_wave2_Rect[i].h=120;
     }
     for(int i=19;i<=27;i++)
     {
     enemyship_wave2_Rect[i].x=30+180*(i-19);     enemyship_wave2_Rect[i].y=225;
     enemyship_wave2_Rect[i].w=120;               enemyship_wave2_Rect[i].h=120;
     }
}
void EnemyShip2::setting_initial_heath(int h)
{
     for(int i=1;i<=27;i++)
     {
         enemy_maxHealth_2[i] = h;
         enemy_Health_2[i] = enemy_maxHealth_2[i];
     }
}
void EnemyShip2::create_HP_bar()
{
     for(int i=1;i<=27;i++)
     {
        healthbar_rect_2[i].x = enemyship_wave2_Rect[i].x + 25;
        healthbar_rect_2[i].y = enemyship_wave2_Rect[i].y + 20 ;
        healthbar_rect_2[i].w = enemyship_wave2_Rect[i].w / 10;
        healthbar_rect_2[i].h = enemyship_wave2_Rect[i].h / 2;
     }
}
void EnemyShip2::render_HP_bar()
{
    for(int i=1;i<=27;i++)if(enemy_Health_2[i]>0)
    {
         current_healthbar_rect_2[i].x = healthbar_rect_2[i].x;
         current_healthbar_rect_2[i].y = healthbar_rect_2[i].y + healthbar_rect_2[i].h - static_cast<int>((static_cast<double>(enemy_Health_2[i]) / enemy_maxHealth_2[i]) * healthbar_rect_2[i].h);
         current_healthbar_rect_2[i].w = healthbar_rect_2[i].w;
         current_healthbar_rect_2[i].h = static_cast<int>((static_cast<double>(enemy_Health_2[i]) / enemy_maxHealth_2[i]) * healthbar_rect_2[i].h);
         if (enemy_Health_2[i] >= 70 * enemy_maxHealth_2[i] / 100) {
            barColor[i] = {0, 255, 0, 255};
         } else if (enemy_Health_2[i] >= 40 * enemy_maxHealth_2[i] / 100) {
            barColor[i] = {255, 255, 0, 255};
         } else if (enemy_Health_2[i] > 0){
            barColor[i] = {255, 0, 0, 255};
         }
         if (enemy_Health_2[i] > 0){
         SDL_SetRenderDrawColor(renderer, barColor[i].r, barColor[i].g, barColor[i].b, barColor[i].a);
         SDL_RenderFillRect(renderer, &current_healthbar_rect_2[i]);

         SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
         SDL_RenderDrawRect(renderer, &healthbar_rect_2[i]);

         left_healthbar_rect_2[i].x = healthbar_rect_2[i].x;
         left_healthbar_rect_2[i].y = healthbar_rect_2[i].y;
         left_healthbar_rect_2[i].w = healthbar_rect_2[i].w;
         left_healthbar_rect_2[i].h = healthbar_rect_2[i].h - current_healthbar_rect_2[i].h;

         SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
         SDL_RenderFillRect(renderer, &left_healthbar_rect_2[i]);
         }
     }
}
void EnemyShip2::create_enemybullet_position()
{
     for(int i=1;i<=27;i++)
     {
         enemybullet_X_2[i]=(2*enemyship_wave2_Rect[i].x+enemyship_wave2_Rect[i].w-enemyship_wave2_Rect[i].w/4)/2;
         enemybullet_Y_2[i]=(float)(enemyship_wave2_Rect[i].y+enemyship_wave2_Rect[i].w/2);
         enemybullet_W_2[i]=enemyship_wave2_Rect[i].w/5;
         enemybullet_H_2[i]=enemyship_wave2_Rect[i].h/2;
     }
}
void EnemyShip2::bullet_fire(int sx,int sy)
{
    for (int i = 1; i <= 27; i++){
        enemybullet_Y_2[i]+=ebspeed;
        if(enemybullet_Y_2[i]>=sy+20&&enemybullet_Y_2[i]<=sy+80)
            if(enemybullet_X_2[i]>=sx+20&&enemybullet_X_2[i]<=sx+80)
            {

                if(shealth<=edam&&enemy_Health_2[i]!=0)shealth=0; else if(enemy_Health_2[i]!=0)shealth-=edam;
                enemybullet_X_2[i] = (2*enemyship_wave2_Rect[i].x+enemyship_wave2_Rect[i].w-enemyship_wave2_Rect[i].w/4)/2;
                enemybullet_Y_2[i] = (float)(enemyship_wave2_Rect[i].y+enemyship_wave2_Rect[i].w/2);
            }
            if (enemybullet_Y_2[i] > 900){
                enemybullet_X_2[i] = (2*enemyship_wave2_Rect[i].x+enemyship_wave2_Rect[i].w-enemyship_wave2_Rect[i].w/4)/2;
                enemybullet_Y_2[i] = (float)(enemyship_wave2_Rect[i].y+enemyship_wave2_Rect[i].w/2);
        }
    }
}
int EnemyShip2::update_current_health(){
    return shealth;
}
void EnemyShip2::ship_render(SDL_Renderer* renderer) {
     for (int i = 1; i <= 27; i++){SDL_RenderCopy(renderer, ship_texture_2[i], NULL, &enemyship_wave2_Rect[i]);}
}
void EnemyShip2::bullet_render(SDL_Renderer* renderer) {
     for (int i = 1; i <= 27; i++){
        bullet = {enemybullet_X_2[i], enemybullet_Y_2[i], enemybullet_W_2[i], enemybullet_H_2[i]};
        SDL_RenderCopy(renderer, bullet_texture_2[i], NULL, &bullet);
            }
}

void EnemyShip2::destroy_ship(int shipnum)
{
    SDL_DestroyTexture(ship_texture_2[shipnum]);
    ship_texture_2[shipnum]=NULL;
}

void EnemyShip2::destroy_bullet(int shipnum)
{
    SDL_DestroyTexture(bullet_texture_2[shipnum]);
    bullet_texture_2[shipnum]=NULL;
}

void EnemyShip2::Destroy_EnemyShip() {
    for(int i=1;i<=27;i++)
    {
    SDL_DestroyTexture(ship_texture_2[i]);
    SDL_DestroyTexture(bullet_texture_2[i]);
    enemy_Health_2[i]=0;
    }
}

bool EnemyShip2::in_Wave2()
{
    return EnemyShip2::in_Wave2();
}
**/
