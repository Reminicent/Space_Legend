#include "Wave1_create.h"
#include <SDL.h>
#include <SDL_image.h>
#include <bits/stdc++.h>

EnemyShip::EnemyShip(SDL_Renderer* renderer, const std::string& imagePath1, const std::string& imagePath2){
    SDL_Surface* enemyship_surface = IMG_Load(imagePath1.c_str());
    if (!enemyship_surface) {
        std::cerr << "Failed to load enemy image: " << IMG_GetError() << std::endl;
    }
    enemyship_texture = SDL_CreateTextureFromSurface(renderer, enemyship_surface);
    SDL_FreeSurface(enemyship_surface);

    SDL_Surface* enemybullet_surface = IMG_Load(imagePath2.c_str());
    if (!enemyship_surface) {
        std::cerr << "Failed to load enemy image: " << IMG_GetError() << std::endl;
    }
    enemybullet_texture = SDL_CreateTextureFromSurface(renderer, enemybullet_surface);
    SDL_FreeSurface(enemybullet_surface);

    //this-> shipnum = shipnum;
    this-> shipX = shipX;       this->shipY = shipY;
    this-> i = i;
    this->screen_height = screen_height;   this->screen_width = screen_width;
}
void EnemyShip::setScreenSize(int width, int height) {
    screen_width = width;
    screen_height = height;
}

EnemyShip::~EnemyShip() {
    SDL_DestroyTexture(enemyship_texture);
    SDL_DestroyTexture(enemybullet_texture);
}

void EnemyShip::create_enemyship_position() {
        while(i<shipnum)
        {
            for(int j=0;shipX+180*j<screen_width;j++)
                if(i<shipnum){
                enemyship_matrix[i].x=shipX+180*j;         enemyship_matrix[i].y=shipY;
                enemyship_matrix[i].w=120;                 enemyship_matrix[i].h=120;
                i++;
            }
            shipY+=105;
        }
        for(i=0;i<shipnum;i++)
        {
                enemybulletX[i]=(float)((2*enemyship_matrix[i].x+enemyship_matrix[i].w-enemyship_matrix[i].w/4)/2);
                enemybulletY[i]=(float)(enemyship_matrix[i].y+enemyship_matrix[i].w/2);
                enemybulletW[i]=enemyship_matrix[i].w/5;
                enemybulletH[i]=enemyship_matrix[i].h/2;
        }
}

void EnemyShip::render(SDL_Renderer* renderer) {
    for (int j = 0; j < shipnum; j++){SDL_RenderCopy(renderer, enemyship_texture, NULL, &enemyship_matrix[j]);}
    for (int j = 0; j < shipnum; j++){
                enemybullet_rect = {enemybulletX[j], enemybulletY[j], enemybulletW[j], enemybulletH[j]};
                SDL_RenderCopy(renderer, enemybullet_texture, NULL, &enemybullet_rect);
}
}
