#ifndef INITIAL_INTERFACE_H_INCLUDED
#define INITIAL_INTERFACE_H_INCLUDED

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_mixer.h>

class MainMenu {
public:
    MainMenu();
    void Destroy_MainMenu();

    void Create_MainMenu(SDL_Renderer*renderer);
    void render(SDL_Renderer* renderer);
    bool handleEvent(SDL_Event& e);
private:
    SDL_Renderer* renderer;

    SDL_Texture* playTexture;
    SDL_Texture* instructionsTexture;
    SDL_Texture* quitTexture;
    //SDL_Texture* creditTexture;
    //SDL_Texture* highscoreTexture;

    SDL_Rect playButtonRect;
    SDL_Rect instructionsButtonRect;
    SDL_Rect quitButtonRect;
    SDL_Rect creditButtonRect;
    SDL_Rect highscoreButtonRect;

};

#endif // INITIAL_INTERFACE_H_INCLUDED
