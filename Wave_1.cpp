#include <SDL.h>
#include <SDL_image.h>
#include <bits/stdc++.h>
const int SCREEN_WIDTH = 1600;
const int SCREEN_HEIGHT = 900;
const float BULLET_SPEED = 0.5f;
bool line1=false,line2=false,line3=true,line;

bool IsMouseInsideSquare(int mouseX, int mouseY, int squareX, int squareY, int squareSize) {
    return (mouseX >= squareX && mouseX <= squareX + squareSize &&
            mouseY >= squareY && mouseY <= squareY + squareSize);
}
int main(int argc, char* argv[]) {

    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Wave_1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    SDL_Surface* squareSurface = IMG_Load("C:/Users/Tran Dai Nghia/Desktop/Space Legend/Image/Spaceship/Ship5.png");
    if (!squareSurface) {
        std::cerr << "Failed to load square image: " << IMG_GetError() << std::endl;
        return 1;
    }
    SDL_Surface* shipSurface = IMG_Load("C:/Users/Tran Dai Nghia/Desktop/Space Legend/Image/Spaceship/Ship3.png");
    if (!shipSurface) {
        std::cerr << "Failed to load square image: " << IMG_GetError() << std::endl;
        return 1;
    }

    SDL_Surface* bulletSurface = IMG_Load("C:/Users/Tran Dai Nghia/Desktop/Space Legend/Image/Bullet/Bullet3.png");
    if (!bulletSurface) {
        std::cerr << "Failed to load square image: " << IMG_GetError() << std::endl;
        return 1;
    }

    SDL_Texture* squareTexture = SDL_CreateTextureFromSurface(renderer, squareSurface);
    SDL_FreeSurface(squareSurface);

    SDL_Texture* shipTexture = SDL_CreateTextureFromSurface(renderer, shipSurface);
    SDL_FreeSurface(shipSurface);

    SDL_Texture* bulletTexture = SDL_CreateTextureFromSurface(renderer, bulletSurface);
    SDL_FreeSurface(bulletSurface);

    const int square = 27;    float coorX=30,coorY=15;   int i=0;
    SDL_Rect square2[square];
        while(i<square)
        {
            for(int j=0;coorX+180*j<SCREEN_WIDTH;j++)
                if(i<square){
                square2[i].x=coorX+180*j;         square2[i].y=coorY;
                square2[i].w=120;                 square2[i].h=120;
                i++;
            }
            coorY+=105;
        }

    float bulletX[27],bulletY[27];     i=0;
    int bulletW[27],bulletH[27];
    while(i<square)
        {
                bulletX[i]=(float)((2*square2[i].x+square2[i].w-square2[i].w/4)/2);         bulletY[i]=(float)(square2[i].y+square2[i].w/2);
                bulletW[i]=square2[i].w/5;                                                  bulletH[i]=square2[i].h/2;
                i++;
        }

    int squareX = 640,newSquareX;             int squareY = 680,newSquareY;
    int mouseX = 0;                 int mouseY = 0;
    bool mousePressed = false;
    int squareSize = 100;
    float k;

    bool quit = false;
    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                quit = true;
            } else if (event.type == SDL_MOUSEBUTTONDOWN) {
                SDL_GetMouseState(&mouseX, &mouseY);
                if (IsMouseInsideSquare(mouseX, mouseY, squareX, squareY, squareSize)) {
                    mousePressed = true;
                }
            } else if (event.type == SDL_MOUSEBUTTONUP) {
                mousePressed = false;
            } else if (event.type == SDL_MOUSEMOTION && mousePressed) {
                SDL_GetMouseState(&mouseX, &mouseY);
                 newSquareX = mouseX - squareSize / 2;
                 newSquareY = mouseY - squareSize / 2;

            }

                if (newSquareX >= 0 && newSquareY >= 0 && newSquareX + squareSize <= SCREEN_WIDTH && newSquareY + squareSize <= SCREEN_HEIGHT&& newSquareY >= SCREEN_HEIGHT/2)
                    if(newSquareX - squareSize < squareX&&newSquareY - squareSize < squareY&&squareX - squareSize < newSquareX&&squareY - squareSize < newSquareY){
                    squareX = newSquareX;
                    squareY = newSquareY;
                }
        }

        SDL_SetRenderDrawColor(renderer, 0, 20, 40, 75);
        SDL_RenderClear(renderer);

        SDL_Rect square1 = {squareX, squareY, squareSize, squareSize};
        SDL_RenderCopy(renderer, squareTexture, NULL, &square1);

        line=true;
        if(line3&&line){
            line1=true;      line=false;    line3=false;
            for (int j = 0; j < 9; j++){
                bulletY[j]+=BULLET_SPEED;
                if (bulletY[j] > SCREEN_HEIGHT){
                        bulletY[j] = (float)(square2[j].y+square2[j].w/2);
                        bulletX[j] = (float)(2*square2[j].x+square2[j].w-square2[j].w/4)/2;
                }
            }
        }
        if(line1&&line){
            line2=true;        line=false;    line1=false;
            for (int j = 9; j < 18; j++){
                bulletY[j]+=BULLET_SPEED;
                if (bulletY[j] > SCREEN_HEIGHT){
                        bulletY[j] = (float)(square2[j].y+square2[j].w/2);
                        bulletX[j] = (float)(2*square2[j].x+square2[j].w-square2[j].w/4)/2;
                }
            }
        }

        if(line2&&line){
            line3=true;         line=false;    line2=false;
            for (int j = 18; j < 27; j++){
                bulletY[j]+=BULLET_SPEED;
                if (bulletY[j] > SCREEN_HEIGHT){
                        bulletY[j] = (float)(square2[j].y+square2[j].w/2);
                        bulletX[j] = (float)(2*square2[j].x+square2[j].w-square2[j].w/4)/2;
                }
            }
        }

        for (int j = 0; j < square; j++){SDL_RenderCopy(renderer, shipTexture, NULL, &square2[j]);}
        for (int j = 0; j < square; j++){
                SDL_Rect bullet = {bulletX[j], bulletY[j], bulletW[j], bulletH[j]};
                SDL_RenderCopy(renderer, bulletTexture, NULL, &bullet);
        }


        SDL_RenderPresent(renderer);

    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
