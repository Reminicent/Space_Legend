#ifndef INITIAL_INTERFACE_H_INCLUDED
#define INITIAL_INTERFACE_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>

class MainMenu {
public:
    MainMenu(SDL_Renderer* renderer);
    ~MainMenu();
    void render(SDL_Renderer* renderer);
    bool handleEvent(SDL_Event& e);
private:
    SDL_Renderer* renderer;
    SDL_Texture* playTexture;
    SDL_Texture* instructionsTexture;
    SDL_Texture* quitTexture;
    SDL_Rect playButtonRect;
    SDL_Rect instructionsButtonRect;
    SDL_Rect quitButtonRect;
};

#endif // INITIAL_INTERFACE_H_INCLUDED
