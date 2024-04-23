#include "Wave4_create.h"
#include "gameover.h"
#include <bits/stdc++.h>

SDL_Rect enemyship_wave4_Rect[19];
SDL_Rect current_healthbar_rect_4[19];
SDL_Rect left_healthbar_rect_4[19];
SDL_Rect healthbar_rect_4[19];

SDL_Rect enemyship2_wave4_Rect[3];
SDL_Rect current_healthbar2_rect_4[3];
SDL_Rect left_healthbar2_rect_4[3];
SDL_Rect healthbar2_rect_4[3];

int enemy_maxHealth_4[19],enemy_Health_4[19];
int enemybullet_X_4[18],enemybullet_W_4[18],enemybullet_H_4[18];
float enemybullet_Y_4[18];

int enemy2_maxHealth_4[3],enemy2_Health_4[3];

int enemybullet2_X_4[10],enemybullet2_W_4[10],enemybullet2_H_4[10];
float enemybullet2_Y_4[10];

SDL_Texture* ship_texture_4[19];
SDL_Texture* bullet_texture_4[19];
SDL_Texture* ship2_texture_4[4];
SDL_Texture* bullet2_texture_4[10];

//GameOver gameover;
EnemyShip4::EnemyShip4(){}
void EnemyShip4::get_ship(int shealth, int edam,float ebspeed)
{
    this -> shealth = shealth;
    this -> edam = edam;
    this -> ebspeed = ebspeed;
}
void EnemyShip4::Create_enemyship_1(SDL_Renderer* renderer, const std::string& imagePath1,const std::string& imagePath2) {
    this->renderer = renderer;
    SDL_Surface* ship_surface = IMG_Load(imagePath1.c_str());
    if (!ship_surface) {
        std::cerr << "Failed to load enemy ship image: " << IMG_GetError() << std::endl;
    }

    SDL_Surface* bullet_surface = IMG_Load(imagePath2.c_str());
    if (!bullet_surface) {
        std::cerr << "Failed to load enemy bullet image: " << IMG_GetError() << std::endl;
    }

    for(int i=1;i<=18;i++)
    {
    ship_texture_4[i] = SDL_CreateTextureFromSurface(renderer, ship_surface);
    bullet_texture_4[i] = SDL_CreateTextureFromSurface(renderer, bullet_surface);
    }
    SDL_FreeSurface(ship_surface);
    SDL_FreeSurface(bullet_surface);
}

void EnemyShip4::Create_enemyship_2(SDL_Renderer* renderer, const std::string& imagePath1,const std::string& imagePath2) {
    this->renderer = renderer;
    SDL_Surface* ship_surface = IMG_Load(imagePath1.c_str());
    if (!ship_surface) {
        std::cerr << "Failed to load enemy ship image: " << IMG_GetError() << std::endl;
    }

    SDL_Surface* bullet_surface = IMG_Load(imagePath2.c_str());
    if (!bullet_surface) {
        std::cerr << "Failed to load enemy bullet image: " << IMG_GetError() << std::endl;
    }
    for(int i=1;i<=3;i++)ship2_texture_4[i] = SDL_CreateTextureFromSurface(renderer, ship_surface);
    for(int i=1;i<=9;i++)bullet2_texture_4[i] = SDL_CreateTextureFromSurface(renderer, bullet_surface);

    SDL_FreeSurface(ship_surface);
    SDL_FreeSurface(bullet_surface);
}

