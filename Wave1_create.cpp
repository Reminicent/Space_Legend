#include "Wave1_create.h"
#include "gameover.h"
#include <bits/stdc++.h>
#include <vector>

SDL_Rect enemyship_wave1_Rect[28];
SDL_Rect current_healthbar_rect[28];
SDL_Rect left_healthbar_rect[28];
SDL_Rect healthbar_rect[28];
int enemy_maxHealth[28],enemy_Health[28];
int enemybullet_X[27],enemybullet_W[27],enemybullet_H[27];
float enemybullet_Y[27];
float enemybullet_speed=0.075;
SDL_Texture* ship_texture[28];
SDL_Texture* bullet_texture[28];

GameOver gameover;
EnemyShip::EnemyShip(){}
void EnemyShip::get_ship(int shealth, int edam)
{
    this -> shealth = shealth;
    this -> edam = edam;
}
void EnemyShip::Create_enemyship(SDL_Renderer* renderer, const std::string& imagePath1,const std::string& imagePath2) {
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
    ship_texture[i] = SDL_CreateTextureFromSurface(renderer, ship_surface);
    bullet_texture[i] = SDL_CreateTextureFromSurface(renderer, bullet_surface);
    }
    SDL_FreeSurface(ship_surface);
    SDL_FreeSurface(bullet_surface);
}

EnemyShip::~EnemyShip() {
    for(int i=1;i<=27;i++)
    {
    SDL_DestroyTexture(ship_texture[i]);
    SDL_DestroyTexture(bullet_texture[i]);
    }
}

