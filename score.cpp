#include "score.h"
#include <bits/stdc++.h>
#include <SDL_ttf.h>

Score::Score(){}
Score::~Score() {
    SDL_DestroyTexture(texture);
    TTF_CloseFont(font);
}

void Score::Score_create(SDL_Renderer* renderer, int x, int y, int fontSize) {
    //Free();
    if (texture != nullptr)SDL_DestroyTexture(texture);
    font = TTF_OpenFont("DancingScript.ttf", fontSize);
    if (font == nullptr) {
       std::cerr << "Failed to load font: " << TTF_GetError() << std::endl;
    }

    SDL_Color color = {255, 255, 255};
    SDL_Surface* surface = TTF_RenderText_Solid(font, "Score : 0", color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    int textWidth, textHeight;
    SDL_QueryTexture(texture, nullptr, nullptr, &textWidth, &textHeight);

    position.x = x;
    position.y = y;
    position.w = textWidth;
    position.h = textHeight;
}

void Score::render(SDL_Renderer* renderer) {
    std::string scoreText = "Score : " + std::to_string(score);
    SDL_Surface* surface = TTF_RenderText_Solid(font, scoreText.c_str(), {255, 255, 255});
    //if (texture != nullptr)SDL_DestroyTexture(texture);
    SDL_Texture* newTexture = SDL_CreateTextureFromSurface(renderer, surface);
    SDL_FreeSurface(surface);

    if (texture != nullptr)SDL_DestroyTexture(texture);
    texture = newTexture;

    SDL_RenderCopy(renderer, texture, nullptr, &position);
    if (texture != nullptr)SDL_DestroyTexture(texture);
}

void Score::increaseScore(int value) {
    score += value;
}