void EnemyShip4::update() {}
void EnemyShip4::create_enemyship_position()
{
     for(int i=1;i<=9;i++)
     {
     enemyship_wave4_Rect[i].x=30+180*(i-1);      enemyship_wave4_Rect[i].y=240;
     enemyship_wave4_Rect[i].w=120;               enemyship_wave4_Rect[i].h=120;
     }
     for(int i=10;i<=18;i++)
     {
     enemyship_wave4_Rect[i].x=30+180*(i-10);     enemyship_wave4_Rect[i].y=345;
     enemyship_wave4_Rect[i].w=120;               enemyship_wave4_Rect[i].h=120;
     }
     for(int i=1;i<=3;i++)
     {
     enemyship2_wave4_Rect[i].x=210+540*(i-1);      enemyship2_wave4_Rect[i].y=15;
     enemyship2_wave4_Rect[i].w=210;                enemyship2_wave4_Rect[i].h=210;
     }
}
void EnemyShip4::setting_initial_heath(int h)
{
     for(int i=1;i<=18;i++)
     {
         enemy_maxHealth_4[i] = h;
         enemy_Health_4[i] = enemy_maxHealth_4[i];
     }
     for(int i=1;i<=3;i++)
     {
         enemy2_maxHealth_4[i] = 4*h;
         enemy2_Health_4[i] = enemy2_maxHealth_4[i];
     }
}
void EnemyShip4::create_HP_bar()
{
     for(int i=1;i<=18;i++)
     {
        healthbar_rect_4[i].x = enemyship_wave4_Rect[i].x + 25;
        healthbar_rect_4[i].y = enemyship_wave4_Rect[i].y + 20 ;
        healthbar_rect_4[i].w = enemyship_wave4_Rect[i].w / 10;
        healthbar_rect_4[i].h = enemyship_wave4_Rect[i].h /2;
     }
     for(int i=1;i<=3;i++)
     {
        healthbar2_rect_4[i].x = enemyship2_wave4_Rect[i].x + 25;
        healthbar2_rect_4[i].y = enemyship2_wave4_Rect[i].y + 20 ;
        healthbar2_rect_4[i].w = enemyship2_wave4_Rect[i].w / 10;
        healthbar2_rect_4[i].h = 4*enemyship2_wave4_Rect[i].h /5;
     }
}
void EnemyShip4::render_HP_bar()
{
    for(int i=1;i<=18;i++)if(enemy_Health_4[i]>0)
    {
         current_healthbar_rect_4[i].x = healthbar_rect_4[i].x;
         current_healthbar_rect_4[i].y = healthbar_rect_4[i].y + healthbar_rect_4[i].h - static_cast<int>((static_cast<double>(enemy_Health_4[i]) / enemy_maxHealth_4[i]) * healthbar_rect_4[i].h);
         current_healthbar_rect_4[i].w = healthbar_rect_4[i].w;
         current_healthbar_rect_4[i].h = static_cast<int>((static_cast<double>(enemy_Health_4[i]) / enemy_maxHealth_4[i]) * healthbar_rect_4[i].h);
         if (enemy_Health_4[i] >= 70 * enemy_maxHealth_4[i] / 100) {
            barColor[i] = {0, 255, 0, 255};
         } else if (enemy_Health_4[i] >= 40 * enemy_maxHealth_4[i] / 100) {
            barColor[i] = {255, 255, 0, 255};
         } else if (enemy_Health_4[i] > 0){
            barColor[i] = {255, 0, 0, 255};
         }
         if (enemy_Health_4[i] > 0){
         SDL_SetRenderDrawColor(renderer, barColor[i].r, barColor[i].g, barColor[i].b, barColor[i].a);
         SDL_RenderFillRect(renderer, &current_healthbar_rect_4[i]);

         SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
         SDL_RenderDrawRect(renderer, &healthbar_rect_4[i]);

         left_healthbar_rect_4[i].x = healthbar_rect_4[i].x;
         left_healthbar_rect_4[i].y = healthbar_rect_4[i].y;
         left_healthbar_rect_4[i].w = healthbar_rect_4[i].w;
         left_healthbar_rect_4[i].h = healthbar_rect_4[i].h - current_healthbar_rect_4[i].h;

         SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
         SDL_RenderFillRect(renderer, &left_healthbar_rect_4[i]);
         }
     }
    for(int i=1;i<=3;i++)if(enemy2_Health_4[i]>0)
    {
         current_healthbar2_rect_4[i].x = healthbar2_rect_4[i].x;
         current_healthbar2_rect_4[i].y = healthbar2_rect_4[i].y + healthbar2_rect_4[i].h - static_cast<int>((static_cast<double>(enemy2_Health_4[i]) / enemy2_maxHealth_4[i]) * healthbar2_rect_4[i].h);
         current_healthbar2_rect_4[i].w = healthbar2_rect_4[i].w;
         current_healthbar2_rect_4[i].h = static_cast<int>((static_cast<double>(enemy2_Health_4[i]) / enemy2_maxHealth_4[i]) * healthbar2_rect_4[i].h);
         if (enemy2_Health_4[i] >= 70 * enemy2_maxHealth_4[i] / 100) {
            barColor2[i] = {0, 255, 0, 255};
         } else if (enemy2_Health_4[i] >= 40 * enemy_maxHealth_4[i] / 100) {
            barColor2[i] = {255, 255, 0, 255};
         } else if (enemy2_Health_4[i] > 0){
            barColor2[i] = {255, 0, 0, 255};
         }
         if (enemy2_Health_4[i] > 0){
         SDL_SetRenderDrawColor(renderer, barColor2[i].r, barColor2[i].g, barColor2[i].b, barColor2[i].a);
         SDL_RenderFillRect(renderer, &current_healthbar2_rect_4[i]);

         SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
         SDL_RenderDrawRect(renderer, &healthbar2_rect_4[i]);

         left_healthbar2_rect_4[i].x = healthbar2_rect_4[i].x;
         left_healthbar2_rect_4[i].y = healthbar2_rect_4[i].y;
         left_healthbar2_rect_4[i].w = healthbar2_rect_4[i].w;
         left_healthbar2_rect_4[i].h = healthbar2_rect_4[i].h - current_healthbar2_rect_4[i].h;

         SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
         SDL_RenderFillRect(renderer, &left_healthbar2_rect_4[i]);
         }
     }
}
void EnemyShip4::create_enemybullet_position()
{
     for(int i=1;i<=18;i++)
     {
         enemybullet_X_4[i]=(2*enemyship_wave4_Rect[i].x+enemyship_wave4_Rect[i].w-enemyship_wave4_Rect[i].w/4)/2;
         enemybullet_Y_4[i]=(float)(enemyship_wave4_Rect[i].y+enemyship_wave4_Rect[i].w/2);
         enemybullet_W_4[i]=enemyship_wave4_Rect[i].w/5;
         enemybullet_H_4[i]=enemyship_wave4_Rect[i].h/2;
     }
     for(int i=1;i<=3;i++)
     {
         enemybullet2_X_4[3*i-1]=(2*enemyship2_wave4_Rect[i].x+enemyship2_wave4_Rect[i].w-enemyship2_wave4_Rect[i].w/4)/2;
         enemybullet2_Y_4[3*i-1]=(float)(enemyship2_wave4_Rect[i].y+enemyship2_wave4_Rect[i].w/2);
         enemybullet2_W_4[3*i-1]=enemyship2_wave4_Rect[i].w/4;
         enemybullet2_H_4[3*i-1]=3*enemyship2_wave4_Rect[i].h/2;

         enemybullet2_X_4[3*i-2]=(2*enemyship2_wave4_Rect[i].x+enemyship2_wave4_Rect[i].w-enemyship2_wave4_Rect[i].w/4)/2 - 160;
         enemybullet2_Y_4[3*i-2]=(float)(enemyship2_wave4_Rect[i].y+enemyship2_wave4_Rect[i].w/2) ;
         enemybullet2_W_4[3*i-2]=enemyship2_wave4_Rect[i].w/4;
         enemybullet2_H_4[3*i-2]=3*enemyship2_wave4_Rect[i].h/2;

         enemybullet2_X_4[3*i]=(2*enemyship2_wave4_Rect[i].x+enemyship_wave4_Rect[i].w-enemyship_wave4_Rect[i].w/4)/2 + 160;
         enemybullet2_Y_4[3*i]=(float)(enemyship2_wave4_Rect[i].y+enemyship2_wave4_Rect[i].w/2);
         enemybullet2_W_4[3*i]=enemyship2_wave4_Rect[i].w/4;
         enemybullet2_H_4[3*i]=3*enemyship2_wave4_Rect[i].h/2;
     }
}
void EnemyShip4::bullet_fire(int sx,int sy)
{
    for (int i = 1; i <= 18; i++){
        enemybullet_Y_4[i]+=ebspeed;
        if(enemybullet_Y_4[i]>=sy+20&&enemybullet_Y_4[i]<=sy+80)
            if(enemybullet_X_4[i]>=sx+20&&enemybullet_X_4[i]<=sx+50)
            {

                if(shealth<=edam&&enemy_Health_4[i]!=0)shealth=0; else if(enemy_Health_4[i]!=0)shealth-=edam;
                enemybullet_X_4[i] = (2*enemyship_wave4_Rect[i].x+enemyship_wave4_Rect[i].w-enemyship_wave4_Rect[i].w/4)/2;
                enemybullet_Y_4[i] = (float)(enemyship_wave4_Rect[i].y+enemyship_wave4_Rect[i].w/2);
            }
            if (enemybullet_Y_4[i] > 900){
                enemybullet_X_4[i] = (2*enemyship_wave4_Rect[i].x+enemyship_wave4_Rect[i].w-enemyship_wave4_Rect[i].w/4)/2;
                enemybullet_Y_4[i] = (float)(enemyship_wave4_Rect[i].y+enemyship_wave4_Rect[i].w/2);
        }
    }
    for (int i = 1; i <= 3; i++){
        enemybullet2_Y_4[3*i-2]+=0.2;
        if(enemybullet2_Y_4[3*i-2]+enemybullet2_H_4[3*i-2]-150>=sy&&enemybullet2_Y_4[3*i-2]+enemybullet2_H_4[3*i-2]-150<=sy+20)
            if(enemybullet2_X_4[3*i-2]>=sx+20&&enemybullet2_X_4[3*i-2]<=sx+80)
            {

                if(shealth<=edam*3&&enemy2_Health_4[i]!=0)shealth=0; else if(enemy2_Health_4[i]!=0)shealth-=edam*3;
                enemybullet2_X_4[3*i-2] = (2*enemyship2_wave4_Rect[i].x+enemyship2_wave4_Rect[i].w-enemyship2_wave4_Rect[i].w/4)/2 - 160;
                enemybullet2_Y_4[3*i-2] = (float)(enemyship2_wave4_Rect[i].y+enemyship2_wave4_Rect[i].w/2);
            }
            if (enemybullet2_Y_4[3*i-2] > 900){
                enemybullet2_X_4[3*i-2] = (2*enemyship2_wave4_Rect[i].x+enemyship2_wave4_Rect[i].w-enemyship2_wave4_Rect[i].w/4)/2 - 160;
                enemybullet2_Y_4[3*i-2] = (float)(enemyship2_wave4_Rect[i].y+enemyship2_wave4_Rect[i].w/2);
        }
    }
    for (int i = 1; i <= 3; i++){
        enemybullet2_Y_4[3*i-1]+=0.2;
        if(enemybullet2_Y_4[3*i-1]+enemybullet2_H_4[3*i-1]-150>=sy&&enemybullet2_Y_4[3*i-1]+enemybullet2_H_4[3*i-1]-150<=sy+20)
            if(enemybullet2_X_4[3*i-1]>=sx+20&&enemybullet2_X_4[3*i-1]<=sx+80)
            {

                if(shealth<=edam*3&&enemy2_Health_4[i]!=0)shealth=0; else if(enemy2_Health_4[i]!=0)shealth-=edam*3;
                enemybullet2_X_4[3*i-1] = (2*enemyship2_wave4_Rect[i].x+enemyship2_wave4_Rect[i].w-enemyship2_wave4_Rect[i].w/4)/2;
                enemybullet2_Y_4[3*i-1] = (float)(enemyship2_wave4_Rect[i].y+enemyship2_wave4_Rect[i].w/2);
            }
            if (enemybullet2_Y_4[3*i-1] > 900){
                enemybullet2_X_4[3*i-1] = (2*enemyship2_wave4_Rect[i].x+enemyship2_wave4_Rect[i].w-enemyship2_wave4_Rect[i].w/4)/2;
                enemybullet2_Y_4[3*i-1] = (float)(enemyship2_wave4_Rect[i].y+enemyship2_wave4_Rect[i].w/2);
        }
    }
    for (int i = 1; i <= 3; i++){
        enemybullet2_Y_4[3*i]+=0.2;
        if(enemybullet2_Y_4[3*i]+enemybullet2_H_4[3*i]-150>=sy&&enemybullet2_Y_4[3*i]+enemybullet2_H_4[3*i]-150<=sy+100)
            if(enemybullet2_X_4[3*i]>=sx&&enemybullet2_X_4[3*i]<=sx+100)
            {

                if(shealth<=edam*3&&enemy2_Health_4[i]!=0)shealth=0; else if(enemy2_Health_4[i]!=0)shealth-=edam*3;
                enemybullet2_X_4[3*i] = (2*enemyship2_wave4_Rect[i].x+enemyship2_wave4_Rect[i].w-enemyship2_wave4_Rect[i].w/4)/2 + 160;
                enemybullet2_Y_4[3*i] = (float)(enemyship2_wave4_Rect[i].y+enemyship2_wave4_Rect[i].w/2);
            }
            if (enemybullet2_Y_4[3*i] > 900){
                enemybullet2_X_4[3*i] = (2*enemyship2_wave4_Rect[i].x+enemyship2_wave4_Rect[i].w-enemyship2_wave4_Rect[i].w/4)/2 + 160;
                enemybullet2_Y_4[3*i] = (float)(enemyship2_wave4_Rect[i].y+enemyship2_wave4_Rect[i].w/2);
        }
    }
}
int EnemyShip4::update_current_health(){
    return shealth;
}
void EnemyShip4::ship_render(SDL_Renderer* renderer) {
     for (int i = 1; i <= 18; i++){SDL_RenderCopy(renderer, ship_texture_4[i], NULL, &enemyship_wave4_Rect[i]);}
     for (int i = 1; i <= 3; i++){SDL_RenderCopy(renderer, ship2_texture_4[i], NULL, &enemyship2_wave4_Rect[i]);}
}
void EnemyShip4::bullet_render(SDL_Renderer* renderer) {
     for (int i = 1; i <= 18; i++){
        bullet = {enemybullet_X_4[i], enemybullet_Y_4[i], enemybullet_W_4[i], enemybullet_H_4[i]};
        SDL_RenderCopy(renderer, bullet_texture_4[i], NULL, &bullet);
            }
     for (int i = 1; i <= 9; i++){
        bullet = {enemybullet2_X_4[i], enemybullet2_Y_4[i], enemybullet2_W_4[i], enemybullet2_H_4[i]};
        SDL_RenderCopy(renderer, bullet2_texture_4[i], NULL, &bullet);
            }
}