void EnemyShip::update() {}
void EnemyShip::create_enemyship_position()
{
     for(int i=1;i<=9;i++)
     {
     enemyship_wave1_Rect[i].x=30+180*(i-1);      enemyship_wave1_Rect[i].y=15;
     enemyship_wave1_Rect[i].w=120;               enemyship_wave1_Rect[i].h=120;
     }
     for(int i=10;i<=18;i++)
     {
     enemyship_wave1_Rect[i].x=30+180*(i-10);     enemyship_wave1_Rect[i].y=120;
     enemyship_wave1_Rect[i].w=120;               enemyship_wave1_Rect[i].h=120;
     }
     for(int i=19;i<=27;i++)
     {
     enemyship_wave1_Rect[i].x=30+180*(i-19);     enemyship_wave1_Rect[i].y=225;
     enemyship_wave1_Rect[i].w=120;               enemyship_wave1_Rect[i].h=120;
     }
}
void EnemyShip::setting_initial_heath(int h)
{
     for(int i=1;i<=27;i++)
     {
         enemy_maxHealth[i] = h;
         enemy_Health[i] = enemy_maxHealth[i];
     }
}
void EnemyShip::create_HP_bar()
{
     for(int i=1;i<=27;i++)
     {
        healthbar_rect[i].x = enemyship_wave1_Rect[i].x + 25;
        healthbar_rect[i].y = enemyship_wave1_Rect[i].y + 20 ;
        healthbar_rect[i].w = enemyship_wave1_Rect[i].w / 10;
        healthbar_rect[i].h = enemyship_wave1_Rect[i].h / 2;
     }
}
void EnemyShip::render_HP_bar()
{
    for(int i=1;i<=27;i++)if(enemy_Health>0)
    {
         current_healthbar_rect[i].x = healthbar_rect[i].x;
         current_healthbar_rect[i].y = healthbar_rect[i].y + healthbar_rect[i].h - static_cast<int>((static_cast<double>(enemy_Health[i]) / enemy_maxHealth[i]) * healthbar_rect[i].h);
         current_healthbar_rect[i].w = healthbar_rect[i].w;
         current_healthbar_rect[i].h = static_cast<int>((static_cast<double>(enemy_Health[i]) / enemy_maxHealth[i]) * healthbar_rect[i].h);
         if (enemy_Health[i] >= 70 * enemy_maxHealth[i] / 100) {
            barColor[i] = {0, 255, 0, 255};
         } else if (enemy_Health[i] >= 40 * enemy_maxHealth[i] / 100) {
            barColor[i] = {255, 255, 0, 255};
         } else if (enemy_Health[i] > 0){
            barColor[i] = {255, 0, 0, 255};
         }
         if (enemy_Health[i] > 0){
         SDL_SetRenderDrawColor(renderer, barColor[i].r, barColor[i].g, barColor[i].b, barColor[i].a);
         SDL_RenderFillRect(renderer, &current_healthbar_rect[i]);

         SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
         SDL_RenderDrawRect(renderer, &healthbar_rect[i]);

         left_healthbar_rect[i].x = healthbar_rect[i].x;
         left_healthbar_rect[i].y = healthbar_rect[i].y;
         left_healthbar_rect[i].w = healthbar_rect[i].w;
         left_healthbar_rect[i].h = healthbar_rect[i].h - current_healthbar_rect[i].h;

         SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
         SDL_RenderFillRect(renderer, &left_healthbar_rect[i]);
         }
     }
}
void EnemyShip::create_enemybullet_position()
{
     for(int i=1;i<=27;i++)
     {
         enemybullet_X[i]=(2*enemyship_wave1_Rect[i].x+enemyship_wave1_Rect[i].w-enemyship_wave1_Rect[i].w/4)/2;
         enemybullet_Y[i]=(float)(enemyship_wave1_Rect[i].y+enemyship_wave1_Rect[i].w/2);
         enemybullet_W[i]=enemyship_wave1_Rect[i].w/5;
         enemybullet_H[i]=enemyship_wave1_Rect[i].h/2;
     }
}
void EnemyShip::bullet_fire(int sx,int sy)
{
    for (int i = 1; i <= 27; i++){
        enemybullet_Y[i]+=enemybullet_speed;
        if(enemybullet_Y[i]>=sy+20&&enemybullet_Y[i]<=sy+80)
            if(enemybullet_X[i]>=sx+20&&enemybullet_X[i]<=sx+80)
            {
                if(shealth<=edam&&enemy_Health[i]!=0)shealth=0; else if(enemy_Health[i]!=0)shealth-=edam;
                enemybullet_X[i] = (2*enemyship_wave1_Rect[i].x+enemyship_wave1_Rect[i].w-enemyship_wave1_Rect[i].w/4)/2;
                enemybullet_Y[i] = (float)(enemyship_wave1_Rect[i].y+enemyship_wave1_Rect[i].w/2);
            }
            if (enemybullet_Y[i] > 900){
                enemybullet_X[i] = (2*enemyship_wave1_Rect[i].x+enemyship_wave1_Rect[i].w-enemyship_wave1_Rect[i].w/4)/2;
                enemybullet_Y[i] = (float)(enemyship_wave1_Rect[i].y+enemyship_wave1_Rect[i].w/2);
        }
    }
}
int EnemyShip::update_current_health(){
    return shealth;
}
void EnemyShip::ship_render(SDL_Renderer* renderer) {
     for (int i = 1; i <= 27; i++){SDL_RenderCopy(renderer, ship_texture[i], NULL, &enemyship_wave1_Rect[i]);}
}
void EnemyShip::bullet_render(SDL_Renderer* renderer) {
     for (int i = 1; i <= 27; i++){
        bullet = {enemybullet_X[i], enemybullet_Y[i], enemybullet_W[i], enemybullet_H[i]};
        SDL_RenderCopy(renderer, bullet_texture[i], NULL, &bullet);
            }
}
void EnemyShip::destroy_ship(int shipnum)
{
    SDL_DestroyTexture(ship_texture[shipnum]);
    ship_texture[shipnum]=NULL;
}
void EnemyShip::destroy_bullet(int shipnum)
{
    SDL_DestroyTexture(bullet_texture[shipnum]);
    bullet_texture[shipnum]=NULL;
}

int left_HP_calculator(int hp,int dam)
{
    if(hp<=dam)return 0; else return hp-dam;
}


