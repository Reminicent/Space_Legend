#ifndef SCORE_H_INCLUDED
#define SCORE_H_INCLUDED

#include <SDL.h>
#include <SDL_ttf.h>

class Score {
public:
    Score();
    ~Score();

    void Score_create(SDL_Renderer* renderer, int x, int y, int fontSize);
    void render(SDL_Renderer* renderer);
    void increaseScore(int value);

private:

    int score = 0;
    SDL_Texture* texture;
    SDL_Rect position;
    TTF_Font* font;
};


#endif // SCORE_H_INCLUDED