void EnemyShip4::destroy_ship(int shipnum)
{
    SDL_DestroyTexture(ship_texture_4[shipnum]);
    ship_texture_4[shipnum]=NULL;
}

void EnemyShip4::destroy_ship2(int shipnum)
{
    SDL_DestroyTexture(ship2_texture_4[shipnum]);
    ship2_texture_4[shipnum]=NULL;
}

void EnemyShip4::destroy_bullet(int shipnum)
{
    SDL_DestroyTexture(bullet_texture_4[shipnum]);
    bullet_texture_4[shipnum]=NULL;
}

void EnemyShip4::destroy_bullet2(int shipnum)
{
    SDL_DestroyTexture(bullet2_texture_4[shipnum]);
    bullet2_texture_4[shipnum]=NULL;
}

void EnemyShip4::Destroy_EnemyShip() {
    for(int i=1;i<=18;i++)
    {
    SDL_DestroyTexture(ship_texture_4[i]);
    SDL_DestroyTexture(bullet_texture_4[i]);
    enemy_Health_4[i]=0;
    }
    for(int i=1;i<=3;i++)
    {
    SDL_DestroyTexture(ship2_texture_4[i]);
    enemy2_Health_4[i]=0;
    }
    for(int i=1;i<=9;i++)SDL_DestroyTexture(bullet2_texture_4[i]);
}

bool EnemyShip4::in_Wave4()
{
    return EnemyShip4::in_Wave4();
}
